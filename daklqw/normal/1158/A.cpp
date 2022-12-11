#include <bits/stdc++.h>

const int MAXN = 100010;
typedef long long LL;
int A[MAXN], B[MAXN], n, m;
int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	for (int i = 1; i <= m; ++i) std::cin >> B[i];
	std::sort(A + 1, A + 1 + n);
	std::sort(B + 1, B + 1 + m);
	if (B[1] < A[n] || (m == 1 && B[1] != A[n])) return puts("-1"), 0;
	LL ans = 0;
	for (int i = 1; i <= m; ++i) ans += B[i];
	for (int i = 1; i < n; ++i) ans += (LL) A[i] * m;
	if (A[n] != B[1]) ans += A[n] - A[n - 1];
	std::cout << ans << std::endl;
	return 0;
}