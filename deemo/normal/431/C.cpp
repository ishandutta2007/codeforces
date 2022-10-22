#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int max_n = 100 + 3;

int n, k, d;
ll dp[max_n][max_n][max_n];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> d;
	ll ans = 0;
	for (int i = 1; i <= k; i++){
		dp[i][0][i] = 1;
		if (i == n && i >= d)	ans++;
	}

	for (int h = 1; h <= n; h++)
		for (int sum = 1; sum <= n; sum++){
			for (int maxi = 1; maxi <= min(sum, k); maxi++)
				for (int j = 1; j <= maxi; j++)
					if (j < maxi)	dp[sum][h][maxi] = (dp[sum][h][maxi] + dp[sum - j][h - 1][maxi]) % MOD;
					else
						for (int w = 1; w <= min(maxi, sum - maxi); w++)
							dp[sum][h][maxi] += dp[sum - maxi][h - 1][w], dp[sum][h][maxi] %= MOD;
			if (sum == n)
				for (int maxi = d; maxi <= n; maxi++)
					ans = (ans + dp[n][h][maxi]) % MOD;
		}
	cout << ans << endl;
	return 0;
}