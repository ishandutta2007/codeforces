#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
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
void fms(int & x, int y, int z) {
	x = ((LL) (mod - y) * z + x) % mod;
}

int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
void adde(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
int in[MAXN], out[MAXN], idx;
int ST[18][MAXN << 1];
void dfs(int u, int f = 0) {
	ST[0][++idx] = u;
	in[u] = idx;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != f) {
			dfs(to[i], u);
			ST[0][++idx] = u;
		}
	out[u] = idx;
}
int gmi(int a, int b) { 
	return in[a] < in[b] ? a : b;
}
int LCA(int a, int b) {
	a = in[a], b = in[b];
	if (a > b) std::swap(a, b);
	const int L = std::__lg(++b - a);
	return gmi(ST[L][a], ST[L][b - (1 << L)]);
}

namespace ex {
	int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
	void adde(int b, int e) {
		nxt[++tot] = head[b]; to[head[b] = tot] = e;
		nxt[++tot] = head[e]; to[head[e] = tot] = b;
	}
	int imp[MAXN];
	void clr(int * li, int n) {
		tot = 0;
		for (int i = 1; i <= n; ++i) head[li[i]] = 0;
		for (int i = 1; i <= n; ++i) imp[li[i]] = 0;
	}
	int M;
	const int MAXL = 310;
	const int BLO = 320;
	int C[MAXL][MAXL];
	int ifac[MAXL];
	void init() {
		ifac[0] = ifac[1] = 1;
		for (int i = 2; i != MAXL; ++i)
			ifac[i] = mul(ifac[mod % i], mod - mod / i);
		for (int i = 2; i != MAXL; ++i)
			ifac[i] = mul(ifac[i - 1], ifac[i]);
		for (int i = 0; i != MAXL; ++i)
			for (int j = C[i][0] = 1; j <= i; ++j)
				reduce(C[i][j] = C[i - 1][j] + C[i - 1][j - 1] - mod);
	}
	int dep[MAXL], mad;
	void dfs(int u, int d = 0, int fa = 0) {
		if (imp[u]) {
			mad = std::max(mad, d);
			++dep[std::min(d++, MAXL - 1)];
		}
		for (int i = head[u]; i; i = nxt[i])
			if (to[i] != fa)
				dfs(to[i], d, u);
	}
	int f[MAXL], g[MAXL];
	int solve(int _M, int R) {
		M = _M;
		mad = 0;
		memset(dep, 0, M + 1 << 2);
		memset(f, 0, M + 1 << 2);
		dfs(R);
		if (mad >= M) return 0;
		for (int i = mad; i <= M; ++i) {
			int & t = f[i] = 1;
			for (int j = 0; j <= mad; ++j)
				t = pow(i - j, dep[j], t);
		}
		int res = 0;
		for (int i = 0; i <= M; ++i) {
			g[i] = f[i];
			for (int j = 0; j < i; ++j)
				fms(g[i], g[j], C[i][j]);
			fma(res, g[i], ifac[i]);
		}
		return res;
	}
}
int n;
int main() {
	ex::init();
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int Q; std::cin >> n >> Q;
	for (int i = 1, b, e; i < n; ++i)
		std::cin >> b >> e, adde(b, e);
	dfs(1);
	for (int i = 1; i != 18; ++i)
		for (int j = 1; j + (1 << i) - 1 <= idx; ++j)
			ST[i][j] = gmi(ST[i - 1][j], ST[i - 1][j + (1 << i - 1)]);
	auto cmp = [] (int a, int b) {
		return in[a] < in[b];
	};
	while (Q --> 0) {
		static int li[MAXN << 1];
		int K, M, R;
		std::cin >> K >> M >> R;
		int bak = K + 1; li[bak] = R;
		for (int i = 1; i <= K; ++i)
			std::cin >> li[i], ex::imp[li[i]] = true;
		std::sort(li + 1, li + 1 + bak, cmp);
		bak = std::unique(li + 1, li + 1 + bak) - li - 1;
		for (int i = bak; i > 1; --i)
			li[++bak] = LCA(li[i], li[i - 1]);
		std::sort(li + 1, li + 1 + bak, cmp);
		bak = std::unique(li + 1, li + 1 + bak) - li - 1;
		static int st[MAXN];
		int top = 0;
		for (int i = 1; i <= bak; ++i) {
			const int u = li[i];
			while (top && in[u] > out[st[top]])
				ex::adde(st[top], st[top - 1]), --top;
			assert(top || i == 1);
			st[++top] = u;
		}
		while (top > 1)
			ex::adde(st[top], st[top - 1]), --top;
		std::cout << ex::solve(M, R) << '\n';
		ex::clr(li, bak);
	}
	return 0;
}