/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 515;
int a[N][N][4], inf = 10000002;
int dp[N][N][11];
int n, m, k;

int ans(int x, int y, int k) {
	if (x < 0 || x >= n || y < 0 || y >= m)
		return INT_MAX;
	if (k == 0)
		return 0;
	if (dp[x][y][k] != -1) {
		return dp[x][y][k];
	}
	int mn = min({ans(x + 1, y, k - 1) + a[x][y][1], ans(x - 1, y, k - 1) + a[x][y][0],ans(x, y + 1, k - 1) + a[x][y][2],ans(x, y - 1, k - 1) + a[x][y][3]});
	dp[x][y][k] = mn;
	return mn;
}

// 0 : up, 1 : down, 2 : rigth, 3 left

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			int x;
			cin >> x;
			a[i][j][2] = x;
			a[i][j + 1][3] = x;
		}
	
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 11; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			a[i][j][1] = x;
			a[i + 1][j][0] = x;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (k % 2) {
				cout << -1 << ' ';
			} else {
				cout << ans(i, j, k / 2) * 2 << ' ';
			}
		}
		cout << '\n';
	}
}