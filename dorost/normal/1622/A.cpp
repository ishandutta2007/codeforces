/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int l1, l2, l3;
	cin >> l1 >> l2 >> l3;
	if (l1 == l2 && l3 % 2 == 0) {
		cout << "YES";
	} else if (l3 == l1 + l2) {
		cout << "YES";
	} else {
		if (l1 == l3 && l2 % 2 == 0) {
			cout << "YES";
		} else if (l2 == l1 + l3) {
			cout << "YES";
		} else {
			if (l2 == l3 && l1 % 2 == 0) {
				cout << "YES";
			} else if (l1 == l3 + l2) {
				cout << "YES";
			} else {
				cout << "NO";
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