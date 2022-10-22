#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n * m);
    for (int i = 0; i < n * m; ++i) {
        std::cin >> a[i];
    }
    int s = 0;
    for (int i = 0; i < n * m; ++i) {
        for (int j = i + 1; j < n * m; ++j) {
            s += a[i] < a[j];
        }
    }
    std::cout << s << "\n";
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