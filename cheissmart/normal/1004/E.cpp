#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e5 + 7;

V<pi> G[N];
int n, k, dp[N], mxd[N], mb, mn_len;

void dfs1(int u, int p = -1) {
	mxd[u] = 0;
	for(pi e:G[u]) if(e.F != p) {
		int v = e.F;
		dfs1(v, u);
		mxd[u] = max(mxd[u], mxd[v] + e.S);
	}
}

void dfs2(int u, int p = -1) {
	vi must;
	for(pi e:G[u]) if(e.F != p) {
		int v = e.F;
		dfs2(v, u);
		if(mxd[v] + e.S > mb) must.PB(v);
	}
	if(must.size() > 1) dp[u] = INF;
	else if(must.size() == 1) dp[u] = dp[must[0]] + 1;
	else dp[u] = 1; // must.empty()
}

void dfs3(int u, int p = -1, int upmax = 0) {
	if(upmax > mb) return;
	vi must;
	int mx1 = -INF, mx2 = -INF;
	for(pi e:G[u]) if(e.F != p) {
		int v = e.F;
		if(mxd[v] + e.S > mb) must.PB(v);
		if(mxd[v] + e.S > mx1) mx2 = mx1, mx1 = mxd[v] + e.S;
		else if(mxd[v] + e.S > mx2) mx2 = mxd[v] + e.S;
	}
	if(must.size() <= 2) {
		int cur = 1;
		for(int v:must) cur += dp[v];
		mn_len = min(mn_len, cur);
	}
	for(pi e:G[u]) if(e.F != p) {
		int v = e.F;
		if(mxd[v] + e.S == mx1) dfs3(v, u, max(upmax, mx2) + e.S);
		else dfs3(v, u, max(upmax, mx1) + e.S);
	}
}

bool ok() {
	mn_len = INF;
	dfs2(1);
	dfs3(1);
	return mn_len <= k;
}

signed main()
{
	IO_OP;
	
	cin >> n >> k;
	for(int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].EB(v, w);
		G[v].EB(u, w);
	}
	dfs1(1);
	int lb = 0, rb = 1e9 + 7;
	while(lb <= rb) {
		mb = (lb + rb) / 2;
		if(ok()) rb = mb - 1;
		else lb = mb + 1;
	}
	cout << lb << endl;
}