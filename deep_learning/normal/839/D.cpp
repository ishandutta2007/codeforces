#include <iostream>
#include <cstdio>
#define MOD 1000000007
using namespace std; 
typedef long long ll; 
int app[1000005]; 
ll p[1000005], dp[1000005]; 
int main()
{
	// freopen("839D.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		int x; 
		scanf("%d", &x); 
		app[x]++; 
	}
	p[0] = 1; 
	for (int i = 1; i <= n; i++)
		p[i] = p[i - 1] * 2 % MOD; 
	ll ans = 0; 
	for (int i = 1000000; i > 1; i--)
	{
		int tot = 0; 
		for (int j = i; j <= 1000000; j += i)
			tot += app[j]; 
		if (!tot)
			continue; 
		dp[i] = p[tot - 1] * tot % MOD; 
		for (int j = i + i; j <= 1000000; j += i)
			dp[i] = (dp[i] - dp[j] + MOD) % MOD; 
		ans = (ans + dp[i] * i) % MOD; 
	}
	printf("%lld\n", ans);
	return 0; 
}