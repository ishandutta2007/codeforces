#include <cstdio>
#include <cstring>

const int mod = 1000000007;

int n, k;
long long dp[16][2048];

long long getDP(int l, int x)
{
	if (dp[l][x] != -1)
		return dp[l][x];
	if (l == 1)
		return 1;
	long long sol = 0;
	for (int i = 1; i < x; ++i)
	{
		if (x % i == 0)
		{
			sol += getDP(l - 1, i);
			if (sol >= mod)
				sol %= mod;
		}
	}
	return (dp[l][x] = sol);
}

long long com[2048][2048];

long long gc(int n, int k)
{
	if (k > n)
		return 0;
	if (k < 0)
		return 0;
	if (n == 0)
		return 1;
	if (k == 0)
		return 1;
	if (com[n][k] != -1)
		return com[n][k];
	
	com[n][k] = gc(n - 1, k) + gc(n - 1, k - 1);
	if (com[n][k] >= mod)
		com[n][k] %= mod;
	//~ printf("COM %d %d %lld\n", n, k, com[n][k]);
	return com[n][k];
}

int main()
{
	scanf("%d %d", &n, &k);
	
	memset(dp, -1, sizeof(dp));
	memset(com, -1, sizeof(com));
	
	long long ans = 0;
	for (int i = 1; i <= k && i <= 11; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			ans += getDP(i, j) * gc(k - 1, i - 1);
			if (ans >= mod)
				ans %= mod;
			//~ printf("A %d %d :: %lld %lld\n", i, j, getDP(i, j), gc(k - i, i - 1));
		}
	}
	printf("%d\n", (int) ans);
}