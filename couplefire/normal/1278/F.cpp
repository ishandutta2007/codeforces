#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int N = 5043;

int add(int x, int y)
{
	x += y;
	while(x >= MOD) x -= MOD;
	while(x < 0) x += MOD;
	return x;
}

int mul(int x, int y)
{
	return (x * 1ll * y) % MOD;
}

int binpow(int x, int y)
{
	int z = 1;
	while(y > 0)
	{
		if(y % 2 == 1)
			z = mul(z, x);
		x = mul(x, x);
		y /= 2;
	}
	return z;
}

int inv(int x)
{
	return binpow(x, MOD - 2);
}

int n, m, k;

int dp[N][N];

int main()
{
	cin >> n >> m >> k;
	dp[0][0] = 1;
	for(int i = 0; i < k; i++)
		for(int j = 0; j < k; j++)
		{
			dp[i + 1][j] = add(dp[i + 1][j], mul(dp[i][j], j));
			dp[i + 1][j + 1] = add(dp[i + 1][j + 1], mul(dp[i][j], n - j));
		}
	int ans = 0;
	for(int i = 1; i <= k; i++)
		ans = add(ans, mul(dp[k][i], binpow(inv(m), i)));
	cout << ans << endl;
}