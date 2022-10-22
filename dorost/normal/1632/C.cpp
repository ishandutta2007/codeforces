/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int a, b, a2, b2;
	cin >> a2 >> b2;
	a = a2;
	b = b2;
	int mn = abs(a - b);
	for (int i = 0;; i++) {
		if ((a | b) == b) {
			mn = min(mn, i + 1);
			break;
		}
		b++;
	}
	a = a2;
	b = b2;
	for (int i = 0;; i++) {
		if ((a | b) == b) {
			mn = min(mn, i + 1);
			break;
		}
		a++;
	}
	cout << mn << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}