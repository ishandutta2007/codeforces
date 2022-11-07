#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
struct Edge
{
	int u, v, w, idx; 
	bool in; 
	Edge()
	{
		in = false; 
	}
	inline bool operator <(const Edge &a) const
	{
		return w < a.w; 
	}
} edge[200005]; 
struct DSU
{
	int fa[200005]; 
	DSU()
	{
		for (int i = 0; i < 200005; i++)
			fa[i] = i; 
	}
	int getfa(int u)
	{
		if (u == fa[u])
			return u; 
		return fa[u] = getfa(fa[u]); 
	}
	inline void unite(int u, int v)
	{
		u = getfa(u); 
		v = getfa(v); 
		if (u != v)
			fa[u] = v; 
	}
	inline bool same(int u, int v)
	{
		return getfa(u) == getfa(v); 
	}
} dsu; 
int lst[200005], to[400005], pre[400005], w[400005], idx[400005], tot; 
int fa[25][200005], mn[25][200005], mx[25][200005], dep[200005], ans[200005]; 
inline void upd(int &x, int y)
{
	if (x > y)
		x = y; 
}
inline void add_edge(int u, int v, int _w, int _idx)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	w[tot] = _w; 
	idx[tot] = _idx; 
	lst[u] = tot++; 
}
void dfs(int u, int f = -1)
{
	fa[0][u] = f; 
	for (int i = 1; i < 20; i++)
	{
		fa[i][u] = fa[i - 1][u] == -1 ? -1 : fa[i - 1][fa[i - 1][u]]; 
		mx[i][u] = fa[i - 1][u] == -1 ? mx[i - 1][u] : max(mx[i - 1][u], mx[i - 1][fa[i - 1][u]]); 
	}
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (to[i] == f)
			continue; 
		mx[0][to[i]] = w[i]; 
		dep[to[i]] = dep[u] + 1; 
		dfs(to[i], u); 
	}
}
inline int calc(int u, int v, int w)
{
	if (dep[u] > dep[v])
		swap(u, v); 
	int res = 0; 
	for (int i = 19; i >= 0; i--)
	{
		if (dep[v] - dep[u] & (1 << i))
		{
			res = max(res, mx[i][v]); 
			upd(mn[i][v], w); 
			v = fa[i][v]; 
		}
	}
	if (u == v)
		return res; 
	for (int i = 19; i >= 0; i--)
	{
		if (fa[i][u] != fa[i][v])
		{
			res = max(res, max(mx[i][u], mx[i][v])); 
			upd(mn[i][u], w); 
			upd(mn[i][v], w); 
			u = fa[i][u]; 
			v = fa[i][v]; 
		}
	}
	upd(mn[0][u], w); 
	upd(mn[0][v], w); 
	return max(res, max(mx[0][u], mx[0][v])); 
}
void work(int u, int f = -1)
{
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (to[i] == f)
			continue; 
		ans[idx[i]] = mn[0][to[i]]; 
		work(to[i], u); 
	}
}
int main()
{
	// freopen("827D.in", "r", stdin); 
	memset(lst, -1, sizeof(lst)); 
	int n, m; 
	scanf("%d%d", &n, &m); 
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w); 
		edge[i].idx = i; 
	}
	sort(edge, edge + m); 
	for (int i = 0; i < m; i++)
	{
		if (dsu.same(--edge[i].u, --edge[i].v))
			continue; 
		add_edge(edge[i].u, edge[i].v, edge[i].w, edge[i].idx); 
		add_edge(edge[i].v, edge[i].u, edge[i].w, edge[i].idx); 
		dsu.unite(edge[i].u, edge[i].v); 
		edge[i].in = true; 
	}
	memset(mn, 0x3f, sizeof(mn)); 
	dfs(0); 
	for (int i = 0; i < m; i++)
	{
		if (edge[i].in)
			continue; 
		ans[edge[i].idx] = calc(edge[i].u, edge[i].v, edge[i].w - 1) - 1; 
	}
	for (int i = 19; i > 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (mn[i][j] != 0x3f3f3f3f)
			{
				upd(mn[i - 1][j], mn[i][j]); 
				upd(mn[i - 1][fa[i - 1][j]], mn[i][j]); 
			}
		}
	}
	work(0); 
	for (int i = 0; i < m; i++)
		printf("%d%c", ans[i] == 0x3f3f3f3f ? -1 : ans[i], " \n"[i + 1 == m]);
	return 0; 
}