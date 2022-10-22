/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int w, h, n;
	cin >> w >> h >> n;
	int ans = 1;
	while (w % 2 == 0) {
		w /= 2;
		ans *= 2;
	}
	while (h % 2 == 0) {
		h /= 2;
		ans *= 2;
	}
	cout << (ans >= n ? "YES" : "NO") << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}