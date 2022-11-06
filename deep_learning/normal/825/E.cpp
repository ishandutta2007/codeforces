#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std; 
priority_queue<int> que; 
int to[100005], pre[100005], lst[100005], deg[100005], tot, ans[100005]; 
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	deg[v]++; 
	lst[u] = tot++; 
}
int main()
{
	memset(lst, -1, sizeof(lst)); 
	int n, m; 
	scanf("%d%d", &n, &m); 
	for (int i = 0; i < m; i++)
	{
		int u, v; 
		scanf("%d%d", &u, &v); 
		add_edge(--v, --u); 
	}
	for (int i = 0; i < n; i++)
	{
		if (!deg[i])
			que.push(i); 
	}
	int cur = n; 
	while (!que.empty())
	{
		int u = que.top(); 
		que.pop(); 
		ans[u] = cur--; 
		for (int i = lst[u]; ~i; i = pre[i])
		{
			if (!--deg[to[i]])
				que.push(to[i]); 
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d%c", ans[i], " \n"[i + 1 == n]);
	return 0; 
}