/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int s;
	cin >> s;
	int n = 0;
	for (int i = 1; ; i += 2) {
		s -= i;
		n++;
		if (s <= 0) {
			cout << n << ' ';
			return;
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