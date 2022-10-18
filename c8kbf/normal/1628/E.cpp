#pragma G++ optimize("Ofast")
#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef int _;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

constant maxn = 3E5+8;
constant lg = 30+8;

_ n, m, x, y, z;
int f[lg][maxn], l[maxn], d[lg][maxn], h[maxn], t[maxn<<2], c[maxn<<2], lz[maxn<<2], dt[maxn<<2], dc[maxn<<2];
vector<_p> g[maxn];
queue<_> q;

inline _ read() {
	char ch = getchar();
	_ rv = 0;
	for(; !(ch >= '0' && ch <= '9'); ) ch = getchar();
	for(; ch >= '0' && ch <= '9'; ch = getchar()) rv = (rv<<3)+(rv<<1)+(ch^48);
	return rv;
}

inline void updres(_ L, _ R, _ l, _ r, _ pos);
inline void updset(_ L, _ R, _ l, _ r, _ pos);
inline _p query(_ L, _ R, _ l, _ r, _ pos);
inline void buildb(_ l, _ r, _ pos);
inline void builda(_ l, _ r, _ pos);
inline _p lca(_ x, _ y);
inline void bfs();
int main() {

	n = read();
	m = read();
	for(_ i = 2; i <= n; ++i) l[i] = l[i>>1]+1;
	for(_ i = n; --i; ) {
		x = read();
		y = read();
		z = read();
		g[x].push_back(make_pair(y, z));
		g[y].push_back(make_pair(x, z));
	}
	bfs();
	builda(1, n, 1);
	buildb(1, n, 1);
	for(; m--; ) {
		x = read();
		y = read();
		if(x != 3) z = read();
		if(x == 1) updset(y, z, 1, n, 1);
		ef(x == 2) updres(y, z, 1, n, 1);
		else {
			_p s = query(1, n, 1, n, 1);
//			printf("query is %lld %lld\n", s.first, s.second);
			printf("%d\n", max(s.first, lca(s.second, y).second));
		}
	}

	return 0;
}

inline void bfs() {
	q.push(1);
	for(; !q.empty(); q.pop()) {
		_ t = q.front();
		for(_p i : g[t]) if(i.first != f[0][t]) {
			h[i.first] = h[t]+1;
			f[0][i.first] = t;
			d[0][i.first] = i.second;
			for(_ j = 1; j <= l[h[i.first]]; ++j) {
				f[j][i.first] = f[j-1][f[j-1][i.first]];
				d[j][i.first] = max(d[j-1][i.first], d[j-1][f[j-1][i.first]]);
			}
			q.push(i.first);
		}
	}
	return;
}

inline _p lca(_ x, _ y) {
	if(!~x) return mp(y, -1);
	ef(!~y) return mp(x, -1);
	_ rv = -1;
	if(h[x] < h[y]) swap(x, y);
	for(; h[x] != h[y]; ) {
		rv = max(rv, d[l[h[x]-h[y]]][x]);
		x = f[l[h[x]-h[y]]][x];
	}
	if(x == y) return mp(x, rv);
	for(_ i = 30; i >= 0; --i) if(f[i][x] != f[i][y]) {
		rv = max(rv, max(d[i][x], d[i][y]));
		x = f[i][x];
		y = f[i][y];
	}
	rv = max(rv, max(d[0][x], d[0][y]));
	return mp(f[0][x], rv);
}

inline void pushUp(_ pos) {
	t[pos] = max(t[pos<<1], t[pos<<1|1]);
	_p l = lca(c[pos<<1], c[pos<<1|1]);
	t[pos] = max(t[pos], l.second);
	c[pos] = l.first;
	return;
}

inline void pushDown(_ pos) {
	if(!lz[pos]) {
		t[pos<<1] = t[pos<<1|1] = c[pos<<1] = c[pos<<1|1] = -1;
	} else {
		t[pos<<1] = dt[pos<<1];
		c[pos<<1] = dc[pos<<1];
		t[pos<<1|1] = dt[pos<<1|1];
		c[pos<<1|1] = dc[pos<<1|1];
	}
	lz[pos<<1] = lz[pos<<1|1] = lz[pos];
	lz[pos] = -1;
	return;
}

inline void builda(_ l, _ r, _ pos) {
	if(l == r) {
		t[pos] = -1;
		c[pos] = l;
		return;
	}
	_ md = (l+r)>>1;
	builda(l, md, pos<<1);
	builda(md+1, r, pos<<1|1);
	pushUp(pos);
	return;
}

inline void buildb(_ l, _ r, _ pos) {
	if(l != r) {
		_ md = (l+r)>>1;
		buildb(l, md, pos<<1);
		buildb(md+1, r, pos<<1|1);
	}
	dt[pos] = t[pos];
	dc[pos] = c[pos];
	t[pos] = c[pos] = lz[pos] = -1;
//	printf("initialized %lld\n", pos);
	return;
}

inline _p merge(_p x, _p y) {
	_p rv, l;
	rv.first = max(x.first, y.first);
	l = lca(x.second, y.second);
	rv.first = max(rv.first, l.second);
	rv.second = l.first;
	return rv;
}

inline _p query(_ L, _ R, _ l, _ r, _ pos) {
//	if(l == 1 && r == 1) printf("t at 1, 1 is %lld %lld\n", t[pos], c[pos]);
//	printf("query at L = %lld, R = %lld, l = %lld, r = %lld, pos = %lld, t[pos] = %lld, c[pos] = %lld\n", L, R, l, r, pos, t[pos], c[pos]);
	if(L <= l && r <= R) return mp(t[pos], c[pos]);
	_ md = (l+r)>>1;
	if(~lz[pos]) pushDown(pos);
	_p rv = mp(-1, -1);
	if(L <= md) rv = merge(rv, query(L, R, l, md, pos<<1));
	if(R > md) rv = merge(rv, query(L, R, md+1, r, pos<<1|1));
	return rv;
}

inline void updset(_ L, _ R, _ l, _ r, _ pos) {
	if(L <= l && r <= R) {
		t[pos] = dt[pos];
		c[pos] = dc[pos];
		lz[pos] = 1;
		return;
	}
	_ md = (l+r)>>1;
	if(~lz[pos]) pushDown(pos);
	if(L <= md) updset(L, R, l, md, pos<<1);
	if(R > md) updset(L, R, md+1, r, pos<<1|1);
	pushUp(pos);
	return;
}

inline void updres(_ L, _ R, _ l, _ r, _ pos) {
	if(L <= l && r <= R) {
		t[pos] = c[pos] = -1;
		lz[pos] = 0;
		return;
	}
	_ md = (l+r)>>1;
	if(~lz[pos]) pushDown(pos);
	if(L <= md) updres(L, R, l, md, pos<<1);
	if(R > md) updres(L, R, md+1, r, pos<<1|1);
	pushUp(pos);
	return;
}