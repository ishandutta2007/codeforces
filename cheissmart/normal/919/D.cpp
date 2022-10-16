#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int dp[300005][30];
int a[300005], vis[300005], ans = 0;
vi G[300005];

bool dfs(int u) {
	vis[u] = 2;

	for(int v:G[u]) {
		if(vis[v] == 2)
			return false;
		if(vis[v] == 0 && !dfs(v))
			return false;
		for(int i=0;i<26;i++)
			dp[u][i] = max(dp[u][i], dp[v][i]);
	}
	dp[u][a[u]]++;
	vis[u] = 1;
	for(int i=0;i<26;i++)
		ans = max(ans, dp[u][i]);
	return true;
}

int main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) {
		char c;
		cin >> c;
		a[i] = c - 'a';
	}
	for(int i=0;i<m;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
	}
	for(int i=1;i<=n;i++) {
		if(vis[i] == 0 && !dfs(i)) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans << endl;
}