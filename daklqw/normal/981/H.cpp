#include <bits/stdc++.h>

const int MAXN = 262145;
const int mod = 998244353;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }
int wn[MAXN], wt[MAXN];
int rev[MAXN], lim, dig;
void init(int sz) {
	lim = 1, dig = -1;
	while (lim < sz) lim <<= 1, ++dig;
	for (int i = 0; i < lim; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << dig;
	const int Wn = pow(3, (mod - 1) / lim);
	*wn = 1;
	for (int i = 1; i <= lim; ++i) wn[i] = mul(wn[i - 1], Wn);
}
void NTT(int * A, int typ) {
	for (int i = 0; i < lim; ++i) if (i < rev[i]) std::swap(A[i], A[rev[i]]);
	for (int mid = 1; mid != lim; mid <<= 1) {
		const int Wn = lim / mid / 2;
		for (int i = 0, W = 0; i != mid; ++i, W += Wn)
			wt[i] = wn[typ == 1 ? W : lim - W];
		for (int k = 0; k != lim; k += mid << 1) {
			const int * W = wt;
			for (int l = 0; l != mid; ++l) {
				const int X = A[l + k], Y = mul(*W++, A[l + k + mid]);
				reduce(A[l + k] += Y - mod);
				reduce(A[l + k + mid] = X - Y);
			}
		}
	}
	if (typ == -1) {
		const int liminv = pow(lim, mod - 2);
		for (int i = 0; i != lim; ++i) A[i] = mul(A[i], liminv);
	}
}
int head[MAXN], nxt[MAXN], to[MAXN], tot;
void adde(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
int n, K;
int fac[MAXN], inv[MAXN];
int dp[MAXN], sz[MAXN];
typedef std::vector<int> V;
int li[MAXN], lp[MAXN], bak;
V operator * (const V & a, const V & b) {
	static int ta[MAXN], tb[MAXN];
	const int ls = a.size(), rs = b.size();
	const int sz = ls + rs - 1; init(sz);
	std::copy(a.begin(), a.end(), ta);
	std::copy(b.begin(), b.end(), tb);
	std::fill(ta + ls, ta + lim, 0);
	std::fill(tb + rs, tb + lim, 0);
	NTT(ta, 1); NTT(tb, 1);
	for (int i = 0; i < lim; ++i) ta[i] = mul(ta[i], tb[i]);
	NTT(ta, -1);
	return V(ta, ta + sz);
}
V operator + (const V & a, const V & b) {
	static int res[MAXN];
	const int ls = a.size(), rs = b.size();
	const int sz = std::max(ls, rs);
	std::fill(res, res + sz, 0);
	for (int i = 0; i != ls; ++i) res[i] = a[i];
	for (int i = 0; i != rs; ++i) reduce(res[i] += b[i] - mod);
	return V(res, res + sz);
}
typedef std::pair<V, V> pi;
pi divcon(int l, int r) {
	if (l > r) return pi({1}, {0});
	if (l == r) return pi({1, li[l]}, {lp[l]});
	const int mid = l + r >> 1;
	pi L = divcon(l, mid), R = divcon(mid + 1, r);
	return pi(L.first * R.first, L.first * R.second + L.second * R.first);
}
std::pair<int, int> solve(int up) {
	pi rx = divcon(1, bak);
	const V & r1 = rx.first;
	V r2 = rx.second * V({1, up});
	int ans = 0, ans2 = 0;
	const int sz = r1.size();
	for (int i = 0; i < sz && i <= K; ++i) {
		reduce(ans += mul(r1[i], inv[K - i]) - mod);
		reduce(ans2 += mul(r2[i], inv[K - i]) - mod);
	}
	ans = mul(ans, fac[K]);
	ans2 = mul(ans2, fac[K]);
	return std::make_pair(ans, ans2);
}
int Ans = 0;
void dfs(int u, int fa = 0) {
	sz[u] = 1;
	for (int i = head[u]; i; i = nxt[i]) if (to[i] != fa) {
		dfs(to[i], u);
		sz[u] += sz[to[i]];
		reduce(Ans += mul(dp[u], dp[to[i]]) - mod);
		reduce(dp[u] += dp[to[i]] - mod);
	}
	for (int i = head[u]; i; i = nxt[i]) if (to[i] != fa)
		li[++bak] = sz[to[i]], lp[bak] = dp[to[i]];
	auto res = solve(n - sz[u]);
	reduce(dp[u] += res.first - mod);
	reduce(Ans += res.second - mod);
	bak = 0;
}
int main() {
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i != MAXN; ++i) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mul(inv[mod % i], mod - mod / i);
	}
	for (int i = 2; i != MAXN; ++i)
		inv[i] = mul(inv[i - 1], inv[i]);
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K;
	if (K == 1)
		return std::cout << ((LL) n * (n - 1) / 2) % mod << std::endl, 0;
	for (int i = 1, t1, t2; i < n; ++i)
		std::cin >> t1 >> t2, adde(t1, t2);
	dfs(1);
	std::cout << Ans << std::endl;
	return 0;
}