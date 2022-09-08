/**
 *  created: 24/12/2021, 17:25:39
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, m, a[max_n], U[max_n], V[max_n], X[max_n];
vector<pair<int, int>> g[max_n];

void clr() {
    for (int i = 0; i < n; ++i) {
        a[i] = -1;
        g[i].clear();
    }
}

bool dfs(int v, int cur) {
    a[v] = cur;
    for (auto [to, x] : g[v]) {
        int val = a[v] ^ x;
        if (a[to] == -1) {
            if (!dfs(to, val)) {
                return false;
            }
        } else if (a[to] != val) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(a, -1, sizeof(a));
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i < n; ++i) {
            cin >> U[i] >> V[i] >> X[i];
            --U[i];
            --V[i];
            if (X[i] >= 0) {
                g[U[i]].push_back({V[i], __builtin_popcount(X[i]) % 2});
                g[V[i]].push_back({U[i], __builtin_popcount(X[i]) % 2});
            }
        }
        for (int i = 0; i < m; ++i) {
            int u, v, x;
            cin >> u >> v >> x;
            --u;
            --v;
            g[u].push_back({v, x});
            g[v].push_back({u, x});
        }
        bool ok = 1;
        for (int i = 0; i < n; ++i) {
            if (a[i] == -1) {
                if (!dfs(i, 0)) {
                    ok = 0;
                    break;
                }
            }
        }
        if (!ok) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 1; i < n; ++i) {
                if (X[i] == -1) {
                    X[i] = a[U[i]] ^ a[V[i]];
                }
                cout << U[i] + 1 << " " << 1 + V[i] << " " << X[i] << "\n";
            }
        }
        clr();
    }
    return 0;
}