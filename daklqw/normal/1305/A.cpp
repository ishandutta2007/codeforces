#include <bits/stdc++.h>

const int MAXN = 1100;
int A[MAXN], B[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
int T; std::cin >> T;
while (T --> 0) {
	int n; std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	std::sort(A + 1, A + 1 + n);
	for (int i = 1; i <= n; ++i)
		std::cout << A[i] << (" \n" [i == n]);
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	std::sort(A + 1, A + 1 + n);
	for (int i = 1; i <= n; ++i)
		std::cout << A[i] << (" \n" [i == n]);
}

	return 0;
}