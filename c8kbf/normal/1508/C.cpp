#include <bits/stdc++.h>
#define mp make_pair
#define ef else if

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 2E5+8;

set<_> st, g[maxn];
_ n, m, x, y, c, sm, us;
struct edge {
	_ x, y, c;
	bool operator < (const edge &b) const {
		return c < b.c;
	}
};
vector<edge> ed;
struct dsu {
	_ dt[maxn];
	void init() {
		for(_ i = 1; i <= n; ++i) dt[i] = i;
		return;
	}
	_ find(_ x) {
		return dt[x] == x ? x : dt[x] = find(dt[x]);
	}
	void merge(_ x, _ y) {
		dt[find(x)] = find(y);
		return;
	}
	bool test(_ x, _ y) {
		return find(x) == find(y);
	}
} a, b;

void dfs(_ x);
int main() {

	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= n; ++i) st.insert(i);
	for(_ i = 1; i <= m; ++i) {
		scanf("%lld%lld%lld", &x, &y, &c);
		g[x].insert(y);
		g[y].insert(x);
		ed.push_back((edge){x, y, c});
		sm ^= c;
	}
	sort(ed.begin(), ed.end());
	a.init();
	b.init();
	for(_ i = 1; i <= n; ++i) dfs(i);
	_ ct = 0, ad = sm;
	for(edge i : ed) if(!a.test(i.x, i.y)) {
//		printf("stage 2 merged %lld %lld\n", i.x, i.y);
		a.merge(i.x, i.y);
		b.merge(i.x, i.y);
		ct += i.c;
	}
	if(us != ((n*(n-1))>>1)-m) printf("%lld\n", ct);
	else {
//		puts("no cycle found...");
		for(edge i : ed) if(!b.test(i.x, i.y)) ad = min(ad, i.c);
		printf("%lld\n", ct+ad);
	}

	return 0;
}

void dfs(_ x) {
	st.erase(x);
	_ t = 0;
	for(set<_>::iterator it = st.upper_bound(t); it != st.end(); it = st.upper_bound(t)) {
		t = *it;
		if(g[x].count(t)) continue;
		a.merge(x, t);
		++us;
		dfs(t);
	}
	return;
}