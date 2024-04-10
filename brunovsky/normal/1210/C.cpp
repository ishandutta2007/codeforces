#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

constexpr long mod = 1e9 + 7;
long ans = 0;
vector<vector<int>> adj;
vector<long> beauty;

void dfs(int u, int p, unordered_map<long, int> cnts) {
    unordered_map<long, int> new_cnts;
    for (auto [g, n] : cnts) {
        new_cnts[gcd(g, beauty[u])] += n;
    }
    new_cnts[beauty[u]]++;
    for (const auto& [g, n] : new_cnts) {
        ans = (ans + g * n) % mod;
    }
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, new_cnts);
        }
    }
}

auto solve() {
    int N;
    cin >> N;
    adj.assign(N, {});
    beauty.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> beauty[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1, {});
    return ans;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}