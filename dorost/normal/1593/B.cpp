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
	int a5 = false, b5 = false, a0 = false, b7 = false, b0 = false, b2 = false;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == '5' && !a5)
			a5 = i;
		if (s[i] == '5' && a0 && !b5)
			b5 = i;
		if (s[i] == '0' && a0 && !b0)
			b0 = i;
		if (s[i] == '0' && !a0)
			a0 = i;
		if (s[i] == '2' && a5 && !b2)
			b2 = i;
		if (s[i] == '7' && a5 && !b7)
			b7 = i;
	}
	int x = max({b5, b2, b7, b0});
	cout << (int)s.size() - x - 2 << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}