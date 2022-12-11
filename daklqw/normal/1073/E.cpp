#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;
const int MAXN = 70;
const int Dollar1 = 998244353;
inline void add(int & x, const int y) { x += y - Dollar1; x += x >> 31 & Dollar1; }
inline int up(const int x) { return x >= Dollar1 ? x - Dollar1 : x; }
inline int down(const int x) { return x < 0 ? x + Dollar1 : x; }
inline int mul(const int x, const int y) { return static_cast<LL> (x) * y % Dollar1; }
struct Status {
	int cnt, add;
	explicit Status(int _ = -1, int __ = -1) { cnt = _; add = __; }
	inline bool operator ~ () const { return ~cnt; }
} f[MAXN][1 << 10];
bool can[1 << 10];
int dig[MAXN], pw10[MAXN];
Status dfs(int dd, int s, bool lim, bool pre) {
	if (!can[s]) return Status(0, 0);
	if (!~dd) return Status(1, 0);
	Status & dp = f[dd][s];
	if (!lim && !pre && ~dp) return dp;
	const int UP = lim ? dig[dd] : 9;
	Status res(0, 0);
	for (int i = 0; i <= UP; ++i) {
		int tars = s;
		if (!(pre && i == 0)) tars |= 1 << i;
		if (!can[s]) continue;
		Status rt = dfs(dd - 1, tars, lim && i == UP, pre && i == 0);
		// TODO
		add(res.cnt, rt.cnt);
		add(res.add, rt.add);
		add(res.add, mul(mul(i, pw10[dd]), rt.cnt));
	}
	if (!lim && !pre) dp = res;
	return res;
}

LL l, r;
int k;
int calc(LL x) {
	int dd = 0;
	while (x) {
		dig[dd++] = x % 10;
		x /= 10;
	}
	return dfs(dd - 1, 0, true, true).add;
}
int main() {
	pw10[0] = 1;
	for (int i = 1; i != MAXN; ++i) pw10[i] = mul(pw10[i - 1], 10);
	std::cin >> l >> r >> k;
	for (int i = 0; i != 1024; ++i)
		if (__builtin_popcount(i) <= k)
			can[i] = true;
	std::cout << down(calc(r) - calc(l - 1)) << std::endl;
	return 0;
}