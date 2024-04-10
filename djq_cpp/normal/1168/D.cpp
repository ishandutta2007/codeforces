#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i ++)
#define rep1(i, n) for(int i = 1; i <= (n); i ++)

int n, q;
int par[150005];
char ch[150005];
vector<int> T[150005];
int dep[150005];
int maxd;
int f_pa[150005], f_son[150005];

int wei[150005][26];
int dp[150005][26], sum[150005];
int tot_una;

void dfs(int v, int cd)
{
	dep[v] = cd;
	maxd = max(maxd, cd);
	
	if(cd == 0) f_pa[v] = v;
	f_son[v] = v;
	
	rep(i, T[v].size()) {
		int u = T[v][i];
		
		if(T[u].size() == 1) f_pa[u] = f_pa[v];
		else f_pa[u] = u;
		dfs(u, cd + 1);
		if(T[v].size() == 1) f_son[v] = f_son[u];
	}
}

void regen_dp(int v, int tp)
{
	if(sum[v] > maxd - dep[v]) tot_una --;
	sum[v] -= dp[v][tp];
	dp[v][tp] = 0;
	rep(i, T[v].size()) {
		int u = T[v][i];
		u = f_son[u];
		dp[v][tp] = max(dp[v][tp], wei[u][tp] + dp[u][tp]);
	}
	sum[v] += dp[v][tp];
	if(sum[v] > maxd - dep[v]) tot_una ++;
}

void update(int id, int coef)
{
	int cur = f_son[id];
	wei[cur][ch[id] - 'a'] += coef;
	
	for(cur = par[cur] == -1 ? -1 : f_pa[par[cur]]; cur != -1; cur = par[cur] == -1 ? -1 : f_pa[par[cur]]) {
		regen_dp(cur, ch[id] - 'a');
	}
}

int main()
{
	scanf("%d%d", &n, &q);
	par[1] = -1;
	for(int i = 2; i <= n; i ++) {
		scanf("%d %c", &par[i], &ch[i]);
		T[par[i]].push_back(i);
	}
	dfs(1, 0);
	bool ok = true;
	for(int i = 2; i <= n; i ++) if(T[i].empty() && dep[i] != maxd) ok = false; 
	
	for(int i = 2; i <= n; i ++) if(ch[i] != '?') update(i, 1);
	
	rep(i, q) {
		int id, cc;
		scanf("%d %c", &id, &cc);
		if(ch[id] != '?') update(id, -1);
		ch[id] = cc;
		if(ch[id] != '?') update(id, 1);
		if(tot_una == 0 && ok) {
			printf("Shi ");
			int ret = 0;
			rep(i, 26) ret += (i + 1) * (maxd - sum[1] + dp[1][i]);
			printf("%d\n", ret);
		} else printf("Fou\n");
	}
	return 0;
}