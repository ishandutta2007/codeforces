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

bool vis[N];
int mx[N];
vi s, G[N];

int dfs(int u) {
	vis[u] = 1;
	int ret = u;
	s.PB(u);
	for(int v:G[u]) {
		if(!vis[v]) ret = max(ret, dfs(v));
	}
	return ret;
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
	for(int i=1;i<=n;i++) {
		if(vis[i]) continue;
		s.clear();
		int b = dfs(i);
		for(int e:s) mx[e] = b; 
	}
	int i = 1, ans = 0;
	while(i <= n) {
		set<int> s;
		int r = mx[i];
		while(i <= r) {
			s.insert(mx[i]);
			r = max(r, mx[i]);
			i++;
		}
		ans += (int)s.size() - 1;
	}
	cout << ans << endl;
}