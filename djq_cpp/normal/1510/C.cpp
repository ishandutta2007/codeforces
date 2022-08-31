#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n, m, pa[100005], ord[100005], cnt;
vector<int> G[100005], T[100005];
int de[100005];
vector<PII> E;

void dfs(int v, int par)
{
	ord[v] = ++ cnt;
	pa[v] = par;
	rep(i, G[v].size()) {
		int u = G[v][i];
		if(u == par || ord[u] > ord[v]) continue;
		if(pa[u]) {
			for(int i = v; i != u; i = pa[i]) de[i] = -1;
		} else dfs(u, v);
	}
}

int dp[100005][2], cho[100005];
void gen_dp(int v)
{
	dp[v][0] = 0; dp[v][1] = INF;
	int cnt = 0;
	rep(i, T[v].size()) {
		int u = T[v][i];
		gen_dp(u);
		dp[v][1] = min(dp[v][1] + dp[u][0], dp[v][0] + dp[u][1]);
		dp[v][0] += dp[u][0];
		cnt += !de[u];
	}
	int ndp1 = dp[v][0] - cnt / 2;
	if(pa[v] == -1 || de[v]) {
		dp[v][0] = min(ndp1, dp[v][1] - (cnt - 1) / 2);
		cho[v] = cnt & 1 ? dp[v][0] == dp[v][1] - (cnt - 1) / 2 : dp[v][0] != ndp1; dp[v][1] = INF;
	} else {
		dp[v][0] = min(dp[v][0] - (cnt + 1) / 2, dp[v][1] - cnt / 2) + 1;
		cho[v] = dp[v][0] == dp[v][1] - cnt / 2 + 1; dp[v][1] = ndp1;
	}
}
int mu[100005];
void gen_sol(int v, int tp)
{
	if(tp == 1) rep(i, T[v].size()) {
		int u = T[v][i];
		gen_sol(u, 0);
	} else {
		rep(i, T[v].size()) {
			int u = T[v][i];
			if(de[u] == -1) continue;
			if(cho[v] && (mu[v] == -1 || dp[mu[v]][1] - dp[mu[v]][0] > dp[u][1] - dp[u][0])) mu[v] = u;
		}
		rep(i, T[v].size()) {
			int u = T[v][i];
			if(mu[v] == u) de[u] = 1;
			gen_sol(u, mu[v] == u);
		}
	}
}

int hv[100005];
void gen_sol2(int v)
{
	rep(i, T[v].size()) {
		int u = T[v][i];
		gen_sol2(u);
		if(hv[u] == -1) continue;
		if(hv[v] == -1) hv[v] = hv[u];
		else {
			E.push_back(MP(hv[u], hv[v])); hv[v] = -1;
		}
	}
	if(hv[v] == -1 && !de[v]) hv[v] = v;
	else if(hv[v] != -1 && de[v]) {
		E.push_back(MP(pa[hv[v]] == v ? pa[v] : v, hv[v]));
		hv[v] = -1;
	}
}

bool solve()
{
	scanf("%d%d", &n, &m);
	if(n == 0) return false;
	rep1(i, n) {
		G[i].clear(); T[i].clear(); hv[i] = -1; mu[i] = -1;
		pa[i] = 0; ord[i] = 0; de[i] = 0;
	}
	rep(i, m) {
		int s, x, y;
		scanf("%d%d", &s, &x);
		rep(j, s - 1) {
			scanf("%d", &y);
			G[x].push_back(y); G[y].push_back(x);
			x = y;
		}
	}
	
	cnt = 0; dfs(1, -1);
	for(int i = 2; i <= n; i ++) T[pa[i]].push_back(i);
	
	gen_dp(1);
	de[1] = -1;
	gen_sol(1, 0);
	E.clear();
	gen_sol2(1);
	printf("%d\n", dp[1][0]);
	rep(i, dp[1][0]) printf("%d %d\n", E[i].first, E[i].second);
	return true;
}

int main()
{
	while(solve());
	return 0;
}