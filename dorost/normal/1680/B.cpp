/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, m;
	cin >> n >> m;
	int mn = INT_MAX, mnj = INT_MAX;
	vector <pair <int, int>> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == 'R') {
				v.push_back(make_pair(i, j));
				mn = min(mn, i);
				mnj = min(mnj, j);
			}
		}
	}
	bool f = false;
	for (pair <int, int> p : v) {
		if (p.F == mn && p.S == mnj) {
			f = true;
		}
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