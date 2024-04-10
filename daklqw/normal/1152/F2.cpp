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
const int MAXK = 13 * (1 << 4);
int id[13][1 << 4], idx;
struct mat {
	int A[MAXK][MAXK];
	friend mat operator * (mat A, mat B) {
		mat res;
		for (int i = 0; i != idx; ++i)
			for (int j = 0; j != idx; ++j) {
				LL r = 0;
				for (int k = 0; k != idx; ++k)
					r += mul(A.A[i][k], B.A[k][j]);
				res.A[i][j] = r % mod;
			}
		return res;
	}
} a, b;
int n, m, K;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K >> m;
	const int U = 1 << m;
	for (int i = 0; i <= K; ++i)
		for (int j = 0; j != U; ++j)
			id[i][j] = idx++;
	for (int i = 0; i <= K; ++i)
		for (int j = 0; j != U; ++j) {
			int s = (j << 1) & (U - 1);
			b.A[id[i][s]][id[i][j]] = 1;
			if (i < K) {
				b.A[id[i + 1][s | 1]][id[i][j]] = 1 + __builtin_popcount(j);
			}
		}
	a.A[id[0][0]][0] = 1;
	for (; n; n >>= 1, b = b * b) if (n & 1) a = b * a;
	int ans = 0;
	for (int i = 0; i != U; ++i)
		reduce(ans += a.A[id[K][i]][0] - mod);
	std::cout << ans << std::endl;
	return 0;
}