/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	cin >> n;
	if (n % 3 == 0) {
		for (int i = 0; i < n / 3; i++)
			cout << 21;
		cout << '\n';
	} else if (n % 3 == 1) {
		for (int i = 0; i < n / 3; i++)
			cout << 12;
		cout << 1;
		cout << '\n';
	} else {
		for (int i = 0; i < n / 3; i++)
			cout << 21;
		cout << 2;
		cout << '\n';
	}
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