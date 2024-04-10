/* 	* In the name of GOD  */

#pragma GCC optimize("O3,unroll-loops")

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int M = 998244353;
const int N = 201234;
int dp[2][N];
int sum[N];

int f(int x) {
	return x & 1;
}

void solve() {
	int n, k;
	cin >> n >> k;
	dp[0][0] = 1;
	for (int i = 1; i <= 640; i++) {
		int x = k + i - 1;
		for (int j = 0; j <= n; j++) {
			dp[f(i)][j] = 0;
			if (j >= x) {
				dp[f(i)][j] = dp[f(i - 1)][j - x];
				dp[f(i)][j] += dp[f(i)][j - x];
				if (dp[f(i)][j] >= M)
					dp[f(i)][j] -= M;
			}
			sum[j] += dp[f(i)][j];
			if (sum[j] >= M)
				sum[j] -= M;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << sum[i] << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}