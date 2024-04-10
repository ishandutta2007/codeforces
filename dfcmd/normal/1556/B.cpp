#include <bits/stdc++.h>

const long long INF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
	int n;
	std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[i] &= 1;
    }
    long long ans = INF;
    for (int v = 0; v < 2; ++v) {
        int c[2] = {0, 0};
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += std::max(c[a[i]] + (a[i] == v) - c[a[i] ^ 1], 0);
            ++c[a[i]];
        }
        if (c[v] == n / 2 && c[v ^ 1] == (n + 1) / 2) {
            ans = std::min(ans, sum);
        }
    }
    std::cout << (ans == INF ? -1 : ans) << "\n";
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