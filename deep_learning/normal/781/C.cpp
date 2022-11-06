#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
bool vis[200005]; 
int arr[400005], len; 
int lst[200005], to[400005], pre[400005], tot; 
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
void dfs(int u)
{
	vis[u] = true; 
	arr[len++] = u; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (!vis[to[i]])
		{
			dfs(to[i]); 
			arr[len++] = u; 
		}
	}
}
int main()
{
	// freopen("C.in", "r", stdin);
	memset(lst, -1, sizeof(lst)); 
	int n, m, k; 
	scanf("%d%d%d", &n, &m, &k); 
	for (int i = 0; i < m; i++)
	{
		int u, v; 
		scanf("%d%d", &u, &v); 
		add_edge(--u, --v); 
		add_edge(v, u); 
	}
	dfs(0); 
	for (int i = 0; i < k; i++)
	{
		int l = min(len - 1, (2 * n + k - 1) / k * i), r = min(len, (2 * n + k - 1) / k * (i + 1)); 
		printf("%d ", r - l);
		for (int j = l; j < r; j++)
			printf("%d%c", arr[j] + 1, " \n"[j + 1 == r]);
	}
	return 0; 
}