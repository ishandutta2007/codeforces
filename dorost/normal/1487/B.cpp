/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

void solve() {
	int n, k;
	cin >> n >> k;
	if (n % 2 == 0) {
		cout << (k - 1) % n + 1 << ' ';
	} else {
		cout << ((k - 1) % n + ((k - 1) / (n / 2))) % n + 1 << ' ';
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}