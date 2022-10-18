#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

constant maxn = 5E5+8;
constant maxm = 1E5+8;
constant big = 300+8;
constant maxl = 500+8;

_ n, m, cnt, d[maxn], ct, s = -1;
struct qr {
	v_ g;
	_ x;
	inline bool operator < (const qr &b) const {
		return x < b.x;
	}
} a[maxn];
bitset<maxm> b[maxl];
v_ g[maxn];
map<_, _> mp;

int main() {

	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= n; ++i) {
		for(_ j = m; j--; ) {
			_ x;
			scanf("%lld", &x);
			a[i].g.push_back(x);
			d[++cnt] = x;
		}
		scanf("%lld", &a[i].x);
	}
	sort(a+1, a+1+n);
	sort(d+1, d+1+cnt);
	cnt = unique(d+1, d+1+cnt)-d-1;
	for(_ i = 1; i <= n; ++i) for(_ &j : a[i].g) {
		j = lower_bound(d+1, d+1+cnt, j)-d;
		g[j].push_back(i);
	}
	for(_ i = 1; i <= cnt; ++i) if(g[i].size() > big) {
		mp[i] = ++ct;
		b[ct].set();
		for(_ j : g[i]) b[ct].reset(j);
	}
	for(_ i = 1; i <= n; ++i) {
		bitset<maxm> t;
		t.set();
		for(_ j : a[i].g) if(g[j].size() > big) t &= b[mp[j]];
		else for(_ k : g[j]) t.reset(k);
		t.reset(0);
		_ fs = t._Find_first();
		if(fs <= n) {
//			printf("i = %lld, fs = %lld\n", i, fs);
			_ c = a[i].x+a[fs].x;
			s = !~s ? c : min(s, c);
		}
	}
	printf("%lld\n", s);


	return 0;
}