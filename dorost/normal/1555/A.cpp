/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

void solve() {
	int n;
	cin >> n;
	int mn = LLONG_MAX;
	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 10; j++) {
			int a = max(0LL, n - i * 6 - j * 8);
			int b = i * 15 + j * 20 + (a + 9) / 10 * 25;
			mn = min(mn, b);
		}
	}
	cout << mn << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}