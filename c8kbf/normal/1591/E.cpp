
#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef long double _D;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef string str;
typedef const long long constant;

constant maxn = 1E6+8;

_ tc, n, m, a[maxn], o[maxn], p[maxn], ad, c[maxn], x, y, z;
v_ g[maxn];
struct qr {
	_ x, y, id;
};
vector<qr> q[maxn];
set<_> st[maxn];

void remove(_ x);
void insert(_ x);
void dfs(_ x);
int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld%lld", &n, &m);
		for(_ i = 1; i <= n; ++i) {
			g[i].clear();
			q[i].clear();
			st[i].clear();
			p[i] = c[i] = 0;
			scanf("%lld", &a[i]);
		}
		ad = 0;
		for(_ i = 2; i <= n; ++i) {
			scanf("%lld", &x);
			g[x].push_back(i);
		}
		for(_ i = 1; i <= m; ++i) {
			scanf("%lld%lld%lld", &x, &y, &z);
			q[x].push_back((qr){y, z, i});
		}
		dfs(1);
		for(_ i = 1; i <= m; ++i) printf("%lld ", o[i]);
		putchar(10);
	}

	return 0;
}

void dfs(_ x) {
	insert(a[x]);
	for(qr i : q[x]) {
//		printf("proessing %lld...\n", i.id);
//		for(_ i = 1; i <= n; ++i) printf("p[%lld] = %lld\n", i, p[i]+ad);
//		for(_ i = 1; i <= n; ++i) {
//			printf("st[%lld]: ", i);
//			for(_ j : st[i]) printf("%lld ", j);
//			putchar(10);
//		}
		_ l = i.x, r = n, md, s = -1, pl = i.x == 1 ? -ad : p[i.x-1];
		for(; l <= r; ) {
			md = (l+r)>>1;
			if(p[md]-pl >= i.y) {
				s = md;
				r = md-1;
			} else l = md+1;
		}
//		printf("s = %lld\n", s);
		o[i.id] = !~s ? -1 : *st[s].begin();
	}
	for(_ i : g[x]) dfs(i);
	remove(a[x]);
	return;
}

void insert(_ x) {
	if(!c[x]) {
		st[1].insert(x);
		++ad;
	} else {
		st[c[x]].erase(x);
		st[c[x]+1].insert(x);
		--p[c[x]];
	}
	++c[x];
	return;
}

void remove(_ x) {
	if(c[x] == 1) {
		st[1].erase(x);
		--ad;
	} else {
		st[c[x]].erase(x);
		st[c[x]-1].insert(x);
		++p[c[x]-1];
	}
	--c[x];
	return;
}