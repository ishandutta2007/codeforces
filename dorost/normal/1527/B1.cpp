/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, z = 0;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0')
			z++;
	}
	if (n % 2 && s[n / 2] == '0') {
		z--;
		if (z == 0) {
			cout << "BOB\n";
		} else {
			cout << "ALICE\n";
		}
	} else {
		if (z % 4 == 0) {
			cout << "BOB\n";
		} else {
			cout << "BOB\n";
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}