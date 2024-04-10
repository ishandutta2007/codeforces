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

const int INF = 1e18 + 7, N = 200005;

int tt, cnt, vis[N], low[N], w[N], ww[N], bcc[N], sz[N];
vi G[N], s;

void dfs(int u, int pa = 0) {
	low[u] = vis[u] = ++tt;
	s.PB(u);
	for(int v:G[u]) if(v != pa) {
		if(vis[v]) low[u] = min(low[u], vis[v]);
		else {
			dfs(v, u);
			if(low[v] > vis[u]) {
				++cnt;
				int k;
				do {
					bcc[k = s.back()] = cnt;
					ww[cnt] += w[k];
					sz[cnt]++;
					s.pop_back();
				} while(k != v);
			}
			low[u] = min(low[u], low[v]);
		}
	}
	if(pa == 0) {
		++cnt;
		while(s.size()) {
			bcc[s.back()] = cnt;
			ww[cnt] += w[s.back()];
			sz[cnt]++;
			s.pop_back();
		}
	}
}

vi g[N];
int dp[N][2];

void dfs1(int u, int p = 0) {
	for(int v:g[u]) if(v != p)
		dfs1(v, u);
	if(sz[u] == 1) dp[u][0] = -INF;
	else dp[u][0] = ww[u];
	int sum = 0;
	bool ok = false;
	for(int v:g[u]) if(v != p) {
		if(dp[v][0] >= 0) sum += dp[v][0], ok = true;
	}
	if(ok) dp[u][0] = sum + ww[u];
	dp[u][1] = max(ww[u], dp[u][0]);
	for(int v:g[u]) if(v != p)
		dp[u][1] = max(dp[u][1], sum - max(dp[v][0], 0LL) + ww[u] + dp[v][1]);
}

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> w[i];
	for(int i=0;i<m;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}	
	int s;
	cin >> s;
	dfs(s);
	for(int i=1;i<=n;i++)
		for(int j:G[i])
			if(bcc[i] != bcc[j])
				g[bcc[i]].PB(bcc[j]), g[bcc[j]].PB(bcc[i]);
	for(int i=1;i<=cnt;i++) {
		sort(ALL(g[i]));
		g[i].resize(unique(ALL(g[i])) - g[i].begin());
	}
	dfs1(bcc[s]);
	cout << dp[bcc[s]][1] << endl;

}