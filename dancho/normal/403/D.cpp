#include <cstdio>
#include <cstring>

const int mod = 1000000007;

long long dp[55][1024];

long long hc[55][1024];

long long fac[1024];

long long getHC(int h, int p)
{
	if (p < 0)
		return 0;
	if (h <= 0)
		return 0;
	if (h == 1)
		return 1;
	if (hc[h][p] != -1)
		return hc[h][p];

	long long sol = 0;
	for (int i = 0; i <= p; i++)
	{
		sol += getHC(h - 1, i);
		if (sol >= mod)
			sol %= mod;
	}

	hc[h][p] = sol;
	return hc[h][p];
}

long long getDP(int mu, int sm)
{
	//~ printf("IN DP %d %d\n", mu, sm);
	if (mu == 0 && sm == 0)
		return 1;
	if (mu <= 0)
		return 0;
	if (sm == 0)
		return 0;
	if (dp[mu][sm] != -1)
		return dp[mu][sm];
	long long ans = 0;
	for (int x = 1; x * mu <= sm; ++x)
	{
		ans += getDP(mu-1, sm - x * mu);
		if (ans >= mod)
			ans %= mod;
	}
	dp[mu][sm] = ans;
	return dp[mu][sm];
}

long long hcs[64][1024];

int n, k;

int main()
{
	memset(dp, -1, sizeof(dp));
	memset(hc, -1, sizeof(hc));
	fac[0] = 1;
	for (int i = 1; i < 1010; i++)
	{
		fac[i] = fac[i-1] * i;
		if (fac[i] >= mod)
			fac[i] %= mod;
	}

	memset(hcs, 0, sizeof(hcs));
	for (int k = 1; k <= 50; ++k)
	{
		for (int j = 0; j <= 1000; ++j)
		{
			if (j - k >= 0)
				hcs[k][j] = hcs[k][j - k] + getHC(k + 1, j);
			else
				hcs[k][j] = getHC(k + 1, j);
			if (hcs[k][j] >= mod)
				hcs[k][j] %= mod;
		}
	}

	int t, T;
	scanf("%d", &T);
	for (t = 0; t < T; ++t)
	{
		scanf("%d %d", &n, &k);

		if (k * (k + 1) / 2 > n)
		{
			// If this isn't a special case it might be safer!
			printf("0\n");
			continue;
		}
		long long ans = 0;
		for (int s = 0; s <= n - k; ++s)
		{
			ans += getDP(k - 1, s) * hcs[k][n - k - s];
			if (ans >= mod)
				ans %= mod;
		}

		ans = ans * fac[k];
		if (ans >= mod)
			ans %= mod;
		printf("%d\n", (int) ans);
	}
	return 0;
}