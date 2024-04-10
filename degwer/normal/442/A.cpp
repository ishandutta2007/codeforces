#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef pair<int, int>pii;
pii g(string s)
{
	pii ret;
	if (s[0] == 'R')ret.first = 0;
	if (s[0] == 'G')ret.first = 1;
	if (s[0] == 'B')ret.first = 2;
	if (s[0] == 'Y')ret.first = 3;
	if (s[0] == 'W')ret.first = 4;
	ret.second = s[1] - '1';
	return ret;
}
int main()
{
	int num;
	scanf("%d", &num);
	vector<pii>v;
	for (int i = 0; i < num; i++)
	{
		string s;
		cin >> s;
		v.push_back(g(s));
	}
	int mini = 100000;
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			bool f = true;
			for (int k = 0; k < num; k++)
			{
				for (int l = k + 1; l < num; l++)
				{
					if (v[k] == v[l])continue;
					if ((v[k].first==v[l].first||(v[k].first != v[l].first && (i&(1 << v[k].first)) == 0 && (i&(1 << v[l].first)) == 0)) && (v[k].second==v[l].second||(v[k].second != v[l].second && (j&(1 << v[k].second)) == 0 && (j&(1 << v[l].second)) == 0)))
					{
						f = false;
						break;
					}
				}
			}
			if (f)
			{
				int a = 0;
				for (int k = 0; k < 5; k++)if (i&(1 << k))a++;
				for (int k = 0; k < 5; k++)if (j&(1 << k))a++;
				mini = min(mini, a);
			}
		}
	}
	printf("%d\n", mini);
}