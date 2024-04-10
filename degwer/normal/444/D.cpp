#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
#define B 300
#define NB 700
vector<int>dat[1000000];
int ptn[60000][5];
int ans[NB][NB];
int las[NB];
int tos[1000000];
int getn(string s)
{
	int now = 0;
	for (int i = 0; i < s.size(); i++)
	{
		now *= 28;
		now += s[i] - 'a' + 1;
	}
	return now;
}
int main()
{
	string str;
	cin >> str;
	int num = str.size();
	for (int i = 0; i < 10; i++)str.push_back('a' + 26);
	for (int i = 0; i < num; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			string s;
			for (int k = 0; k < j; k++)s.push_back(str[i + k]);
			int x = getn(s);
			ptn[i][j] = x;
			dat[x].push_back(i);
		}
	}
	vector<int>vec;
	for (int i = 0; i < 1000000; i++)
	{
		if (dat[i].size() >= B)vec.push_back(i), tos[i] = vec.size() - 1;
	}
	for (int i = 0; i < NB; i++)for (int j = 0; j < NB; j++)ans[i][j] = 1000000000;
	for (int i = 0; i < NB; i++)las[i] = -1000000000;
	for (int i = 0; i < num; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			int x = ptn[i][j];
			if (dat[x].size() >= B)
			{
				las[tos[x]] = i;
				for (int k = 0; k < vec.size(); k++)
				{
					ans[tos[x]][k] = min(ans[tos[x]][k], i - las[k] + j);
				}
			}
		}
	}
	int query;
	scanf("%d", &query);
	for (int p = 0; p < query; p++)
	{
		string sa, sb;
		cin >> sa >> sb;
		int x1 = getn(sa), x2 = getn(sb);
		if (dat[x1].size()>dat[x2].size())swap(x1, x2), swap(sa, sb);
		if (dat[x1].size() == 0)
		{
			printf("-1\n");
			continue;
		}
		if (dat[x1].size() < B)
		{
			int anss = 1000000000;
			for (int i = 0; i < dat[x1].size(); i++)
			{
				int low = lower_bound(dat[x2].begin(), dat[x2].end(), dat[x1][i]) - dat[x2].begin();
				if (low != dat[x2].size())anss = min(anss, dat[x2][low] - dat[x1][i] + int(sb.size()));
				if (low != 0)anss = min(anss, dat[x1][i] - dat[x2][low - 1] + int(sa.size()));
			}
			printf("%d\n", max(int(max(sa.size(),sb.size())),anss));
		}
		else
		{
			printf("%d\n", max(int(max(sa.size(), sb.size())), min(ans[tos[x1]][tos[x2]], ans[tos[x2]][tos[x1]])));
		}
	}
}