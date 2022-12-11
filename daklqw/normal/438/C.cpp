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
inline int nxt(int x) { return x == n ? 1 : x + 1; }
int sgn(LL x) { return x < 0 ? -1 : x > 0; }
LL cross(vec x, vec y, vec z) { return (y - x) ^ (z - x); }

typedef std::pair<vec, vec> line;
line poly[MAXN];
bool inside(vec a, vec b, vec c) {
	return (b - a) * (a - c) > 0;
}
int _intersect(line a, line b) {
	static vec line::*x = &line::first;
	static vec line::*y = &line::second;
	int lhs = sgn(cross(a.*x, b.*x, b.*y));
	int rhs = sgn(cross(a.*y, b.*x, b.*y));
	if (!lhs && inside(a.*x, b.*x, b.*y)) return true;
	if (!rhs && inside(a.*y, b.*x, b.*y)) return true;
	if (!lhs && !rhs) return false;
	return (lhs == -rhs) * 2;
}
bool intersect(line a, line b) {
	int l = _intersect(a, b), r = _intersect(b, a);
	if ((l | r) & 1) return true;
	return l && r;
}
bool contain(vec x) {
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		vec a = ps[i], b = ps[nxt(i)];
		if (x == a) return false;
		if (a.y < b.y) std::swap(a, b);
		if (x.y >= a.y || x.y < b.y) continue;
		res ^= cross(x, a, b) > 0;
	}
	return res;
}
bool ok[MAXN][MAXN];
int dp[MAXN][MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> ps[i].x >> ps[i].y;
		ps[i].x <<= 1, ps[i].y <<= 1;
	}
	for (int i = 1; i <= n; ++i) {
		poly[i] = line(ps[i], ps[nxt(i)]);
		ok[i][nxt(i)] = ok[nxt(i)][i] = true;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = i + 2; j <= n - (i == 1); ++j) {
			vec mid = ps[i] + ps[j];
			mid.x >>= 1, mid.y >>= 1;
			bool can = contain(mid);
			line now(ps[i], ps[j]);
			for (int k = 1; k <= n && can; ++k)
				can &= !intersect(now, poly[k]);
			ok[i][j] = ok[j][i] = can;
		}
	for (int i = 1; i + 1 <= n; ++i) dp[i][i + 1] = 1;
	for (int L = 3; L <= n; ++L)
		for (int l = 1; l + L - 1 <= n; ++l) {
			int r = l + L - 1;
			if (!ok[l][r]) continue;
			for (int p = l + 1; p < r; ++p)
				if (ok[l][p] && ok[r][p] && cross(ps[l], ps[p], ps[r]) != 0)
					fma(dp[l][r], dp[l][p], dp[p][r]);
		}
	std::cout << dp[1][n] << std::endl;
	return 0;
}