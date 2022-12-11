#include <bits/stdc++.h>

const int MAXN = 1000010;
int head[MAXN], nxt[MAXN], to[MAXN], tot;
int ind[MAXN], oud[MAXN], que[MAXN], dp[MAXN];
void adde(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	++ind[e], ++oud[b];
}
int n, m, CC;
int mat[20], f[1 << 20];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1, b, e; i <= m; ++i)
		std::cin >> b >> e, adde(b, e);
	int head = 0, tail = -1;
	for (int i = 1; i <= n; ++i) if (!ind[i])
		que[++tail] = i, dp[i] |= 1 << tail;
	CC = tail + 1;
	while (head <= tail) {
		int t = que[head++];
		for (int i = ::head[t]; i; i = nxt[i]) {
			dp[to[i]] |= dp[t];
			if (!--ind[to[i]]) que[++tail] = to[i];
		}
	}
	for (int i = 1, t = 0; i <= n; ++i) if (!oud[i]) {
		for (int j = 0; j < CC; ++j) if (dp[i] >> j & 1)
			mat[j] |= 1 << t;
		++t;
	}
	const int U = 1 << CC;
	for (int i = 1; i != U; ++i) {
		f[i] = f[i & i - 1] | mat[__builtin_ctz(i)];
		if (__builtin_popcount(i) >= __builtin_popcount(f[i]) + (i == U - 1))
			return std::cout << "NO" << std::endl, 0;
	}
	std::cout << "YES" << std::endl;
	return 0;
}