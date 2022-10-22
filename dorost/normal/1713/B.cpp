/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
pair <int, int> p[N];

void solve() {
	int mn = INT_MAX, mx = INT_MIN;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].F;
		p[i].S = i;
	}
	bool f = true;
	sort(p, p + n);
	reverse(p, p + n);
	for (int i = 0; i < n; i++) {
		mn = min(mn, p[i].S);
		mx = max(mx, p[i].S);
		if (i == n - 1 || p[i].F != p[i + 1].F)
			f &= ((mx - mn) == i);
	}
	cout << (f ? "YES" : "NO") << '\n';
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