#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef long double _D;
typedef const long long constant;

constant maxn = 1E5+8;
constant maxm = 1E4+8;

_ n, m;
struct qr {
	_ x, y, l, r;
} a[maxn];
_p b[maxm];
_D t[maxm<<2], lz[maxm<<2];

void update(_ L, _ R, _ l, _ r, _ pos, _D c);
void build(_ l, _ r, _ pos);
void pushDown(_ pos);
void pushUp(_ pos);
int main() {
	
	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= n; ++i) scanf("%lld%lld%lld%lld", &a[i].x, &a[i].y, &a[i].l, &a[i].r);
	for(_ i = 1; i <= m; ++i) scanf("%lld%lld", &b[i].first, &b[i].second);
	sort(b+1, b+1+m);
	build(1, m, 1);
		for(_ i = 1; i <= n; ++i) {
		_ l = lower_bound(b+1, b+1+m, mp(a[i].x+1, -1LL))-b, r = lower_bound(b+1, b+1+m, mp(a[i].x+a[i].y+1, -1LL))-b-1;
		update(l, r, 1, m, 1, 1-a[i].r/100.L);
		l = lower_bound(b+1, b+1+m, mp(a[i].x-a[i].y, -1LL))-b, r = lower_bound(b+1, b+1+m, mp(a[i].x, -1LL))-b-1;
		update(l, r, 1, m, 1, 1-a[i].l/100.L);
	}
	printf("%.20Lf\n", t[1]);
	
	return 0;
}

void pushUp(_ pos) {
	t[pos] = t[pos<<1] + t[pos<<1|1];
	return;
}

void pushDown(_ pos) {
	t[pos<<1] *= lz[pos];
	t[pos<<1|1] *= lz[pos];
	lz[pos<<1] *= lz[pos];
	lz[pos<<1|1] *= lz[pos];
	lz[pos] = 1;
	return;
}

void build(_ l, _ r, _ pos) {
	lz[pos] = 1;
	if(l == r) {
		t[pos] = b[l].second;
		return;
	}
	_ md = (l+r)>>1;
	build(l, md, pos<<1);
	build(md+1, r, pos<<1|1);
	pushUp(pos);
	return;
}

void update(_ L, _ R, _ l, _ r, _ pos, _D c) {
	if(L > R || L <= 0 || R > m) return;
	if(L <= l && r <= R) {
		t[pos] *= c;
		lz[pos] *= c;
		return;
	}
	_ md = (l+r)>>1;
	if(lz[pos] != 1) pushDown(pos);
	if(L <= md) update(L, R, l, md, pos<<1, c);
	if(R > md) update(L, R, md+1, r, pos<<1|1, c);
	pushUp(pos);
	return;
}