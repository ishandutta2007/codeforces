#include <bits/stdc++.h>

const int MAXN = 3610;
const int mod = 998244353;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int n, H, W;
bool vx[MAXN], vy[MAXN];
int C[MAXN][MAXN];
int f[MAXN][MAXN], g[MAXN][MAXN];
int MA;
void conv(int * tar, const int * A, const int * B) {
	static int tmp[MAXN];
	int ca = MA + 1, cb = MA + 1; 
	while (ca && !A[ca - 1]) --ca;
	while (cb && !B[cb - 1]) --cb;
	int sz = ca + cb - 1;
	memset(tmp, 0, sz << 2);
	for (int i = 0; i != ca; ++i)
		for (int j = 0; j != cb; ++j)
			tmp[i + j] = (tmp[i + j] + (LL) A[i] * B[j]) % mod;
	memcpy(tar, tmp, sz << 2);
}
int fac[MAXN];
void trans(bool * vis, int n, int f[MAXN][MAXN]) {
	static int h[MAXN];
	memset(h, 0, sizeof h);
	h[0] = 1; vis[n + 1] = true;
	int lst = 0;
	std::vector<int> V;
	for (int i = 1; i <= n + 1; ++i)
		if (vis[i]) {
			if (i - lst - 1) V.push_back(i - lst - 1);
			lst = i;
		}
	int sm = 0;
	for (auto m : V) {
		sm += m;
		static int dp[MAXN][MAXN], ta[MAXN];
		for (int i = 0; i <= m; ++i)
			memset(dp[i], 0, m + 1 << 2);
		dp[0][0] = 1;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j <= i; ++j) {
				reduce(dp[i + 1][j] += dp[i][j] - mod);
				reduce(dp[i + 2][j + 1] += dp[i][j] - mod);
			}
		}
		memset(ta, 0, sizeof ta);
		for (int j = 0; j <= m; ++j) ta[j] = dp[m][j];
		conv(h, h, ta);
	}
	for (int j = 0; j <= sm; ++j)
		for (int i = 0; i * 2 <= sm && i <= j; ++i)
			f[j][i] = (LL) h[i] * C[sm - i * 2][j - i] % mod * fac[i] % mod;
}
int main() {
	fac[0] = 1;
	for (int i = 1; i != MAXN; ++i)
		fac[i] = mul(fac[i - 1], i);
	for (int i = 0; i != MAXN; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			reduce(C[i][j] = C[i - 1][j - 1] + C[i - 1][j] - mod);
	}
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> H >> W >> n; MA = std::max(H, W);
	for (int i = 1; i <= n; ++i)
		for (int j = 1, x, y; j <= 2; ++j) {
			std::cin >> x >> y;
			vx[x] = vy[y] = true;
		}
	trans(vx, H, f), trans(vy, W, g);
	int ans = 0;
	for (int i = 0; i <= MA; ++i)
		for (int j = 0; j <= i; ++j)
			ans = (ans + (LL) f[i][j] * g[i][i - j]) % mod;
	std::cout << ans << std::endl;
	return 0;
}