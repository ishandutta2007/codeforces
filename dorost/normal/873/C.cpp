/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int a[N][N];

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int sum = 0, cost = 0;
	for (int i = 0; i < m; i++) {
		int mx = 0, ans = 0, num = 0;
		for (int j = 0; j < n; j++) {
			if (a[j][i] == 1) {
				int x = 0;
				for (int l = j; l < min(n, j + k); l++) {
					x += a[l][i];
				}
				if (mx < x) {
					mx = x;
					ans = num;
				}
				num++;
			}
		}
		sum += mx;
		cost += ans;
	}
	cout << sum << ' ' << cost << '\n';
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}