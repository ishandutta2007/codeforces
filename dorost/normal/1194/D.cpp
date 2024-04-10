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
	if (k == 3) {
		cout << (n % 4 ? "Alice" : "Bob");
	} else if (k % 3) {
		cout << (n % 3 ? "Alice" : "Bob");
	} else {
		if (n < k) {
			cout << (n % 3 ? "Alice" : "Bob");
		} else {
			if (((n % (k + 1)) % 3 == 0) && (n % (k + 1)) != k) {
				cout << "Bob";
			} else {
				cout << "Alice";
			}
		}
	}
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}