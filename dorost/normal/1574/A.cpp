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
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cout << '(';
		}
		for (int j = 0; j < i; j++) {
			cout << ')';
		}
		for (int j = 0; j < n - i; j++) {
			cout << '(';
		}
		for (int j = 0; j < n - i; j++) {
			cout << ')';
		}
		cout << '\n';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}