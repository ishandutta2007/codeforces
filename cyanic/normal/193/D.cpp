#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid ((l + r) >> 1)
using namespace std;

const int maxn = 300009;
struct segment {
	int mn1, mn2, cnt1, cnt2, lazy;
	int init(int _mn1, int _mn2) {
		mn1 = _mn1; mn2 = _mn2;
		lazy = cnt1 = cnt2 = 0;
	}
} T[maxn<<2], tmp;
int p[maxn], cur[maxn], n, a, b;
long long ans;

segment merge(segment L, segment R) {
	int mn1 = L.mn1, mn2 = L.mn2;
	if (R.mn1 < mn1) { mn2 = mn1; mn1 = R.mn1;}
	else if (R.mn1 < mn2 && R.mn1 != mn1) mn2 = R.mn1;
	if (R.mn2 < mn2) mn2 = R.mn2;
	segment res; res.init(mn1, mn2);
	res.cnt1 += (res.mn1 == L.mn1) * L.cnt1;
	res.cnt1 += (res.mn1 == L.mn2) * L.cnt2;
	res.cnt1 += (res.mn1 == R.mn1) * R.cnt1;
	res.cnt1 += (res.mn1 == R.mn2) * R.cnt2;
	res.cnt2 += (res.mn2 == L.mn1) * L.cnt1;
	res.cnt2 += (res.mn2 == L.mn2) * L.cnt2;
	res.cnt2 += (res.mn2 == R.mn1) * R.cnt1;
	res.cnt2 += (res.mn2 == R.mn2) * R.cnt2;
	return res;
}

int build(int o, int l, int r) {
	if (l == r) return T[o].mn2 = maxn, T[o].cnt1 = 1;
	build(lc, l, mid); build(rc, mid+1, r);
	T[o] = merge(T[lc], T[rc]);
}

void pushdown(int o) {
	T[lc].mn1 += T[o].lazy; T[lc].mn2 += T[o].lazy; T[lc].lazy += T[o].lazy;
	T[rc].mn1 += T[o].lazy; T[rc].mn2 += T[o].lazy; T[rc].lazy += T[o].lazy;
	T[o].lazy = 0;
}

int update(int o, int l, int r, int x, int y, int z) {
	if (l == x && y == r) return T[o].mn1 += z, T[o].mn2 += z, T[o].lazy += z;
	pushdown(o); 
	if (y <= mid) update(lc, l, mid, x, y, z);
	else if (mid+1 <= x) update(rc, mid+1, r, x, y, z);
	else update(lc, l, mid, x, mid, z), update(rc, mid+1, r, mid+1, y, z);
	T[o] = merge(T[lc], T[rc]);
}

segment query(int o, int l, int r, int x, int y) {
	if (l == x && y == r) return T[o]; pushdown(o);
	if (y <= mid) return query(lc, l, mid, x, y);
	if (mid+1 <= x) return query(rc, mid+1, r, x, y);
	return merge(query(lc, l, mid, x, mid), query(rc, mid+1, r, mid+1, y));
}

int main() {
	scanf("%d", &n);
	rep (i, 1, n) scanf("%d", &p[i]), cur[p[i]] = i;
	build(1, 1, n);
	rep (i, 1, n) {
		a = p[cur[i]-1]; b = p[cur[i]+1];
		a = !a ? n + 1 : a; b = !b ? n + 1 : b;
		if (a > i && b > i) update(1, 1, n, 1, i, 1);
		else if (b > i) update(1, 1, n, a + 1, i, 1);
		else if (a > i) update(1, 1, n, b + 1, i, 1);
		else update(1, 1, n, 1, min(a, b), -1), update(1, 1, n, max(a, b) + 1, i, 1);
		if (i == 1) continue; tmp = query(1, 1, n, 1, i-1);
		ans += (tmp.mn1 <= 2) * tmp.cnt1;
		ans += (tmp.mn2 <= 2) * tmp.cnt2;
	}
	printf("%I64d\n", ans);
	return 0;
}