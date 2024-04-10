#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

vector<int> adj[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
    auto check = [&](int k) {
        for (int i = 1; i <= n; i++) {
            int u = (i + k - 1) % n + 1;
            for (int j : adj[i]) {
                int v = (j + k - 1) % n + 1;
                if (!binary_search(adj[u].begin(), adj[u].end(), v)) return 0;
            }
        }
        return 1;
    };
    for (int k = n, i = 2; i <= k; i++) {
        if (k % i == 0) {
            if (check(n / i)) return puts("Yes"), 0;
            while (k % i == 0) k /= i;
        }
    }
    return puts("No"), 0;
}