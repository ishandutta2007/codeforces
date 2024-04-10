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

const int INF = 1e9 + 7, N = 2e5 + 7;

array<int, 4> edges[N]; // c, a, b, t
array<int, 3> qq[N]; // v, x, i
int e[N], p[N], mx_edge[N];
array<int, 2> ans[N];
array<int, 2> mx[N]; // val, u
V<pi> G[N];

int pa[N][20], st[N][20], d[N];

void dfs(int u, int pp = 0) {
	for(int i = 1; i < 20; i++) {
		pa[u][i] = pa[pa[u][i - 1]][i - 1];
		st[u][i] = max(st[u][i - 1], st[pa[u][i - 1]][i - 1]);
	}
	for(auto [v, w] : G[u]) if(v != pp) {
		pa[v][0] = u, st[v][0] = w, d[v] = d[u] + 1;
		dfs(v, u);
	}
}

signed main()
{
	IO_OP;

	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		cin >> e[i];

	for(int i = 0; i < n - 1; i++) {
		cin >> edges[i][1] >> edges[i][2] >> edges[i][0] >> edges[i][3];
		G[edges[i][1]].EB(edges[i][2], edges[i][3]);
		G[edges[i][2]].EB(edges[i][1], edges[i][3]);
	}

	dfs(1);

	sort(edges, edges + n - 1, greater<array<int, 4>>());

	for(int i = 0; i < q; i++) {
		int v, x;
		cin >> v >> x;
		qq[i] = {v, x, i};
	}
	sort(qq, qq + q, greater<array<int, 3>>());

	for(int i = 1; i <= n; i++) {
		p[i] = i;
		mx[i] = {e[i], i};
	}

	function<int(int)> find = [&] (int u) {
		return p[u] == u ? u : p[u] = find(p[u]);
	};

	auto qry = [&] (int u, int v) {
		if(d[u] > d[v]) swap(u, v);
		int res = 0;
		for(int i = 0; i < 20; i++) if((d[v] - d[u]) >> i & 1) {
			res = max(res, st[v][i]);			
			v = pa[v][i];
		}
		if(u == v) return res;
		for(int i = 19; i >= 0; i--) {
			if(pa[u][i] != pa[v][i]) {
				res = max(res, st[u][i]);
				res = max(res, st[v][i]);
				u = pa[u][i], v = pa[v][i];
			}
		}
		res = max(res, st[u][0]);
		res = max(res, st[v][0]);
		assert(pa[u][0] == pa[v][0]);
		return res;
	};

	auto add_edge = [&] (int u, int v, int t) {
		u = find(u), v = find(v);
		assert(u != v);
		if(mx[u][0] != mx[v][0]) {
			if(mx[u] > mx[v])
				p[v] = u;
			else
				p[u] = v;
		} else {
			p[v] = u;
			mx_edge[u] = max(mx_edge[u], t);
			mx_edge[u] = max(mx_edge[u], mx_edge[v]);
			mx_edge[u] = max(mx_edge[u], qry(mx[u][1], mx[v][1]));
		}
	};

	for(int i = 0, j = 0; i < q; i++) {
		while(j < n - 1 && edges[j][0] >= qq[i][0]) {
			add_edge(edges[j][1], edges[j][2], edges[j][3]);
			j++;
		}
		int u = find(qq[i][1]);
		ans[qq[i][2]] = {mx[u][0], max(mx_edge[u], qry(qq[i][1], mx[u][1]))};
	}
	for(int i = 0; i < q; i++)
		cout << ans[i][0] << " " << ans[i][1] << '\n';

}