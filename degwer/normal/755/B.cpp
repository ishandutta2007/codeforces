#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
using namespace std;
int main()
{
	int na, nb;
	scanf("%d%d", &na, &nb);
	set<string>se;
	for (int i = 0; i < na; i++)
	{
		string s;
		cin >> s;
		se.insert(s);
	}
	int c = 0;
	for (int i = 0; i < nb; i++)
	{
		string s;
		cin >> s;
		if (se.find(s) != se.end())c++;
	}
	int a = na - c, b = nb - c;
	for (;;)
	{
		if (a == 0 && c == 0)
		{
			printf("NO\n");
			break;
		}
		if (c > 0)c--;
		else a--;
		if (b == 0 && c == 0)
		{
			printf("YES\n");
			break;
		}
		if (c > 0)c--;
		else b--;
	}
}