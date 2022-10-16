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

const int INF = 1e9 + 7, N = 3e5 + 7;

V<pi> G[N];
int p[N][19], d[N], a[N], wp[N];
ll dp[N], dp2[N], sdp[N];

void dfs(int u, int pa = 0, int depth = 0, int pw = 0) {
	p[u][0] = pa, d[u] = depth, wp[u] = pw;

	dp[u] = a[u] - 2 * pw;
	for(auto [v, w]:G[u]) if(v != pa) {
		dfs(v, u, depth + 1, w);
		dp[u] += dp[v];
	}
	dp[u] = max(dp[u], 0LL);
}

void dfs2(int u, int pa = 0, ll p_dp = 0) {
	dp2[u] = p_dp;
	ll sum = p_dp;
	for(auto [v, w]:G[u]) if(v != pa)
		sum += dp[v];
	sdp[u] = sum;
	for(auto [v, w]:G[u]) if(v != pa) {
		ll tt = max(a[u] - 2 * w + sum - dp[v], 0LL);
		dfs2(v, u, tt);
	}
}

struct Data {
	ll cost, x, y;
	int s, t;
	Data(){}
	Data(ll _cost, ll _x, ll _y, int _s, int _t) {
		cost = _cost, x = _x, y = _y, s = _s, t = _t;
	}
	friend Data operator + (Data lhs, Data rhs) {
		Data res;
		res.x = lhs.x, res.y = rhs.y;
		res.s = lhs.s, res.t = rhs.t;
		res.cost = lhs.cost - (sdp[lhs.t] - lhs.y) - a[lhs.t] + rhs.cost - (sdp[lhs.t] - rhs.x) + sdp[lhs.t] - lhs.y - rhs.x;
		return res;
	}
	Data reverse() {
		Data res = *this;
		swap(res.x, res.y);
		swap(res.s, res.t);
		return res;
	}
} up[N][19];

int lca(int u, int v) {
	if(d[u] > d[v]) swap(u, v);
	assert(d[v] >= d[u]);
	for(int i = 0; i < 19; i++)
		if((d[v] - d[u]) >> i & 1)
			v = p[v][i];
	assert(d[u] == d[v]);
	if(u == v) return u;
	for(int i = 18; i >= 0; i--)
		if(p[u][i] != p[v][i])
			u = p[u][i], v = p[v][i];
	assert(p[u][0] == p[v][0]);
	return p[u][0];
}

Data go_up(int u, int step) {
	assert(step);
	int k = __lg(step);
	Data res = up[u][k];
	u = p[u][k];
	for(int i = 0; i < k; i++)
		if(step >> i & 1) {
			res = res + up[u][i];
			u = p[u][i];
		}
	return res;
}


Data go_down(int u, int step) {
	assert(step);
	int k = __lg(step);
	Data res = up[u][k].reverse();
	u = p[u][k];
	for(int i = 0; i < k; i++)
		if(step >> i & 1) {
			res = up[u][i].reverse() + res;
			u = p[u][i];
		}
	return res;
}

signed main()
{
	IO_OP;

	int n, q;
	cin >> n >> q;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	for(int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].EB(v, w);
		G[v].EB(u, w);
	}

	dfs(1);
	dfs2(1);

	for(int i = 2; i <= n; i++) {
		ll x = dp2[i], y = dp[i];
		up[i][0] = Data(a[i] + a[p[i][0]] - wp[i] + sdp[i] + sdp[p[i][0]] - x - y, x, y, i, p[i][0]);
	}

	for(int j = 1; j < 19; j++) {
		for(int i = 1; i <= n; i++) if(d[i] >= (1 << j)) {
			p[i][j] = p[p[i][j - 1]][j - 1];
			up[i][j] = up[i][j - 1] + up[p[i][j - 1]][j - 1];
		}
	}

	while(q--) {
		int u, v;
		cin >> u >> v;
		if(u == v) {
			cout << a[u] + sdp[u] << '\n';
			continue;
		} 
		int l = lca(u, v);
		if(l == v) cout << go_up(u, d[u] - d[l]).cost << '\n';
		else if(l == u) cout << go_down(v, d[v] - d[l]).cost << '\n';
		else cout << (go_up(u, d[u] - d[l]) + go_down(v, d[v] - d[l])).cost << '\n';
	}

}