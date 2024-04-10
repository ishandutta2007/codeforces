/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	string s, t;
	cin >> n >> s >> t;
	int a = 0, b = 0, c = 0, d = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1' && t[i] == '1')
			a++;
		else if (t[i] == '0' && s[i] == '1')
			d++;
		else if (t[i] == '1' && s[i] == '0')
			b++;
		else
			c++;
	}
	int mn = INT_MAX;
	if (b == 0 && d == 0) {
		cout << 0 << ' ';
		return;
	}
	int ca = a, cb = b, cc = c, cd = d;
	for (int i = 0; i <= n * 10; i++) {
		if (i % 2 == 0) {
			if (a == 0)
				break;
			int ta = a, tb = b, tc = c, td = d;
			a = tb + 1;
			b = ta - 1;
			c = td;
			d = tc;
		} else {
			if (d == 0)
				break;
			int ta = a, tb = b, tc = c, td = d;
			a = tb;
			b = ta;
			c = td - 1;
			d = tc + 1;
		}
		if (b == 0 && d == 0) {
			mn = min(mn, i + 1);
		}
	}
	a = ca;
	b = cb;
	c = cc;
	d = cd;
	for (int i = 0; i <= n * 10; i++) {
		if (i % 2) {
			if (a == 0)
				break;
			int ta = a, tb = b, tc = c, td = d;
			a = tb + 1;
			b = ta - 1;
			c = td;
			d = tc;
		} else {
			if (d == 0)
				break;
			int ta = a, tb = b, tc = c, td = d;
			a = tb;
			b = ta;
			c = td - 1;
			d = tc + 1;
		}
		if (b == 0 && d == 0) {
			mn = min(mn, i + 1);
		}
	}
	cout << (mn == INT_MAX ? -1 : mn) << ' ';
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