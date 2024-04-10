#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef long double _D;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

constant maxn = 3E5+8;

_ n, m, x, y, z, f[maxn], cnt, cnum, dfn[maxn], low[maxn], a[maxn], c[maxn], b[maxn];
v_ g[maxn];
set<_> h[maxn];
stack<_> st;
bitset<maxn> v;

void art(_ x, _ fa, bool ts);
void paint(_ x);
void dfs(_ x, _ fa);
_ find(_ x);
int main() {

	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= n; ++i) f[i] = i;
	for(; m--; ) {
		scanf("%lld%lld%lld", &x, &y, &z);
		g[x].push_back(y);
		g[y].push_back(x);
		if(z) f[find(x)] = find(y);
	}
	for(_ i = 1; i <= n; ++i) if(!dfn[i]) dfs(i, -1);
	for(_ i = 1; i <= n; ++i) for(_ j : g[i]) if(c[i] != c[j]) h[c[i]].insert(c[j]);
//	for(_ i = 1; i <= n; ++i) printf("c[%lld] = %lld\n", i, c[i]);
//	for(_ i = 1; i <= n; ++i) printf("find[%lld] = %lld\n", i, find(i));
//	for(_ i = 1; i <= cnum; ++i) printf("b[%lld] = %lld\n", i, b[i]);
	scanf("%lld%lld", &x, &y);
	art(c[x], -1, false);

	return 0;
}

_ find(_ x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

void dfs(_ x, _ fa) {
	v.set(x);
	st.push(x);
	dfn[x] = low[x] = ++cnt;
	for(_ i : g[x]) if(i != fa) {
		if(!dfn[i]) {
			dfs(i, x);
			low[x] = min(low[x], low[i]);
		} ef(v[i]) low[x] = min(low[x], dfn[i]);
	}
//	printf("x = %lld, low[x] = %lld, dfn[x] = %lld\n", x, low[x], dfn[x]);
	if(low[x] == dfn[x]) {
		++cnum;
		for(; st.top() != x; ) paint(st.top());
		paint(x);
	}
	return;
}

void paint(_ x) {
	c[x] = cnum;
	if(!a[cnum]) a[cnum] = x;
	else {
		if(find(x) == find(a[cnum])) b[cnum] = 1;
		else f[find(a[cnum])] = find(x);
	}
	st.pop();
	v.reset(x);
	return;
}

void art(_ x, _ fa, bool ts) {
	if(b[x]) ts = true;
	if(x == c[::y]) {
		puts(ts ? "YES" : "NO");
		return;
	}
	for(_ i : h[x]) if(i != fa) art(i, x, ts | (find(a[x]) == find(a[i])));
	return;
}