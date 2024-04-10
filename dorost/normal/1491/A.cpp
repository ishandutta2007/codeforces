/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
bool f[N];

void solve() {
	int n, q, x = 0, y = 0;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> f[i];
		if (f[i])
			x++;
		else
			y++;
	}
	while (q--) {
		int t, a;
		cin >> t >> a;
		if (t == 1) {
			if (f[a - 1]) {
				x--;
				y++;
			} else {
				x++;
				y--;
			}
			f[a - 1] = !f[a - 1];
		} else {
			cout << (a <= x ? 1 : 0) << '\n';
		}
	}
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}