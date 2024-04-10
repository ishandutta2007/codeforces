/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	cin >> n;
	n--;
	if (n % 2) {
		cout << n / 2 << ' ' << n / 2 + 1;
	} else {
		for (int i = 2; i < 10000; i++) {
			if (__gcd(i, n - i) == 1) {
				cout << i << ' ' << n - i;
				break;
			}
		}
	}
	cout << ' ' << 1 << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}