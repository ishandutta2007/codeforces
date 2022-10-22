/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int x;
	cin >> x;
	int b = 1, c = 2, ans = 1;
	while (b < x) {
		b += c;
		c++;
		ans++;
	}
	cout << ans + ((b - x) == 1) << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}