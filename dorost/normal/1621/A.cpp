/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, k;
	cin >> n >> k;
	if (k > (n + 1) / 2) {
		cout << -1 << '\n';
	} else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j && i % 2 == 0 && k) {
					cout << 'R', k--;
				} else
					cout << '.';
			}
			cout << '\n';
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