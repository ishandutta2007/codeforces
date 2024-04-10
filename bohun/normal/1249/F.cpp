#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ss(x) (int) x.size()
 
using namespace std;

const int nax = 222;

int n, a, b, k;
vector <int> v[nax];
int dp[nax][nax];
int dp2[nax];
int cost[nax];
int h[nax];

void dfs(int u, int p) {
	h[u] = h[p] + 1;
	dp[u][h[u]] = cost[u];
	for(auto it : v[u]) {
		if(it == p) 
			continue;
		dfs(it, u);
		
		for(int i = 0; i <= n; ++i)
			dp2[i] = max(dp[u][i], dp[it][i]);
				
		int height = 0;
		int c = 0;
		for(int i = h[u]; i <= n; ++i)
			for(int j = h[u]; j <= n; ++j) {
				height = i + j - 2 * h[u];
				c = min(i, j);
				if(height <= k)
					continue;
				dp2[c] = max(dp2[c], dp[u][i] + dp[it][j]);
			}
		
		for(int i = 0; i <= n; ++i)
			dp[u][i] = dp2[i];
	}
}
				
		
		
 
int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", cost + i);
	for(int i = 1; i <= n - 1; ++i) {
		scanf("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1, 0);
	int ans = 0;
	for(int i = 0; i <= n; ++i)
		ans = max(ans, dp[1][i]);
	printf("%d", ans);
 
 
	return 0;
}