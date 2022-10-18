#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 4E5+8;

_ n, m, b[maxn], c[maxn], s, cnt, x, y, dfn[maxn], low[maxn], cnum, d[maxn];
vector<_p> g[maxn];
stack<_> st;
bitset<maxn> v, u;
_p o[maxn], e[maxn];
vector<_> G[maxn];

void dfs2(_ x);
void dfs1(_ x, _ le);
void paint(_ x);
void tarjan(_ x, _ le);
int main() {
	
	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= m; ++i) {
		scanf("%lld%lld", &x, &y);
		g[x].push_back(mp(y, i));
		g[y].push_back(mp(x, i));
		e[i].first = x;
		e[i].second = y;
	}
	tarjan(1, -1);
	for(_ i = 1; i <= cnum; ++i) if(c[i] > c[s]) s = i;
	printf("%lld\n", c[s]);
	for(_ i = 1; i <= n; ++i) if(!u[b[i]]) {
		u.set(b[i]);
		dfs1(i, -1);
	}
	for(_ i = 1; i <= n; ++i) for(_p j : g[i]) if(b[i] != b[j.first]) G[b[i]].push_back(b[j.first]);
	v.reset();
	dfs2(s);
	for(_ i = 1; i <= m; ++i) if(!o[i].first) {
		if(d[b[e[i].first]] > d[b[e[i].second]]) o[i] = e[i];
		else o[i] = mp(e[i].second, e[i].first);
	}
	for(_ i = 1; i <= m; ++i) printf("%lld %lld\n", o[i].first, o[i].second);
	
	return 0;
}

void tarjan(_ x, _ le) {
	v.set(x);
	st.push(x);
	dfn[x] = low[x] = ++cnt;
	for(_p i : g[x]) if(!dfn[i.first]) {
		tarjan(i.first, i.second);
		low[x] = min(low[x], low[i.first]);
	} ef(i.second != le && v[i.first]) low[x] = min(low[x], dfn[i.first]);
	if(low[x] == dfn[x]) {
		++cnum;
		for(; !st.empty() && st.top() != x; ) paint(st.top());
		paint(x);
	}
	return;
}

void paint(_ x) {
	st.pop();
	v.reset(x);
	b[x] = cnum;
	++c[cnum];
	return;
}

void dfs1(_ x, _ le) {
	v.set(x);
	for(_p i : g[x]) if(b[x] == b[i.first] && i.second != le) {
		if(!v[i.first]) {
			dfs1(i.first, i.second);
			o[i.second] = mp(x, i.first);
		} else o[i.second] = mp(i.first, x);
	}
	return;
}

void dfs2(_ x) {
	v.set(x);
	for(_ i : G[x]) if(!v[i]) {
		d[i] = d[x]+1;
		dfs2(i);
	}
	return;
}