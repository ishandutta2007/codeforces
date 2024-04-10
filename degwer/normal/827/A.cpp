#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
using namespace std;
string ans;
int main()
{
	int num;
	scanf("%d", &num);
	set<int>se;
	for (int i = 0; i < 2100000; i++)se.insert(i);
	ans.resize(2100000);
	int maxi = 0;
	for (int i = 0; i < num; i++)
	{
		string s;
		cin >> s;
		int zn;
		scanf("%d", &zn);
		for (int j = 0; j < zn; j++)
		{
			int z;
			scanf("%d", &z);
			z--;
			maxi = max(maxi, z + int(s.size()));
			set<int>::iterator it = se.lower_bound(z);
			for (;;)
			{
				if ((*it) >= z + s.size())break;
				ans[*it] = s[(*it) - z];
				se.erase(it++);
			}
		}
	}
	for (int i = 0; i < maxi; i++)
	{
		if (ans[i] == 0)printf("a");
		else printf("%c", ans[i]);
	}
	printf("\n");
}