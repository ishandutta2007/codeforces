/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int ask(int x, int y, int z) {
	cout << "? " << x + 1 << ' ' << y + 1 << ' ' << z + 1 << endl;
	int k;
	cin >> k;
	return k;
}

int print(int x, int y) {
	cout << "! " << x + 1 << ' ' << y + 1 << endl;
}

void solve() {
	int n;
	cin >> n;
	if (n == 4) {
		int a = ask(0, 1, 2);
		int b = ask(0, 1, 3);
		int c = ask(0, 2, 3);
		int d = ask(1, 2, 3);
		int mx = max({a, b, c, d});
		int cn[4] = {2, 2, 2, 2};
		if (a == mx) 
			cn[3]--;
		if (b == mx)
			cn[2]--;
		if (c == mx)
			cn[1]--;
		if (d == mx)
			cn[0]--;
		vector <int> v;
		for (int i = 0; i < 4; i++) {
			if (cn[i] == 2)
				v.push_back(i);
		}
		assert(v.size() <= 2);
		print(v[0], (v.size() == 1 ? v[0] : v[1]));
		return;
	}
	int mx = 0, in = -1;
	int ii = 0, jj = 1;
	for (int i = 0; i < n; i++) {
		if (i == ii || i == jj)
			continue;
		int y = ask(ii, jj, i);
		if (y >= mx) {
			mx = y;
			in = i;
		}
	}
	int in2 = ii;
	int mx2 = 0, in3 = -1;
	for (int i = 0; i < n; i++) {
		if (i == in || i == in2) {
			continue;
		}
		int y;
		if (i == jj) {
			continue;
		} else {
			y = ask(in, in2, i);
		}
		if (y >= mx2) {
			mx2 = y;
			in3 = i;
		}
	}
	int y1 = ask(in, ii, jj);
	int y2 = ask(in, in3, ii);
	int y3 = ask(in, in3, jj);
	int x = max({y1, y2, y3});
	int cnt[3] = {};
	if (y1 == x)
		cnt[0]++;
	if (y2 == x)
		cnt[1]++;
	if (y3 == x)
		cnt[2]++;
	if (cnt[0] + cnt[1] + cnt[2] == 1) {
		if (y1 == x) {
			print(ii, jj);
		}
		if (y2 == x) {
			print(ii, in3);
		}
		if (y3 == x) {
			print(in3, jj);
		}
		return;
	} else if (cnt[0] + cnt[1] + cnt[2] == 2) {
		if (y1 != x) {
			print(in, in3);
		}
		if (y2 != x) {
			print(in, jj);
		}
		if (y3 != x) {
			print(in, ii);
		}
	} else {
		print(in, in3);
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}