#include <bits/stdc++.h>

void solve() {
    int n, s;
    std::cin >> n >> s;
    std::cout << s / (n - (n + 1) / 2 + 1) << "\n";
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