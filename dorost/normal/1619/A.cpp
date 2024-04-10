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
	int n = s.size();
	if (n % 2) {
		cout << "NO\n";
		return;
	}
	n /= 2;
	for (int i = 0; i < n; i++) {
		if (s[i] != s[i + n]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}