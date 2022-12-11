#include <bits/stdc++.h>

const int MAXN = 410;
const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int f[MAXN][MAXN];
int n;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	f[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n; ++j)
			for (int k = 0; j + k <= n; ++k) {
				const int v = mul(f[i - 1][j], f[i - 1][k]);
				reduce(f[i][j + k + 1] += v - mod);
				reduce(f[i][j + k] += mul(v, j + k << 1 | 1) - mod);
				reduce(f[i][j + k - 1] += mul(v, (j + k) * (j + k - 1)) - mod);
			}
	}
	std::cout << f[n][1] << std::endl;
	return 0;
}