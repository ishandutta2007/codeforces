/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 100012, SegN = 262200, C = 20;
int seg[C][SegN];
bool lz[C][SegN];
int a[N];

void shift (int i, int v, int tl, int mid, int tr) {
	if (lz[i][v]) {
		lz[i][v] = 0;
		lz[i][v << 1] ^= 1;
		lz[i][v << 1 | 1] ^= 1;
		seg[i][v << 1] = (mid - tl + 1) - seg[i][v << 1];
		seg[i][v << 1 | 1] = (tr - mid) - seg[i][v << 1 | 1];
	}
}

void build (int i, int v = 1, int tl = 0, int tr = N - 1) {
	if (tl == tr) {
		seg[i][v] = (a[tl] >> i) & 1;
	} else {
		int mid = (tl + tr) >> 1;
		build (i, v << 1, tl, mid);
		build (i, v << 1 | 1, mid + 1, tr);
		seg[i][v] = seg[i][v << 1] + seg[i][v << 1 | 1];
	}
}

void upd (int i, int l, int r, int v = 1, int tl = 0, int tr = N - 1) {
	if (l > r)
		return;
	if (l == tl && r == tr) {
		lz[i][v] ^= 1;
		seg[i][v] = (r - l + 1) - seg[i][v];
		return;
	}
	int mid = (tl + tr) >> 1;
	shift (i, v, tl, mid, tr);
	upd (i, l, min(r, mid), v << 1, tl, mid);
	upd (i, max(l, mid + 1), r, v << 1 | 1, mid + 1, tr);
	seg[i][v] = seg[i][v << 1] + seg[i][v << 1 | 1];
}

int get (int i, int l, int r, int v = 1, int tl = 0, int tr = N - 1) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return seg[i][v];
	int mid = (tl + tr) >> 1;
	shift (i, v, tl, mid, tr);
	return get(i, l, min(r, mid), v << 1, tl, mid) + get(i, max(l, mid + 1), r, v << 1 | 1, mid + 1, tr);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < C; i++)
		build(i);
	int q;
	cin >> q;
	while (q--) {
		int t, l, r;
		cin >> t >> l >> r;
		--l, --r;
		if (t == 1) {
			ll ans = 0;
			for (int i = 0; i < C; i++) 
				ans += (1LL << i) * get (i, l, r);
			cout << ans << '\n';
		} else {
			int x;
			cin >> x;
			for (int i = 0; i < C; i++) {
				if ((x >> i) & 1)
					upd (i, l, r);
			}
		}
	}
}