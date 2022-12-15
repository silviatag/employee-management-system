#include <iostream>
#include <string>
using namespace std;


class Employee
{
private:
	string FullName;
	string Email;
	string Phone;
	string Position;
	double Salary;
public:

	//constructors
	Employee() //default
	{
		FullName = "";
		Email = "";
		Phone = "";
		Position = "";
		Salary = 0;
	}
	Employee(string name, string mail, string phone, string pos, double salary)
	{
		FullName = name;
		Email = mail;
		Phone = phone;
		Position = pos;
		Salary = salary;
	}


	//setters and getters
	void set_FullName(string s)
	{
		FullName = s;
	}
	string get_FullName()
	{
		return FullName;
	}
	void set_Email(string s)
	{
		Email = s;
	}
	string get_Email()
	{
		return Email;
	}
	void set_Phone(string s)
	{
		Phone = s;
	}
	string get_Phone()
	{
		return Phone;
	}
	void set_Position(string s)
	{
		Position = s;
	}
	string get_Position()
	{
		return Position;
	}
	void set_Salary(double s)
	{
		Salary = s;
	}
	double get_Salary()
	{
		return Salary;
	}
	void display_employee_info()
	{
		cout << "Full name:\t" << FullName << endl;
		cout << "Email:\t\t" << Email << endl;
		cout << "Phone:\t\t" << Phone << endl;
		cout << "Position:\t" << Position << endl;
		cout << "Salary:\t\t" << Salary << endl;
		cout <<  "--------------------" << endl << endl;
	}
};

template <class T>
class Node
{
public:
	T value;
	Node<T>* next;

	Node(T e)
	{
		value = e;
		next = NULL;
	}
};

template <class T>
class EmployeeList
{
	Node<T>* head;
public:
	EmployeeList()
	{
		head = NULL;
	}

	bool insert_employee(T e)
	{
		Node<T>* newnode= new Node<T>(e);
		Node<T>* ptr = head;
		if (head == NULL)
		{
			head = newnode;
			cout << "employee has been added" << endl;
			return true;
		}
		while (ptr != NULL)
		{
			if(ptr->value.get_Email()== e.get_Email())
			{
				cout << "employee already exists" << endl;
				return false;
			}
			ptr = ptr->next;
		}
		ptr = head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = newnode;
		cout << "employee has been added" << endl;
		return true;
	}


	bool edit_salary(string email, double s)
	{
		Node<T>* ptr = head;
		if (head == NULL)
		{
			cout << "The system is empty" << endl;
			return false;
		}

		while (ptr)
		{
			if (ptr->value.get_Email() == email)
			{
				ptr->value.set_Salary(s);
				cout << "salary has been edited" << endl;
				return true;
			}
			ptr = ptr->next;
		}
		cout << "employee was not found" << endl;
		return false;
	}

	bool delete_employee(string email)
	{
		Node<T>* ptr = head;
		Node<T>* temp = NULL;
		if (head == NULL)
		{
			cout << "The system is empty" << endl;
			return false;
		}



		if (ptr->value.get_Email() == email)
		{
			temp = ptr->next;
			head = temp;
			delete ptr;
			cout << "Employee successfully deleted" << endl;
			return true;
		}



		while (ptr)
		{
			if (ptr->next->value.get_Email() == email)
			{
				temp = ptr->next;
				ptr->next = temp->next;
				delete temp;
				cout << "Employee successfully deleted" << endl;
				return true;
			}
			ptr = ptr->next;
		}
		cout << "employee was not found" << endl;
		return false;
	}

