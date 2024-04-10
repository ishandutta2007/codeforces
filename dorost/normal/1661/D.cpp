/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 300300, L = 550, B = 546;
ll a[N], b[B];
ll c[B];

inline ll get (int i) {
	return a[i] + b[i / L] - (c[i / L] * (i % L));
}

inline void dec(int l, int r, ll k) {
	if (r - l + 1 <= L - 1) {
		for (int i = l; i <= r; i++) {
			a[i] -= (k * (i - l + 1));
		}
		return;
	}
	int sb = 0, eb = 0;
	for (int i = l;; i++) {
		if (i % L == 0) {
			sb = i / L;
			break;
		}
		if (a[i] <= 0)
			continue;
		a[i] -= (k * (i - l + 1));
	}
	for (int i = r;; i--) {
		if (i % L == L - 1) {
			eb = i / L;
			break;
		}
		if (a[i] <= 0)
			continue;
		a[i] -= (k * (i - l + 1));
	}
	for (int i = sb; i <= eb; i++) {
		c[i] += k;
		b[i] -= (k * ((i * L) - l + 1));
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ll ans = 0;
	for (int i = n - 1; i >= k; i--) {
		ll x = get(i);
		if (x <= 0)
			continue;
		dec(i - k + 1, i, ((x + k - 1) / k));
		ans += ((x + k - 1) / k);
	}
	ll mx = 0;
	for (int i = 0; i < k; i++) {
		mx = max(mx, (get(i) + i) / (i + 1));
	}
	cout << ans + mx;
}