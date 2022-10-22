/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int r, g, b, a;
	cin >> r >> g >> b >> a;
	int ans = r % 2 + g % 2 + b % 2 + a % 2;
	if (ans < 2) {
		cout << "YES\n";
		return;
	}
	r--;
	b--;
	g--;
	a += 3;
	ans = r % 2 + g % 2 + b % 2 + a % 2;
	if (ans < 2 && r >= 0 && g >= 0 && b >= 0) {
		cout << "YES\n";
		return;
	}
	cout << "No\n";
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}