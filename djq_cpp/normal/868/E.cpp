#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n, st, m;
vector<int> G[55];
int dis[55][55];
int cnt[55];
int dp[55][55][55][55];

int gen_dp(int u, int v, int s, int ds)
{
	if(dp[u][v][s][ds] != -1) return dp[u][v][s][ds];
	
	int ret = INF;
	if(s == 0) ret = 0;
	else if(ds != 0) {
		if(G[v].size() == 1) ret = gen_dp(v, u, s - ds, s - ds) + dis[u][v];
		else {
			int tmp[55] = {};
			tmp[0] = INF;
			rep(i, G[v].size()) {
				int nu = G[v][i];
				if(nu == u) continue;
				for(int j = s; j >= 0; j --) {
					tmp[j] = min(tmp[j], gen_dp(v, nu, s, 0));
					rep1(k, j) tmp[j] = max(tmp[j], min(tmp[j - k], gen_dp(v, nu, s, k)));
				}
			}
			
			for(int i = 0; i <= s; i ++) dp[u][v][s][i] = tmp[i] + dis[u][v];
			ret = dp[u][v][s][ds];
		}
	}
	
	return dp[u][v][s][ds] = ret;
}

int gen_tot(int u, int v)
{
	int ret = cnt[v];
	rep(i, G[v].size()) {
		int nu = G[v][i];
		if(nu == u) continue;
		ret += gen_tot(v, nu);
	}
	return ret;
}

int main()
{
	scanf("%d", &n);
	rep(i, n - 1) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[u].push_back(v);
		G[v].push_back(u);
		dis[u][v] = dis[v][u] = w;
	}
	scanf("%d%d", &st, &m);
	rep(i, m) {
		int x;
		scanf("%d", &x);
		cnt[x] ++;
	}
	
	memset(dp, -1, sizeof(dp));
	
	int ans = INF;
	rep(i, G[st].size()) {
		int v = G[st][i];
		ans = min(ans, gen_dp(st, v, m, gen_tot(st, v)));
	}
	printf("%d\n", ans);
	return 0;
}