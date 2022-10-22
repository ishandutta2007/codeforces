/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 501;
string ans;
bool a[N][N], vis[N][N];
int dx[4] = {1, -1, 0, 0}, n;
int dy[4] = {0, 0, 1, -1};
char dc[4] = {'D', 'U', 'R', 'L'};

bool ok2(int x, int y) {
	return (x >= 0 && y >= 0 && x < n && y < n && a[x][y] == 1);
}

bool ok(int x, int y, int d) {
	for (int k = 0; k < N; k++) {
		if (ok2(x + k * dx[d], y + k * dy[d]))
			return true;
	}
	return false;
}

void dfs(int x, int y) {
	if (!a[x][y]) {
		ans += '1';
		a[x][y] = true;
	}
	vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		if (!vis[x + dx[i]][y + dy[i]]) {
			if (ok(x + dx[i], y + dy[i], i)) {
				ans += dc[i];
				dfs(x + dx[i], y + dy[i]);
				ans += dc[i ^ 1];
			}
		}
	}
}

void dfs2(int x, int y) {
	vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		if (!vis[x + dx[i]][y + dy[i]]) {
			if (ok2(x + dx[i], y + dy[i])) {
				ans += dc[i];
				dfs2(x + dx[i], y + dy[i]);
				ans += dc[i ^ 1];
			}
		}
	}
	if (a[x][y]) {
		ans += '2';
		a[x][y] = false;
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int x0 = 0, y0 = 0;
	cin >> n >> x0 >> y0;
	x0--, y0--;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			cin >> a[i][j];
	}
	dfs(x0, y0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vis[i][j] = false;
		}
	}
	dfs2(x0, y0);
	bool bad = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bad |= a[i][j];
		}
	}
	if (bad) {
		cout << "NO\n";
	} else {
		cout << "YES\n" << ans;
	}
}