/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	string s;
	cin >> n >> s;
	bool f = false, h = false;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0')
			f = true;
		if (n % 2 == 0)
			h = true;
		if (i != n / 2 && s[i] == '0') 
			h = true;
	}
	if (!f) {
		cout << 1 << ' ' << n / 2 << ' ' << n / 2 + 1 << ' ' << n / 2 + n / 2 << '\n';
		return;
	}
	if (!h) {
		cout << 1 << ' ' << n / 2 << ' ' << n / 2 + 2 << ' ' << n << '\n';
		return;
	}
	for (int i = 0; i < n / 2; i++) {
		if (s[i] == '0') {
			cout << i + 1 << ' ' << n << ' ' << i + 2 << ' ' << n << '\n';
			return;
		}
	}
	for (int i = (n + 1) / 2; i < n; i++) {
		if (s[i] == '0') {
			cout << 1 << ' ' << i + 1 << ' ' << 1 << ' ' << i << '\n';
			return;
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