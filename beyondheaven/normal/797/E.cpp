// LUOGU_RID: 96293151
#include <bits/stdc++.h>
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int &x : a) {
		std::cin >> x;
	}

	int B = sqrt(n);
	std::vector<std::vector<int>> t(n);
	for (int i = n; i--; ) {
		t[i].resize(B + 1);
		for (int j = 1; j <= B; j++) {
			int k = i + a[i] + j;
			if (k >= n) {
				t[i][j] = 1;
			} else {
				t[i][j] = t[k][j] + 1;
			}
		}
	}

	int q;
	std::cin >> q;
	while (q--) {
		int p, k;
		std::cin >> p >> k;
		p--;

		if (k <= B) {
			std::cout << t[p][k] << "\n";
			continue;
		}

		int ans = 0;
		while (p < n) {
			ans += 1;
			p = p + a[p] + k;
		}
		std::cout << ans << "\n";
	}
	return 0;
}