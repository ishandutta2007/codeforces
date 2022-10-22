#include <bits/stdc++.h>

const int P = 998244353;

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

void solve() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	int now = 0;
	int sum = 0;
	for (int i = 0; i <= n; ++i) {
		if (i == n || s[i] == '0') {
			sum -= now & 1;
			now = 0;
		} else {
			++sum;
			++now;
		}
	}
	sum /= 2;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cnt += s[i] == '0';
	}
	int ans = 1;
	for (int i = 1; i <= sum + cnt; ++i) {
		ans = 1ll * ans * i % P;
	}
	for (int i = 1; i <= sum; ++i) {
		ans = 1ll * ans * qpow(i, P - 2) % P;
	}
	for (int i = 1; i <= cnt; ++i) {
		ans = 1ll * ans * qpow(i, P - 2) % P;
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}