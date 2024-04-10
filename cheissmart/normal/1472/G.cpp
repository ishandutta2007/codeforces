#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

vi G[N];
int vis[N], dp[N], d[N];

void dfs(int u) {
	if(vis[u]) return;
	vis[u] = 1;
	for(int v:G[u]) if(d[v] > d[u]) {
		dfs(v);
		dp[u] = min(dp[u], dp[v]);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		G[i].clear();
		vis[i] = 0;
		dp[i] = INF;
		d[i] = -1;
	}
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].PB(v);
	}
	d[0] = 0;
	queue<int> q;
	q.push(0);
	while(q.size()) {
		int u = q.front(); q.pop();
		for(int v:G[u]) if(d[v] == -1) {
			d[v] = d[u] + 1;
			q.push(v);
		}
	}
	for(int i = 0; i < n; i++) {
		dp[i] = d[i];
		for(int j:G[i])
			dp[i] = min(dp[i], d[j]);
	}
	for(int i = 0; i < n; i++)
		dfs(i);
	for(int i = 0; i < n; i++)
		cout << dp[i] << " \n"[i == n - 1];
}

signed main()
{
	IO_OP;
	int t;
	cin >> t;
	while(t--) solve();
	
}