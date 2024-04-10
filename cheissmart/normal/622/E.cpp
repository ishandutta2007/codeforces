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

const int INF = 1e9 + 7, N = 5e5 + 7;

vi G[N], s;

void dfs(int u, int p, int d = 0) {
	if(G[u].size() == 1) s.PB(d);
	for(int v:G[u]) if(v != p)
		dfs(v, u, d + 1);
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i = 1; i < n; i++)	{
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	int ans = 0;
	for(int u:G[1]) {
		s.clear();
		dfs(u, 1);
		sort(ALL(s));
		int mx = -INF;
		for(int i:s) {
			mx = max(mx + 1, i);
		}
		ans = max(ans, mx + 1);
	}
	cout << ans << endl;
	
}