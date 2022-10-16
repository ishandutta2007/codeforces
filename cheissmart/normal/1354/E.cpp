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
vi sa, na;

int vis[N];
vi G[N];

bool dfs(int u, int c = 1) {
	vis[u] = c;
	if(c == 1) sa.PB(u);
	else na.PB(u);
	for(int v:G[u]) {
		if(vis[v] == 0) {
			if(!dfs(v, 3 ^ c))
				return false;
		} else if(vis[v] == vis[u]) return false;
	}
	return true;
}

int dp[N][N], w[N][N], ans[N];

signed main()
{
	IO_OP;
	
	int n, m, x, y, z;
	cin >> n >> m >> x >> y >> z;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	V<vi> saa, naa;
	for(int i = 1; i <= n; i++) {
		if(vis[i] == 0) {
			sa.clear(), na.clear();
			if(!dfs(i)) {
				cout << "NO" << endl;
				return 0;
			}
			saa.PB(sa);
			naa.PB(na);
		}
	}

	dp[0][0] = 1;
	for(int i = 1; i <= saa.size(); i++) {
		int a = saa[i-1].size(), b = naa[i-1].size();
		for(int j = 0; j <= n; j++) {
			if(j - a >= 0 && dp[i-1][j-a]) {
				dp[i][j] = 1;
				w[i][j] = 0;
			}
			else if(j - b >= 0 && dp[i-1][j-b]) {
				dp[i][j] = 1;
				w[i][j] = 1;
			}
		}
	}
	if(dp[saa.size()][y] == 0) {
		cout << "NO"<< endl;
		return 0;
	}
	cout << "YES" << endl;
	int l = saa.size(), r = y;
	while(l) {
		if(w[l][r] == 0) {
			for(int e:saa[l - 1]) ans[e] = 2;
			r -= saa[l-1].size();
		} else {
			for(int e:naa[l - 1]) ans[e] = 2;
			r -= naa[l-1].size();
		}
		l--;
	}
	for(int i = 1; i <= n; i++) {
		if(ans[i]) cout << ans[i];
		else {
			if(x) {
				cout << 1;
				x--;
			} else {
				cout << 3;
				z--;
			}
		}
	}
}