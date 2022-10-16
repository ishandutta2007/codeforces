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
const ll oo = 1e18;

ll w[N];
ll dp[N];
V<pair<int, pair<ll, ll>>> G[N];
pair<ll, ll> pe[N];
int p[N][20], d[N];

struct Data {
	ll a[2][2];
	Data(ll a00 = oo, ll a01 = oo, ll a10 = oo, ll a11 = oo) {
		a[0][0] = a00, a[0][1] = a01, a[1][0] = a10, a[1][1] = a11;
	}
	friend Data operator + (Data lhs, Data rhs) {
		Data res;
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				for(int k = 0; k < 2; k++)
					res.a[i][k] = min(res.a[i][k], lhs.a[i][j] + rhs.a[j][k]);
		return res;
	}
	void transpose() {
		swap(a[0][1], a[1][0]);
	}
} up[N][20], self[N];

string to_string(Data d) {
	return "(" + to_string(d.a[0][0]) + ", " + to_string(d.a[0][1]) + ", " + to_string(d.a[1][0]) + ", " + to_string(d.a[1][1]) + ")";
}

void dfs(int u, int pa = 0, int depth = 0) {
	p[u][0] = pa, d[u] = depth;
	for(int i = 1; i < 20; i++)
		p[u][i] = p[p[u][i - 1]][i - 1];
	dp[u] = w[u];
	for(auto[v, ws]:G[u]) if(v != pa) {
		pe[v] = ws;
		dfs(v, u, depth + 1);
		dp[u] = min(dp[u], dp[v] + ws.F + ws.S);
	}
}

void dfs2(int u, int pa = 0, ll dp_up = oo) {
	dp[u] = min(dp[u], dp_up);
	for(auto[v, ws]:G[u]) if(v != pa) {
		dfs2(v, u, dp[u] + ws.F + ws.S);
	}
}

int lca(int u, int v) {
	if(d[u] > d[v]) swap(u, v);
	assert(d[v] >= d[u]);
	for(int i = 0; i < 20; i++)
		if((d[v] - d[u]) >> i & 1)
			v = p[v][i];
	assert(d[v] == d[u]);
	if(u == v) return u;
	for(int i = 19; i >= 0; i--)
		if(p[u][i] != p[v][i])
			u = p[u][i], v = p[v][i];
	assert(p[u][0] == p[v][0]);
	return p[u][0];
}

Data go_up(int u, int step) {
	Data res = self[u];
	for(int i = 0; i < 20; i++)
		if(step >> i & 1) {
			res = res + up[u][i];
			u = p[u][i];
		}
	return res;
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> w[i];
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		ll w1, w2;
		cin >> u >> v >> w1 >> w2;
		G[u].EB(v, MP(w1, w2));
		G[v].EB(u, MP(w1, w2));
	}

	dfs(1);
	dfs2(1);

	for(int i = 1; i <= n; i++)
		self[i] = Data(0, dp[i], dp[i], 0);
	for(int i = 2; i <= n; i++) {
		up[i][0] = Data(pe[i].F, oo, oo, pe[i].S) + self[p[i][0]];
	}

	for(int j = 1; j < 20; j++)
		for(int i = 1; i <= n; i++) if(p[i][j])
			up[i][j] = up[i][j - 1] + up[p[i][j - 1]][j - 1];
	int q;
	cin >> q;
	while(q--) {
		int u, v;
		cin >> u >> v;
		assert(u != v);
		pi uu = {(u - 1) / 2 + 1, (u - 1) & 1};
		pi vv = {(v - 1) / 2 + 1, (v - 1) & 1};
		if(uu.F == vv.F) {
			cout << dp[uu.F] << '\n';
			continue;
		}
		int l = lca(uu.F, vv.F);
		Data up = go_up(uu.F, d[uu.F] - d[l]), down = go_up(vv.F, d[vv.F] - d[l]);
		down.transpose();
		Data res = up + down;
		cout << res.a[uu.S][vv.S] << '\n';
	}

}