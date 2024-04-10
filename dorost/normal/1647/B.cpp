/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
string s[N];
bool vis[N][N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int mx1[N * N], mx2[N * N], mn1[N * N], mn2[N * N], t[N * N];
int cnt = 0;
int n, m;

bool ok(int x, int y) {
	if (x >= n || y >= m || x < 0 || y < 0) {
		return false;
	}
	if (s[x][y] == '0')
		return false;
	if (vis[x][y])
		return false;
	return true;
}

void dfs(int x, int y, int c) {
	if (!ok(x, y))
		return;
	t[c]++;
	mx1[c] = max(mx1[c], x);
	mn1[c] = min(mn1[c], x);
	mx2[c] = max(mx2[c], y);
	mn2[c] = min(mn2[c], y);
	vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		dfs(x + dx[i], y + dy[i], c);
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		mx1[i] = 0;
		mx2[i] = 0;
		mn1[i] = INT_MAX;
		mn2[i] = INT_MAX;
		t[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) {
			vis[i][j] = false;
		}
	}
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ok(i, j)) {
				dfs(i, j, cnt);
				cnt++;
			}
		}
	}
	bool f = true;
	for (int i = 0; i < n * m; i++) {
		if (t[i] == 0)
			continue;
		if (t[i] != (mx1[i] - mn1[i] + 1) * (mx2[i] - mn2[i] + 1))
			f = false;
	}
	cout << (f ? "YES" : "NO") << '\n';
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