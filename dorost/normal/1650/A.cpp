/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	string s;
	char c;
	cin >> s >> c;
	for (int i = 0; i < s.size(); i += 2) {
		if (c == s[i]) {
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
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