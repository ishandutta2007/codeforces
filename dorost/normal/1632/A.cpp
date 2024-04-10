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
	if (n >= 3) {
		cout << "NO\n";
	} else if (n == 1 || (n == 2 && s[0] != s[1])) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}