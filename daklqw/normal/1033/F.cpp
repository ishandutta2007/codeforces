#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

int A[1 << 12 | 3], n;
int B[1 << 12 | 3];
char buf[100];
void fwt() {
	const int U = 1 << n;
	for (int i = 0; i < n; ++i) {
		const int mid = 1 << i;
		if (buf[i] == 'A' || buf[i] == 'a') {
			for (int j = 0; j < U; j += mid << 1)
				for (int k = j; k != j + mid; ++k)
					B[k] += B[k + mid];
		}
		if (buf[i] == 'O' || buf[i] == 'o') {
			for (int j = 0; j < U; j += mid << 1)
				for (int k = j; k != j + mid; ++k)
					B[k + mid] += B[k];
		}
		if (buf[i] == 'X' || buf[i] == 'x') {
			for (int j = 0; j < U; j += mid << 1)
				for (int k = j; k != j + mid; ++k) {
					const int x = B[k], y = B[k + mid];
					B[k] += y;
					B[k + mid] = x - y;
				}
		}
	}
}
void ifwt() {
	const int U = 1 << n;
	for (int i = 0; i < n; ++i) {
		const int mid = 1 << i;
		if (buf[i] == 'A' || buf[i] == 'a') {
			for (int j = 0; j < U; j += mid << 1)
				for (int k = j; k != j + mid; ++k)
					B[k] -= B[k + mid];
		}
		if (buf[i] == 'O' || buf[i] == 'o') {
			for (int j = 0; j < U; j += mid << 1)
				for (int k = j; k != j + mid; ++k)
					B[k + mid] -= B[k];
		}
		if (buf[i] == 'X' || buf[i] == 'x') {
			for (int j = 0; j < U; j += mid << 1)
				for (int k = j; k != j + mid; ++k) {
					const int x = B[k], y = B[k + mid];
					B[k] = x + y >> 1;
					B[k + mid] = x - y >> 1;
				}
		}
	}
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int T, t, Q;
	std::cin >> n >> T >> Q;
	while (T --> 0) std::cin >> t, ++A[t];
	const int U = 1 << n;
	while (Q --> 0) {
		std::cin >> buf, std::reverse(buf, buf + n);
		memcpy(B, A, U << 2);
		fwt();
		for (int i = 0; i != U; ++i) B[i] *= B[i];
		ifwt();
		int mask = 0;
		for (int i = 0; i != n; ++i)
			if (buf[i] >= 'a' && buf[i] <= 'z')
				mask |= 1 << i;
		std::cout << B[mask] << std::endl;
	}
	return 0;
}