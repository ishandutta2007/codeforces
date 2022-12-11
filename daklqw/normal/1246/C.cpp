#include <bits/stdc++.h>

const int MAXN = 2010;
const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int fastpow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}

int f[MAXN][MAXN], g[MAXN][MAXN];
int down[MAXN][MAXN], right[MAXN][MAXN], mat[MAXN][MAXN];
int n, m;
char buf[MAXN];
void addf(int a, int x, int y, int v) {
	if (x > y) return ;
	// std::cout << "ADDF " << a << ' ' << x << ' ' << y << ' ' << v << std::endl;
	reduce(f[a][x] += v - mod);
	reduce(f[a][y + 1] -= v);
}
void addg(int a, int x, int y, int v) {
	if (x > y) return ;
	// std::cout << "ADDG " << a << ' ' << x << ' ' << y << ' ' << v << std::endl;
	reduce(g[x][a] += v - mod);
	reduce(g[y + 1][a] -= v);
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		std::cin >> buf;
		for (int j = 1; j <= m; ++j)
			mat[i][j] = buf[j - 1] == 'R';
	}
	for (int i = 1; i <= n; ++i)
		for (int j = m; j; --j)
			right[i][j] = mat[i][j] + right[i][j + 1];
	for (int i = n; i; --i)
		for (int j = 1; j <= m; ++j)
			down[i][j] = down[i + 1][j] + mat[i][j];
	f[1][1] = 1; f[1][2] = -1;
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			reduce(f[i][j] += f[i][j - 1] - mod);
			reduce(g[i][j] += g[i - 1][j] - mod);
			// std::cout << "DP " << i << ' ' << j << ' ' << f[i][j] << ' ' << g[i][j] << std::endl;
			int tf = right[i][j] - mat[i][j], td = down[i][j] - mat[i][j];
			int nf = f[i][j];
			// f
			td += mat[i][j];
			// std::cout << "NOW " << tf << ' ' << td << std::endl;
			if (j + tf > m || i + td > n) nf = 0;
			addf(i + 1, j + 1, m - tf, nf);
			addg(j + 1, i + 1, n - td, nf);
			if (i == n && j == m) reduce(ans += nf - mod);
			else {
				if (i == n && tf == 0) reduce(ans += nf - mod);
				if (j == m && td == 0) reduce(ans += nf - mod);
			}
			td -= mat[i][j];
			// g
			nf = g[i][j];
			tf += mat[i][j];
			// std::cout << "NOW " << tf << ' ' << td << std::endl;
			if (j + tf > m || i + td > n) nf = 0;
			addf(i + 1, j + 1, m - tf, nf);
			addg(j + 1, i + 1, n - td, nf);
			if (i == n && j == m) reduce(ans += nf - mod);
			else {
				if (i == n && tf == 0) reduce(ans += nf - mod);
				if (j == m && td == 0) reduce(ans += nf - mod);
			}
			tf -= mat[i][j];
		}
	std::cout << ans << std::endl;
	return 0;
}