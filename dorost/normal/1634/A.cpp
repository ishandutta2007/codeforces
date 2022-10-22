/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	string t = s;
	reverse(t.begin(), t.end());
	if (t == s || k == 0) {
		cout << 1 << '\n';
	} else {
		cout << 2 << '\n';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}