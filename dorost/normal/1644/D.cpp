/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234, M = 998244353;
int x[N], y[N];
bool a[N], b[N];

int tav(int x, int n) {
	if (n == 0)
		return 1;
	ll ans = tav(x, n / 2);
	ans = ans * ans;
	ans %= M;
	if (n % 2) {
		ans *= x;
		ans %= M;
	}
	return ans;
}

void solve() {
	int n, m, k, q, ans = 0;
	cin >> n >> m >> k >> q;
	for (int i = 0; i < q; i++) {
		cin >> x[i] >> y[i];
		a[x[i]] = false;
		b[y[i]] = false;
	}
	int sat = 0, sot = 0;
	for (int i = q - 1; i >= 0; i--) {
		bool f = (a[x[i]]) || (sot == m);
		bool h = (b[y[i]]) || (sat == n);
		if (!a[x[i]])
			sat++;
		a[x[i]] = true;
		if (!b[y[i]])
			sot++;
		b[y[i]] = true;
		if (!f || !h) {
			ans++;
		}
	}
	cout << tav(k, ans) << ' ';
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