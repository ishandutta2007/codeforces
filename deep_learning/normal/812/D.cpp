#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
int lst[100005], to[200005], pre[200005], tot; 
int st[100005], en[100005], t; 
int app[100005], fa[100005]; 
inline void add_edge(int u, int v)
{
	// cout << u << " " << v << endl; 
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
void dfs(int u)
{
	st[u] = ++t; 
	for (int i = lst[u]; ~i; i = pre[i])
		dfs(to[i]); 
	en[u] = t; 
}
int main()
{
	// freopen("812D.in", "r", stdin); 
	memset(lst, -1, sizeof(lst)); 
	memset(app, -1, sizeof(app)); 
	memset(fa, -1, sizeof(fa)); 
	int n, m, k, q; 
	scanf("%d%d%d%d", &n, &m, &k, &q); 
	while (k--)
	{
		int x, y; 
		scanf("%d%d", &x, &y); 
		x--; 
		y--; 
		if (app[y] != -1)
			fa[x] = app[y]; 
		app[y] = x; 
	}
	for (int i = 0; i < n; i++)
	{
		if (fa[i] != -1)
			add_edge(fa[i], i); 
	}
	for (int i = 0; i < n; i++)
	{
		if (fa[i] == -1)
			dfs(i); 
	}
	while (q--)
	{
		int x, y; 
		scanf("%d%d", &x, &y); 
		x--; 
		y--; 
		y = app[y]; 
		if (y != -1 && st[x] <= st[y] && en[y] <= en[x])
			printf("%d\n", en[x] - st[x] + 1);
		else
			printf("0\n");
	}
	return 0; 
}