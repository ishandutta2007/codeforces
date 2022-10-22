/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	string s;
	cin >> s;
	int x = 1000000, y = 0, t = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			t++;
			x = min(x, i);
			y = max(y, i);
		}
	}
	if (t == 0) {
		cout << 0 << ' ';
	} else if (t == y - x + 1) {
		cout << 1 << ' ';
	} else {
		cout << 2 << ' ';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}