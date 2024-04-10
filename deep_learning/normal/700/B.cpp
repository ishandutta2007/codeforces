#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
typedef long long ll; 
int dep[200005], fa[200005][25], pos[200005], flg[200005], t; 
int lst[200005], to[400005], pre[400005], tot; 
inline bool comp(int u, int v)
{
	return flg[u] < flg[v]; 
}
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
inline int lca(int u, int v)
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
void dfs(int u, int f = -1)
{
	flg[u] = t++; 
	fa[u][0] = f; 
	for (int i = 1; i < 20; i++)
		fa[u][i] = fa[u][i - 1] == -1 ? -1 : fa[fa[u][i - 1]][i - 1]; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (to[i] == f)
			continue; 
		dep[to[i]] = dep[u] + 1; 
		dfs(to[i], u); 
	}
}
int main()
{
	// freopen("B.in", "r", stdin); 
	memset(lst, -1, sizeof(lst)); 
	int n, k; 
	scanf("%d%d", &n, &k); 
	for (int i = 0; i < k << 1; i++)
	{
		scanf("%d", pos + i); 
		pos[i]--; 
	}
	for (int i = 1; i < n; i++)
	{
		int u, v; 
		scanf("%d%d", &u, &v); 
		add_edge(--u, --v);
		add_edge(v, u); 
	}
	dfs(0); 
	sort(pos, pos + (k << 1), comp); 
	ll ans = 0; 
	for (int i = 0; i < k; i++)
	{
		int u = pos[i], v = pos[i + k]; 
		ans += dep[u] + dep[v] - (dep[lca(u, v)] << 1); 
	}
	printf("%lld\n", ans);
	return 0;
}