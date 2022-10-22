/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

void solve() {
	int a, b;
	cin >> a >> b;
	if (b == 1) {
		cout << "NO\n";
	} else {
		cout << "YES\n" << a << ' ' << a * b * 2 - a << ' ' << a * b * 2 << '\n';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}