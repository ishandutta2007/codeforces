#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	int a, b;
	string s;
	cin >> a >> b >> s;
	string r;
	int h = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (b - i == h)
		{
			for (int j = 0; j < b - i; j++)r.push_back(')');
			break;
		}
		r.push_back(s[i]);
		h += (s[i] == '(') ? 1 : -1;
	}
	cout << r << endl;
}