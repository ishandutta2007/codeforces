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

vi G[N];
int d[N];

void dfs(int u, int p = -1, int depth = 0) {
	d[u] = depth;
	for(int v:G[u]) if(v != p) {
		dfs(v, u, depth + 1);
	}
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n-1;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}	
	int s;
	for(int i=1;i<=n;i++) if(G[i].size() == 1) s = i;
	dfs(s);
	int ans1 = 1;
	for(int i=1;i<=n;i++) if(G[i].size() == 1 && (d[i] & 1))
		ans1 = 3;
	int ans2 = n - 1;
	for(int i=1;i<=n;i++) {
		int cnt = 0;
		for(int v:G[i]) if(G[v].size() == 1) cnt++;
		if(cnt) ans2 -= cnt - 1;
	}
	cout << ans1 << " " << ans2 << endl;
}