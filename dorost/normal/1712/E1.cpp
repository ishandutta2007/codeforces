/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 2 * 2 * 1069 * 100;
vector <int> divs[N];

ll C2 (int x) {
	return ((ll)x * (ll)(x - 1)) / 2LL;
}

void solve() {
	int l, r;
	cin >> l >> r;
	for (int i = 0; i < N; i++)
		divs[i].clear();
	for (int i = l; i <= r; i++) 
		for (int j = i * 2; j <= r * 2; j += i) 
			divs[j].push_back(i);
	ll k1 = 0, k2 = 0;
	for (int k = l; k <= r; k++) {
		k1 += C2((int)divs[k].size());
		k2 -= C2((int)divs[k].size());
		k2 += C2((int)divs[k * 2].size() - 1);
	}
	ll ans = ((ll)(r - l + 1) * (ll)(r - l) * (ll)(r - l - 1)) / 6LL - k1 - k2;
	for (int k = l; k <= r; k++) {
		for (int in = 0; in < (int)divs[k * 2].size(); in++) {
			int i = divs[k * 2][in];
			int in2 = upper_bound(divs[k * 2].begin(), divs[k * 2].end(), k - i) - divs[k * 2].begin() - 1;
			ans += max(in2 - in, 0);
		}
	}
	ans -= k1;
	cout << ans << '\n';
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