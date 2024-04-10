#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5;
int l[MN], r[MN]; long long dp[MN][2];
vector<int> adj[MN];
void dfs (int cur, int p = -1) {
	for (int i : adj[cur]) if (i != p) {
		dfs(i,cur);
		dp[cur][0] += max(abs(l[cur]-l[i])+dp[i][0],abs(l[cur]-r[i])+dp[i][1]);
		dp[cur][1] += max(abs(r[cur]-l[i])+dp[i][0],abs(r[cur]-r[i])+dp[i][1]);
	}
}
void solve () {
	int n; scanf ("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d %d",&l[i],&r[i]);
		adj[i].clear(); dp[i][0] = dp[i][1] = 0;
	}
	for (int i = 1; i < n; i++) {
		int a,b; scanf ("%d %d",&a,&b);
		adj[a].push_back(b); adj[b].push_back(a);
	}
	dfs(1);
	printf ("%lld\n",max(dp[1][0],dp[1][1]));
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}