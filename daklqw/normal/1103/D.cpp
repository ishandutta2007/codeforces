#include <bits/stdc++.h>

const int MAXN = 1e6 + 10;
typedef long long LL;
void gmi(int & x, int y) { x > y ? x = y : 0; }
void gmi(LL & x, LL y) { x > y ? x = y : 0; }
LL K;
LL A[MAXN];
int C[MAXN];
LL gcd(LL a, LL b) {
	return b ? gcd(b, a % b) : a;
}
int n;
LL li[30]; int cnt[30], bak;

typedef std::vector<LL> VI;
std::map<LL, std::vector<int> > mi;
std::map<LL, VI> ms;
int cl[1 << 11], cb;
LL dp[12][1 << 11];
void dfs(int S, int mask, LL now, const VI & vl) {
	if (now > K) return ;
	if (S == bak) { cl[cb++] = mask; return ; }
	dfs(S + 1, mask, now, vl);
	dfs(S + 1, mask | 1 << S, now * vl[S], vl);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K;
	LL g = 0;
	for (int i = 1; i <= n; ++i)
		std::cin >> A[i], g = gcd(g, A[i]);
	for (int i = 1; i <= n; ++i)
		std::cin >> C[i];
	LL t = g;
	for (int i = 2; (LL) i * i <= t; ++i)
		if (t % i == 0) {
			int cc = 0;
			while (t % i == 0) t /= i, ++cc;
			li[bak] = i, cnt[bak++] = cc;
		}
	if (t > 1) li[bak] = t, cnt[bak++] = 1;
	for (int i = 1; i <= n; ++i) {
		VI tx(bak, 1); t = 1;
		for (int j = 0; j < bak; ++j)
			while (A[i] % li[j] == 0)
				A[i] /= li[j], t *= li[j], tx[j] *= li[j];
		if (!mi.count(t)) ms[t] = tx;
		mi[t].push_back(C[i]);
	}
	memset(dp, 0x3f, sizeof dp);
	const LL INFL = **dp;
	const int U = 1 << bak;
	**dp = 0;
	LL ans = INFL;
	for (auto t : ms) {
		dfs(0, 0, 1, t.second);
		std::vector<int> & lx = mi[t.first];
		std::sort(lx.begin(), lx.end());
		for (int T = 0; T < lx.size() && T < bak; ++T) {
			for (int i = bak; i;--i) {
				for (int j = 0; j < cb; ++j) {
					const int xc = U - 1 - cl[j];
					for (int k = xc; ; k = k - 1 & xc) {
						if (dp[i - 1][k] != INFL)
							gmi(dp[i][cl[j] | k], dp[i - 1][k] + lx[T]);
						if (!k) break;
					}
				}
			}
		}
		cb = 0;
	}
	for (int i = 0; i <= bak; ++i)
		if (dp[i][U - 1] != INFL)
			gmi(ans, dp[i][U - 1] * i);
	if (ans == INFL) ans = -1;
	std::cout << ans << std::endl;
	return 0;
}