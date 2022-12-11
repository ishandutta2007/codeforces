#include <bits/stdc++.h>

const int MAXN = 5e5 + 10;
typedef long long LL;
int A[MAXN], n;
int main() {
	std::cin >> n;
	LL ans = 0;
	static int st[MAXN], top;
	for (int i = 1; i <= n; ++i) {
		std::cin >> A[i];
		while (top > 1 && st[top - 1] >= st[top] && st[top] <= A[i])
			ans += std::min(st[--top], A[i]);
		st[++top] = A[i];
	}
	std::sort(st + 1, st + 1 + top);
	ans += std::accumulate(st + 1, st + 1 + std::max(0, top - 2), 0ll);
	std::cout << ans << std::endl;
	return 0;
}