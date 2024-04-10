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
	for (auto x : {'r', 'g', 'b'}) {
		char y = (x + 'A' - 'a');
		for (int i = 0; i < 6; i++) 
			if (s[i] == y) {
				cout << "NO\n";
				return;
			} else if (s[i] == x)
				break;
	}
	cout << "YES\n";
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}