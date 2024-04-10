/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 501234, M = 998244353;
int dp[N][3], sum[N][3], a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n + 10; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = 0;
			sum[i][j] = 0;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				dp[i][j] = 1;
				dp[i][j] += sum[a[i] + 2][2];
				dp[i][j] += sum[a[i]][0];
				dp[i][j] %= M;
				sum[a[i]][j] += dp[i][j];
				sum[a[i]][j] %= M;
			} else if (j == 1) {
				dp[i][j] = 1;
				dp[i][j] += sum[a[i]][1];
				dp[i][j] += sum[a[i] + 1][1];
				dp[i][j] %= M;
				dp[i][j] += sum[a[i] + 2][2];
				dp[i][j] %= M;
				sum[a[i]][j] += dp[i][j];
				sum[a[i]][j] %= M;
			} else {
				dp[i][j] = 1;
				if (a[i] > 1) {
					dp[i][j] += sum[a[i] - 2][0];
				}
				dp[i][j] += sum[a[i]][2];
				dp[i][j] %= M;
				sum[a[i]][j] += dp[i][j];
				sum[a[i]][j] %= M;
			}
		}
	}
	int ans = sum[0][1] + sum[1][2];
	ans %= M;
	ans += M;
	ans %= M;
	cout << ans << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}