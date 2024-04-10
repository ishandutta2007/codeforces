/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "9\n";
		return;
	} else if (n == 2) {
		cout << "98\n";
		return;
	}
	cout << 989;
	n -= 3;
	for (int i = 0; i < n; i++) {
		cout << ((i) % 10 + 10) % 10;
	}
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}