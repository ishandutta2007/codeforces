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
	if (n % 2 && k != 1) {
		cout << "NO\n";
		return;
	}
	cout << "Yes\n";
	int t1 = 1, t2 = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (i % 2 == 0) {
				cout << t1 << ' ';
				t1 += 2;
			} else {
				cout << t2 << ' ';
				t2 += 2;
			}
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