	bool update_info(string email)
	{
		Node<T>* ptr = head;
		if (head == NULL)
		{
			cout << "The system is empty" << endl;
			return false;
		}

		while (ptr)
		{
			if (ptr->value.get_Email() == email)
			{
				int update;
				cout << "1. Update full name " << endl;
				cout << "2. Update email " << endl;
				cout << "3. Update Phone number " << endl;
				cout << "4. Update Position " << endl;
				cout << "5. Update Salary " << endl;
				//cin >> update;
				///////////////////////////////////////////////

				while (true)
				{
					string str;
					cin >> update;
					if (cin.fail() || (update > 5 || update <= 0))
					{
						cin.clear();
						getline(cin, str);
						cout << "invalid input, try Again... "<<endl;
						continue;
					}

					if (cin.peek() != '\n')
					{
						getline(cin, str);
						cout << "invalid input, try Again... "<<endl;
					}
					else break;
				}



				if (update == 1)
				{
					string name;
					cout << "Enter new name: ";
					cin.ignore();
					getline(cin, name);
					ptr->value.set_FullName(name);
				}
				else if (update == 2)
				{
					string email;
					cout << "Enter new email: ";
					cin >> email;
					ptr->value.set_Email(email);
				}
				else if (update == 3)
				{
					string num;
					cout << "Enter new phone number: ";
					cin >> num;
					ptr->value.set_Phone(num);
				}
				else if (update == 4)
				{
					string pos;
					cout << "Enter new position: ";
					cin >> pos;
					ptr->value.set_Position(pos);
				}
				else if (update == 5)
				{
					double salary;
					cout << "Enter new salary: ";
					cin >> salary;
					ptr->value.set_Salary(salary);
				}
				cout << "employee has been updated" << endl;
				return true;
			}
			ptr = ptr->next;
		}
		cout << "employee was not found" << endl;
		return false;
	}

	void print_all_employees()
	{
		Node<T>* ptr = head;
		if (head == NULL)
		{
			cout <<endl<< "system is empty" << endl;
			return;
		}
		cout << "All employees on the system:  " << endl << endl;
		while (ptr)
		{
			ptr->value.display_employee_info();
			ptr = ptr->next;
		}
	}
};

int main()
{
	int choice = 0;
	EmployeeList<Employee> employees;
	while (choice != 6)
	{
		cout << "----------------------------------------"  << endl;
		cout << "Welcome to the Employee Management System" << endl;
		cout << "Choose of the following to use the system features" << endl;
		cout << "1. Insert a new Employee" << endl;
		cout << "2. Edit employee's salary" << endl;
		cout << "3. Delete an employee" << endl;
		cout << "4. Print all employees" << endl;
		cout << "5. Update employee iinformation" << endl;
		cout << "6. Close the program" << endl;
		cout << "----------------------------------------" << endl << endl;
		//cin >> choice;

		while (true)
		{
			string str;
			cin >> choice;
			if (cin.fail()||(choice>6 || choice<=0))
			{
				cin.clear();
				getline(cin, str);
				cout << "invalid input, try Again... " << endl;
				continue;
			}

			if (cin.peek() != '\n')
			{
				getline(cin, str);
				cout << "invalid input, try Again... " << endl;
			}
			else break;
		}

		switch (choice)
		{
			case 1: //inserting an employee
			{
				string FullName;
				string Email;
				string Phone;
				string Position;
				double Salary;
				cout << "Enter your full name:		";
				cin >> FullName;
				cout << "Enter your email:		";
				cin >> Email;
				cout << "Enter your phone:		";
				cin >> Phone;
				cout << "Enter your Position:		";
				cin >> Position;
				cout << "Enter your Salary:		";
				//cin >> Salary;
				while (true)
				{
					string str;
					cin >> Salary;
					if (cin.fail())
					{
						cin.clear();
						getline(cin, str);
						cout << "invalid input, enter salary again... " << endl;
						continue;
					}

					if (cin.peek() != '\n')
					{
						getline(cin, str);
						cout << "invalid input, try Again... " << endl;
					}
					else break;
				}
				Employee e (FullName, Email, Phone, Position, Salary);
				employees.insert_employee(e);
				break;
			}
			case 2:
			{
				string email;
				double salary;
				cout << "Email of the employee you want to edit their salary:  ";
				cin >> email;
				cout << "you want to edit their salary to:  ";
				//cin >> salary;

				while (true)
				{
					string str;
					cin >> salary;
					if (cin.fail())
					{
						cin.clear();
						getline(cin, str);
						cout << "invalid input, try Again... " << endl;
						continue;
					}

					if (cin.peek() != '\n')
					{
						getline(cin, str);
						cout << "invalid input, try Again... " << endl;
					}
					else break;
				}

				employees.edit_salary(email, salary);
				break;
			}
			case 3:
			{
				string email;
				cout << "Email of the employee you want to delete:  ";
				cin >> email;
				employees.delete_employee(email);
				break;
			}
			case 4:
			{
				employees.print_all_employees();
				break;
			}
			case 5:
			{
				string email;
				cout << "email of the employee you want to update: ";
				cin >> email;
				employees.update_info(email);
				break;
			}
		}
	}

}
