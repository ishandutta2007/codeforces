#pragma G++ optimize("Ofast")
#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

constant maxn = 2E5+8;

_ n, m, a[maxn], b[maxn], t[maxn<<2], lz[maxn<<2], p, x, y, z;
struct qr {
	_ id, x, y;
};
vector<qr> sc, ns, q;
struct pr {
	_p x, y;
} ta[maxn<<2];

inline pr query(_ L, _ R, _ l, _ r, _ pos);
inline void buildb(_ l, _ r, _ pos);
inline void op(_ l, _ r, _ pos);
inline void update(_ L, _ R, _ l, _ r, _ c, _ pos);
inline void build(_ l, _ r, _ pos);
int main() {

	memset(b, 4, sizeof b);

	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= m; ++i) {
		scanf("%lld", &p);
		if(p) {
			scanf("%lld", &x);
			q.push_back((qr){i, x, -1});
		} else {
			scanf("%lld%lld%lld", &x, &y, &z);
			if(z) sc.push_back((qr){i, x, y});
			else ns.push_back((qr){i, x, y});
		}
	}
	build(1, n, 1);
	for(qr i : ns) {
		update(i.x, i.y, 1, n, i.id, 1);
//		printf("from %lld to %lld is not sick at time %lld\n", i.x, i.y, i.id);
	}
	op(1, n, 1);
//	for(_ i = 1; i <= n; ++i) printf("a[%lld] = %lld\n", i, a[i]);
	buildb(1, n, 1);
	for(qr i : sc) {
		pr t = query(i.x, i.y, 1, n, 1);
//		printf("query %lld to %lld gives {%lld, %lld}, {%lld, %lld}\n", i.x, i.y, t.x.first, t.x.second, t.y.first, t.y.second);
		b[t.x.second] = min(b[t.x.second], max(i.id, t.y.first));
	}
	for(qr i : q) {
		if(a[i.x] <= i.id) puts("NO");
		ef(b[i.x] <= i.id) puts("YES");
		else puts("N/A");
	}

	return 0;
}

inline void pushDown(_ pos) {
	t[pos<<1] = min(t[pos<<1], lz[pos]);
	t[pos<<1|1] = min(t[pos<<1|1], lz[pos]);
	lz[pos<<1] = min(lz[pos<<1], lz[pos]);
	lz[pos<<1|1] = min(lz[pos<<1|1], lz[pos]);
	return;
}

inline void build(_ l, _ r, _ pos) {
	t[pos] = lz[pos] = m+1;
	if(l == r) return;
	_ md = (l+r)>>1;
	build(l, md, pos<<1);
	build(md+1, r, pos<<1|1);
	return;
}

inline void update(_ L, _ R, _ l, _ r, _ c, _ pos) {
	if(L <= l && r <= R) {
		lz[pos] = min(lz[pos], c);
		t[pos] = min(t[pos], c);
		return;
	}
	_ md = (l+r)>>1;
	pushDown(pos);
	if(L <= md) update(L, R, l, md, c, pos<<1);
	if(R > md) update(L, R, md+1, r, c, pos<<1|1);
	return;
}

inline void op(_ l, _ r, _ pos) {
	if(l == r) {
		a[l] = t[pos];
		return;
	}
	_ md = (l+r)>>1;
	pushDown(pos);
	op(l, md, pos<<1);
	op(md+1, r, pos<<1|1);
	return;
}

inline pr merge(pr x, pr y) {
	if(x.x >= y.x) return (pr){x.x, max(x.y, y.x)};
	else return (pr){y.x, max(y.y, x.x)};
}

inline void pushUp(_ pos) {
	ta[pos] = merge(ta[pos<<1], ta[pos<<1|1]);
	return;
}

inline void buildb(_ l, _ r, _ pos) {
	if(l == r) {
		ta[pos] = (pr){mp(a[l], l), mp(0, -1)};
		return;
	}
	_ md = (l+r)>>1;
	buildb(l, md, pos<<1);
	buildb(md+1, r, pos<<1|1);
	pushUp(pos);
	return;
}

inline pr query(_ L, _ R, _ l, _ r, _ pos) {
	if(L <= l && r <= R) return ta[pos];
	_ md = (l+r)>>1;
	pr rv = (pr){mp(-1, -1), mp(-1, -1)};
	if(L <= md) rv = merge(rv, query(L, R, l, md, pos<<1));
	if(R > md) rv = merge(rv, query(L, R, md+1, r, pos<<1|1));
	return rv;
}