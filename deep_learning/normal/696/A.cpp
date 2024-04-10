#include <iostream>
#include <cstdio>
#include <map>
using namespace std; 
typedef long long ll; 
map<ll, ll> cost; 
inline int cnt(ll x)
{
	int res = 0; 
	while (x)
	{
		res++; 
		x >>= 1; 
	}
	return res;
}
inline ll work(ll u, ll v)
{
	int x = cnt(u), y = cnt(v); 
	if (x > y)
	{
		swap(x, y); 
		swap(u, v); 
	}
	for (int i = x; i < y; i++)
		v >>= 1; 
	while (u != v)
	{
		u >>= 1; 
		v >>= 1; 
	}
	return u; 
}
inline ll query(ll u, ll v)
{
	ll lca = work(u, v), res = 0; 
	while (u != lca)
	{
		res += cost[u]; 
		u >>= 1; 
	}
	while (v != lca)
	{
		res += cost[v]; 
		v >>= 1; 
	}
	return res; 
}
inline void modify(ll u, ll v, ll w)
{
	ll lca = work(u, v); 
	while (u != lca)
	{
		cost[u] += w; 
		u >>= 1; 
	}
	while (v != lca)
	{
		cost[v] += w; 
		v >>= 1; 
	}
}
int main()
{
	// freopen("A.in", "r", stdin); 
	int q; 
	scanf("%d", &q); 
	while (q--)
	{
		int tp; 
		scanf("%d", &tp); 
		if (tp - 1)
		{
			ll u, v; 
			scanf("%lld%lld", &u, &v); 
			printf("%lld\n", query(u, v));
		}
		else
		{
			ll u, v, w;
			scanf("%lld%lld%lld", &u, &v, &w); 
			modify(u, v, w); 
		}
	}
	return 0; 
}