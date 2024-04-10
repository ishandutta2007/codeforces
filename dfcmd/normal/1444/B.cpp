#include <bits/stdc++.h>

const int N = 150005, P = 998244353;

int n, a[N << 1], fac[N], inv[N];

int qpow(int a, int b) {
	int s = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			s = 1ll * s * a % P;
		}
		a = 1ll * a * a % P;
	}
	return s;
}

void init(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % P;
	}
	inv[n] = qpow(fac[n], P - 2);
	for (int i = n; i; --i) {
		inv[i - 1] = 1ll * inv[i] * i % P;
	}
}

int C(int n, int m) {
	if (m < 0 || m > n) {
		return 0;
	}
	return 1ll * fac[n] * inv[m] % P * inv[n - m] % P;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 1; i <= 2 * n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a + 1, a + 1 + 2 * n);
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum = (sum + a[i + n] - a[i]) % P;
	}
	init(n);
	int cnt = 0;
	for (int i = 0; i <= n; ++i) {
		cnt = (cnt + 1ll * C(n, i) * C(n, i)) % P;
	}
	std::cout << 1ll * cnt * sum % P << std::endl;
}