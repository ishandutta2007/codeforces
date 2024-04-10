#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string s;
	cin >> s;
	string t = "CODEFORCES";
	if (s.size() < t.size())
	{
		printf("NO\n");
		return 0;
	}
	for (int i = 0; i <= t.size(); i++)
	{
		string z;
		for (int j = 0; j < i; j++)z.push_back(s[j]);
		for (int j = s.size() - t.size() + i; j < s.size(); j++)z.push_back(s[j]);
		if (t == z)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}