#include <bits/stdc++.h>

const int MAXN = 2e6 + 10;
typedef long long LL;
int n, Q, A[MAXN];
int in[MAXN], out[MAXN], idx;
int head[MAXN], nxt[MAXN];
int dep[MAXN], fa[MAXN];
LL pre[MAXN];
void dfs(int u) {
	in[u] = ++idx;
	for (int i = head[u]; i; i = nxt[i]) dfs(i);
	out[u] = idx;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> Q;
	for (int i = 1; i <= n; ++i) {
		std::cin >> A[i];
		A[i + n] = A[i];
	}
	for (int i = 1; i <= n * 2; ++i)
		pre[i] = pre[i - 1] + A[i];

	while (Q --> 0) {
		LL K; std::cin >> K;
		memset(head, 0, (n + 1) << 3);
		int r = n * 2;
		int ans = 0x3f3f3f3f;
		for (int i = n * 2; i; --i) {
			while (pre[r] - pre[i - 1] > K) --r;
			fa[i] = r + 1;
			dep[i] = dep[r + 1] + 1;
			nxt[i] = head[r + 1], head[r + 1] = i;
		}
		idx = 0;
		dfs(n * 2 + 1);
		r = n * 2 + 1;
		for (int i = n; i; --i) {
			while (r >= i + n || !(in[r] <= in[i] && in[i] <= out[r]))
				--r;
			// assert(fa[r] >= i + n);
			ans = std::min(ans, dep[i] - dep[r] + 1);
		}
		std::cout << ans << '\n';
	}
	return 0;
}