/* 	* In the name of GOD  */

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 100001, M = 450;
int a[N];
ll sum[N][M];
ll dp[N][2];

int f(int x) {
	return x & 1;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int i = 1; i < min(n + 1, M); i++) {
		if (i == 1)
			sum[0][i] = a[i - 1];
		else
			sum[0][i] = sum[0][i - 1] + a[i - 1];
	}
	for (int j = 1; j < M; j++) {
		for (int i = 1; i <= n - j; i++) {
			sum[i][j] = sum[i - 1][j] + a[i + j - 1] - a[i - 1];
		}
	}
	int ans = 0;
	for (int j = 1; j < M; j++) {
		for (int i = n - 1; i >= 0; i--) {
			if (i == n - 1) {
				dp[i][f(j)] = (j == 1 ? a[i] : 0);
			} else if (j == 1) {
				dp[i][f(j)] = max((ll)a[i], dp[i + 1][f(j)]);
			} else {
				if (i + j >= n)
					dp[i][f(j)] = 0;
				else { 
					ll x = dp[i + j][f(j - 1)];
					dp[i][f(j)] = dp[i + 1][f(j)];
					if (x > sum[i][j])
						dp[i][f(j)] = max(dp[i][f(j)], sum[i][j]);
				}
			}
			if (i == 0 && dp[i][f(j)] != 0) {
				ans = max(ans, j);
			}
		}
	}
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