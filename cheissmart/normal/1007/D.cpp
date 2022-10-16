#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, N = 1e5 + 7;

struct Two_SAT {
	int n;
	V<pi> edges;
	void init(int num_of_var) {
		n = num_of_var * 2;
		edges.clear();
	}
	int add_var() {
		return (n += 2) - 2;
	}
	int neg(int u) { return u ^ 1; };
	void either(int u, int v) {
		edges.EB(neg(u), v);
		edges.EB(neg(v), u);
	}
	void implies(int u, int v) { either(neg(u), v); }
	int yes(int x) {
		return 2 * x;
	}
	V<vi> G, rG;
	vi scc, order;
	V<bool> vis, ans;
	void dfs(int u) {
		vis[u] = 1;
		for(int v:rG[u]) if(!vis[v])
			dfs(v);
		order.PB(u);
	}
	void dfs2(int u, int id) {
		scc[u] = id;
		if(!scc[u ^ 1])
			ans[u / 2] = (u & 1) == 0;
		for(int v:G[u]) if(!scc[v])
			dfs2(v, id);
	}
	V<bool> solve() {
		G = V<vi>(n), rG = V<vi>(n);
		scc = vi(n), order = vi();
		vis = V<bool>(n), ans = V<bool>(n / 2);
		for(auto&[u, v]:edges) {
			G[u].PB(v);
			rG[v].PB(u);
		}
		for(int i = 0; i < n; i++)
			if(!vis[i])
				dfs(i);
		reverse(ALL(order));
		int cnt = 1;
		for(int i:order)
			if(!scc[i])
				dfs2(i, cnt++);
		for(int i = 0; i < n; i += 2)
			if(scc[i] == scc[i ^ 1])
				return {};
		return ans;
	}
} ts;

int n, dummy;

int t[N * 4];

void build(int v = 1, int tl = 0, int tr = n) {
	t[v] = dummy;
	if(tr - tl == 1) return;
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm, tr);
}

void hit_with(int v, int u) {
	ts.either(ts.neg(t[v]), ts.neg(u));
	int tt = ts.add_var();
	ts.implies(t[v], tt);
	ts.implies(u, tt);
	t[v] = tt;
}

void push(int v) {
	hit_with(v * 2, t[v]);
	hit_with(v * 2 + 1, t[v]);
}

void add_tag(int l, int r, int u, int v = 1, int tl = 0, int tr = n) {
	if(l <= tl && tr <= r) {
		hit_with(v, u);
		return;
	}
	int tm = (tl + tr) / 2;
	if(l < tm) add_tag(l, r, u, v * 2, tl, tm);
	if(r > tm) add_tag(l, r, u, v * 2 + 1, tm, tr);
}

void push_down(int v = 1, int tl = 0, int tr = n) {
	if(tr - tl == 1) return;
	push(v);
	int tm = (tl + tr) / 2;
	push_down(v * 2, tl, tm);
	push_down(v * 2 + 1, tm, tr);
}

vi G[N];

int p[N], sz[N], top[N], d[N];

void dfs_sz(int u, int pa = 0, int depth = 0) {
	p[u] = pa, d[u] = depth;
	if(find(ALL(G[u]), pa) != G[u].end())
		G[u].erase(find(ALL(G[u]), pa));
	sz[u] = 1;
	for(int i = 0; i < int(G[u].size()); i++) {
		int v = G[u][i];
		dfs_sz(v, u, depth + 1);
		sz[u] += sz[v];
		if(sz[v] > sz[G[u][0]])
			swap(G[u][i], G[u][0]);
	}
}

int tin[N], tt;

void dfs_hld(int u) {
	tin[u] = tt++;
	for(int v:G[u]) {
		if(v == G[u][0]) top[v] = top[u];
		else top[v] = v;
		dfs_hld(v);
	}
}

void go(int a, int b, int u) {
	while(a != b) {
		if(top[a] == top[b]) {
			if(tin[a] > tin[b])
				swap(a, b);
			add_tag(tin[a], tin[b], u);
			break;
		}
		if(d[top[a]] > d[top[b]])
			swap(a, b);
		int c = p[top[b]];
		add_tag(tin[top[b]] - 1, tin[b], u);
		b = c;
	}
}

signed main()
{
	IO_OP;

	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}

	dfs_sz(1);
	top[1] = 1;
	dfs_hld(1);

	int m;
	cin >> m;
	ts.init(m * 2);
	dummy = ts.add_var();
	build();

	for(int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		assert(a != b && c != d);
		ts.either(ts.yes(i), ts.yes(i + m));
		go(a, b, ts.yes(i));
		go(c, d, ts.yes(i + m));
	}

	push_down();

	auto ans = ts.solve();
	if(ans.empty()) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for(int i = 0; i < m; i++) {
		cout << ans[i + m] + 1 << '\n';
	}

}