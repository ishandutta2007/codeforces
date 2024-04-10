/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 401;
string s[N];

void solve() {
	int n;
	cin >> n;
	vector <pair <int, int>> x;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < n; j++) {
			if (s[i][j] == '*') {
				x.push_back({i, j});
			}
		}
	}
	int x1, x2, y1, y2, x3, x4, y3, y4;
	x1 = x[0].F;
	y1 = x[0].S;
	x2 = x[1].F;
	y2 = x[1].S;
	if (x1 == x2) {
		if (x1 == 0) {
			x3 = x1 + 1;
			x4 = x1 + 1;
			y3 = y1;
			y4 = y2;
		} else {
			x3 = x1 - 1;
			x4 = x1 - 1;
			y3 = y1;
			y4 = y2;
		}
	} else if (y1 == y2) {
		if (y1 == 0) {
			y3 = y1 + 1;
			y4 = y1 + 1;
			x3 = x1;
			x4 = x2;
		} else {
			y3 = y1 - 1;
			y4 = y1 - 1;
			x3 = x1;
			x4 = x2;
		}
	} else {
		y3 = y2;
		y4 = y1;
		x3 = x1;
		x4 = x2;
	}
	s[x3][y3] = '*';
	s[x4][y4] = '*';
	for (int i = 0; i < n; i++) {
		cout << s[i] << '\n';
	}


}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}