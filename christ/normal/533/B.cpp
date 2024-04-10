#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const int MN = 2e5+3, MOD = 1e9+7;
#define all(x) (x).begin(),(x).end()
ll dp[MN][2];
int v[MN];
vector<int> adj[MN];
void dfs (int cur) { //i confuse
	dp[cur][1] = LLONG_MIN>>2;
	for (int i : adj[cur]) {
		dfs(i);
		ll old = dp[cur][0];
		dp[cur][0] = max({dp[cur][0],dp[cur][1]+dp[i][1],dp[cur][0]+dp[i][0]});
		dp[cur][1] = max({dp[cur][1],old+dp[i][1],dp[cur][1]+dp[i][0]});
	}
	dp[cur][1] = max(dp[cur][0]+v[cur],dp[cur][1]);
} 
int main () {
   	int n;
	scanf ("%d",&n);
	for (int i = 1; i <= n; i++) {
		int p;
		scanf ("%d %d",&p,v+i);
		if (~p) adj[p].push_back(i);
	}
	dfs(1);
	printf ("%lld\n",dp[1][1]);
	return 0;
}