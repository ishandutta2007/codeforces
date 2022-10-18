#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 5E5+8;

_ n, m, a[4][maxn], ta[maxn<<2], b[maxn], c[maxn];
struct rg {
	_ l, r, x;
	bool operator < (const rg &b) const {
		if(r != b.r) return r < b.r;
		return l < b.l;
	}
} r[maxn];
struct qr {
	_ x, y, c;
} t[maxn<<2];

qr query(_ L, _ R, _ l, _ r, _ pos);
void build(_ l, _ r, _ pos);
_ queryA(_ L, _ R, _ l, _ r, _ pos);
void updateA(_ l, _ r, _ c, _ k, _ pos);
void buildA(_ l, _ r, _ pos);
int main() {

	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= 3; ++i) for(_ j = 1; j <= n; ++j) {
		scanf("%lld", &a[i][j]);
		a[i][j] += a[i][j-1];
	}
	for(_ i = 1; i <= n; ++i) {
		b[i] = a[1][i]-a[2][i-1];
		c[i] = a[2][i]+a[3][n]-a[3][i-1];
//		printf("i = %lld, b = %lld, c = %lld\n", i, b[i], c[i]);
	}
	for(_ i = 1; i <= m; ++i) scanf("%lld%lld%lld", &r[i].l, &r[i].r, &r[i].x);
	sort(r+1, r+1+m);
	buildA(1, n, 1);
	for(_ i = 1; i <= m; ++i) if(r[i].r != n) {
		_ cr = queryA(r[i].l, r[i].r, 1, n, 1);
		updateA(1, n, r[i].r+1, cr-r[i].x, 1);
	}
	for(_ i = 1; i <= n; ++i) {
		b[i] = queryA(i, i, 1, n, 1);
//		printf("new b[%lld] = %lld\n", i, b[i]);
	}
	build(1, n, 1);
	_ s = -1E17;
	for(_ i = 1; i <= m; ++i) s = max(s, query(r[i].l, r[i].r, 1, n, 1).c-r[i].x);
	printf("%lld\n", s);

	return 0;
}

void pushUpA(_ pos) {
	ta[pos] = max(ta[pos<<1], ta[pos<<1|1]);
	return;
}

void buildA(_ l, _ r, _ pos) {
	if(l == r) {
		ta[pos] = b[l];
		return;
	}
	_ md = (l+r)>>1;
	buildA(l, md, pos<<1);
	buildA(md+1, r, pos<<1|1);
	pushUpA(pos);
	return;
}

void updateA(_ l, _ r, _ c, _ k, _ pos) {
	if(l == r) {
		ta[pos] = max(ta[pos], k);
		return;
	}
	_ md = (l+r)>>1;
	if(c <= md) updateA(l, md, c, k, pos<<1);
	else updateA(md+1, r, c, k, pos<<1|1);
	pushUpA(pos);
	return;
}

_ queryA(_ L, _ R, _ l, _ r, _ pos) {
	if(L <= l && r <= R) return ta[pos];
	_ md = (l+r)>>1, rv = -1E17;
	if(L <= md) rv = max(rv, queryA(L, R, l, md, pos<<1));
	if(R > md) rv = max(rv, queryA(L, R, md+1, r, pos<<1|1));
	return rv;
}

qr merge(qr x, qr y) {
	qr rv;
	rv.c = max({x.c, y.c, x.x+y.y});
	rv.x = max(x.x, y.x);
	rv.y = max(x.y, y.y);
	return rv;
}

void pushUp(_ pos) {
	t[pos] = merge(t[pos<<1], t[pos<<1|1]);
}

void build(_ l, _ r, _ pos) {
	if(l == r) {
		t[pos] = (qr){b[l], c[l], b[l]+c[l]};
		return;
	}
	_ md = (l+r)>>1;
	build(l, md, pos<<1);
	build(md+1, r, pos<<1|1);
	pushUp(pos);
	return;
}

qr query(_ L, _ R, _ l, _ r, _ pos) {
	if(L <= l && r <= R) return t[pos];
	_ md = (l+r)>>1;
	if(L <= md && R > md) return merge(query(L, R, l, md, pos<<1), query(L, R, md+1, r, pos<<1|1));
	ef(L <= md) return query(L, R, l, md, pos<<1);
	else return query(L, R, md+1, r, pos<<1|1);
}


/*
5 2
-20 -10 -11 -10 1
1 3 3 6 3
14 -20 3 6 2
1 2 2
3 5 3
*/