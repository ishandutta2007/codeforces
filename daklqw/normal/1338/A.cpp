#include <bits/stdc++.h>

const int MAXN = 100010;
long long A[MAXN];
int n;
bool chk() {
	for (int i = 1; i < n; ++i) if (A[i] > A[i + 1]) return true;
	return false;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int T; std::cin >> T;
	while (T --> 0) {
		std::cin >> n;
		for (int i = 1; i <= n; ++i) std::cin >> A[i];
		int ans = 0;
		long long mi = 0x3f3f3f3f3f3f3f3fll;
		for (int i = n; i; --i) {
			mi = std::min(mi, A[i]);
			if (A[i] > mi)
			ans = std::max(ans, (int) std::__lg(A[i] - mi) + 1);
		}
	//	for (int i = 0; chk(); ++i) {
	//		for (int j = 2; j <= n; ++j)
	//			if (A[j] < A[j - 1])
	//				A[j] += 1ll << i;
	//		++ans;
	//	}
		std::cout << ans << '\n';
	}
	return 0;
}