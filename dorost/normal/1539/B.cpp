/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], ps[N];

void solve() {
	int n, q;
	string s;
	cin >> n >> q >> s;
	for (int i = 0; i < n; i++) {
		a[i + 1] = s[i] - 'a' + 1;
	}
	ps[0] = a[0];
	for (int i = 1; i <= n; i++) {
		ps[i] = ps[i - 1] + a[i];
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << ps[r] - ps[l - 1] << ' ';
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