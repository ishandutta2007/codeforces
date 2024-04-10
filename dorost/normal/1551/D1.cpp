/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	if (n % 2) {
		swap(n, m);
		k = (n * m) / 2 - k;
	}
	if (n == 1) {
		if (k == m / 2) {
			cout << "YES ";
		} else {
			cout << "NO ";
		}
		return;
	} 
	if (m == 1) {
		if (k == 0) {
			cout << "YES ";
		} else {
			cout << "NO ";
		}
		return;
	}
	if ((m % 2 + k % 2) == 0) {
		cout << "YES "; 
		return;
	}
	if (k > m / 2 * n) {
		cout << "NO ";
		return;
	}
	if (m % 2 == 0) {
		cout << "NO ";
		return;
	}
	if (k % 2 == 0) {
		cout << "YES ";
		return;
	}
	if (k % 2) {
		cout << "NO ";
		return;
	}
	assert(1);
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}