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

vi G[N], bad, g[N];
int dp[N][3], u[N], v[N], dead[N], vis[N];

int who(int x, int i) {
	return u[i] ^ v[i] ^ x;
}

void dfs(int u, int p = -1) {
	vi DP({0, INF, INF});
	for(int e:G[u]) if(who(u, e) != p) {
		int v = who(u, e);
		vi new_DP(3, INF);
		dfs(v, u);
		for(int i = 0; i < 3; i++) {
			if(i < 2) { // keep edge
				for(int j = 0; j < 2; j++) {
					new_DP[j + 1] = min(new_DP[j + 1], DP[j] + dp[v][i]);
				}
			}
			// delete edge
			for(int j = 0; j < 3; j++) {
				new_DP[j] = min(new_DP[j], DP[j] + dp[v][i] + 1);
			}
		}
		swap(DP, new_DP);
	}
	for(int i = 0; i < 3; i++)
		dp[u][i] = DP[i];
}

void upd_dead(int e) {
	dead[e] = 1;
	bad.PB(e);
}

void go(int u, int s, int p = -1) {
	vi DP({0, INF, INF});
	V<V<pi>> froms;
	vi edges;
	for(int e:G[u]) if(who(u, e) != p) {
		int v = who(u, e);
		vi new_DP(3, INF);
		V<pi> from(3, {-1, -1});
		for(int i = 0; i < 3; i++) {
			if(i < 2) { // keep edge
				for(int j = 0; j < 2; j++) {
					if(DP[j] + dp[v][i] < new_DP[j + 1]) {
						new_DP[j + 1] = DP[j] + dp[v][i];
						from[j + 1] = {1, i};
					}
				}
			}
			// delete edge
			for(int j = 0; j < 3; j++) {
				if(DP[j] + dp[v][i] + 1 < new_DP[j]) {
					new_DP[j] = DP[j] + dp[v][i] + 1;
					from[j] = {0, i};
				}
			}
		}
		swap(DP, new_DP);
		froms.PB(from);
		edges.PB(e);
	}
	while(edges.size()) {
		pi p = froms.back()[s];
		go(who(u, edges.back()), p.S, u);
		if(p.F == 0) upd_dead(edges.back());
		s -= p.F;
		froms.pop_back();
		edges.pop_back();
	}
	assert(s == 0);
}

void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		cin >> u[i] >> v[i];
		G[u[i]].PB(i);
		G[v[i]].PB(i);
	}
	dfs(1);
	int agm = 0;
	for(int i = 0; i < 3; i++)
		if(dp[1][i] < dp[1][agm])
			agm = i;
	go(1, agm);
	assert(int(bad.size()) == dp[1][agm]);

	V<pi> to_add;

	for(int i = 0; i < n - 1; i++) if(!dead[i]) {
		g[u[i]].PB(v[i]);
		g[v[i]].PB(u[i]);
	}
	int p = -1;
	for(int i = 1; i <= n; i++) if(!vis[i]) {
		vi leaves;
		function<void(int, int)> find_leaves = [&] (int u, int p) {
			vis[u] = 1;
			if(int(g[u].size()) == 0)
				leaves.PB(u), leaves.PB(u);
			else if(int(g[u].size()) == 1)
				leaves.PB(u);
			for(int v:g[u]) if(v != p)
				find_leaves(v, u);
		};
		find_leaves(i, -1);
		assert(leaves.size() == 2);
		if(p != -1)
			to_add.EB(p, leaves[0]);
		p = leaves[1];
	}
	assert(to_add.size() == bad.size());
	cout << bad.size() << '\n';

	for(int i = 0; i < int(bad.size()); i++) {
		cout << u[bad[i]] << ' ' << v[bad[i]] << ' ' << to_add[i].F << ' ' << to_add[i].S << '\n';
	}

	bad.clear();
	for(int i = 1; i <= n; i++) {
		dead[i - 1] = 0;
		G[i].clear();
		g[i].clear();
		vis[i] = 0;
	}
}


signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--)
		solve();

}