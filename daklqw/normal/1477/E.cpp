#include <bits/stdc++.h>

const int MAXN = 2e5 + 10;
const int MAXB = 1 << 20;
typedef long long LL;
const LL NINF = std::numeric_limits<LL>::min();
typedef std::pair<int, LL> pi;
struct BIT {
	int tr[MAXB];
	LL sm[MAXB];
	LL all;
	void add(int x, int v) {
		int d = x++ * v;
		for (all += d; x < MAXB; x += x & -x)
			tr[x] += v, sm[x] += d;
	}
	pi getsm(int x) {
		x = std::min(x, MAXB - 2);
		int fi = 0; LL se = 0;
		for (++x; x; x &= x - 1)
			fi += tr[x], se += sm[x];
		return std::make_pair(fi, se);
	}
	int kth(int k) {
		--k; int r = 0;
		for (int i = 19, t; ~i; --i)
			if ((t = r | 1 << i) < MAXB && tr[t] <= k)
				k -= tr[r = t];
		return r;
	}
} bs[2];
int n, m;
int ma0, ma1, mi0, mi1;
LL qry0(int x) {
	return bs[0].all - (LL) x * n;
}
LL qry1(int x) {
	auto c = bs[1].getsm(std::max(x, 0) - 1);
	return (bs[1].all - c.second) - (LL) (m - c.first) * x;
}
int A[2][MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int Q;
	std::cin >> n >> m >> Q;
	for (int i = 1; i <= n; ++i)
		std::cin >> A[0][i], bs[0].add(A[0][i], 1);
	for (int i = 1; i <= m; ++i)
		std::cin >> A[1][i], bs[1].add(A[1][i], 1);
	while (Q --> 0) {
		int opt, x, y;
		std::cin >> opt >> x;
		if (opt <= 2) {
			--opt;
			std::cin >> y;
			bs[opt].add(A[opt][x], -1);
			bs[opt].add(A[opt][x] = y, 1);
		} else {
			ma0 = bs[0].kth(n), ma1 = bs[1].kth(m);
			mi0 = bs[0].kth(1), mi1 = bs[1].kth(1);
			LL ans = NINF;
			int dd = std::min(mi0, mi1);
			auto _solve = [x, dd] (int k, int b) {
				if (k < 1) return NINF;
				if (b == 0 && k > n) return NINF;
				if (b == 1 && k > m) return NINF;
				int fi = bs[b].kth(k) - x;
				int dm = std::min(fi, dd);
				LL r = qry0(dm) - qry1(fi);
				if (!b) r += dm - fi;
				return r;
			};
			auto solve = [_solve] (int k, int b) {
				LL re = NINF;
				for (int i = -1; i <= 1; ++i)
					re = std::max(re, _solve(k + i, b));
				return re;
			};
			// int sp0 = bs[0].getsm(dd + x).first;
			int sp1 = bs[1].getsm(dd + x).first;
			ans = std::max(ans, solve(1, 0));
			ans = std::max(ans, solve(1, 1));
			ans = std::max(ans, solve(n, 0));
			ans = std::max(ans, solve(m, 1));
			ans = std::max(ans, solve(bs[0].getsm(ma1 + x).first, 0));
			ans = std::max(ans, solve(std::min(m - n, sp1), 1));
			if (m - n - 1 > 0) {
				int vx = bs[1].kth(m - n - 1);
				ans = std::max(ans, solve(bs[0].getsm(vx + x).first, 0));
			}
			std::cout << ans << '\n';
		}
	}
	return 0;
}