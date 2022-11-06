#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
int lst[30005], to[100005], pre[100005], tot; 
bool vis[30005]; 
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
void dfs(int u)
{
	if (vis[u])
		return; 
	vis[u] = true; 
	for (int i = lst[u]; ~i; i = pre[i])
		dfs(to[i]); 
	printf("%d ", u + 1);
}
int main()
{
	// freopen("412D.in", "r", stdin); 
	memset(lst, -1, sizeof(lst)); 
	int n, m; 
	scanf("%d%d", &n, &m); 
	for (int i = 0; i < m; i++)
	{
		int u, v; 
		scanf("%d%d", &u, &v); 
		add_edge(--u, --v); 
	}
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
			dfs(i); 
	}
	printf("\n");
	return 0; 
}