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

const int INF = 1e9 + 7;

int ans[5005], vis[5005], k = 1;

V<pi> G[5005];

void dfs(int u) {
	vis[u] = 1;
	for(pi e:G[u]) {
		int v = e.F;
		ans[e.S] = 1;
		if(vis[v] == 0)
			dfs(v);
		else if(vis[v] == 1) {
			ans[e.S] = 2 ,k = 2;
		}
	}
	vis[u] = 2;
}

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		int u, v;
		cin >> u >> v;
		G[u].EB(v, i);
	}
	for(int i=1;i<=n;i++) {
		if(!vis[i]) dfs(i);
	}
	cout << k << endl;
	for(int i=0;i<m;i++)
		cout << ans[i] << " ";
}