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
ll dp[1005][1005]; 
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
inline void upd(ll &a, ll b)
{
	a += b; 
	if (a >= MOD)
		a -= MOD; 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("908D.in", "r", stdin); 
#endif
	int k, pa, pb; 
	scanf("%d%d%d", &k, &pa, &pb); 
	ll x = pa * quick_pow(pa + pb, MOD - 2) % MOD;
	ll y = pb * quick_pow(pa + pb, MOD - 2) % MOD; 
	dp[0][1] = 1; 
	ll ans = 0; 
	for (int i = 0; i <= k; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (i + j >= k)
			{
				upd(ans, dp[i][j] * ((i + j) + x * quick_pow(y, MOD - 2) % MOD) % MOD); 
				continue; 
			}
			upd(dp[i + j][j], dp[i][j] * y % MOD); 
			upd(dp[i][j + 1], dp[i][j] * x % MOD); 
		}
	}
	printf("%lld\n", ans);
	return 0; 
}