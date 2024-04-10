/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

bool ok(int x, int n) {
	return (x >= 0 && x < n);
}

void solve() {
	int n, x;
	string s;
	cin >> s >> x;
	n = s.size();
	string a, g;
	for (int i = 0; i < n; i++)
		a += '1', g += '0';
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			if (ok(i - x, n))
				a[i - x] = '0';
			if (ok(i + x, n))
				a[i + x] = '0';
		}
	}
	bool f = true;
	for (int i = 0; i < n; i++) {
		if (a[i] == '1') {
			if (ok(i - x, n))
				g[i - x] = '1';
			if (ok(i + x, n))
				g[i + x] = '1';
		}
	}
	f = (g == s);
	if (f)
		cout << a << '\n';
	else
		cout << "-1\n";
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}