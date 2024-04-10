#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#define fi first
#define se second
using namespace std;
const int maxn = 1000006;
int dfn[maxn], dc, low[maxn], st[maxn], tp, col[maxn], cc;
bool vis[maxn];
vector <int> G[maxn];
void dfs(int u, int f){
	dfn[u] = low[u] = ++ dc;
	vis[u] = true;
	st[++ tp] = u;
	for (int i = 0; i < G[u].size(); ++ i){
		int v = G[u][i];
		if (v == f)
			continue;
		if (vis[v])
			low[u] = min(low[u], dfn[v]);
		else if (! dfn[v]){
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		}
	}
	if (dfn[u] == low[u]){
		col[u] = ++ cc;
		while (st[tp] != u){
			col[st[tp]] = cc;
			vis[st[tp --]] = false;
		}
		vis[st[tp --]] = false;
	}
}
int a[maxn], e[maxn][2], cnt[maxn];
long long sum[maxn], dp[maxn][2], mx;
bool one[maxn];
set <int> E[maxn];
void solve(int u, int f){
    one[u] = cnt[u] == 1;
    dp[u][1] = sum[u];
	long long mxu = 0;
	for (int i = 0; i < G[u].size(); ++ i){
		int v = G[u][i];
		if (v != f){
			solve(v, u);
			one[u] &= one[v];
			dp[u][1] += dp[v][1];
			if (one[v])
                mxu = max(mxu, dp[v][0]);
		}
	}
	if (one[u]){
        dp[u][0] = sum[u] + mxu;
        mx = max(mx, dp[u][0]);
        dp[u][1] = 0;
	}
}
int read(){
	int c = 0; char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c;
}
int main(){
	int n = read(), m = read();
	for (int i = 1; i <= n; ++ i)
		a[i] = read();
	for (int i = 1; i <= m; ++ i){
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
		e[i][0] = u, e[i][1] = v;
	}
	int s = read();
	dfs(s, 0);
	for (int i = 1; i <= n; ++ i)
		G[i].clear();
	for (int i = 1; i <= n; ++ i)
		if (col[i])
			++ cnt[col[i]], sum[col[i]] += a[i];
	for (int i = 1; i <= m; ++ i){
		int u = col[e[i][0]], v = col[e[i][1]];
		if (u != v && E[u].find(v) == E[u].end()){
			E[u].insert(v);
			E[v].insert(u);
			G[u].push_back(v);
			G[v].push_back(u);
		}
	}
	solve(s = col[s], 0);
	cout << dp[s][1] + mx << endl;
}