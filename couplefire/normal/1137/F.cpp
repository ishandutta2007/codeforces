#include <bits/stdc++.h>
using namespace std;
template<class T> void cmax(T &x, const T &y) { x = (x > y) ? x : y; }

int n, m;
const int N = 5e5 + 5;
struct node_t {
	int l, r, c;
	node_t() {}
	node_t(int ll, int rr = -1, int cc = N) {
		l = ll, r = rr, c = cc;
	}
	bool operator <(const node_t &rhs) const {
		return l < rhs.l;
	}
};
set<node_t> *s[N], pool[N];
vector<int> g[N];
void add(int x, int y) {
	g[x].emplace_back(y);
	g[y].emplace_back(x);
}
int c[N];
int lowbit(int x) {
	return x & -x;
}
void upd(int x, int y) {
	while (x < N) {
		c[x] += y;
		x += lowbit(x);
	}
}
int query(int x) {
	int res = 0;
	while (x) {
		res += c[x];
		x ^= lowbit(x);
	}
	return res;
}
typedef set<node_t>::iterator IT;
IT split(set<node_t> *s, int pos) {
	auto it = s->lower_bound(node_t(pos));
	if(it != s->end() && it->l == pos) {
		return it;
	} else {
		--it; int l = it->l, r = it->r, c = it->c;
		s->erase(it), s->insert(node_t(l, pos - 1, c));
		return s->insert(node_t(pos, r, c)).first;
	}
}
int fa[N], dep[N], sz[N], son[N];
void dfs(int u) {
	sz[u] = 1; dep[u] = dep[fa[u]] + 1;
	for (auto v : g[u]) {
		if (v != fa[u]) {
			fa[v] = u; dfs(v); sz[u] += sz[v];
			if (sz[v] > sz[son[u]]) { son[u] = v; }
		}
	}
}
int top[N], mx[N], dfn[N], INDEX;
void dfs2(int u, int t) {
	top[u] = t; cmax(mx[u], dfn[u] = ++INDEX);
	if (son[u]) {
		dfs2(son[u], t);
		cmax(mx[u], mx[son[u]]);
	}
	if (u == t) {
		s[u] = &pool[u];
		s[u]->insert(node_t(dfn[u], mx[u] + 1));
	}
	for (auto v : g[u]) {
		if (!top[v]) {
			dfs2(v, v);
		}
	}
}
int lca(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) {
			swap(u, v);
		}
		u = fa[top[u]];
	}
	return dep[u] < dep[v] ? u : v;
}
int dis(int u, int v) {
	return dep[u] + dep[v] - dep[lca(u, v)] * 2 + 1;
}
void ins(set<node_t> *s, int l, int r, int c) {
	auto itr = split(s, r + 1);
	auto itl = split(s, l);
	for (auto it = itl; it != itr; it++) {
		upd(it->c, -(it->r - it->l + 1));
	}
	upd(c, r - l + 1);
	s->erase(itl, itr);
	s->insert(node_t(l, r, c));
}
int bg[N], tim;
void update(int u, int v) {
	bg[++tim] = u;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) {
			swap(u, v);
		}
		ins(s[top[u]], dfn[top[u]], dfn[u], tim);
		u = fa[top[u]];
	}
	if (dep[u] > dep[v]) swap(u, v);
	ins(s[top[u]], dfn[u], dfn[v], tim);
}
int qry(int u) {
	int c = split(s[top[u]], dfn[u])->c;
	return query(c - 1) + dis(u, bg[c]);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		add(x, y);
	}
	dfs(1);
	dfs2(1, 1);
	for (int i = 1; i < n; i++) {
		update(i, i + 1);
	}
	int lst = n;
	while (m--) {
		string s;
		cin >> s;
		int v; 
		cin >> v;
		if (s == "up") {
			update(lst, v), lst = v;
		} else if (s == "when") {
			cout << qry(v) << '\n';
		} else {
			int u; cin >> u;
			cout << (qry(u) < qry(v) ? u : v) << '\n';
		}
	}
	return 0;
}