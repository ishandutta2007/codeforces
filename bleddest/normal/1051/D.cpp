#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<cstdio>

using namespace std;

const int MOD = 998244353;

int add(int x, int y)
{
	x += y;
	while (x >= MOD)
		x -= MOD;
	while (x < 0)
		x += MOD;
	return x;
}

int mul(int x, int y)
{
	return (x * 1ll * y) % MOD;
}

int dp[1043][2048][4];

int f(int x, int y)
{
	if (x == y)
		return 0;
	if ((y == 0 || y == 3) && ((x ^ y) != 3))
		return 0;
	if ((y == 1 || y == 2) && ((x ^ y) == 3))
		return 2;
	return 1;
}

int main()
{
	int n, k;
	cin >> n >> k;
	// dp[i][j][k] ---    i ,  j    --- k
	dp[1][1][0] = 1;
	dp[1][2][1] = 1;
	dp[1][2][2] = 1;
	dp[1][1][3] = 1;
	for(int i = 1; i < n; i++)
		for(int j = 0; j <= 2 * n; j++)
			for (int k = 0; k < 4; k++)
			{
				if (dp[i][j][k] == 0) continue;
				for (int p = 0; p < 4; p++)
				{
					int nc = j + f(k, p);
					dp[i + 1][nc][p] = add(dp[i + 1][nc][p], dp[i][j][k]);
				}
			}
	int ans = 0;
	for (int i = 0; i < 4; i++)
		ans = add(ans, dp[n][k][i]);
	cout << ans << endl;
	return 0;
}