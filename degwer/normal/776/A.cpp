#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string sa, sb;
	cin >> sa >> sb;
	cout << sa << " " << sb << endl;
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		string a, b;
		cin >> a >> b;
		if (a == sa)sa = b;
		else sb = b;
		cout << sa << " " << sb << endl;
	}
}