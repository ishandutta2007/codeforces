#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
const int MAXK = 110;
const int mod = 1e9 + 7;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
void fma(int & x, int y, int z) {
	x = ((LL) y * z + x) % mod;
}

int n, K;
int fac[MAXN];
typedef std::map<int, int> M;
M sx, sy;
int fa[MAXK];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int mat[MAXK][MAXK];
int get(M & m, int x) {
	if (!m.count(x)) {
		int t = m.size();
		return m[x] = t;
	}
	return m[x];
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	for (int i = *fac = 1; i != MAXN; ++i)
		fac[i] = mul(fac[i - 1], i);
	std::cin >> n >> K;
	for (int i = 1; i <= K * 2; ++i) fa[i] = i;
	for (int i = 1, x, y, z; i <= K; ++i) {
		std::cin >> x >> y >> z;
		reduce(z -= 1);
		x = get(sx, x) + 1;
		y = get(sy, y) + 1;
		mat[x][y] = z;
		fa[find(y + K)] = find(fa[x]);
	}
	static int ans[MAXK];
	*ans = 1;
	for (int T = 1; T <= K; ++T) if (fa[T] == T) {
		sx.clear(), sy.clear();
		static int A[MAXK][MAXK];
		memset(A, 0, sizeof A);
		for (int j = 1; j <= K; ++j)
			if (find(j) == T) get(sx, j);
		for (int j = 1; j <= K; ++j)
			if (find(j + K) == T) get(sy, j);
		if (sx.empty() || sy.empty()) continue;
		bool swp = false;
		if (sx.size() < sy.size())
			std::swap(sx, sy), swp = true;
		for (auto a : sx)
			for (auto b : sy) {
				int tx = a.first, ty = b.first;
				A[a.second][b.second] = swp ? mat[ty][tx] : mat[tx][ty];
			}
		const int L = sx.size(), R = sy.size();
		const int U = 1 << R;
		int S = 0;
		static int f[1 << 25];
		memset(f, 0, U << 2);
		f[0] = 1;
		for (int i = 0; i < L; ++i) {
			static int tmp[1 << 25];
			memcpy(tmp, f, U << 2);
			for (int j = 0; j < R; ++j) if (A[i][j]) {
				const int D = S - (S & (1 << j));
				for (int k = D; k; k = k - 1 & D)
					fma(f[k | (1 << j)], tmp[k], A[i][j]);
				fma(f[1 << j], tmp[0], A[i][j]);
				S |= 1 << j;
			}
		}
		static int g[MAXK], h[MAXK];
		memset(g, 0, sizeof g);
		memset(h, 0, sizeof h);
		for (int i = 0; i < U; ++i)
			reduce(g[__builtin_popcount(i)] += f[i] - mod);
		for (int i = 0; i <= K; ++i)
			for (int j = 0; j <= K; ++j)
				fma(h[i + j], ans[i], g[j]);
		memcpy(ans, h, K + 1 << 2);
	}
	int Ans = 0;
	for (int i = 0; i <= K && i <= n; ++i)
		fma(Ans, ans[i], fac[n - i]);
	std::cout << Ans << std::endl;
	return 0;
}