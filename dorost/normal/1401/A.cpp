/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, k;
	cin >> n >> k;
	int ans = 0;
	if (n <= k)
		cout << k - n << '\n';
	else
		cout << abs(k - n) % 2 << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}