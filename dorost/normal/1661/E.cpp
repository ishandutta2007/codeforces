/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 501234;
char s[3][N];
vector <pair <pair <int, int>, pair <int, int>>> v[3];
int ps[3][N], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, n;
bool vis[3][N];
int mn = N, mx = -1;

bool ok(int x, int y) {
	return !(x < 0 || y < 0 || x >= 3 || y >= n || s[x][y] == '0');
}

void dfs(int x, int y) {
	vis[x][y] = true;
	if (x == 1) {
		mn = min(mn, y);
		mx = max(mx, y);
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (ok(nx, ny) && !vis[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
		if (i != 1) {
			for (int j = 0; j < n; j++) {
				if ((j == 0 || s[i][j - 1] == '0') && s[i][j] == '1') {
					v[i].push_back({{j, 0}, {N, -1}});
				}
				if (s[i][j] == '1' && (j == n - 1 || s[i][j + 1] == '0')) {
					v[i][v[i].size() - 1].F.S = j;
				}
			}
		} else {
			for (int j = 0; j < n; j++) {
				if (j == 0) {
					ps[i][j] = (s[i][j] == '1');
				} else {
					ps[i][j] = ps[i][j - 1] + (s[i][j] == '1');
				}
			}
		}
	}
	for (int i = 0; i < 3; i += 2) {
		for (int k = 0; k < v[i].size(); k++) {
			pair <pair <int, int>, pair <int, int>> p = v[i][k];
			for (int j = p.F.F; j <= p.F.S; j++) {
				if (s[1][j] == '1') {
					p.S.F = min(p.S.F, j);
					p.S.S = max(p.S.S, j);
				}
			}
			v[i][k] = p;
			if (p.S.S == -1) {
				ps[i][p.F.S]++;
			}
		}
		for (int k = 1; k < n; k++) {
			ps[i][k] += ps[i][k - 1];
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] == '1' && !vis[i][j]) {
				mn = N, mx = -1;
				dfs(i, j);
				if (mx != -1) {
					v[1].push_back({{mn, mx}, {N, -1}});
				}
			}
		}
	}
	sort(v[1].begin(), v[1].end());
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		int aa = upper_bound(v[1].begin(), v[1].end(), make_pair(make_pair(r, N), make_pair(N, N))) - v[1].begin();
		int bb = lower_bound(v[1].begin(), v[1].end(), make_pair(make_pair(l, -1), make_pair(-1, -1))) - v[1].begin();
		if (bb != 0) {
			if (v[1][bb - 1].F.S >= l)
				bb--;
		}
		int ans = aa - bb;
		if (ans == 1) {
			if (ps[1][r] - (l == 0 ? 0 : ps[1][l - 1]) == 0)
				ans = 0;
		}
		for (int i = 0; i < 3; i += 2) {
			if (v[i].empty())
				continue;
			aa = upper_bound(v[i].begin(), v[i].end(), make_pair(make_pair(r, N), make_pair(N, N))) - v[i].begin();
			if (aa != 0) {
				aa--;
			} else {
				continue;
			}
			bb = lower_bound(v[i].begin(), v[i].end(), make_pair(make_pair(l, -1), make_pair(-1, -1))) - v[i].begin();
			if (bb != 0) {
				if (v[i][bb - 1].F.S >= l)
					bb--;
			}
			if (aa < bb)
				continue;
			int s = v[i][bb].F.S, e = v[i][aa].F.S - 1;
			if (s <= e)
				ans += ps[i][e] - (ps[i][s]);
			if (aa != bb) {
				if (v[i][aa].S.F > r || v[i][aa].S.F < l)
					ans++;
				if (v[i][bb].S.S < l || v[i][bb].S.S > r)
					ans++;
			} else {
				s = max(l, v[i][aa].F.F);
				e = min(r, v[i][aa].F.S);
				if (ps[1][e] - (s == 0 ? 0 : ps[1][s - 1]) == 0)
					ans++;
			}
		}
		cout << ans << ' ';
	}
}