#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define MOD 1000000007
using namespace std; 
typedef long long ll; 
int sz[1005], fa[1005]; 
char str[55][1005]; 
ll sum[1005], dp[1005][1005]; 
inline void upd(ll &a, ll b)
{
	a += b; 
	if (a >= MOD)
		a -= MOD; 
}
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
	if (u != v)
	{
		fa[u] = v; 
		sz[v] += sz[u]; 
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("908E.in", "r", stdin); 
#endif
	int n, m; 
	scanf("%d%d", &n, &m); 
	for (int i = 0; i < n; i++)
	{
		fa[i] = i; 
		sz[i] = 1; 
	}
	for (int i = 0; i < m; i++)
		scanf("%s", str[i]); 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			bool f = true; 
			for (int k = 0; k < m && f; k++)
			{
				if (str[k][i] != str[k][j])
					f = false; 
			}
			if (f)
				unite(i, j); 
		}
	}
	dp[1][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			upd(sum[i], dp[i][j]); 
			upd(dp[i + 1][j], dp[i][j] * (j + 1) % MOD); 
			upd(dp[i + 1][j + 1], dp[i][j]); 
		}
	}
	ll ans = 1;
	for (int i = 0; i < n; i++)
	{
		if (fa[i] == i)
			ans = (ans * sum[sz[i]]) % MOD; 
	}
	printf("%lld\n", ans);
	return 0; 
}