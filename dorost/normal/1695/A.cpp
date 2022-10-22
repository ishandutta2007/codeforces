/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, m, h = 0, w = 0;
	cin >> n >> m;
	int mx = INT_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			if (a > mx) {
				mx = a;
				h = max(i + 1, n - i);
				w = max(j + 1, m - j);
			}
		}
	}
	cout << h * w << endl;
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