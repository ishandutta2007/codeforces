#include <iostream>
#include <cstdio>
using namespace std; 
typedef long long ll; 
int deg[1000005], fa[1000005]; 
bool vis[1000005]; 
int getfa(int x)
{
	if (x == fa[x])
		return x; 
	return fa[x] = getfa(fa[x]); 
}
int main()
{
	// freopen("B.in", "r", stdin); 
	int n, m, cnt = 0; 
	scanf("%d%d", &n, &m); 
	for (int i = 0; i < n; i++)
		fa[i] = i; 
	for (int i = 0; i < m; i++)
	{
		int u, v; 
		scanf("%d%d", &u, &v); 
		vis[--u] = vis[--v] = true; 
		if (u == v)
		{
			cnt++; 
			continue; 
		}
		deg[u]++; 
		deg[v]++; 
		fa[getfa(u)] = getfa(v); 
	}
	int x; 
	for (int i = 0; i < n; i++)
	{
		if (vis[i])
		{
			x = getfa(i); 
			break; 
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (vis[i] && getfa(i) != x)
		{
			printf("0\n");
			return 0;
		}
	}
	ll ans = 0; 
	for (int i = 0; i < n; i++)
		ans += (ll)deg[i] * (deg[i] - 1) >> 1; 
	printf("%lld\n", ans + (ll)cnt * (m - cnt) + (ll)cnt * (cnt - 1) / 2);
	return 0; 
}