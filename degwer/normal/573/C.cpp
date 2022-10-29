#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[100000];
vector<int>ko[100000];
bool flag[100000];
int dp1[100000];
int dp2[100000];
int par[100000];
void dfs(int node)
{
	if (flag[node])return;
	flag[node] = true;
	for (int i = 0; i < pat[node].size(); i++)
	{
		if (!flag[pat[node][i]])
		{
			ko[node].push_back(pat[node][i]);
			par[pat[node][i]] = node;
			dfs(pat[node][i]);
		}
	}
}
void calc(int node)
{
	for (int i = 0; i < ko[node].size(); i++)calc(ko[node][i]);
	int c[3] = { 0,0,0 };
	for (int i = 0; i < ko[node].size(); i++)
	{
		c[dp1[ko[node][i]]]++;
	}
	if (c[0] <= 1 && c[1] == 0 && c[2] == 0)
	{
		dp1[node] = 0;
	}
	else if (c[0] == 2 && c[1] == 0 && c[2] == 0)
	{
		dp1[node] = 1;
	}
	else dp1[node] = 2;
}
void calc2(int node)
{
	int c[3] = { 0,0,0 };
	for (int i = 0; i < ko[node].size(); i++)
	{
		c[dp1[ko[node][i]]]++;
	}
	if (node != 0)c[dp2[node]]++;
	for (int i = 0; i < ko[node].size(); i++)
	{
		c[dp1[ko[node][i]]]--;
		if (c[0] <= 1 && c[1] == 0 && c[2] == 0)
		{
			dp2[ko[node][i]] = 0;
		}
		else if (c[0] == 2 && c[1] == 0 && c[2] == 0)
		{
			dp2[ko[node][i]] = 1;
		}
		else dp2[ko[node][i]] = 2;
		c[dp1[ko[node][i]]]++;
	}
	for (int i = 0; i < ko[node].size(); i++)calc2(ko[node][i]);
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num - 1; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	fill(flag, flag + num, false);
	dfs(0);
	calc(0);
	calc2(0);
	for (int i = 0; i < num; i++)
	{
		//printf("%d %d\n", dp1[i], dp2[i]);
		int c = 0;
		for (int j = 0; j < ko[i].size(); j++)
		{
			if (dp1[ko[i][j]] == 2)c++;
		}
		if (i != 0 && dp2[i] == 2)c++;
		if (c > 2)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
}