#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#define pb push_back
using namespace std; 
int col[200005]; 
vector<int> adj[200005]; 
inline bool comp(int x, int y)
{
	return col[x] < col[y]; 
}
void dfs(int u, int fa = -1)
{
	sort(adj[u].begin(), adj[u].end(), comp);
	int cur = 1;
	int l = 0, r = (int)adj[u].size() - 1, pos = adj[u].size(); 
	while (l <= r)
	{
		int m = l + r >> 1; 
		if (col[adj[u][m]])
		{
			pos = m; 
			r = m - 1; 
		}
		else
			l = m + 1; 
	}
	for (int i = 0; i < adj[u].size() && !col[adj[u][i]]; i++)
	{
		while ((pos < adj[u].size() && cur == col[adj[u][pos]]) || cur == col[u])
		{
			if (cur != col[u])
				pos++; 
			cur++; 
		}
		col[adj[u][i]] = cur++; 
	}
	for (int i = 0; i < adj[u].size(); i++)
	{
		if (adj[u][i] != fa)
			dfs(adj[u][i], u); 
	}
}
int main()
{
	// freopen("A.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 1; i < n; i++)
	{
		int u, v; 
		scanf("%d%d", &u, &v); 
		adj[--u].pb(--v); 
		adj[v].pb(u); 
	}
	col[0] = 1; 
	dfs(0); 
	int ans = 0; 
	for (int i = 0; i < n; i++)
		ans = max(ans, col[i]); 
	printf("%d\n", ans);
	for (int i = 0; i < n; i++)
		printf("%d%c", col[i], " \n"[i + 1 == n]);
	return 0; 
}