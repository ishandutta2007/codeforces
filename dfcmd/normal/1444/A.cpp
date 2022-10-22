#include <bits/stdc++.h>

long long p;
int q;
long long ans;

void solve(int i) {
	int cq = 0;
	int pw = 1;
	while (q % i == 0) {
		++cq;
		q /= i;
		pw *= i;
	}
	long long tp = p;
	int cp = 0;
	while (tp % i == 0) {
		++cp;
		tp /= i;
	}
	ans = std::max(ans, tp * pw / i);
}

void solve() {
	std::cin >> p >> q;
	if (p % q != 0) {
		std::cout << p << std::endl;
		return;
	}
	ans = 0;
	for (int i = 2; i * i <= q; ++i) {
		if (q % i == 0) {
			solve(i);
		}
	}
	if (q > 1) {
		solve(q);
	}
	std::cout << ans << std::endl;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
}