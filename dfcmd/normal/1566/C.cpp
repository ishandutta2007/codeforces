#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;
    std::vector<bool> vis(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            ans += 2;
        } else if (a[i] == '0') {
            if (i > 0 && !vis[i - 1] && a[i - 1] == '1' && b[i - 1] == '1') {
                ans += 2;
            } else if (i + 1 < n && a[i + 1] == '1' && b[i + 1] == '1') {
                ans += 2;
                vis[i + 1] = true;
            } else {
                ans += 1;
            }
        }
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