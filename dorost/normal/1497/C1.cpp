/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, k;
	cin >> n >> k;
	if (n % 4 == 0) {
		cout << n / 2 << ' ' << n / 4 << ' ' << n / 4 << '\n';
	} else if (n % 2) {
		cout << 1 << ' ' << n / 2 << ' ' << n / 2 << '\n';
	} else {
		cout << 2 << ' ' << n / 2 - 1 << ' ' << n / 2 - 1 << '\n';
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