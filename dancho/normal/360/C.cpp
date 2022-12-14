#include <cstdio>
#include <cstring>

const int mod = 1000000007;

int n, k;
char s[2048];
long long dp[2048][2048];
long long sdp[2048][2048];

int main()
{
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	
	memset(dp, 0, sizeof(dp));
	memset(sdp, 0, sizeof(sdp));
	dp[0][0] = 1;
	int i, j, p;
	for (j = 0; j <= k; ++j)
	{
		sdp[0][j] = dp[0][j];
		for (i = 1; i <= n; ++i)
		{
			long long lt = s[i-1] - 'a';
			long long gt = 'z' - s[i-1];
			dp[i][j] = sdp[i-1][j] * lt;
			if (dp[i][j] >= mod)
				dp[i][j] %= mod;
			long long m = n-i+1;
			for (p = 1; m*p <= j && i >= p; ++p)
			{
				dp[i][j] += gt * dp[i-p][j-m*p];
				if (dp[i][j] >= mod)
					dp[i][j] %= mod;
			}
			sdp[i][j] = sdp[i-1][j] + dp[i][j];
			if (sdp[i][j] >= mod)
				sdp[i][j] -= mod;
		}
	}
	long long ans = 0;
	for (i = n; i >= 0; --i)
	{
		ans += dp[i][k];
		if (ans >= mod)
			ans %= mod;
	}
	printf("%d\n", (int) ans);
	return 0;
}