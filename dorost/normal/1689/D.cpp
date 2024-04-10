/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
vector <pair <int, int>> v;

pair <bool, pair <int, int>> is_valid (int x) {
	int apbl = INT_MIN, apbr = INT_MAX, anbl = INT_MIN, anbr = INT_MAX;
	for (pair <int, int> p : v) {
		apbl = max(apbl, p.F + p.S - x);
		apbr = min(apbr, p.F + p.S + x);
		anbl = max(anbl, p.F - p.S - x);
		anbr = min(anbr, p.F - p.S + x);
	}
	if (apbl > apbr || anbl > anbr) {
		return make_pair(false, make_pair(0, 0));
	} else {
		if (apbl == apbr && anbl == anbr) {
			if ((apbl - anbl) % 2) {
				return make_pair(false, make_pair(0, 0));
			}
			int b = (apbl - anbl) / 2;
			int a = apbl - b;
			return make_pair(true, make_pair(a, b));
		}
		if (apbl != apbr) {
			if ((apbl - anbl) % 2 == 0) {
				int b = ((apbl - anbl)) / 2;
				int a = apbl - b;
				return make_pair(true, make_pair(a, b));
			} else {
				apbl++;
				int b = ((apbl - anbl)) / 2;
				int a = apbl - b;
				return make_pair(true, make_pair(a, b));
			}
		} else {
			if ((apbl - anbl) % 2 == 0) {
				int b = (apbl - anbl) / 2;
				int a = apbl - b;
				return make_pair(true, make_pair(a, b));
			} else {
				anbl++;
				int b = (apbl - anbl) / 2;
				int a = apbl - b;
				return make_pair(true, make_pair(a, b));
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		v.clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char c;
				cin >> c;
				if (c == 'B')
					v.push_back({i, j});
			}
		}
		int l = -1, r = n + m - 2;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (is_valid(mid).F)
				r = mid;
			else
				l = mid;
		}
		cout << is_valid(r).S.F + 1 << ' ' << is_valid(r).S.S + 1 << '\n';
	}
}