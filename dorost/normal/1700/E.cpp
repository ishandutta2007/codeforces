/* 	* In the name of GOD  */

#pragma GCC optimiza("O3")

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 400005;
vector <int> a[N];
vector <bool> f[N];
vector <bool> of[N];
vector <bool> b[N];
int cnt = 0, dx[5] = {0, 0, 1, -1, 0};
int dy[5] = {1, -1, 0, 0, 0}, ans, n, m;

bool ok(int i, int j) {
	return ((i >= 0) && (j >= 0) && (i < n) && (j < m));
}

void wef (int x1, int y1, int x2, int y2) {
	if (x1 == x2 && y1 == y2)
		return;
	if (b[x1][y1] && b[x2][y2] && make_pair(x1, y1) < make_pair(x2, y2))
		return;
	swap(a[x1][y1], a[x2][y2]);
	for (int k = 0; k < 5; k++) {
		int nx = x1 + dx[k];
		int ny = y1 + dy[k];
		if (ok(nx, ny)) {
			if (f[nx][ny])
				cnt--;
			f[nx][ny] = false;
			if (a[nx][ny] == 1) {
				if (f[nx][ny] == false)
					cnt++;
				f[nx][ny] = true;
				continue;
			}
			for (int k = 0; k < 4; k++) {
				if (ok(nx + dx[k], ny + dy[k]) && a[nx + dx[k]][ny + dy[k]] < a[nx][ny]) {
					if (f[nx][ny] == false)
						cnt++;
					f[nx][ny] = true;
				}
			}
		}
	}
	for (int k = 0; k < 5; k++) {
		int nx = x2 + dx[k];
		int ny = y2 + dy[k];
		if (ok(nx, ny)) {
			if (f[nx][ny])
				cnt--;
			f[nx][ny] = false;
			if (a[nx][ny] == 1) {
				if (f[nx][ny] == false)
					cnt++;
				f[nx][ny] = true;
				continue;
			}
			for (int k = 0; k < 4; k++) {
				if (ok(nx + dx[k], ny + dy[k]) && a[nx + dx[k]][ny + dy[k]] < a[nx][ny]) {
					if (f[nx][ny] == false)
						cnt++;
					f[nx][ny] = true;
				}
			}
		}
	}
	if (cnt == n * m) {
		ans++;
	}
	for (int k = 0; k < 5; k++) {
		int nx = x2 + dx[k];
		int ny = y2 + dy[k];
		if (ok(nx, ny)) {
			if (f[nx][ny] != of[nx][ny]) {
				if (f[nx][ny] == false)
					cnt++;
				else
					cnt--;
			}
			f[nx][ny] = of[nx][ny];
		}
	}
	for (int k = 0; k < 5; k++) {
		int nx = x1 + dx[k];
		int ny = y1 + dy[k];
		if (ok(nx, ny)) {
			if (f[nx][ny] != of[nx][ny]) {
				if (f[nx][ny] == false)
					cnt++;
				else
					cnt--;
			}
			f[nx][ny] = of[nx][ny];
		}
	}
	swap(a[x1][y1], a[x2][y2]);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			a[i].push_back(x);
			f[i].push_back(false);
			of[i].push_back(false);
			b[i].push_back(false);
		}
	}
	vector <pair <int, int>> bad;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				if (f[i][j] == false)
					cnt++;
				f[i][j] = true;
				of[i][j] = true;
				continue;
			}
			for (int k = 0; k < 4; k++) {
				if (ok(i + dx[k], j + dy[k]) && a[i + dx[k]][j + dy[k]] < a[i][j]) {
					if (f[i][j] == false)
						cnt++;
					f[i][j] = true;
					of[i][j] = true;
				}
			}
			if (!f[i][j]) {
				bad.push_back(make_pair(i, j));
			}
		}
	}
	if ((int)bad.size() > 10) {
		cout << 2 << '\n';
		return 0;
	}
	if ((int)bad.size() == 0) {
		cout << 0 << '\n';
		return 0;
	}
	if (bad.size() <= 5) {
		int k = (int)bad.size();
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < 4; j++) {
				if (ok(bad[i].F + dx[j], bad[i].S + dy[j])) {
					bad.push_back(make_pair(bad[i].F + dx[j], bad[i].S + dy[j]));
				}
			}
		}
		for (pair <int, int> p : bad) {
			b[p.F][p.S] = true;
		}
		set <pair <int, int>> bb;
		for (pair <int, int> p : bad)
			bb.insert(p);
		for (pair <int, int> p : bb) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					wef(p.F, p.S, i, j);
				}
			}
		}
	} else {
		int k = (int)bad.size();
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < 4; j++) {
				if (ok(bad[i].F + dx[j], bad[i].S + dy[j])) {
					bad.push_back(make_pair(bad[i].F + dx[j], bad[i].S + dy[j]));
				}
			}
		}
		for (pair <int, int> p : bad) {
			b[p.F][p.S] = true;
		}
		set <pair <int, int>> bb;
		for (pair <int, int> p : bad)
			bb.insert(p);
		for (pair <int, int> p : bb) {
			for (pair <int, int> q : bb) {
				wef(p.F, p.S, q.F, q.S);
			}
		}
	}
	if (ans == 0) {
		cout << 2;
	} else {
		cout << 1 << ' ' << ans;
	}
}