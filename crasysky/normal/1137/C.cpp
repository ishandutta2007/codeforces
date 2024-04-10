#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#define Pr pair <int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int maxn = 5000006;
int edges[3][maxn], head[3][maxn], nxt[3][maxn], e[3];
void adde(int w, int u, int v){
	edges[w][++ e[w]] = v, nxt[w][e[w]] = head[w][u], head[w][u] = e[w];
}
int dfn[maxn], dc, low[maxn], st[maxn], tp, col[maxn], cc;
bool vis[maxn];
void Tarjan(int u){
	dfn[u] = low[u] = ++ dc;
	st[++ tp] = u, vis[u] = true;
	for (int i = head[0][u]; i; i = nxt[0][i]){
		int v = edges[0][i];
		if (! dfn[v]){
			Tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (vis[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]){
		col[u] = ++ cc;
		vis[u] = false;
		while (st[tp] != u){
			vis[st[tp]] = false;
			col[st[tp --]] = cc;
		}
		-- tp;
	}
}
int dp[maxn], tmp[maxn], v[maxn];
string s[100005];
void dfs(int u){
	if (dp[u] != -1)
		return;
	dp[u] = 0;
	for (int i = head[1][u]; i; i = nxt[1][i]){
		int v = edges[1][i];
		dfs(v);
		dp[u] = max(dp[u], dp[v]);
	}
	dp[u] += v[u];
}
int read(){
	int c = 0, f = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c * f; 
} 
int main(){
	int n = read(), m = read(), d = read();
	for (int i = 1; i <= m; ++ i){
		int u = read(), v = read();
		for (int j = 1; j <= d; ++ j)
			adde(0, (u - 1) * d + j, (v - 1) * d + j % d + 1);
	}
	for (int i = 1; i <= n * d; ++ i)
		if (! dfn[i])
			Tarjan(i);
	for (int i = 1; i <= n; ++ i)
		cin >> s[i];
	for (int i = 1; i <= n * d; ++ i){
		int u = (i + d - 1) / d;
		int day = i % d == 0 ? d : i % d;
		if (s[u][day - 1] - '0')
			adde(2, col[i], u);
		for (int j = head[0][i]; j; j = nxt[0][j])
			if (col[i] != col[edges[0][j]])
				adde(1, col[i], col[edges[0][j]]);
	}
	for (int i = 1; i <= cc; ++ i){
		int t = 0;
		for (int j = head[2][i]; j; j = nxt[2][j])
			tmp[++ t] = edges[2][j];
		sort(tmp + 1, tmp + 1 + t);
		v[i] = unique(tmp + 1, tmp + 1 + t) - tmp - 1;
	}
	for (int i = 1; i <= cc; ++ i)
		dp[i] = -1;
	dfs(col[1]);
	cout << dp[col[1]] << endl;
}
/*
1010101010
111
*/