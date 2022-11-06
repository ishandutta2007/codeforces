#include <iostream>
#include <cstring>
#include <utility>
#include <cstdio>
#include <set>
#define mp make_pair
using namespace std; 
typedef set<pair<int, int> > tp; 
int ans[300005], sz[300005]; 
int lst[300005], to[300005], pre[300005], tot; 
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
tp dfs(int u)
{
	tp se; 
	sz[u] = 1; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		tp res = dfs(to[i]); 
		sz[u] += sz[to[i]]; 
		if (res.size() > se.size())
			swap(res, se); 
		for (tp::iterator it = res.begin(); it != res.end(); it++)
			se.insert(*it); 
	}
	se.insert(mp(sz[u], u)); 
	ans[u] = se.lower_bound(mp(sz[u] / 2 + 1, -1))->second; 
	return se; 
}
int main()
{
	// freopen("B.in", "r", stdin); 
	memset(lst, -1, sizeof(lst)); 
	int n, q; 
	scanf("%d%d", &n, &q); 
	for (int i = 1; i < n; i++)
	{
		int x; 
		scanf("%d", &x); 
		add_edge(--x, i); 
	}
	dfs(0); 
	while (q--)
	{
		int u; 
		scanf("%d", &u); 
		printf("%d\n", ans[--u] + 1);
	}
	return 0; 
}