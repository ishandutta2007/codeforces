/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 55;
string s[N];

void solve() {
	int n, m;
	cin >> n >> m;
	int x = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) {
			if (x == 3)
				continue;
			if (s[i][j] != '.') {
				if (((i + j) % 2 == (s[i][j] == 'W')) && x != 2) {
					x = 1;
				} else if (x != 1 && (((i + j) % 2 == (s[i][j] == 'R')))) {
					x = 2;
				} else {
					x = 3;
				}
			}
		}
	}
	if (x == 3) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	if (x == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << ((i + j) % 2 ? 'W' : 'R');
			}
			cout << '\n';;
		}
	} else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << ((i + j) % 2 ? 'R' : 'W');
			}
			cout << '\n';;
		}
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}