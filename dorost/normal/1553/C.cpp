/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

int tak(string x) {
	int a = 0, b = 0;
	for (int i = 0; i < 10; i++) {
		int l = 0;
		if (x[i] == '1')
			l = 1;
		if (i % 2 == 0) {
			a += l;
		} else {
			b += l;
		}
		int aa = max(a, b), bb = min(a, b);
		if (aa > bb + (9 - i + (a > b)) / 2) {
			return i + 1;
		}
	}
	return 10;
}

void solve() {
	string s;
	cin >> s;
	string t = s, r = s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '?') {
			if (i % 2 == 0) {
				t[i] = '1';
				r[i] = '0';
			} else {
				t[i] = '0';
				r[i] = '1';
			}
		} else {
			t[i] = s[i];
			r[i] = s[i];
		}
	}
	cout << min(tak(t), tak(r)) << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}