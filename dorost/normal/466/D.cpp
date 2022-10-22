/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 2012, M = 1000000007;
int dp[N][N], a[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, h;
	cin >> n >> h;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > h) {
			cout << 0;
			return 0;
		}
		a[i] = h - a[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < N - 2; j++) {
			if (j != a[i] && j != a[i] - 1) {
				dp[i][j] = 0;
			} else {
				if (i == 0) {
					dp[i][j] = 1;
				} else {
					if (j == a[i] - 1) {
						dp[i][j] = dp[i - 1][j] * (j + 1) + dp[i - 1][j + 1] * (j + 1);
						dp[i][j] %= M;
					} else {
						if (j == 0) {
							dp[i][j] = dp[i - 1][j];
						} else {
							dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
							dp[i][j] %= M;
						}
					}
				}
			}
		}
	}
	cout << dp[n][0];
}