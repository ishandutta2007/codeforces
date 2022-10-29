#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
string d[8] = { "vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon" };
int main()
{
	int t;
	scanf("%d", &t);
	string s;
	cin >> s;
	for (int i = 0; i < 8; i++)
	{
		if (s.size() == d[i].size())
		{
			bool f = true;
			for (int j = 0; j < s.size(); j++)
			{
				if (!(s[j] == d[i][j] || s[j] == '.'))f = false;
			}
			if (f)cout << d[i] << endl;
		}
	}
}