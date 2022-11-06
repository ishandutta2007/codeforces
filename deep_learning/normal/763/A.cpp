#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll; 
int c[102400], orig[102400], ans = -1; 
bool flg[102400]; 
vector<int> adj[102400]; 
int dfs(int u, int fa = -1)
{
	for (int i = 0; i < adj[u].size(); i++)
	{
		if (adj[u][i] == fa)
			continue; 
		int res = dfs(adj[u][i], u); 
		if (res != c[u])
			c[u] = -1; 
	}
	return c[u]; 
}
bool check(int u, int fa)
{
	for (int i = 0; i < adj[u].size(); i++)
	{
		if (adj[u][i] != fa && c[adj[u][i]] == -1)
			return false; 
	}
	return true; 
}
void work(int u, int req, int fa = 0)
{
	// if (req != orig[u])
	// {
	// 	if (check(u, 0))
	// 	{
	// 		printf("YES\n%d\n", u + 1);
	// 		exit(0); 
	// 	}
	// 	return; 
	// }
	int cnt = 0, pos; 
	for (int i = 0; i < adj[u].size(); i++)
	{
		if (adj[u][i] == fa)
			continue; 
		if (c[adj[u][i]] == -1)
		{
			cnt++; 
			pos = i; 
		}
	}
	// cout << u << " " << cnt << endl; 
	if (!cnt)
	{
		printf("YES\n%d\n", u + 1);
		exit(0); 
	}
	if (cnt == 1 && orig[u] == req && check(adj[u][pos], u))
	{
		printf("YES\n%d\n", adj[u][pos] + 1);
		exit(0); 
	}
	if (cnt == 1 && req == orig[u] && req == orig[adj[u][pos]])
		work(adj[u][pos], orig[adj[u][pos]], u); 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("763A.in", "r", stdin); 
#endif
	int n; 
	scanf("%d", &n); 
	for (int i = 1; i < n; i++)
	{
		int u, v; 
		scanf("%d%d", &u, &v); 
		adj[--u].pb(--v); 
		adj[v].pb(u); 
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", c + i); 
		orig[i] = c[i]; 
	}
	dfs(0); 
	// for (int i = 0; i < n; i++)
	// 	printf("%d\n", c[i]);
	if (check(0, -1))
	{
		printf("YES\n1\n");
		return 0; 
	}
	int res = orig[0], cnt = 0, pos; 
	for (int i = 0; i < adj[0].size(); i++)
	{
		if (c[adj[0][i]] == -1 || c[adj[0][i]] != res)
		{
			cnt++;
			pos = i; 
		}
	}
	if (cnt == 1)
		work(adj[0][pos], res); 
	printf("NO\n");
	return 0; 
}