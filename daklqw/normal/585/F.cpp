#include <bits/stdc++.h>

const int MAXN = 50010;
const int mod = 1000000007;
void reduce(int & x) { x += x >> 31 & mod; }
int nxt[MAXN][10], fail[MAXN], idx = 1, ed[MAXN];
void ins(char * L, char * R) {
	int now = 1;
	while (L != R) {
		int & p = nxt[now][*L++ & 15];
		if (!p) p = ++idx;
		now = p;
	}
	ed[now] = true;
}
std::queue<int> q;
void build() {
	for (int i = 0; i != 10; ++i)
		if (nxt[1][i]) fail[nxt[1][i]] = 1, q.push(nxt[1][i]);
		else nxt[1][i] = 1;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int i = 0; i != 10; ++i)
			if (nxt[t][i])
				fail[nxt[t][i]] = nxt[fail[t]][i], q.push(nxt[t][i]);
			else nxt[t][i] = nxt[fail[t]][i];
		ed[t] |= ed[fail[t]];
	}
}
char buf[MAXN], L[MAXN], R[MAXN];
int n, D;
int dp[2][MAXN][2][2];
// now, node, ok, ge
int calc(char * buf) {
	int now = 1, lst = 0;
	memset(dp, 0, sizeof dp);
	dp[now][1][0][0] = 1;
	for (int i = 0; i < D; ++i) {
		std::swap(lst, now);
		memset(dp[now], 0, sizeof(dp[now]));
		int nc = buf[i] & 15;
		for (int j = 1; j <= idx; ++j)
		for (int k = 0; k != 2; ++k)
		for (int l = 0; l != 2; ++l)
		if (int t = dp[lst][j][k][l]) {
			for (int p = 0; p != 10; ++p) {
				int nx = nxt[j][p];
				int eq = p == nc ? l : p > nc;
				reduce(dp[now][nx][k | ed[nx]][eq] += t - mod);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= idx; ++i)
		reduce(ans += dp[now][i][1][0] - mod);
	return ans;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> buf >> L >> R;
	n = strlen(buf); D = strlen(L);
	std::reverse(buf, buf + n);
	std::reverse(L, L + D);
	std::reverse(R, R + D);
	for (int i = 0, d = D / 2; i + d <= n; ++i)
		ins(buf + i, buf + i + d);
	build();
	int ans = 0, now = 1;
	for (int i = 0; i < D; ++i)
		ans |= ed[now = nxt[now][L[i] & 15]];
	reduce(ans += calc(R) - mod);
	reduce(ans -= calc(L));
	std::cout << ans << std::endl;
	return 0;
}