#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    std::vector<bool> bud(n);
    std::vector<int> deg(n);
    int ans = 0;

    auto dfs = [&](auto self, int u, int fa) -> void {
        for (int v : E[u]) {
            if (v != fa) {
                self(self, v, u);
                deg[u] += !bud[v];
            }
        }
        ans += !deg[u];
        if (fa != -1 && deg[u]) {
            bool ok = true;
            for (int v : E[u]) {
                if (v != fa && !bud[v]) {
                    ok &= !deg[v];
                }
            }
            ans -= ok;
            bud[u] = ok;
        }
    };

    dfs(dfs, 0, -1);
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