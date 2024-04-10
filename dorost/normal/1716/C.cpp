/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int dp[2][N];
int a[2][N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
	dp[0][n - 1] = max(a[0][n - 1] + 2, a[1][n - 1] + 1);
	dp[1][n - 1] = max(a[1][n - 1] + 2, a[0][n - 1] + 1);
	for (int i = 0; i < 2; i++) {
		for (int j = n - 2; j >= 0; j--) {
			dp[i][j] = dp[i][j + 1] + 1;
			dp[i][j] = max(dp[i][j], a[!i][j] + 1);
			dp[i][j] = max(dp[i][j], a[i][j] + (n - j) * 2 - ((i == 0) && (j == 0)));
		}
	}
	int ans = dp[0][0];
	int t = 0;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < 2; i++) {
			int x = i, y = j;
			if (j % 2)
				x = !x;
			if (x == 0 && y == 0)
				continue;
			t++;
			t = max(t, a[x][y] + 1);
			if (i == 1) {
				ans = min(ans, max(t + (n - j - 1) * 2, dp[x][y + 1]));
			}
		}
	}
	cout << ans << '\n';
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