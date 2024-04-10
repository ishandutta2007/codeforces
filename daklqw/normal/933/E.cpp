#include <bits/stdc++.h>

const int MAXN = 300010;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int A[MAXN], n;
LL dp[MAXN]; int pre[MAXN];
void gmin(int at, int v, int fr) {
	fr = std::max(fr, 0);
	if (dp[fr] + v < dp[at]) {
		dp[at] = dp[fr] + v;
		pre[at] = fr;
	}
}
int li[MAXN], bak;
void add(int at) {
	if (at < 0 || at == n || A[at] == 0 || A[at + 1] == 0) return ;
	li[++bak] = at; int v = std::min(A[at], A[at + 1]);
	A[at] -= v, A[at + 1] -= v;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	for (int i = 1; i <= n + 1; ++i) {
		dp[i] = INF;
		gmin(i, A[i - 1], i - 2);
		if (i > 1) gmin(i, std::max(A[i - 1], A[i - 2]), i - 3);
	}
	int now = std::min_element(dp + n, dp + n + 2) - dp;
	while (now) {
		if (pre[now] == now - 3)
			add(now - 2), add(now - 1), add(now - 3);
		else
			add(now - 1), add(now - 2);
		now = pre[now];
	}
	std::cout << bak << '\n';
	for (int i = 1; i <= bak; ++i)
		std::cout << li[i] << '\n';
	return 0;
}