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
	int ans = 0;
	bool f = false, h = false;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (i == 0 || i == n - 1)
			continue;
		if (x % 2)
			f = true;
		if (x >= 2)
			h = true;
		ans += (x + 1) / 2;
	}
	if (n == 3) {
		cout << (f ? -1 : ans) << ' ';
	} else {
		cout << (f && !h ? -1 : ans) << ' ';
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}