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

const int INF = 1e9 + 7, N = 100005;

vi G[N];
int a[N], sum[N], d[N], pa[N][20], n, l, s;

void dfs1(int u, int depth = 1) {
	d[u] = depth;
	sum[u] = sum[pa[u][0]] + a[u];
	for(int v:G[u]) dfs1(v, depth + 1);
}

int ans[N], low[N];

int go(int u) {
	int ans = u;
	for(int i=19;i>=0;i--) {
		int v = pa[ans][i];
		if(!v) continue;
		if(d[u] - d[v] + 1 <= l && sum[u] - sum[pa[v][0]] <= s) {
			ans = v;
		}
	}
	return d[ans];
}

void dfs(int u) {
	if(G[u].size() == 0) {
		ans[u] = 1;
		low[u] = go(u);
		return;
	}
	low[u] = d[u];
	int mn = INF;
	for(int v:G[u]) {
		dfs(v);
		ans[u] += ans[v];
		mn = min(mn, low[v]);	
	}
	if(mn > d[u]) {
		ans[u]++;
		low[u] = go(u);		
	} else {
		low[u] = mn;
	}
}

signed main()
{
	IO_OP;
	
	cin >> n >> l >> s;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		if(a[i] > s) return cout << -1 << endl, 0;
	}
	for(int i=2;i<=n;i++) {
		cin >> pa[i][0];
		G[pa[i][0]].EB(i);
	}
	dfs1(1);
	for(int j=1;j<20;j++)
		for(int i=1;i<=n;i++)
			pa[i][j] = pa[pa[i][j-1]][j-1];
	dfs(1);
	cout << ans[1] << endl;
}