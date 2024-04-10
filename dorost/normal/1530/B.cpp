/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 21;
int a[N][N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = 0;
		}
	}
	int x = 0;
	for (int i = 0; i < m; i += 2) {
		a[0][i] = 1;
		x++;
	}
	x = 0;
	for (int i = 2; i < n; i += 2) {
		a[i][m - 1] = 1;
	}
	for (int i = m - 3; i >= 0; i -= 2) {
		a[n - 1][i] = 1;
	}
	for (int i = n - 3; i >= 2; i -= 2) {
		a[i][0] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}