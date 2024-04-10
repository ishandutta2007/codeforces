/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N];

void solve() {
	int n, q, k;
	cin >> n >> q >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		int x = a[r] - a[l] - 1 - (r - l - 1);
		cout << x * 2 + k - a[r] + a[l] - 1 << ' ';
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}