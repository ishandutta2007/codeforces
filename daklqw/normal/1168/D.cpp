#include <bits/stdc++.h>

const int MAXN = 150010;
int fa[MAXN], len[MAXN];
int es[MAXN][26], dp[MAXN][26], upto[MAXN];
int Q, n;
int head[MAXN], nxt[MAXN], to[MAXN], val[MAXN], bel[MAXN], tot;
int deg[MAXN];
char buf[5];
std::vector<int> ts[MAXN];
inline void getmax(int & a, int b) { a = a > b ? a : b; }
inline bool isimp(int u) { return deg[u] != 1 || u == 1; }
void upd(int u, int ch) {
	getmax(dp[upto[u]][ch], dp[u][ch] + es[u][ch]);
}
int dfs(int u, int tp) {
	bool syd = isimp(u);
	if (syd) upto[u] = tp;
	for (int i = head[u]; i; i = nxt[i]) {
		if (val[to[i]] != '?') ++es[to[i]][val[to[i]] - 'a'];
		if (!syd) for (int j = 0; j != 26; ++j) es[to[i]][j] += es[u][j];
		int res = dfs(to[i], syd ? u : tp);
		if (!syd) bel[u] = res;
		else ts[u].push_back(res);
		if (!len[u]) len[u] = len[to[i]] + 1;
		else if (len[u] != len[to[i]] + 1) {
			while (Q --> 0) puts("Fou");
			exit(0);
		}
	}
	if (syd) bel[u] = u;
	return bel[u];
}
int errs, sum[MAXN];
void updtoroot(int u, int c) {
	while (u != 1) { 
		errs -= sum[upto[u]] > len[upto[u]];
		sum[upto[u]] -= dp[upto[u]][c];
		dp[upto[u]][c] = 0;
		for (auto t : ts[upto[u]]) upd(t, c);
		sum[upto[u]] += dp[upto[u]][c];
		errs += sum[upto[u]] > len[upto[u]];
		u = upto[u];
	}
}
int main() {
	scanf("%d%d", &n, &Q);
	for (int i = 2; i <= n; ++i) {
		scanf("%d%s", fa + i, buf);
		++deg[fa[i]];
		nxt[++tot] = head[fa[i]];
		to[head[fa[i]] = tot] = i;
		val[i] = *buf;
	}
	dfs(1, 1);
//	for (int i = 1; i <= n; ++i) printf("%d ", len[i]); putchar(10);
//	for (int i = 1; i <= n; ++i) printf("%d ", deg[i]); putchar(10);
//	for (int i = 1; i <= n; ++i) printf("%d ", bel[i]); putchar(10);
//	for (int i = 1; i <= n; ++i) printf("%d ", upto[i]); putchar(10);
//	for (int i = 1; i <= n; ++i) {
//		printf("TO %d : ", i);
//		for (auto t : ts[i])
//			printf("%d ", t);
//		putchar(10);
//	}
	for (int i = n; i; --i) {
		if (!isimp(i)) continue;
		int & sum = ::sum[i];
		for (int j = 0; j != 26; ++j) {
			if (i != 1) upd(i, j);
			sum += dp[i][j];
		}
		errs += sum > len[i];
	}
	while (Q --> 0) {
		int u; scanf("%d%s", &u, buf);
		bool chg = *buf != val[u];
		if (chg) {
			if (val[u] != '?') {
				--es[bel[u]][val[u] - 'a'];
				updtoroot(bel[u], val[u] - 'a');
			}
			val[u] = *buf;
			if (val[u] != '?') {
				++es[bel[u]][val[u] - 'a'];
				updtoroot(bel[u], val[u] - 'a');
			}
		}
		if (errs) puts("Fou");
		else {
			int ans = 0;
			for (int i = 0; i != 26; ++i)
				ans += (i + 1) * (len[1] - sum[1] + dp[1][i]);
			printf("Shi %d\n", ans);
		}
//		for (int i = 1; i <= n; ++i) if (isimp(i)) {
//			for (int j = 0; j != 26; ++j)
//				printf("%d ", dp[i][j]); putchar(10);
//		}
	}
	return 0;
}