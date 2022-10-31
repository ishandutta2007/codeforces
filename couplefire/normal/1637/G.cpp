#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    if (n == 2) {
        std::cout << -1 << '\n';
        return;
    }
    int lim = 1;
    while (lim < n) lim *= 2;

    std::vector<int> cnt(lim + 1);
    std::fill_n(cnt.begin() + 1, n, 1);

    std::vector<std::pair<int, int>> ans;

    auto operate = [&](int x, int y) {
        ans.emplace_back(x, y);
        --cnt[x];
        --cnt[y];
        ++cnt[x + y];
        ++cnt[std::abs(x - y)];
    };

    auto play = [&](auto &&self, int n, int c) -> void {
        if (n <= 2) return;
        if (n == (n & -n)) --n;
        int k = 1;
        while (k * 2 <= n) k *= 2;
        for (int i = 1; k + i <= n; ++i) {
            operate((k - i) * c, (k + i) * c);
        }
        self(self, k - (n - k) - 1, c);
        self(self, n - k, c * 2);
    };
    play(play, n, 1);

    int tar = lim;
    while (cnt[tar] == 0) --tar;
    if (!cnt[0]) {
        for (int i = 1; i <= lim; i *= 2) {
            if (cnt[i] >= 2) {
                operate(i, i);
                break;
            }
        }
    }
    for (int i = 1; i < tar; i *= 2) {
        for (int j = cnt[i]; j; --j) {
            int x = i;
            while (x < tar) {
                operate(0, x);
                operate(x, x);
                x *= 2;
            }
        }
    }
    operate(0, tar);

    std::cout << ans.size() << '\n';
    for (auto [x, y] : ans) std::cout << x << ' ' << y << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) solve();

    return 0;
}