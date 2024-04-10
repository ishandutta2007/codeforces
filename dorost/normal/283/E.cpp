/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234, SegN = (1 << 18);
int seg[SegN], s[N];
bool lz[SegN];
vector <int> st[N], en[N];

void shift (int v, int tl, int tr, int mid) {
	if (!lz[v])
		return;
	lz[v << 1] ^= 1;
	lz[v << 1 | 1] ^= 1;
	seg[v << 1] = mid - tl + 1 - seg[v << 1];
	seg[v << 1 | 1] = tr - mid - seg[v << 1 | 1];
	lz[v] = 0;
}

void upd (int l, int r, int v = 1, int tl = 0, int tr = N - 1) {
	if (r < tl || tr < l) 
		return;
	if (l <= tl && tr <= r) {
		lz[v] ^= 1;
		seg[v] = tr - tl + 1 - seg[v];
	} else {
		int mid = (tl + tr) >> 1;
		shift(v, tl, tr, mid);
		upd (l, r, v << 1, tl, mid);
		upd (l, r, v << 1 | 1, mid + 1, tr);
		seg[v] = seg[v << 1] + seg[v << 1 | 1];
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	sort(s, s + n);
	for (int i = 0; i < k; i++) {
		int L, R, l, r;
		cin >> L >> R;
		l = lower_bound(s, s + n, L) - s;
		r = upper_bound(s, s + n, R) - s - 1;
		if (l < r) {
			st[l].push_back(r);
			en[r].push_back(l);
		}
	}
	ll ans = ((ll)n * (ll)(n - 1) * (ll)(n - 2)) / 6LL;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (i) 
			for (int l : en[i - 1])
				upd (l, i - 1), cnt ^= 1;
		for (int r : st[i])
			upd (i, r), cnt ^= 1;
		if (i)
			upd (0, i - 1);
		int x = seg[1] - cnt;
		if (i)
			upd (0, i - 1);
		ans -= (ll)x * (ll)(x - 1) / 2LL;
	}
	cout << ans;
}