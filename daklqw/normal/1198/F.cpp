#include <bits/stdc++.h>

const int MAXN = 100010;
int n, A[MAXN];
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
typedef std::vector<int> VI;
VI factor(int x) {
	VI res;
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0) {
			res.push_back(i);
			while (x % i == 0) x /= i;
		}
	if (x > 1) res.push_back(x);
	return res;
}
int get(int x, const VI & li) {
	int res = 0, sz = li.size();
	for (int i = 0; i != sz; ++i)
		if (x % li[i] == 0)
			res |= 1 << i;
	return res;
}
const int RR = 9;
bool can[1 << RR][1 << RR];
struct info {
	int x, y, u, t;
} frm[1 << RR][1 << RR];
void gmx(int x, int y, info p) {
	if (!can[x][y]) { can[x][y] = true, frm[x][y] = p; }
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	if (n <= 20) {
		static int dp[1 << 20];
		const int U = 1 << n;
		for (int i = 1; i != U; ++i)
			dp[i] = gcd(dp[i & i - 1], A[__builtin_ctz(i) + 1]);
		for (int i = 1; i + 1 != U; ++i)
			if (dp[i] == 1 && dp[U - 1 - i] == 1) {
				std::cout << "YES" << std::endl;
				for (int j = 0; j < n; ++j)
					std::cout << (i >> j & 1) + 1 << ' ';
				return 0;
			}
		std::cout << "NO" << std::endl;
		return 0;
	}
	VI lhs = factor(A[1]);
	const int LS = lhs.size();
	std::mt19937 rd(time(0) + (size_t) new char);
	int TT = std::max<int>(std::log(1e-10) / std::log(9. / n), 3);
	for (int T = 1; T <= TT; ++T) {
		int at = rd() % (n - 1) + 2;
		VI rhs = factor(A[at]);
		const int RS = rhs.size();
		for (int i = 0; i != (1 << LS); ++i) {
			memset(frm[i], 0, (1 << RS) * sizeof(info));
			memset(can[i], 0, (1 << RS) * sizeof(bool));
		}
		static int cx[20], cy[20], rk[400];
		memset(cx, 0, sizeof cx);
		memset(cy, 0, sizeof cy);
		int bak = 0;
		for (int i = 2; i <= n; ++i) if (i != at) {
			int ls = ~get(A[i], lhs), rs = ~get(A[i], rhs);
			bool can = false;
			for (int j = 0; j != LS && !can; ++j)
				if ((ls >> j & 1) && ++cx[j] <= 20)
					can = true;
			for (int j = 0; j != RS && !can; ++j)
				if ((rs >> j & 1) && ++cy[j] <= 20)
					can = true;
			if (can) rk[++bak] = i;
		}
		can[(1 << LS) - 1][(1 << RS) - 1] = true;
		for (int i = 1; i <= bak; ++i) {
			int ls = get(A[rk[i]], lhs), rs = get(A[rk[i]], rhs);
			for (int j = 0; j != (1 << LS); ++j)
				for (int k = 0; k != (1 << RS); ++k)
					if (can[j][k]) {
						gmx(j & ls, k, (info) {j, k, i, 0});
						gmx(j, k & rs, (info) {j, k, i, 1});
					}
			if (can[0][0]) {
				std::cout << "YES" << std::endl;
				static int mark[MAXN];
				mark[1] = 1;
				int x = 0, y = 0;
				while (x + 1 != (1 << LS) || y + 1 != (1 << RS)) {
					info f = frm[x][y];
					if (f.t == 0) mark[rk[f.u]] = 1;
					std::tie(x, y) = std::tie(f.x, f.y);
				}
				for (int i = 1; i <= n; ++i)
					std::cout << mark[i] + 1 << ' ';
				return 0;
			}
		}
	}
	std::cout << "NO" << std::endl;
	return 0;
}