#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std; 
int b[102400], g[102400], col[204800]; 
vector<int> adj[204800]; 
void dfs(int u, int c)
{
	if (col[u])
		return; 
	col[u] = c; 
	for (int i = 0; i < adj[u].size(); i++)
		dfs(adj[u][i], 3 - c); 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("741C.in", "r", stdin); 
#endif
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", b + i, g + i); 
		int &u = b[i], &v = g[i]; 
		u--; 
		v--; 
		adj[u].pb(v); 
		adj[v].pb(u);
	}
	for (int i = 0; i < n << 1; i++)
		adj[i].pb(i ^ 1); 
	for (int i = 0; i < n << 1; i++)
	{
		if (!col[i])
			dfs(i, 1); 
	}
	for (int i = 0; i < n; i++)
		printf("%d %d\n", col[b[i]], col[g[i]]);
	return 0; 
}