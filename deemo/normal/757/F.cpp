#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

struct DTreeDag{
	static const int MAXN = 2e5 + 10, LOG = 18;
	int n, sec[MAXN], sz, par[LOG][MAXN], depth[MAXN];
	bool vis[MAXN];
	vector<int> adj[MAXN], res;

	void dfs(int v){
		vis[v] = true;
		for (int u:adj[v])
			if (!vis[u])
				dfs(u);
		sec[sz++] = v;
	}

	int lca(int u, int v){
		if (depth[u] < depth[v]) swap(u, v);
		for (int w = LOG-1; ~w; w--)
			if (depth[u] - (1<<w) >= depth[v])
				u = par[w][u];
		if (u == v) return u;

		for (int w = LOG-1; ~w; w--)
			if (par[w][u] ^ par[w][v])
				u = par[w][u], v = par[w][v];
		return par[0][u];
	}

	vector<int> buildTree(int source) {
		fill(vis, vis + n, 0), sz = 0;
		dfs(source);

		reverse(sec, sec + sz);
		for (int v = 0; v < n; v++) par[0][v] = -1, depth[v] = -1;
		for (int i = 0; i < sz; i++){
			int v = sec[i];
			depth[v] = (~par[0][v]? depth[par[0][v]] + 1: 0);
			
			for (int w = 1; w < LOG; w++)
				if (~par[w-1][v])
					par[w][v] = par[w-1][par[w-1][v]];
				else
					par[w][v] = -1;

			for (int u:adj[v])
				par[0][u] = (par[0][u] == -1? v: lca(par[0][u], v));
		}

		res.assign(par[0], par[0] + n);
		return res;
	}
};

const int MAXN = 2e5 + 10;

int n, m;
vector<pii> adj[MAXN];
ll d[MAXN];
set<pair<ll, int>> st;
DTreeDag sol;
vector<int> par, adj2[MAXN];

void update(int v){
	for (auto e:adj[v]){
		int u = e.F, w = e.S;
		if (d[u] > d[v] + w){
			st.erase({d[u], u});
			d[u] = d[v] + w;
			st.insert({d[u], u});
		}
	}
}

void dijk(int v){
	memset(d, 63, sizeof(d));
	d[v] = 0;
	st.insert({d[v], v});

	while (st.size()){
		auto v = st.begin()->S;
		st.erase(st.begin());
		update(v);
	}
}

int sub[MAXN];
void dfs(int v){
	sub[v] = 1;
	for (int u: adj2[v])
		dfs(u), sub[v] += sub[u];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int s;
	cin >> n >> m >> s, s--;
	while (m--){
		int a, b, c; cin >> a >> b >> c, a--, b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	dijk(s);
	sol.n = n;
	for (int v = 0; v < n; v++)
		for (auto e:adj[v]){
			int u = e.F, w = e.S;
			if (d[u] == d[v] + w)
				sol.adj[v].push_back(u);
		}

	par = sol.buildTree(s);
	for (int v = 0; v < n; v++)
		if (~par[v])
			adj2[par[v]].push_back(v);
	dfs(s);

	int ans = 0;
	for (int u:adj2[s])
		ans = max(ans, sub[u]);
	cout << ans << "\n";
	return 0;
}