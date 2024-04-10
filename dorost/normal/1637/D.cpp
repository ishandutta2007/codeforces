/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int dp[N][N * N];
int a[N], b[N];

void solve() {
	int n, sum = 0, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ans += (a[i] * a[i]) * (n - 2);
		sum += a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		ans += (b[i] * b[i]) * (n - 2);
		sum += b[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < N * n; j++) {
			dp[i][j] = false;
			if (i == 0) {
				if (a[0] == j || b[0] == j) {
					dp[i][j] = true;
				} else {
					dp[i][j] = false;
				}
			} else {
				if (j >= a[i]) {
					dp[i][j] |= dp[i - 1][j - a[i]];
				} 
				if (j >= b[i]) {
					dp[i][j] |= dp[i - 1][j - b[i]];
				}
			}
		}
	}
	int mn = INT_MAX;
	for (int i = 0; i < N * n; i++) {
		if (dp[n - 1][i]) {
			mn = min(mn, i * i + (sum - i) * (sum - i));
		}
	}
	cout << mn + ans << '\n';
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