#include <bits/stdc++.h>

const int MAXN = 1e6 + 10;
int n, A[MAXN], K, B[MAXN];
int ansl[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> K >> n;
	int sm = 0;
	for (int i = 1; i <= n; ++i)
		std::cin >> A[i], B[i] = (sm += A[i]) % K;
	std::cout << (sm + K - 1) / K << '\n';
	B[n] = K;
	std::sort(B + 1, B + 1 + n);
	for (int i = n; i; --i) B[i] -= B[i - 1];
	for (int i = 1; i <= n; ++i)
		std::cout << B[i] << (" \n" [i == n]);
	int cur = 1;
	for (int i = 1; i <= n; ++i)
		while (A[i] > 0 || (i == n && cur != 1)) {
			ansl[cur] = i, A[i] -= B[cur];
			if (cur == n) {
				for (int j = 1; j <= n; ++j)
					std::cout << ansl[j] << (" \n" [j == n]);
				cur = 1;
			} else ++cur;
		}
	return 0;
}