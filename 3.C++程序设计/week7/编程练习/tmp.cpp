#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

string str[21];
int NumOfStr = 0;


bool isNum(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (!isdigit(s[i]))
		{
			return false;
		}
	}
	return true;
}

int find()
{
	char s;
	int n;
	cin >> s >> n;
	return str[n].find(s);
}

int rfind()
{
	char s;
	int n;
	cin >> s >> n;
	return str[n].rfind(s);
}

int get_int()
{
	string str;
	cin >> str;
	if (isNum(str))
	{
		return atoi(str.c_str());
	}
	else
	{
		if (str == "find")
		{
			return find();
		}
		else if (str == "rfind")
		{
			return rfind();
		}
	}
	return 0;
}



string copy()
{
	int n, x, l;
	n = get_int();
	x = get_int();
	l = get_int();
	return str[n].substr(x, l);
}

string add();

string get_str()
{
	string str;
	cin >> str;
	if (str == "copy")
	{
		return copy();
	}
	else if (str == "add")
	{
		return add();
	}
	else
	{
		return str;
	}
}

string add()
{
	string s1 = get_str();
	string s2 = get_str();
	int n1 = atoi(s1.c_str());
	int n2 = atoi(s2.c_str());
	if (isNum(s1) && isNum(s2) && n1 >= 0 && n1 <= 99999 && n2 >= 0 && n2 <= 99999)
	{
		char str[10];
		int a = n1+n2;
		sprintf(str, "%d", a);
		return str;
	}
	else
	{
		return s1 + s2;
	}
}



void insert()
{
	string s = get_str();
	int n = get_int();
	int x = get_int();
	str[n].insert(x, s);
}

void reset()
{
	string s = get_str();
	int n = get_int();
	str[n] = s;
}

void print()
{
	int n = get_int();
	cout << str[n] << endl;
}

void printall()
{
	for (int i = 1; i <= NumOfStr; i++)
	{
		cout << str[i] << endl;
	}
}

int main()
{
	cin >> NumOfStr;
	for (int i = 1; i <= NumOfStr; i++)
	{
		cin >> str[i];
	}
	while (true)
	{
		string operation;
		cin >> operation;
		if (operation == "insert")
		{
			insert();
		}
		else if (operation == "reset")
		{
			reset();
		}
		else if (operation == "print")
		{
			print();
		}
		else if (operation == "printall")
		{
			printall();
		}
		else if (operation == "over")
		{
			break;
		}
	}
	return 0;

}