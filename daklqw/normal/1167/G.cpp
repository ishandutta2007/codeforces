#include <bits/stdc++.h>

const int MAXN = 200010, MA = 7010;
typedef long double db;
typedef std::bitset<MA> B;
int n, D, m, A[MAXN];
B L, R;
inline db calc(int x) { return atan2l(1, x); }
inline db calc(int x, int y) {
	return calc(std::max(x, y)) * 2;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cout << std::fixed << std::setprecision(10);
	std::cin >> n >> D;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	std::cin >> m;
	int lst = 0;
	int lcur = 1, rcur = 1;
	for (int i = 1, at; i <= m; ++i) {
		std::cin >> at;
		L <<= at - lst, R >>= at - lst;
		while (lcur <= n && at - A[lcur] - 1 >= MA) ++lcur;
		while (rcur <= n && A[rcur] - at < 0) ++rcur;
		while (lcur <= n && at - A[lcur] - 1 >= 0)
			L.set(at - A[lcur++] - 1);
		while (rcur <= n && A[rcur] - at < MA)
			R.set(A[rcur++] - at);
		lst = at;
		db deg = 0;
		int j = std::lower_bound(A + 1, A + 1 + n, at) - A;
		if (j <= n) deg = std::max(deg, calc(A[j] - at));
		if (j > 1) deg = std::max(deg, calc(at - A[j - 1] - 1));
		int k = (L & (R | (R << 1) | (R >> 1)))._Find_first();
		if (k != MA) {
			for (int l = k ? -1 : 0; l <= 1; ++l)
				if (R[k + l]) deg = std::max(deg, calc(k, k + l));
		}
		std::cout << deg << '\n';
	}
	return 0;
}