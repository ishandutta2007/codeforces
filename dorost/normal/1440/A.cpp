/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, c0, c1, h;
	string s;
	cin >> n >> c0 >> c1 >> h >> s;
	int mn = INT_MAX;
	int x = 0;
	for (int i = 0; i < n; i++) {
		x += (s[i] == '0' ? c0 : c1);
	}
	mn = min(mn, x);
	x = 0;
	for (int i = 0; i < n; i++) {
		x += (s[i] == '0' ? h + c1 : c1);
	}
	mn = min(mn, x);
	x = 0;
	for (int i = 0; i < n; i++) {
		x += (s[i] == '0' ? c0 : c0 + h);
	}
	mn = min(mn, x);
	cout << mn << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}