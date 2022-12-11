#include <bits/stdc++.h>

const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }
const int MAXN = 100010;
const int MAXS = 10000000;
int npri[MAXS + 10], pri[MAXS / 10], diva[MAXS + 10], cnt;
void sieve() {
	diva[1] = 1;
	for (int i = 2; i <= MAXS; ++i) {
		if (!npri[i]) diva[i] = pri[++cnt] = i;
		for (int j = 1, t; j <= cnt && (t = i * pri[j]) <= MAXS; ++j) {
			npri[t] = true;
			diva[t] = pri[j];
			if (i % pri[j] == 0) break;
		}
	}
}
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
void adde(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
int tree[MAXN], in[MAXN], out[MAXN], idx, sz[MAXN];
int n;
void add(int x, int v) {
	for (; x <= n; x += x & -x) tree[x] += v;
}
int qry(int x) {
	int res = 0;
	for (; x; x &= x - 1) res += tree[x];
	return res;
}
void addi(int x, int v) { add(in[x], v), add(out[x] + 1, -v); }
int qryi(int x) { return qry(in[x]); }
int fa[20][MAXN], dep[MAXN];
int LCA(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	for (int t = dep[x] - dep[y]; t; t &= t - 1)
		x = fa[__builtin_ctz(t)][x];
	for (int i = 19; ~i; --i)
		if (fa[i][x] != fa[i][y])
			x = fa[i][x], y = fa[i][y];
	return x == y ? x : fa[0][x];
}
void dfs(int u) {
	in[u] = ++idx; sz[u] = 1;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa[0][u]) {
			fa[0][to[i]] = u;
			dep[to[i]] = dep[u] + 1;
			dfs(to[i]);
			sz[u] += sz[to[i]];
		}
	out[u] = idx;
}
std::vector<int> hav[MAXS + 10], ql[MAXS + 10];
int us[MAXN], vs[MAXN], ks[MAXN], pw[MAXN], ansl[MAXN], lcs[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	sieve();
	std::cin >> n;
	for (int i = 1, t1, t2; i < n; ++i)
		std::cin >> t1 >> t2, adde(t1, t2);
	dfs(1);
	for (int i = 1; i != 20; ++i)
		for (int j = 1; j <= n; ++j)
			fa[i][j] = fa[i - 1][fa[i - 1][j]];
	for (int i = 1; i <= n; ++i) {
		int t; std::cin >> t;
		while (t != 1) {
			int v = diva[t], p = 1;
			while (diva[t] == v) t /= v, p *= v;
			hav[p].push_back(i);
		}
	}
	int Q; std::cin >> Q;
	for (int i = 1; i <= Q; ++i) {
		std::cin >> us[i] >> vs[i] >> ks[i], ansl[i] = 1;
		lcs[i] = LCA(us[i], vs[i]);
		int t = ks[i];
		while (t != 1) {
			int v = diva[t];
			ql[v].push_back(i);
			while (diva[t] == v) t /= v;
		}
	}
	for (int T = 1; T <= cnt; ++T) if (!ql[pri[T]].empty()) {
		const int v = pri[T];
		for (auto u : ql[v]) {
			pw[u] = 0; int t = ks[u];
			while (t % v == 0) t /= v, ++pw[u];
		}
		for (int i = v, j = 1; i <= MAXS; ++j, i = std::min((LL) i * v, 10000001ll)) if (!hav[i].empty()) {
			for (auto u : hav[i]) addi(u, 1);
			for (auto u : ql[v]) {
				int c = qryi(us[u]) + qryi(vs[u]) - qryi(lcs[u]) - qryi(fa[0][lcs[u]]);
				ansl[u] = pow(v, std::min(pw[u], j) * c, ansl[u]);
			}
			for (auto u : hav[i]) addi(u, -1);
		}
	}
	for (int i = 1; i <= Q; ++i) std::cout << ansl[i] << '\n';
	return 0;
}