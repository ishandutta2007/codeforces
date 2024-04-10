/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234, INF = 1000LL * 1000LL * 1000LL * 100000LL;
int a[N], n, dp[N][4];
string s, h = "hard";

int ans(int i, int x) {
	if (i == n)
		return 0;
	if (dp[i][x] != -1)
		return dp[i][x];
	int mn = ans(i + 1, x) + a[i];
	int xx = x;
	if (s[i] == h[x])
		xx++;
	if (xx != 4)
		mn = min(mn, ans(i + 1, xx));
	return dp[i][x] = mn;
}

void solve() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++)
			dp[i][j] = -1;
	}
	cout << ans(0, 0);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}