#include <bits/stdc++.h>

const int MAXN = 210;
const int mod = 1e9 + 7;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int x, int y) { return (LL) x * y % mod; }
void fma(int & x, int y, int z) {
	x = ((LL) y * z + x) % mod;
}
struct vec {
	int x, y;
	vec() { x = y = 0; }
	vec(int a, int b) { x = a, y = b; }
	vec operator + (vec b) const { return vec(x + b.x, y + b.y); }
	vec operator - (vec b) const { return vec(x - b.x, y - b.y); }
	LL operator ^ (vec b) const { return (LL) x * b.y - (LL) y * b.x; }
	LL operator * (vec b) const { return (LL) x * b.x + (LL) y * b.y; }
	bool operator == (vec b) const { return x == b.x && y == b.y; }
} ps[MAXN];
int n;
LL cross(vec x, vec y, vec z) { return (y - x) ^ (z - x); }
inline int sgn(LL x) { return x < 0 ? -1 : x > 0; }
int dp[MAXN][MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> ps[i].x >> ps[i].y;
	LL area = 0;
	for (int i = 1; i <= n; ++i)
		area += ps[i] ^ ps[i == n ? 1 : i + 1];
	for (int i = 1; i < n; ++i) dp[i][i + 1] = 1;
	for (int L = 3; L <= n; ++L)
		for (int l = 1; l + L - 1 <= n; ++l) {
			int r = l + L - 1;
			for (int p = l + 1; p < r; ++p)
				if (sgn(cross(ps[p], ps[r], ps[l])) == sgn(area))
					fma(dp[l][r], dp[l][p], dp[p][r]);
		}
	std::cout << dp[1][n] << std::endl;
	return 0;
}