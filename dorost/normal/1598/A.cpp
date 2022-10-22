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
	bool f = true;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1' && t[i] == '1')
			f = false;
	}
	cout << (f ? "YES" : "NO") << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}