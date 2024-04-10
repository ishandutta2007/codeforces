/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 56;
string s[N];

void solve() {
	int n, m, r, c;
	cin >> n >> m >> r >> c;
	r--, c--;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	if (s[r][c] == 'B') {
		cout << 0 << '\n';
		return;
	}
	bool f = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i == r || j == c) && s[i][j] == 'B')
				f = true;
		}
	}
	if (f) {
		cout << '1' << '\n';
		return;
	} else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (s[i][j] == 'B') {
					cout << 2 << '\n';
					return;
				}
			}
		}
		cout << -1 << '\n';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}