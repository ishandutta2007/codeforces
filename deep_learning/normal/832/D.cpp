#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
int lst[100005], to[200005], pre[200005], tot; 
int fa[100005][25], dep[100005]; 
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++;
}
void dfs(int u)
{
	for (int i = 1; i < 20; i++)
		fa[u][i] = fa[u][i - 1] == -1 ? -1 : fa[fa[u][i - 1]][i - 1]; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		dep[to[i]] = dep[u] + 1; 
		fa[to[i]][0] = u; 
		dfs(to[i]); 
	}
}
inline int calc(int u, int v)
{
	int res = dep[u] + dep[v]; 
	if (dep[u] > dep[v])
		swap(u, v); 
	for (int i = 0; i < 20; i++)
	{
		if (dep[v] - dep[u] & (1 << i))
			v = fa[v][i]; 
	}
	if (u == v)
		return res - (dep[u] << 1); 
	for (int i = 19; i >= 0; i--)
	{
		if (fa[u][i] != fa[v][i])
		{
			u = fa[u][i]; 
			v = fa[v][i]; 
		}
	}
	return res - (dep[fa[u][0]] << 1); 
}
int main()
{
	// freopen("832D.in", "r", stdin); 
	memset(lst, -1, sizeof(lst));
	int n, q; 
	scanf("%d%d", &n, &q); 
	for (int i = 1; i < n; i++)
	{
		int x; 
		scanf("%d", &x); 
		add_edge(--x, i); 
	}
	fa[0][0] = -1; 
	dfs(0); 
	while (q--)
	{
		int x, y, z; 
		scanf("%d%d%d", &x, &y, &z); 
		x--; 
		y--; 
		z--; 
		int a = calc(x, y), b = calc(x, z), c = calc(y, z); 
		printf("%d\n", max((a + b - c) / 2, max((a + c - b) / 2, (b + c - a) / 2)) + 1);
	}
	return 0; 
}