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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 5e5 + 5;

V<pi> G[N];
int dp1[N], dp2[N], n, k;

int go(vi x, vi y, int k) {
	int ret = 0;
	vi v;
	for(int i=0;i<x.size();i++) {
		ret += x[i];
		if(x[i] < y[i]) {
			v.PB(y[i] - x[i]);
		}
	}
	sort(ALL(v), greater<int>());
	for(int i=0;i<min(k, (int)v.size());i++)
		ret += v[i];
	return ret;
}

void dfs(int u, int p = 0) {
	int cnt = 0;
	vi x, y;
	for(pi edge:G[u]) if(edge.F != p) {
		dfs(edge.F, u);
		cnt++;
		x.PB(dp1[edge.F]);
		y.PB(dp2[edge.F] + edge.S);
	}
	dp1[u] = go(x, y, k);
	dp2[u] = go(x, y, k-1);
}

void solve() {
	cin >> n >> k;
	for(int i=0;i<n-1;i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].EB(v, w);
		G[v].EB(u, w);
	}
	dfs(1);
	cout << dp1[1] << endl;
	// clear
	for(int i=1;i<=n;i++) dp1[i] = dp2[i] = 0;
	for(int i=1;i<=n;i++) G[i].clear();
}

signed main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		solve();
	}	
	
}