/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, u, r, d, l;
	cin >> n >> u >> r >> d >> l;
	for (int i = 0; i < 16; i++) {
		int x = i;
		int a = x % 2;
		x /= 2;
		int b = x % 2;
		x /= 2;
		int c = x % 2;
		x /= 2;
		int d1 = x % 2;
		if (u >= a + b && d >= c + d1 && l >= a + c && r >= b + d1 && u <= (n - (2 - (a + b))) && d <= (n - (2 - (c + d1))) && l <= (n - (2 - (a + c))) && r <= (n - (2 - (b + d1)))) {
			cout << "YES ";
			return;
		}
	}
	cout << "NO "; 
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