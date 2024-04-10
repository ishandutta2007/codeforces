/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
bool f[N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		b--;
		f[b] = true;
	}
	int x = 0;
	for (int i = 0; i < n; i++) {
		if (!f[i]) {
			x = i;
		} else {
			f[i] = false;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i != x) {
			cout << i + 1 << ' ' << x + 1 << '\n';
		}
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}