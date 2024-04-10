/* In the name of GOD */

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 200012, SegN = 524300;
ll seg[SegN];
int fake[SegN], cnt[SegN], lz[SegN], q, d;
bool on[N];

void shift (int v) {
	if (lz[v]) {
		lz[v << 1] += lz[v];
		lz[v << 1 | 1] += lz[v];
		seg[v << 1] += (ll)cnt[v << 1] * lz[v];
		seg[v << 1 | 1] += (ll)cnt[v << 1 | 1] * lz[v];
		lz[v] = 0;
	}
}

int get_fake (int i, int v = 1, int tl = 0, int tr = N - 1) {
	if (tl == tr)
		return fake[v];
	int mid = (tl + tr) >> 1;
	if (i <= mid)
		return fake[v] + get_fake(i, v << 1, tl, mid);
	else
		return fake[v] + get_fake(i, v << 1 | 1, mid + 1, tr);
}

void add_fake (int l, int r, int x, int v = 1, int tl = 0, int tr = N - 1) {
	if (l > r)
		return;
	if (l == tl && r == tr)
		fake[v] += x;
	else {
		int mid = (tl + tr) >> 1;
		add_fake(l, min(r, mid), x, v << 1, tl, mid);
		add_fake(max(mid + 1, l), r, x, v << 1 | 1, mid + 1, tr);
	}
}

void add_cnt (int i, int x, int v = 1, int tl = 0, int tr = N - 1) {
	if (tl == tr)
		cnt[v] += x;
	else {
		int mid = (tl + tr) >> 1;
		shift(v);
		if (i <= mid)
			add_cnt(i, x, v << 1, tl, mid);
		else
			add_cnt(i, x, v << 1 | 1, mid + 1, tr);
		cnt[v] = cnt[v << 1] + cnt[v << 1 | 1];
	}
}

int get_cnt (int l, int r, int v = 1, int tl = 0, int tr = N - 1) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return cnt[v];
	int mid = (tl + tr) >> 1;
	return get_cnt(l, min(r, mid), v << 1, tl, mid) + get_cnt(max(mid + 1, l), r, v << 1 | 1, mid + 1, tr);
}

long long get (int l, int r, int v = 1, int tl = 0, int tr = N - 1) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return seg[v];
	int mid = (tl + tr) >> 1;
	shift(v);
	return get(l, min(r, mid), v << 1, tl, mid) + get(max(mid + 1, l), r, v << 1 | 1, mid + 1, tr);
}

void add (int l, int r, int x, int v = 1, int tl = 0, int tr = N - 1) {
	if (l > r)
		return;
	if (l == tl && r == tr) {
		lz[v] += x;
		seg[v] += (ll)cnt[v] * x;
		return;
	}
	int mid = (tl + tr) >> 1;
	shift(v);
	add (l, min(r, mid), x, v << 1, tl, mid);
	add (max(mid + 1, l), r, x, v << 1 | 1, mid + 1, tr);
	seg[v] = seg[v << 1] + seg[v << 1 | 1];
}

void seti (int i) {
	if (!on[i]) {
		add_cnt (i, 1);
		add (i, i, get_fake(i));
	} else {
		add (i, i, -get_fake(i));
		add_cnt (i, -1);
	}
	on[i] = !on[i];
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> q >> d;
	ll ans = 0;
	while (q--) {
		int a;
		cin >> a;
		int L = a + 1;
		int R = a + d;
		int LL = a - d;
		LL = max(LL, 0);
		int RR = a - 1;
		R = min(R, N - 1);
		if (on[a]) {
			ll x = get_cnt(LL, RR);
			ans -= (x * (x - 1)) / 2;
			x = get_cnt(L, R);
			ans -= (x * (x - 1)) / 2;
			ll wef = get(L, R);
			wef -= (x * (x + 1)) / 2;
			ans -= wef;
		} else {
			ll x = get_cnt(LL, RR);
			ans += (x * (x - 1)) / 2;
			x = get_cnt(L, R);
			ans += (x * (x - 1)) / 2;
			ll wef = get(L, R);
			wef -= (x * (x - 1)) / 2;
			ans += wef;
		}
		add(L, R, (on[a] ? -1 : 1));
		add_fake(L, R, (on[a] ? -1 : 1));
		seti(a);
		cout << ans << '\n';
	}
}