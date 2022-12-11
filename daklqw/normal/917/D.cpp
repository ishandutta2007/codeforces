#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int Dollar1 = 1000000007;
const int MAXN = 110;
typedef long long LL;
inline int mul(const int x, const int y) { return static_cast<LL> (x) * y % Dollar1; }
inline void mulr(int & x, const int y) { x = static_cast<LL> (x) * y % Dollar1; }
inline void add(int & x, const int y) { x += y - Dollar1, x += x >> 31 & Dollar1; }
inline void dec(int & x, const int y) { x -= y, x += x >> 31 & Dollar1; }
inline int down(const int x) { return x + (x >> 31 & Dollar1); }
inline int fastpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) mulr(res, a);
		mulr(a, a);
		b >>= 1;
	}
	return res;
}
int map[MAXN][MAXN], f[MAXN][MAXN], val[MAXN];
inline void addedge(int b, int e, int v) {
	dec(f[b][e], v); dec(f[e][b], v); f[b][b] += v; f[e][e] += v;
}
int guass(int n) {
	int ans = 1;
	for (int i = 1; i <= n; ++i) {
		int at = 0;
		for (int j = i; j <= n; ++j) if (f[j][i]) { at = j; break; }
		std::swap(f[i], f[at]);
		if (i != at) ans = down(-ans);
		const int I = fastpow(f[i][i], Dollar1 - 2);
		for (int j = i + 1; j <= n; ++j) {
			const int V = mul(f[j][i], I);
			for (int k = i; k <= n; ++k)
				dec(f[j][k], mul(f[i][k], V));
		}
	}
	for (int i = 1; i <= n; ++i) mulr(ans, f[i][i]);
	return ans;
}
int n, t1, t2, poly[MAXN], op[MAXN], tmp[MAXN], inv[MAXN];
int main() {
	inv[0] = inv[1] = 1;
	for (int i = 2; i != MAXN; ++i) inv[i] = mul(inv[Dollar1 % i], Dollar1 - Dollar1 / i);
	scanf("%d", &n);
	for (int i = 1; i != n; ++i) {
		scanf("%d%d", &t1, &t2);
		++map[t1][t2]; ++map[t2][t1];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			for (int k = j + 1; k <= n; ++k)
				if (map[j][k]) addedge(j, k, map[j][k] * i);
				else addedge(j, k, 1);
		val[i] = guass(n - 1);
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k)
				f[j][k] = 0;
	}
	int mx = 1;
	op[0] = 1;
	for (int i = 1; i <= n; ++i) {
		const int I = inv[i];
		mulr(mx, i);
		for (int j = n - 1; j; --j)
			add(op[j], mul(op[j - 1], down(-I)));
	}
	for (int i = 1; i <= n; ++i) {
		int bd = 1;
		for (int j = 1; j <= n; ++j) if (j != i)
			mulr(bd, down(j - i));
		bd = fastpow(bd, Dollar1 - 2);
		mulr(bd, val[i]);
		for (int j = 0; j != n; ++j) tmp[j] = op[j];
		const int I = inv[i];
		for (int j = 0; j < n - 1; ++j) add(tmp[j + 1], mul(tmp[j], I));
		for (int j = 0; j != n; ++j) add(poly[j], mul(mul(tmp[j], bd), inv[i]));
	}
	for (int i = 0; i != n; ++i) printf("%d ", mul(poly[i], mx)); putchar(10);
	return 0;
}