/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 109;
int a[N];
bool f[N][N], vis[N][N];
int dp[N][N];
int lim;

bool ans(int x, int y) {
	if (x < 0 || y < 0 || x >= lim - 1 || y > lim)
		return false;
	if (vis[x][y])
		return dp[x][y] = false;
	vis[x][y] = true;
	if (f[x][y]) {
		return dp[x][y] = false;
	}
	if (dp[x][y] != -1) 
		return dp[x][y];
	return dp[x][y] = (ans(x + 1, y) || ans(x, y + 1) || ans(x - 1, y) || ans(x, y - 1));
}

void solve() {
	int n, u, v;
	cin >> n >> u >> v;
	set <int> st;
	int mn = INT_MAX, mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		st.insert(a[i]);
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	int cnt = st.size();
	if (mx == mn) {
		cout << min(2 * v, u + v) << ' ';
	} else if (mx - mn + 1 == cnt) {
		for (int i = 0; i < n + 5; i++) {
			for (int j = 0; j < n + 5; j++) {
				dp[i][j] = -1;
				f[i][j] = false;
				vis[i][j] = false;
			}
		}
		for (int i = 0; i < n + 5; i++) {
			dp[i][n + 1] = 1;
		}
		for (int i = 0; i < n; i++) {
			f[i][a[i] - mn + 1] = true;
		}
		lim = n + 1;
		bool h = ans(0, 0);
		if (h) 
			cout << 0 << ' ';
		else
			cout << min(u, v) << ' ';
	} else {
		cout << 0 << ' ';
	}
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