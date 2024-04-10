#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i ++)
#define rep1(i, n) for(int i = 1; i <= (n); i ++)
const int INF = 1e9 + 7;

int n, k;
int dp[1000005], dpe[1000005];
int md[1000005];
vector<int> G[1000005];

void dfs(int v, int cd)
{
	if(G[v].empty()) {
		md[v] = cd;
		dp[v] = 1;
		return;
	}
	md[v] = INF;
	rep(i, G[v].size()) {
		int u = G[v][i];
		dfs(u, cd + 1);
		md[v] = min(md[v], md[u]);
		if(md[u] <= cd + k)	{
			dp[v] += dp[u];
			dpe[v] = max(dpe[v], dpe[u] - dp[u]);
		} else dpe[v] = max(dpe[v], dpe[u]);
	}
	dpe[v] += dp[v];
}

int main()
{
	scanf("%d%d", &n, &k);
	rep(i, n - 1) {
		int v;
		scanf("%d", &v);
		G[v].push_back(i + 2);
	}
	dfs(1, 0);
	int ans = 0;
	rep1(i, n) ans = max(ans, dpe[i]);
	printf("%d\n", ans);
	return 0;
}