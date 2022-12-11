#include <bits/stdc++.h>

const int MAXN = 210;
typedef long long LL;
typedef long double db;
typedef LL VT;
struct vec {
	VT x, y;
	vec() { x = y = 0; }
	vec(VT a, VT b) { x = a, y = b; }
// WARN: modify following 4 functions if VT is int
// 1. A * B    2. return LL
	VT operator ^ (vec b) const { return x * b.y - y * b.x; }
	VT operator * (vec b) const { return x * b.x + y * b.y; }
	VT norm2() const { return x * x + y * y; }
	db norm() const { return sqrt(x * x + y * y); }
	vec operator - (vec b) const { return vec(x - b.x, y - b.y); }
	vec operator + (vec b) const { return vec(x + b.x, y + b.y); }
	vec operator * (db k) const { return vec(x * k, y * k); }
	int po() const {
		return y == 0 ? x < 0 : y < 0;
	}
	friend bool operator < (const vec & a, const vec & b) {
		return a.po() == b.po() ? (a ^ b) > 0 : a.po() < b.po();
		// return x == b.x ? y < b.y : x < b.x;
	}
	friend std::istream & operator >> (std::istream & in, vec & x) {
		in >> x.x >> x.y;
		return in;
	}
	friend std::ostream & operator << (std::ostream & out, vec x) {
		out << '(' << x.x << ',' << x.y << ')';
		return out;
	}
} ps[MAXN];
inline LL cross(vec a, vec b, vec c) {
	return (b - a) ^ (c - a);
}
std::vector<std::pair<vec, std::pair<int, int> > > V;
LL dp[MAXN][MAXN][52];
void gma(LL & x, LL y) { x < y ? x = y : 0; }
int n, K;
std::bitset<210> in[MAXN][MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K;
	for (int i = 1; i <= n; ++i) std::cin >> ps[i];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) if (i != j)
			V.emplace_back(ps[i] - ps[j], std::make_pair(j, i));
	std::sort(V.begin(), V.end());
	memset(dp, 0xcf, sizeof dp);
	const LL NINF = ***dp;
	for (int i = 1; i <= n; ++i) dp[i][i][0] = 0;
	const int SZ = V.size();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) if (i != j) {
			for (int k = 1; k <= n; ++k)
				if (cross(ps[i], ps[k], ps[j]) < 0)
					in[i][j].set(k);
		}
	for (int T = 0; T < SZ; ++T) {
		int x, y; std::tie(x, y) = V[T].second;
		LL area = ps[x] ^ ps[y];
		for (int i = 1; i <= n; ++i)
			if ((in[i][x] & in[x][y] & in[y][i]).none())
				for (int j = 0; j < K; ++j) if (dp[i][x][j] != NINF) {
					if (y == i && (j != 0 && j != K - 1)) continue;
					gma(dp[i][y][j + 1], dp[i][x][j] + area);
				}
	}
	LL ans = 0;
	for (int i = 1; i <= n; ++i)
		gma(ans, dp[i][i][K]);
	std::cout << std::fixed << std::setprecision(2);
	std::cout << ans / 2. << std::endl;
	return 0;
}