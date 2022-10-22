/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 5012, inf = 25000010;
bool a[N];
int dp[N][N], x[N], y[N];
int xx = 0, yy = 0;

int ans(int l, int r) {
	if (l == xx) {
		return 0;
	}
	if (l > xx || r >= yy)
		return inf;
	if (dp[l][r] != -1) {
		return dp[l][r];
	}
	return dp[l][r] = min(ans(l, r + 1), ans(l + 1, r + 1) + abs(x[l] - y[r]));
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i]) {
			x[xx] = i;
			xx++;
		} else {
			y[yy] = i;
			yy++;
		}
	}
	for (int i = 0; i < xx + 10; i++) {
		for (int j = 0; j < yy + 10; j++) {
			dp[i][j] = -1;
		}
	}
	cout << ans(0, 0);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}