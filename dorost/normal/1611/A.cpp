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
	int w = -1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] % 2 == 0) {
			w = i;
			break;
		}
	}
	if (s[s.size() - 1] % 2 == 0) {
		cout << 0 << ' ';
	} else if (w == 0) {
		cout << 1 << ' ';
	} else if (w != -1) {
		cout << 2 << ' ';
	} else {
		cout << -1 << ' ';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}