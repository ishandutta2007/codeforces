#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
int lst[300005], to[600005], pre[600005], w[600005], tot; 
int f[300005], g[300005], dfn[300005], low[300005], comp[300005], comp_cnt, t; 
int u[300005], v[300005], _w[300005], dis[300005], mx[300005], que[300005]; 
bool bridge[600005], vis[300005];
inline void add_edge(int u, int v, int _w)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	w[tot] = _w; 
	lst[u] = tot++; 
}
void trajan(int u, int fa = -1)
{
	dfn[u] = t++; 
	low[u] = dfn[u]; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (dfn[to[i]] == -1)
		{
			trajan(to[i], u); 
			if (dfn[u] < low[to[i]])
				bridge[i] = bridge[i ^ 1] = true; 
			low[u] = min(low[u], low[to[i]]); 
		}
		else if (to[i] != fa)
			low[u] = min(low[u], dfn[to[i]]); 
	}
}
void dfs(int u, int cur)
{
	if (vis[u])
		return; 
	vis[u] = true; 
	comp[u] = cur; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (bridge[i])
			continue; 
		dfs(to[i], cur); 
	}
}
int main()
{
	// freopen("652E.in", "r", stdin); 
	int n, m; 
	scanf("%d%d", &n, &m);
	memset(lst, -1, sizeof(lst)); 
	memset(dfn, -1, sizeof(dfn)); 
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", u + i, v + i, _w + i); 
		add_edge(--u[i], --v[i], _w[i]);
		add_edge(v[i], u[i], _w[i]); 
	}
	trajan(0); 
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
			dfs(i, comp_cnt++); 
	}
	memset(lst, -1, sizeof(lst)); 
	tot = 0; 
	// for (int i = 0; i < n; i++)
	// 	printf("%d%c", comp[i], " \n"[i + 1 == n]);
	for (int i = 0; i < m; i++)
	{
		if (comp[u[i]] != comp[v[i]])
		{
			add_edge(comp[u[i]], comp[v[i]], _w[i]); 
			add_edge(comp[v[i]], comp[u[i]], _w[i]); 
		}
		else if (_w[i])
			mx[comp[u[i]]] = 1; 
	}
	int s, t; 
	scanf("%d%d", &s, &t); 
	s--; 
	t--; 
	int he = 0, ta = 1; 
	memset(dis, -1, sizeof(dis)); 
	memset(vis, false, sizeof(vis)); 
	dis[comp[s]] = mx[comp[s]]; 
	vis[comp[s]] = true; 
	que[0] = comp[s]; 
	while (he < ta)
	{
		int u = que[he++]; 
		// cout << u << " " << dis[u] << endl; 
		if (u == comp[t])
		{
			printf("%s\n", dis[u] > 0 ? "YES" : "NO");
			return 0; 
		}
		for (int i = lst[u]; ~i; i = pre[i])
		{
			// cout << u << " " << to[i] << endl; 
			if (!vis[to[i]])
			{
				vis[to[i]] = true; 
				dis[to[i]] = dis[u] + w[i] + mx[to[i]]; 
				que[ta++] = to[i]; 
			}
		}
	}
	printf("NO\n");
	return 0; 
}