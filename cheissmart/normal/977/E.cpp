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

int vis[N];
vi G[N], s;

void dfs(int u) {
	vis[u] = 1;
	s.PB(u);
	for(int v:G[u]) if(!vis[v]) dfs(v);
}

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			s.clear();
			dfs(i);
			bool ok = 1;
			for(int u:s) ok &= G[u].size() == 2;
			cnt += ok;
		}
	}
	cout << cnt << endl;

}