#include <bits/stdc++.h>

const int N = 100005;

int n, p, k, x, y;
char a[N];
int sum[N];

int getSum(int x) {
	return x > n ? 0 : sum[x];
}

void solve() {
	std::cin >> n >> p >> k;
	std::cin >> (a + 1);
	std::cin >> x >> y;
	for (int i = n; i; --i) {
		sum[i] = getSum(i + k) + (a[i] == '0');
	}
	int ans = 0x3f3f3f3f;
	for (int i = 0; i <= n - p; ++i) {
		ans = std::min(ans, i * y + getSum(i + p) * x);
	}
	std::cout << ans << "\n";
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