#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std; 
int lst[100005], to[200005], pre[200005], tot; 
int vis[100005]; 
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
void dfs(int u, int col = 1)
{
	if (vis[u] && col != vis[u])
	{
		printf("-1\n");
		exit(0); 
	}
	if (vis[u])
		return;
	vis[u] = col;  
	for (int i = lst[u]; ~i; i = pre[i])
		dfs(to[i], col ^ 3); 
}
int main()
{
	// freopen("A.in", "r", stdin); 
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
	int x = 0, y = 0; 
	for (int i = 0; i < n; i++)
	{
		x += vis[i] == 1; 
		y += vis[i] == 2; 
	}
	printf("%d\n", x);
	for (int i = 0; i < n; i++)
	{
		if (vis[i] == 1)
			printf("%d%c", i + 1, " \n"[!--x]);
	}
	printf("%d\n", y);
	for (int i = 0; i < n; i++)
	{
		if (vis[i] == 2)
			printf("%d%c", i + 1, " \n"[!--y]);
	}
	return 0; 
}