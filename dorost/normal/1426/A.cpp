/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, x;
	cin >> n >> x;
	if (n <= 2) {
		cout << 1 << '\n';
		return;
	}
	n -= 3;
	cout << n / x + 2 << '\n';;
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}