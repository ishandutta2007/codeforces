#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
const int MAXK = 210;
const int mod = 1e9 + 7;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
void fma(int & x, int y, int z) {
	x = ((LL) y * z + x) % mod;
}
int S[MAXK][MAXK], fac[MAXK];
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
void adde(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}

int sz[MAXN], dp[MAXN][MAXK], ansl[MAXK];
int n, K;
void dfs(int u, int fa = 0) {
	sz[u] = 1;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa)
			dfs(to[i], u);
	static int lhs[2][MAXK], rhs[2][MAXK];
	const size_t SIZ = K + 1 << 2;
	for (int O = 0; O < 2; ++O)
		memset(lhs[O], 0, SIZ);
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa) {
			const int v = to[i];
			for (int O = 0; O < 2; ++O)
				memcpy(rhs[O], lhs[O], SIZ);
			for (int j = 0; j <= sz[v] && j <= K; ++j) {
				for (int k = 0; k <= sz[u] && j + k <= K; ++k)
					fma(rhs[1][j + k], lhs[0][k] + lhs[1][k], dp[v][j]);
				reduce(rhs[0][j] += dp[v][j] - mod);
			}
			for (int O = 0; O < 2; ++O)
				memcpy(lhs[O], rhs[O], SIZ);
			sz[u] += sz[v];
		}
	for (int i = 0; i <= K; ++i) {
		reduce(ansl[i] += lhs[0][i] - mod);
		reduce(lhs[0][i] = lhs[0][i] * 2 - mod);
		reduce(lhs[1][i] = lhs[1][i] * 2 - mod);
		reduce(ansl[i] += lhs[1][i] - mod);
		reduce(dp[u][i] = lhs[0][i] + lhs[1][i] - mod);
	}
	reduce(dp[u][0] += 1 - mod);
	for (int i = K; i; --i)
		reduce(dp[u][i] += dp[u][i - 1] - mod);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K;
	for (int i = 1, b, e; i < n; ++i)
		std::cin >> b >> e, adde(b, e);
	*fac = **S = 1;
	for (int i = 1; i <= K; ++i) {
		for (int j = 1; j <= i; ++j)
			fma(S[i][j] = S[i - 1][j - 1], S[i - 1][j], j);
		fac[i] = mul(fac[i - 1], i);
	}
	dfs(1);
	int ans = 0;
	for (int i = 0; i <= K; ++i)
		fma(ans, mul(S[K][i], fac[i]), ansl[i]);
	std::cout << ans << std::endl;
	return 0;
}