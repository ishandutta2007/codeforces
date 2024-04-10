#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iomanip>

const int MAXN = 110;
struct S {
	long double a, b, c;
	explicit S(long double _ = 0, long double __ = 0, long double ___ = 0) {
		a = _; b = __; c = ___;
	}
	inline S operator / (const long double x) const {
		return S(a / x, b / x, c / x);
	}
	inline S operator * (const long double x) const {
		return S(a * x, b * x, c * x);
	}
	inline friend S operator + (const S & a, const S & b) {
		return S(a.a + b.a, a.b + b.b, a.c + b.c);
	}
	inline S & operator = (const S & b) {
		this -> a = b.a; this -> b = b.b; this -> c = b.c;
		return *this;
	}
} f[MAXN][MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN];
S dfs(int a, int b, int c) {
	int x = (!a) + (!b) + (!c);
	if (x == 2) return S(a > 0, b > 0, c > 0);
	S & dp = f[a][b][c];
	if (vis[a][b][c]) return dp;
	vis[a][b][c] = true;
	double tx = (a * b) + (b * c) + (c * a);
	if (a && b) dp = dp + dfs(a, b - 1, c) * a * b / tx;
	if (b && c) dp = dp + dfs(a, b, c - 1) * b * c / tx;
	if (a && c) dp = dp + dfs(a - 1, b, c) * a * c / tx;
	return dp;
}

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;
	S res = dfs(a, b, c);
	std::cout << std::fixed << std::setprecision(14) << res.a << " ";
	std::cout << std::fixed << std::setprecision(14) << res.b << " ";
	std::cout << std::fixed << std::setprecision(14) << res.c << std::endl;
	return 0;
}