#include <bits/stdc++.h>

const int MAXN = 61;
const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }
int A[MAXN], n;
int f[MAXN][MAXN][MAXN], g[MAXN][MAXN];
int fac[MAXN], inv[MAXN];
int D(int a, int b) { return (LL) fac[a] * inv[a - b] % mod; }
int main() {
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i != MAXN; ++i) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mul(inv[mod % i], mod - mod / i);
	}
	for (int i = 2; i != MAXN; ++i)
		inv[i] = mul(inv[i - 1], inv[i]);
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	f[0][0][0] = 1;
	const int I2 = mod + 1 >> 1;
	for (int i = 3; i <= n; ++i)
		for (int j = 3; j <= i; ++j)
			reduce(f[0][0][i] += (LL) f[0][0][i - j] * D(i - 1, j - 1) % mod * I2 % mod - mod);
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= n; ++j) {
			if (i > 1) f[0][i][j] = mul(i - 1, f[0][i - 2][j]);
			if (j) reduce(f[0][i][j] += mul(j, f[0][i][j - 1]) - mod);
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			for (int k = 0; k <= n; ++k) {
				if (j) f[i][j][k] = mul(j, f[i - 1][j - 1][k]);
				if (k) reduce(f[i][j][k] += mul(k, f[i - 1][j + 1][k - 1]) - mod);
			}
	g[A[1] + 1][A[1]] = 1;
	for (int i = A[1] + 2; i <= n; ++i)
		for (int r = 1; r <= i; ++r) {
			int c2 = 0, c3 = 0;
			for (int k = r; k; --k) {
				c2 += A[k] == 2, c3 += A[k] == 3;
				reduce(g[i][i - r] += mul(g[r][r - k + 1], f[i - r][c2][c3]) - mod);
			}
		}
	int Ans = 0;
	for (int i = 1; i < n; ++i) {
		int c2 = 0, c3 = 0;
		for (int j = i + 1; j <= n; ++j)
			c2 += A[j] == 2, c3 += A[j] == 3;
		reduce(Ans += mul(g[n][n - i], f[0][c2][c3]) - mod);
	}
	std::cout << Ans << std::endl;
	return 0;
}