#include <bits/stdc++.h>

const int MAXN = 4010;
const int mod = 998244353;
const int MAXK = 76;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }
int n, K;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;

int vis[MAXN], sz[MAXN];
int sznow, rtv, rt;
int li[MAXN], bak;
int xs[MAXN << 1], ys[MAXN << 1], ypa;
void getroot(int u, int fa = 0) {
	int maxv = 0; sz[u] = 1;
	li[++bak] = u;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa && !vis[to[i]]) {
			xs[++ypa] = u, ys[ypa] = to[i];
			xs[++ypa] = to[i], ys[ypa] = u;
			getroot(to[i], u);
			sz[u] += sz[to[i]];
			maxv = std::max(maxv, sz[to[i]]);
		}
	maxv = std::max(maxv, sznow - sz[u]);
	if (maxv < rtv) rtv = maxv, rt = u;
}
void init(int sz) {
	sznow = sz, rtv = sz + 1, rt = 0;
}
int f[MAXN][MAXK], g[MAXN][MAXK];
void divide(int u, int * A) {
	for (int i = 1; i <= bak; ++i) {
		memset(f[li[i]], 0, K + 1 << 2);
		memset(g[li[i]], 0, K + 1 << 2);
	}
	f[u][0] = g[u][0] = 1;
	for (int i = 1; i <= K; ++i)
		for (int j = 1; j <= ypa; ++j) {
			if (ys[j] != u)
				reduce(f[ys[j]][i] += f[xs[j]][i - 1] - mod);
			reduce(g[ys[j]][i] += g[xs[j]][i - 1] - mod);
		}
	for (int i = 1; i <= bak; ++i)
		for (int j = 0; j <= K; ++j)
			for (int k = 0; k <= j; ++k)
				reduce(A[j] += mul(f[li[i]][k], g[li[i]][j - k]) - mod);
	bak = ypa = 0;
	vis[u] = true;
	for (int i = head[u]; i; i = nxt[i])
		if (!vis[to[i]]) {
			getroot(to[i]), bak = ypa = 0;
			init(sz[to[i]]);
			getroot(to[i]);
			divide(rt, A);
		}
}
void solve(int * A) {
	for (int i = 1, b, e; i < n; ++i) {
		std::cin >> b >> e;
		nxt[++tot] = head[b]; to[head[b] = tot] = e;
		nxt[++tot] = head[e]; to[head[e] = tot] = b;
	}
	memset(vis, 0, n + 1 << 2);
	init(n); getroot(1);
	divide(rt, A);
	memset(head, 0, n + 1 << 2); tot = 0;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int n1, n2;
	std::cin >> n1 >> n2 >> K;
	static int A[100], B[100];
	n = n1, solve(A);
	n = n2, solve(B);
	static int C[110][110];
	for (int i = 0; i <= K; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			reduce(C[i][j] = C[i - 1][j - 1] + C[i - 1][j] - mod);
	}
	int ans = 0;
	for (int i = 0; i <= K; ++i)
		reduce(ans += (LL) A[i] * B[K - i] % mod * C[K][i] % mod - mod);
	std::cout << ans << std::endl;
	return 0;
}