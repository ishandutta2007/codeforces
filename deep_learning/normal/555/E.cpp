#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
int lst[200005], to[400005], pre[400005], tot; 
int f[200005], g[200005], dfn[200005], low[200005], comp[200005], comp_cnt, t; 
int fa[200005][25], dep[200005], u[200005], v[200005]; 
bool bridge[400005], vis[200005];
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
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
void init(int u, int f = -1)
{
	fa[u][0] = f; 
	for (int i = 1; i < 20; i++)
		fa[u][i] = fa[u][i - 1] == -1 ? -1 : fa[fa[u][i - 1]][i - 1]; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (to[i] == f)
			continue; 
		dep[to[i]] = dep[u] + 1; 
		init(to[i], u); 
	}
}
void upd(int u, int fa = -1)
{
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (to[i] == fa)
			continue; 
		upd(to[i], u); 
		f[u] += f[to[i]]; 
		g[u] += g[to[i]]; 
	}
}
inline int work(int u, int v)
{
	if (dep[u] > dep[v])
		swap(u, v); 
	for (int i = 0; i < 20; i++)
	{
		if (dep[v] - dep[u] & (1 << i))
			v = fa[v][i];
	}
	if (u == v)
		return u; 
	for (int i = 19; i >= 0; i--)
	{
		if (fa[u][i] != fa[v][i])
		{
			u = fa[u][i]; 
			v = fa[v][i]; 
		}
	}
	return fa[u][0]; 
}
int main()
{
	// freopen("555E.in", "r", stdin); 
	int n, m, q; 
	scanf("%d%d%d", &n, &m, &q);
	memset(lst, -1, sizeof(lst)); 
	memset(dfn, -1, sizeof(dfn)); 
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", u + i, v + i); 
		add_edge(--u[i], --v[i]);
		add_edge(v[i], u[i]); 
	}
	trajan(0); 
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
			dfs(i, comp_cnt++); 
	}
	// for (int i = 0; i < n; i++)
	// 	printf("%d%c", comp[i], " \n"[i + 1 == n]);
	memset(lst, -1, sizeof(lst)); 
	tot = 0; 
	for (int i = 0; i < m; i++)
	{
		if (comp[u[i]] != comp[v[i]])
		{
			add_edge(comp[u[i]], comp[v[i]]); 
			add_edge(comp[v[i]], comp[u[i]]); 
		}
	}
	init(0); 
	while (q--)
	{
		int u, v; 
		scanf("%d%d", &u, &v); 
		u = comp[--u]; 
		v = comp[--v]; 
		if (u == v)
			continue; 
		int x = work(u, v); 
		if (x == -1)
		{
			printf("No\n");
			return 0; 
		}
		// cout << u << " " << v << " " << x << endl; 
		f[u]++; 
		g[v]++; 
		f[x]--; 
		g[x]--; 
	}
	// for (int i = 0; i < comp_cnt; i++)
	// 	cout << f[i] << " " << g[i] << endl; 
	upd(0); 
	for (int i = 1; i < comp_cnt; i++)
	{
		// cout << f[i] << " " << g[i] << endl; 
		if (f[i] && g[i])
		{
			printf("No\n");
			return 0; 
		}
	}
	printf("Yes\n");
	return 0; 
}