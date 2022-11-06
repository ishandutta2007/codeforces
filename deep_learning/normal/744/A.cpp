#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std; 
typedef long long ll; 
int fa[1005], sz[1005], c[1005], u[100005], v[100005]; 
bool vis[1005]; 
int getfa(int u)
{
	if (u == fa[u])
		return u; 
	return fa[u] = getfa(fa[u]); 
}
inline void unite(int u, int v)
{
	fa[getfa(u)] = getfa(v); 
}
inline bool same(int u, int v)
{
	return getfa(u) == getfa(v); 
}
int main()
{
	// freopen("A.in", "r", stdin); 
	int n, m, k; 
	scanf("%d%d%d", &n, &m, &k); 
	int cnt = n; 
	for (int i = 0; i < n; i++)
		fa[i] = i; 
	for (int i = 0; i < k; i++)
	{
		scanf("%d", c + i); 
		c[i]--; 
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", u + i, v + i); 
		unite(--u[i], --v[i]); 
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (same(c[i], j))
			{
				sz[i]++; 
				cnt -= !vis[j]; 
				vis[j] = true; 
			}
		}
	}
	sort(sz, sz + k); 
	ll ans = 0; 
	sz[k - 1] += cnt; 
	for (int i = 0; i < k; i++)
		ans += (ll)sz[i] * (sz[i] - 1) / 2; 
	printf("%lld\n", ans - m);
	return 0; 
}