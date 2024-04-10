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

const int INF = 1e9 + 7, N = 5005;

int u[N], v[N], d[N], pa[N], a[N], b[N], w[N];
vi G[N];

int ans[N];

void dfs(int u, int p = -1, int depth = 0) {
	d[u] = depth;
	pa[u] = p;
	for(int v:G[u]) if(v != p) {
		dfs(v, u, depth + 1);
	}
}

void add(int u, int v, int w) {
	if(d[u] < d[v]) swap(u, v);
	while(d[u] > d[v]) {
		ans[u] = max(ans[u], w);
		u = pa[u];
	}
	while(u != v) {
		ans[u] = max(ans[u], w);
		u = pa[u];
		ans[v] = max(ans[v], w);
		v = pa[v];
	}
}

bool ok(int u, int v, int w) {
	if(d[u] < d[v]) swap(u, v);
	int cur = INF;
	while(d[u] > d[v]) {
		cur = min(ans[u], cur);
		u = pa[u];
	}
	while(u != v) {
		cur = min(ans[u], cur);
		cur = min(ans[v], cur);
		u = pa[u];
		v = pa[v];
	}
	return cur == w;
}
signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		ans[i] = 1;
	for(int i=0;i<n-1;i++) {
		cin >> u[i] >> v[i];
		G[u[i]].PB(v[i]);
		G[v[i]].PB(u[i]);
	}
	dfs(1);
	int m;
	cin >> m;
	for(int i=0;i<m;i++) {
		cin >> a[i] >> b[i] >> w[i];
		add(a[i], b[i], w[i]);
	}
	for(int i=0;i<m;i++) {
		if(!ok(a[i], b[i], w[i])) {
			cout << -1 << endl;
			return 0;
		}
	}
	for(int i=0;i<n-1;i++) {
		if(d[u[i]] > d[v[i]])
			cout << ans[u[i]] << " ";
		else
			cout << ans[v[i]] << " ";
	}
}