#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#define pb push_back
using namespace std; 
typedef long long ll; 
vector<int> adj[32]; 
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}; 
ll ansx[32], ansy[32]; 
void dfs(int u, ll x = 0, ll y = 0, int len = 1 << 30, int dir = 0, int fa = -1)
{
	ansx[u] = x; 
	ansy[u] = y; 
	if (adj[u].size() >= 5)
	{
		printf("NO\n");
		exit(0); 
	}
	for (int i = 0; i < adj[u].size(); i++)
	{
		if (adj[u][i] == fa)
			continue; 
		int cur = 0; 
		for (; cur < 4; cur++)
		{
			if (!(dir & (1 << cur)))
				break; 
		}
		dir |= 1 << cur; 
		dfs(adj[u][i], x + len * dx[cur], y + len * dy[cur], len >> 1, 1 << (cur + 2 & 3), u); 
	}
}
int main()
{
	// freopen("761E.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 1; i < n; i++)
	{
		int u, v; 
		scanf("%d%d", &u, &v); 
		adj[--u].pb(--v); 
		adj[v].pb(u); 
	}
	dfs(0); 
	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%lld %lld\n", ansx[i], ansy[i]);
	return 0; 
}