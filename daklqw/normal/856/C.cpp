#include <bits/stdc++.h>

const int MAXN = 2010;
const int mod = 998244353;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int f[2][11][MAXN], g[2][11][MAXN];
int n, fac[MAXN << 1], inv[MAXN << 1];
int C(int a, int b) {
	if (b < 0) return 0;
	return a >= b ? (LL) fac[a] * inv[b] % mod * inv[a - b] % mod : 0;
}
int main() {
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i != MAXN << 1; ++i) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mul(inv[mod % i], mod - mod / i);
	}
	for (int i = 2; i != MAXN << 1; ++i)
		inv[i] = mul(inv[i - 1], inv[i]);
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);
	int T; std::cin >> T;
	while (T --> 0) {
		std::cin >> n;
		int now = 1, lst = 0;
		for (int j = 0; j != 11; ++j) {
			memset(f[now][j], 0, n + 1 << 2);
			memset(g[now][j], 0, n + 1 << 2);
		}
		f[now][0][0] = 1;
		g[now][0][0] = 1;
		int co = 0, ce = 0;
		for (int i = 1; i <= n; ++i) {
			int v;
			std::swap(now, lst);
			for (int j = 0; j != 11; ++j) {
				memset(f[now][j], 0, n + 1 << 2);
				memset(g[now][j], 0, n + 1 << 2);
			}
			std::cin >> v;
			int coef = 1, val = 0, t = v;
			while (t) {
				val += coef * (t % 10);
				t /= 10;
				coef = -coef;
			}
			val %= 11, val += val >> 31 & 11;
			coef == 1 ? ++ce : ++co;
			// std::cout << coef << " " << val << std::endl;
			for (int j = 0; j < 11; ++j)
				for (int k = 0; k <= n; ++k) {
					coef == -1 ?
					reduce(f[now][j][k] = (k > 0 ? f[lst][(j + val) % 11][k - 1] : 0) + f[lst][(j - val + 11) % 11][k] - mod) :
					(void) (f[now][j][k] = f[lst][j][k]);
					coef == 1 ?
					reduce(g[now][j][k] = (k > 0 ? g[lst][(j + val) % 11][k - 1] : 0) + g[lst][(j - val + 11) % 11][k] - mod) :
					(void) (g[now][j][k] = g[lst][j][k]);
				}
		}
	//	std::cout << co << " " << ce << std::endl;
	//	std::cout << "dEBUG: ";
	//	for (int i = 0; i != 11; ++i)
	//		std::cout << f[now][i][co >> 1] << " ";
	//	std::cout << std::endl;
		int ans = 0;
		for (int i = 0; i <= ce; ++i) {
			for (int j = 0; j != 11; ++j) {
				int val = mul(f[now][j][co >> 1], g[now][(11 - j) % 11][i]);
		//		if (val)
		//			std::cout << i << " " << j << " " << g[now][(11 - j) % 11][i] << std::endl;
				val = mul(val, fac[co >> 1]);
				val = mul(val, fac[co + 1 >> 1]);
				int oi = co + 1 >> 1, ei = co + 2 >> 1;
				val = mul(val, fac[i]);
				if (i) val = mul(val, C(i + oi - 1, oi - 1));
				val = mul(val, fac[ce - i]);
				if (ce - i) val = mul(val, C(ce - i + ei - 1, ei - 1));
				reduce(ans += val - mod);
				// std::cout << i << " " << j << " " << val << std::endl;
			}
		}
		std::cout << ans << '\n';
	}
	return 0;
}