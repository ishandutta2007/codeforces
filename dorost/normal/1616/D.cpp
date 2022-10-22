/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 50123;
int dp[N][2], a[N];

void solve() {
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> x;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			if (i == 0) {
				if (j == 0) {
					dp[i][j] = 0;
				} else {
					dp[i][j] = 1;
				}
			} else if (j == 0) {
				dp[i][j] = max(dp[i - 1][0], dp[i - 1][1]);
			} else {
				dp[i][j] = dp[i - 1][0] + 1;
				if (a[i] + a[i - 1] >= x * 2) {
					dp[i][j] = max(dp[i][j], (i == 1 ? 0 : dp[i - 2][0]) + 2);
					if (i >= 2 && a[i] + a[i - 1] + a[i - 2] >= 3 * x) {
						dp[i][j] = max(dp[i][j], dp[i - 1][1] + 1);
					}
				}
			}
		}
	}
	cout << max(dp[n - 1][0], dp[n - 1][1]) << ' ';
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