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
	if (s[0] == s[s.size() - 1]) {
		cout << s << '\n';
	} else {
		s[0] = (s[0] == 'a' ? 'b' : 'a');
		cout << s << '\n';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}