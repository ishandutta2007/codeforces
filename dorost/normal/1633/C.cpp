/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

bool ok(int hc, int dc, int hm, int dm) {
	return ((hc + dm - 1) / dm) >= ((hm + dc - 1) / dc);
}

void solve() {
	int hc, dc, hm, dm;
	int k, w, a;
	cin >> hc >> dc >> hm >> dm >> k >> w >> a;
	bool f = false;
	for (int i = 0; i <= k; i++) {
		f |= ok(hc + (a * i), dc + (w * (k - i)), hm, dm);
	}
	cout << (f ? "YES" : "NO") << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}