#include <bits/stdc++.h>

typedef long long LL;
const int MAXN = 200010;
LL A[MAXN], B[MAXN], ta, tb;
int n, m, K;
int main() {
	std::cin >> n >> m >> ta >> tb >> K;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	for (int i = 1; i <= m; ++i) std::cin >> B[i];
	if (K >= n || K >= m) return puts("-1"), 0;
	LL ans = 0;
	for (int i = 0; i <= K; ++i) {
		LL now = A[i + 1] + ta;
		int at = std::lower_bound(B + 1, B + 1 + m, now) - B;
		if (m - at + 1 <= K - i) return puts("-1"), 0;
		ans = std::max(B[at + K - i] + tb, ans);
	}
	std::cout << ans << std::endl;
	return 0;
}