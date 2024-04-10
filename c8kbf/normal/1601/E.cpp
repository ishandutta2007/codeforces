#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

constant maxn = 3E5+8;

_ n, m, k, a[maxn], b[maxn], x, y, ct, c[maxn], t[maxn<<2], p[maxn<<2], d[maxn], f[maxn], dp[maxn], o[maxn];
multiset<_> st;
struct qr {
	_ id, x, y;
};
vector<qr> g[maxn];

bool cmp(_ x, _ y);
_p query(_ L, _ R, _ l, _ r, _ pos);
void update(_ l, _ r, _ c, _ k, _ pos);
void build(_ l, _ r, _ c, _ pos);
int main() {

	scanf("%lld%lld%lld", &n, &m, &k);
	for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for(_ i = n; i >= 1; --i) {
		if(i < n-k) st.erase(st.find(a[i+k+1]));
		st.insert(a[i]);
		b[i] = *st.begin();
	}
	for(_ i = 1; i <= m; ++i) {
		scanf("%lld%lld", &x, &y);
		if((y-x)/k) g[!(x%k) ? k : x%k].push_back((qr){i, (x-1)/k+1, (y-x)/k});
		o[i] += a[x];
//		printf("%lld\n", o[i]);
	}
	for(_ i = 1; i <= k; ++i) if(!g[i].empty()) {
		ct = 0;
		for(_ j = i; j <= n; j += k) c[++ct] = b[j];
//		printf("ct = %lld\n", ct);
//		for(_ j = 1; j <= ct; ++j) printf("c[%lld] = %lld\n", j, c[j]);
		build(1, ct, ct+1, 1);
		for(_ j = 1; j <= ct; ++j) f[j] = j;
		sort(f+1, f+1+ct, cmp);
//		for(_ j = 1; j <= ct; ++j) printf("f[%lld] = %lld\n", j, f[j]);
		for(_ j = 1; j <= ct; ++j) {
			d[f[j]] = query(f[j], ct, 1, ct, 1).first;
			update(1, ct, f[j], f[j], 1);
		}
//		for(_ j = 1; j <= ct; ++j) printf("d[%lld] = %lld\n", j, d[j]);
		dp[ct+1] = 0;
		for(_ j = ct; j >= 1; --j) dp[j] = dp[d[j]]+(d[j]-j)*c[j];
//		for(_ j = 1; j <= ct; ++j) printf("dp[%lld] = %lld\n", j, dp[j]);
		for(_ j = 1; j <= ct; ++j) update(1, ct, j, c[j], 1);
		for(qr j : g[i]) {
			_ dx = query(j.x, j.x+j.y, 1, ct, 1).second;
//			printf("j.x = %lld, j.y = %lld, dx = %lld\n", j.x, j.y, dx);
			o[j.id] += dp[j.x]-dp[dx]+(j.x+j.y-dx)*c[dx];
		}
	}
	for(_ i = 1; i <= m; ++i) printf("%lld\n", o[i]);

	return 0;
}

void pushUp(_ pos) {
	t[pos] = min(t[pos<<1], t[pos<<1|1]);
	if(t[pos] == t[pos<<1]) p[pos] = p[pos<<1];
	else p[pos] = p[pos<<1|1];
	return;
}

void build(_ l, _ r, _ c, _ pos) {
	if(l == r) {
		t[pos] = c;
		p[pos] = l;
		return;
	}
	_ md = (l+r)>>1;
	build(l, md, c, pos<<1);
	build(md+1, r, c, pos<<1|1);
	pushUp(pos);
	return;
}

void update(_ l, _ r, _ c, _ k, _ pos) {
	if(l == r) {
		t[pos] = k;
		return;
	}
	_ md = (l+r)>>1;
	if(c <= md) update(l, md, c, k, pos<<1);
	else update(md+1, r, c, k, pos<<1|1);
	pushUp(pos);
	return;
}

_p query(_ L, _ R, _ l, _ r, _ pos) {
	if(L <= l && r <= R) return mp(t[pos], p[pos]);
	_p rv = mp(1E17, -1);
	_ md = (l+r)>>1;
	if(L <= md) {
		_p c = query(L, R, l, md, pos<<1);
		if(c.first < rv.first) rv = c;
	}
	if(R > md) {
		_p c = query(L, R, md+1, r, pos<<1|1);
		if(c.first < rv.first) rv = c;
	}
	return rv;
}

bool cmp(_ x, _ y) {
	return c[x] < c[y];
}

/*
7 2 2
6 5 7 3 6 15 2
2 7
3 7

7 1 2
6 5 7 3 6 15 2
3 7

7 1 2
6 5 7 3 6 15 2
2 7

*/