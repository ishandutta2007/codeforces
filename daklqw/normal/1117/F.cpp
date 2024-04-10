#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;

int f[17][1 << 17];
int cnt[17], dp[1 << 17], g[1 << 17];
int lst[17];
int n, P;
char buf[MAXN];
int can[17][17];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> P >> buf;
	memset(lst, -1, sizeof lst);
	auto cmp = [] (int a, int b) {
		return lst[a] > lst[b];
	};
	for (int i = 0; i < n; ++i) {
		static int sr[17];
		for (int j = 0; j < P; ++j) sr[j] = j;
		std::sort(sr, sr + P, cmp);
		int mask = 0;
		const int ch = buf[i] - 'a';
		for (int j = 0; j < P; ++j) {
			if (lst[sr[j]] == -1) break;
			f[ch][mask] |= 1 << sr[j];
			if (sr[j] == ch) break;
			mask |= 1 << sr[j];
		}
		lst[ch] = i;
		++cnt[ch];
	}
	const int U = 1 << P;
	for (int i = 0; i < P; ++i)
		for (int j = 0; j < P; ++j)
			for (int k = 0; k != U; ++k)
				if (k >> j & 1)
					f[i][k] |= f[i][k ^ (1 << j)];
	for (int i = 0; i < P; ++i)
		for (int j = 0; j < P; ++j)
			std::cin >> can[i][j];
	int ans = n;
	g[0] = true;
	for (int i = 0; i != U; ++i) {
		if (i)
			dp[i] = dp[i & i - 1] + cnt[__builtin_ctz(i)];
		for (int j = 0; j != P; ++j)
			if (i >> j & 1)
				g[i] |= g[i ^ (1 << j)];
		if (!g[i]) continue;
		bool yes = true;
		for (int j = 0; j < P; ++j) if (!(i >> j & 1))
			for (int k = j; k < P; ++k) if (!(i >> k & 1))
				if ((f[j][i] >> k & 1) || (f[k][i] >> j & 1))
					yes &= can[j][k];
		if (yes) ans = std::min(ans, n - dp[i]);
		else g[i] = false;
	}
	std::cout << ans << std::endl;
	return 0;
}