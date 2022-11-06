#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
int lst[200005], to[400005], pre[400005], tot; 
int x[200005], y[200005], z[200005], ans_cnt; 
bool vis[200005], del[400005]; 
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
bool dfs(int u, int fa = -1, int pe = -1)
{
	int e = -1; 
	vis[u] = true; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (to[i] == fa)
			continue; 
		if (!vis[to[i]])
			dfs(to[i], u, i); 
		if (del[i])
			continue; 
		if (~e)
		{
			x[ans_cnt] = to[e]; 
			y[ans_cnt] = u; 
			z[ans_cnt++] = to[i]; 
			del[e] = del[e ^ 1] = true; 
			del[i] = del[i ^ 1] = true; 
			e = -1; 
		}
		else
			e = i; 
	}
	if (~e && ~fa)
	{
		x[ans_cnt] = to[e]; 
		y[ans_cnt] = u; 
		z[ans_cnt++] = fa; 
		del[e] = del[e ^ 1] = true; 
		del[pe] = del[pe ^ 1] = true; 
		return true; 
	}
	return false; 
}
int main()
{
	// freopen("860D.in", "r", stdin); 
	memset(lst, -1, sizeof(lst)); 
	int n, m; 
	scanf("%d%d", &n, &m); 
	for (int i = 0; i < m; i++)
	{
		int u, v; 
		scanf("%d%d", &u, &v); 
		add_edge(--u, --v); 
		add_edge(v, u); 
	}
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
			dfs(i); 
	}
	printf("%d\n", ans_cnt);
	for (int i = 0; i < ans_cnt; i++)
		printf("%d %d %d\n", x[i] + 1, y[i] + 1, z[i] + 1);
	return 0; 
}