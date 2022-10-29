#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[200000];
vector<int>ko[200000];
bool flag[200000];
int cnt = 0;
void dfs(int node)
{
	if (flag[node])return;
	flag[node] = true;
	for (int i = 0; i < pat[node].size(); i++)
	{
		if (!flag[pat[node][i]])
		{
			ko[node].push_back(pat[node][i]);
			dfs(pat[node][i]);
		}
	}
	if (ko[node].size() == 0)cnt++;
}
int calc(int node, int d)
{
	if (ko[node].size() == 0)return 1;
	if (d % 2 == 0)
	{
		int mini = 1000000000;
		for (int i = 0; i < ko[node].size(); i++)
		{
			mini = min(mini, calc(ko[node][i], d + 1));
		}
		return mini;
	}
	else
	{
		int s = 0;
		for (int i = 0; i < ko[node].size(); i++)
		{
			s += calc(ko[node][i], d + 1);
		}
		return s;
	}
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
	printf("%d %d\n", cnt - calc(0, 0) + 1, calc(0, 1));
}