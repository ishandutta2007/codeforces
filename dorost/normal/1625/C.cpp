/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 502;
int dp[2][N][N], d[N], a[N], mn[N][N];

int f(int x) {
	return x & 1;
}

inline void solve() {
	int n, l, k;
	cin >> n >> l >> k;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	d[n] = l;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	a[n] = INT_MAX;
	for (int i = 1; i < N; i++)
		for (int j = 0; j < N; j++)
			mn[i][j] = 1000 * 1000 * 1000 + 10;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			for (int l = 0; l <= k; l++) {
				if (j == i - 1) {
					dp[f(i)][j][l] = mn[i - 1][l] + a[j] * (d[i] - d[i - 1]);
				} else if (l) {
					dp[f(i)][j][l] = dp[f(i - 1)][j][l - 1] + a[j] * (d[i] - d[i - 1]);
				} else {
					dp[f(i)][j][l] = 1000 * 1000 * 1000 + 10;
				}
				mn[i][l] = min(mn[i][l], dp[f(i)][j][l]);
			}
		}
	}
	cout << mn[n][k];
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	solve();
}