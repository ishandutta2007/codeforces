/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
int n, m;
string s;

pair <int, int> is_valid(int x) {
	if (x == 0)
		return {0, 0};
	if (x > s.size())
		return {-1, -1};
	int r = 0, c = 0, b = 0, p = 0;
	int v = 0, w = 0;
	for (int i = 0; i < x; i++) {
		if (s[i] == 'R')
			w++;
		else if (s[i] == 'L')
			w--;
		else if (s[i] == 'U')
			v++;
		else 
			v--;
		if (v < 0) {
			p = max(p, -1 * v);
		} else {
			b = max(b, v);
		}
		if (w < 0) {
			c = max(c, -1 * w);
		} else {
			r = max(r, w);
		}
	}
//	cout << x << ' ' << p << ' ' << b << ' ' << r << ' ' << c << '\n';
	if (r + c >= m || b + p >= n) {
		return {-1, -1};
	} else {
		return {b, c};
	}
}

void solve() {
	cin >> n >> m >> s;
	int l = 0, r = s.size() + 1;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (is_valid(mid).F != -1) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << is_valid(l).F + 1 << ' ' << is_valid(l).S + 1 << '\n';
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