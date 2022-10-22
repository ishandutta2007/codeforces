/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, k1, k2, w, b;
	cin >> n >> k1 >> k2 >> w >> b;
	int x = min(k1, k2), y = min(n - k1, n - k2), z = abs(k1 - k2);
	cout << (w <= x + z / 2 && b <= y + z / 2 ? "YES" : "NO") << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}