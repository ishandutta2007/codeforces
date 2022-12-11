#include <bits/stdc++.h>

const int MAXN = 50;
const int mod = 1004535809;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }

char mat[MAXN][MAXN];
int n;
int fa[MAXN], siz[MAXN];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int imap[MAXN], idx;
int out[MAXN];
void adde(int b, int e) {
	out[b] |= 1 << e;
	out[e] |= 1 << b;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 0; i < n; ++i) fa[i] = i;
	for (int i = 0; i < n; ++i) {
		std::cin >> mat[i];
		for (int j = 0; j < n; ++j)
			if (mat[i][j] == 'A')
				fa[find(i)] = find(j);
	}
	int ans = n - 1;
	for (int i = 0; i < n; ++i) ++siz[find(i)];
	for (int i = 0; i < n; ++i)
		if (i == fa[i]) {
			if (siz[i] > 1) imap[i] = idx++, ++ans;
			else imap[i] = -1;
		}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (mat[i][j] == 'X') {
				if (find(i) == find(j)) {
					std::cout << -1 << std::endl;
					return 0;
				} else {
					int x = imap[find(i)], y = imap[find(j)];
					if (x == -1 || y == -1) continue;
					adde(x, y);
				}
			}
	const int U = 1 << idx;
	static int dp[1 << 23];
	dp[0] = 1;
	for (int i = 1; i != U; ++i) {
		int lst = i & i - 1;
		if (!dp[lst]) continue;
		int u = __builtin_ctz(i);
		dp[i] = true;
		for (int j = 0; j != n && dp[i]; ++j)
			if (lst >> j & 1)
				dp[i] &= !(out[j] >> u & 1);
	}
	for (int i = 0; i != idx; ++i)
		for (int j = 0; j != U; ++j)
			if (j >> i & 1)
				dp[j] += dp[j ^ (1 << i)];
	static int pw[1 << 23];
	for (int i = 0; i != U; ++i) pw[i] = 1;
	for (int i = 0; i <= idx; ++i) {
		int sm = 0;
		for (int j = 0; j != U; ++j) {
			if (__builtin_parity((U - 1) ^ j))
				reduce(sm -= pw[j]);
			else reduce(sm += pw[j] - mod);
		}
		if (sm) {
			ans -= idx - i;
			break;
		}
		for (int j = 0; j != U; ++j)
			pw[j] = mul(pw[j], dp[j]);
	}
	std::cout << ans << std::endl;
	return 0;
}