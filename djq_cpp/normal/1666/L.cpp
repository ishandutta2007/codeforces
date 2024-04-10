#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, s;
    std::cin >> n >> m >> s;
    s--;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        if (v != s) {
            adj[u].push_back(v);
        }
    }
    
    std::vector<int> last(n, -1), st(n, -1);
    
    auto dfs = [&](auto self, auto u) -> void {
        for (auto v : adj[u]) {
            if (st[v] == -1) {
                st[v] = st[u];
                last[v] = u;
                self(self, v);
            } else if (st[v] != st[u]) {
                std::cout << "Possible\n";
                std::vector<int> a, b{v};
                for (auto i = v; i != -1; i = last[i]) {
                    a.push_back(i);
                }
                for (auto i = u; i != -1; i = last[i]) {
                    b.push_back(i);
                }
                std::reverse(a.begin(), a.end());
                std::reverse(b.begin(), b.end());
                std::cout << a.size() << "\n";
                for (auto x : a) {
                    std::cout << x + 1 << " \n"[x == v];
                }
                std::cout << b.size() << "\n";
                for (auto x : b) {
                    std::cout << x + 1 << " \n"[x == v];
                }
                std::exit(0);
            }
        }
    };
    for (auto v : adj[s]) {
        last[v] = s;
        st[v] = v;
    }
    for (auto v : adj[s]) {
        dfs(dfs, v);
    }
    
    std::cout << "Impossible\n";
    
    return 0;
}