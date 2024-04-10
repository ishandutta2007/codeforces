/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, m;
	cin >> n >> m;
	if (m <= 1) {
		cout << 1;
		return;
	}
	if (m == n) {
		cout << 0;
		return;
	}
	if (m < (n + 1) / 2) {
		cout << m;
	}else {
		cout << n - m;
	}
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}