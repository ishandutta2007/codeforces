#include <bits/stdc++.h>
constexpr int maxn = 1e6 + 5;

int n, k, p[maxn], vis[maxn], cnt[maxn];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}

	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) {
			continue;
		}

		int x = i, len = 0;
		while (!vis[x]) {
			vis[x] = 1;
			len++;
			x = p[x];
		}
		cnt[len]++;
		c += len / 2;
	}
	
	std::bitset<maxn> B;
	B[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (!cnt[i]) {
			continue;
		}

		int t = 2 - cnt[i] % 2;
		if (2 * i <= n) {
			cnt[2 * i] += (cnt[i] - t) / 2;
		}
		while (t--) {
			B |= (B << i);
		}
	}

	std::cout << k + 1 - B[k] << " " << std::min(2 * k - std::max(k - c, 0), n) << "\n";
	return 0;
}