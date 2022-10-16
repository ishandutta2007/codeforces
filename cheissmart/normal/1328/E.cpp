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

const int INF = 1e9 + 7, N = 2e5 + 7;

int p[N][20], d[N];
vi G[N];

void dfs(int u, int pa = 0, int depth = 0) {
	d[u] = depth, p[u][0] = pa;
	for(int v:G[u]) if(v != pa)
		dfs(v, u, depth + 1);
}

int up(int u, int len) {
	for(int i=19;i>=0;i--)
		if(len >> i & 1)
			u = p[u][i];
	return u;
}

bool isanc(int u, int v) { // u is v's anc
	return up(v, d[v] - d[u]) == u;
}
bool cmp(int a, int b) {
	return d[a] < d[b];
}

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n-1;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs(1);
	for(int j=1;j<20;j++)
		for(int i=1;i<=n;i++)
			p[i][j] = p[p[i][j-1]][j-1];
	while(m--) {
		int k;
		cin >> k;
		vi tt;
		for(int i=0;i<k;i++) {
			int t;
			cin >> t;
			tt.PB(t == 1 ? 1 : p[t][0]);
		}
		sort(ALL(tt), cmp);
		bool ok = true;
		for(int i=0;i<k-1;i++) {
			ok &= isanc(tt[i], tt[i+1]);
		}
		cout << (ok ? "YES" : "NO") << endl;
	}

}