#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define MOD 1000000007
#define pb push_back
#define mp make_pair
using namespace std; 
typedef long long ll; 
int x[100005], y[100005], x_app[100005], y_app[100005]; 
int fa[200005], sz[200005]; 
bool mark[200005]; 
int getfa(int u)
{
	if (u == fa[u])
		return u; 
	return fa[u] = getfa(fa[u]); 
}
inline void unite(int u, int v)
{
	u = getfa(u); 
	v = getfa(v); 
	if (u == v)
		mark[u] = true; 
	else
	{
		fa[u] = v; 
		sz[v] += sz[u]; 
		mark[v] |= mark[u]; 
	}
}
inline ll quick_pow(ll a, int n)
{
	ll res = 1; 
	while (n)
	{
		if (n & 1)
			res = res * a % MOD; 
		a = a * a % MOD; 
		n >>= 1; 
	}
	return res; 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("871C.in", "r", stdin); 
#endif
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", x + i, y + i); 
		x_app[i] = x[i]; 
		y_app[i] = y[i]; 
	}
	sort(x_app, x_app + n); 
	sort(y_app, y_app + n); 
	int cnt1 = unique(x_app, x_app + n) - x_app, cnt2 = unique(y_app, y_app + n) - y_app; 
	for (int i = 0; i < cnt1 + cnt2; i++)
	{
		fa[i] = i; 
		sz[i] = 1; 
	}
	for (int i = 0; i < n; i++)
	{
		x[i] = lower_bound(x_app, x_app + cnt1, x[i]) - x_app; 
		y[i] = lower_bound(y_app, y_app + cnt2, y[i]) - y_app; 
		unite(x[i], y[i] + cnt1); 
	}
	ll ans = 1; 
	for (int i = 0; i < cnt1 + cnt2; i++)
	{
		if (getfa(i) == i && mark[i])
			ans = ans * quick_pow(2, sz[i]) % MOD;
		else if (getfa(i) == i)
			ans = ans * (quick_pow(2, sz[i]) + MOD - 1) % MOD; 
	}
	printf("%lld\n", ans);
	return 0; 
}