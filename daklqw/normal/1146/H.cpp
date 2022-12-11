#include <bits/stdc++.h>

const int MAXN = 310;
typedef long long LL;
typedef long double db;
typedef LL VT;
struct vec {
	VT x, y;
	vec() { x = y = 0; }
	vec(VT a, VT b) { x = a, y = b; }
	VT operator ^ (vec b) const { return x * b.y - y * b.x; }
	VT operator * (vec b) const { return x * b.x + y * b.y; }
	VT norm2() const { return x * x + y * y; }
	db norm() const { return sqrt(x * x + y * y); }
	vec operator - (vec b) const { return vec(x - b.x, y - b.y); }
	vec operator + (vec b) const { return vec(x + b.x, y + b.y); }
	vec operator * (db k) const { return vec(x * k, y * k); }
	bool operator < (const vec & b) const {
		return (*this ^ b) > 0;
	}
	friend std::istream & operator >> (std::istream & in, vec & x) {
		in >> x.x >> x.y;
		return in;
	}
	friend std::ostream & operator << (std::ostream & out, vec & x) {
		out << x.x << ' ' << x.y;
		return out;
	}
} ps[MAXN];
typedef std::tuple<vec, int, int> pi;
typedef std::vector<pi> VP;
VP A[4];
int n;
LL dp[MAXN][MAXN][5];
int get(vec x) {
	if (x.x >= 0 && x.y < 0) return 3;
	if (x.x < 0 && x.y <= 0) return 2;
	if (x.x >= 0 && x.y < 0) return 1;
	return 0;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> ps[i];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) if (i != j) {
			vec x = ps[j] - ps[i];
			A[get(x)].emplace_back(x, i, j);
		}
	for (int i = 0; i < 4; ++i) {
		std::sort(A[i].begin(), A[i].end());
		for (auto t : A[i]) {
			++dp[std::get<1>(t)][std::get<2>(t)][0];
			for (int j = 1; j <= n; ++j) if (j != std::get<1>(t))
				for (int k = 0; k < 4; ++k)
					dp[j][std::get<2>(t)][k + 1] += dp[j][std::get<1>(t)][k];
		}
	}
	LL ans = 0;
	for (int i = 1; i <= n; ++i) ans += dp[i][i][4];
	std::cout << ans << std::endl;
	return 0;
}