#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int lst[300005], to[600005], pre[600006], idx[600005], tot; 
int fa[300005], pree[300005], d[300005], pos = -1; 
bool vis[300005], choose[300005];  
inline void add_edge(int u, int v, int _idx)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	idx[tot] = _idx; 
	lst[u] = tot++; 
}
void dfs(int u, int f = -1)
{
	vis[u] = true; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (vis[to[i]])
			continue; 
		fa[to[i]] = u; 
		pree[to[i]] = idx[i]; 
		dfs(to[i], u); 
		if (d[to[i]] == 1)
		{
			choose[idx[i]] ^= 1; 
			d[to[i]] = 0; 
			if (~d[u])
				d[u] ^= 1; 
		}
	}
	if (d[u] == -1)
		pos = u; 
}
int main()
{
	// freopen("840B.in", "r", stdin); 
	memset(lst, -1, sizeof(lst)); 
	int n, m; 
	scanf("%d%d", &n, &m); 
	for (int i = 0; i < n; i++)
		scanf("%d", d + i);
	for (int i = 0; i < m; i++)
	{
		int u, v; 
		scanf("%d%d", &u, &v);
		add_edge(--u, --v, i); 
		add_edge(v, u, i); 
	}
	fa[0] = -1; 
	dfs(0); 
	if (d[0] == 1)
	{
		if (pos == -1)
		{
			printf("-1\n");
			return 0; 
		}
		while (pos)
		{
			choose[pree[pos]] ^= 1; 
			pos = fa[pos]; 
		}
	}
	int ans = 0; 
	for (int i = 0; i < m; i++)
		ans += choose[i]; 
	printf("%d\n", ans);
	for (int i = 0; i < m; i++)
	{
		if (choose[i])
			printf("%d%c", i + 1, " \n"[!--ans]);
	}
	return 0; 
}