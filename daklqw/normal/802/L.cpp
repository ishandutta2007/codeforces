#include <bits/stdc++.h>

const int MAXN = 100010;
const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }

int n;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], val[MAXN << 1], tot;
int deg[MAXN];
void adde(int b, int e, int v) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e; val[tot] = v;
	nxt[++tot] = head[e]; to[head[e] = tot] = b; val[tot] = v;
	++deg[b], ++deg[e];
}
int A[MAXN], B[MAXN];
int prob[MAXN];
void dfs(int u, int fa = 0) {
	if (deg[u] == 1 && fa) return (void) (A[u] = B[u] = 0);
	int pb = pow(deg[u], mod - 2);
	int suma = 0, coef = 0, sumb = 0;
	for (int i = head[u]; i; i = nxt[i]) {
		if (to[i] != fa) {
			dfs(to[i], u);
			reduce(suma += A[to[i]] - mod);
			reduce(sumb += B[to[i]] - mod);
		}
		reduce(sumb += val[i] - mod);
	}
	reduce(coef = 1 - mul(suma, pb));
	coef = pow(coef, mod - 2);
	sumb = mul(sumb, pb);
	B[u] = mul(sumb, coef);
	A[u] = mul(pb, coef);
}
int ta[MAXN], tb[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	for (int i = 1, t1, t2, t3; i < n; ++i)
		std::cin >> t1 >> t2 >> t3, adde(++t1, ++t2, t3);
	dfs(1);
	std::cout << B[1] << std::endl;
	return 0;
}