#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int dc[300000];
string dat;
vector<int>pat[300000];
vector<int>ko[300000];
bool flag[300000];
int trie[300000][26];
int ans[300000];
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
}
int merge(int na, int nb)
{
	int ret = 1;
	for (int i = 0; i < 26; i++)
	{
		if (trie[na][i] == -1)
		{
			trie[na][i] = trie[nb][i];
		}
		else if (trie[nb][i] != -1)
		{
			ret += merge(trie[na][i], trie[nb][i]);
		}
	}
	return ret;
}
void calc(int node)
{
	for (int i = 0; i < ko[node].size(); i++)calc(ko[node][i]);
	fill(trie[node], trie[node] + 26, -1);
	int sum = 1;
	int dec = 0;
	for (int i = 0; i < ko[node].size(); i++)
	{
		sum += ans[ko[node][i]];
		if (trie[node][dat[ko[node][i]] - 'a'] != -1)
		{
			dec += merge(trie[node][dat[ko[node][i]] - 'a'], ko[node][i]);
		}
		else trie[node][dat[ko[node][i]] - 'a'] = ko[node][i];
	}
	ans[node] = sum - dec;
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &dc[i]);
	}
	cin >> dat;
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
	int maxi = -1, k = 0;
	for (int i = 0; i < num; i++)
	{
		if (maxi < ans[i] + dc[i])
		{
			maxi = ans[i] + dc[i];
			k = 1;
		}
		else if (maxi == ans[i] + dc[i])k++;
	}
	printf("%d\n%d\n", maxi, k);
}