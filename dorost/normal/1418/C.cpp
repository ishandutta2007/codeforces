/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int dp[N][2], a[N], n;

int ans(int y, int x) {
	if (x >= n)
		return 0;
	if (dp[x][y] != -1)
		return dp[x][y];
	if (y == 1) {
		return dp[x][y] = min({(a[x] == 1) + ans(1 - y, x + 1), (a[x] == 1) + (a[x + 1] == 1) + ans(1 - y, x + 2)});
	}else {
		return dp[x][y] = min(ans(1 - y, x + 1), ans(1 - y, x + 2));
	}
}

void solve() {
	cin >> n;
	a[n] = 0;
	a[n + 1] = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i], dp[i][0] = -1, dp[i][1] = -1;
	cout << ans(1, 0) << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}