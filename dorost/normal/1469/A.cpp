/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	string s;
	cin >> s;
	if (s.size() % 2 || s[0] == ')' || s[s.size() - 1] == '(') {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}