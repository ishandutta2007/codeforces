#include <bits/stdc++.h>

const int MAXN = 100010;
typedef long long LL;
int n, m, S; LL T;
int to[40][MAXN];
int dp[2][MAXN];
void predo() {
	int * now = dp[0], * lst = dp[1];
	for (int i = 0; i < n; ++i) now[i] = i;
	for (int i = 1, t; i < n; ++i) {
		std::swap(lst, now);
		t = std::min(n - i, m);
		memcpy(now, lst + i, t << 2);
		memcpy(now + t, lst, m - t << 2);
		t = std::max(i, m);
		memcpy(now + t, lst + t - i, n - t << 2);
		memcpy(now + m, lst + m - i + n, t - m << 2);
	}
	for (int i = 0; i < n; ++i) to[0][i] = now[i];
	for (int i = 1; i != 40; ++i)
		for (int j = 0; j < n; ++j)
			to[i][j] = to[i - 1][to[i - 1][j]];
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> S >> T; --S;
	while (T % n) S = (S >= m ? S - T-- % n + n : S + T--) % n;
	T /= n, predo();
	for (int i = 39; ~i; --i) if (T >> i & 1) S = to[i][S];
	std::cout << S + 1 << std::endl;
	return 0;
}