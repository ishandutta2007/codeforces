#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

int N;
vector<vector<int>> adj;
vector<int> spliced, connected;
vector<array<int, 2>> keep_connected;
vector<array<int, 2>> removed, endpoints;

int dfs_connected(int u, int p = -1);
void dfs_spliced(int u, int p = -1);

int dfs_connected(int u, int p) {
    int w = keep_connected[u][0], last = u;
    for (int v : adj[u]) {
        if (v != p && v != w) {
            removed.push_back({u, v});
            dfs_spliced(v, u);
        } else if (v != p && v == w) {
            last = dfs_connected(v, u);
        }
    }
    return last;
}

void dfs_spliced(int u, int p) {
    auto [w1, w2] = keep_connected[u];
    vector<int> endp;
    for (int v : adj[u]) {
        if (v != p && v != w1 && v != w2) {
            removed.push_back({u, v});
            dfs_spliced(v, u);
        } else if (v != p && (v == w1 || v == w2)) {
            endp.push_back(dfs_connected(v, u));
        }
    }
    int S = endp.size();
    if (S == 0) {
        endpoints.push_back({u, u});
    } else if (S == 1) {
        endpoints.push_back({u, endp[0]});
    } else if (S == 2) {
        endpoints.push_back({endp[0], endp[1]});
    } else {
        assert(false);
    }
}

void dfs_dp(int u, int p = -1) {
    spliced[u] = connected[u] = 0;
    keep_connected[u] = {-1, -1};

    // start off by disconnecting everything
    // spliced[u]: we may keep 0,1,2
    // connected[u]: we may keep 0,1
    vector<array<int, 2>> deltas;
    int keep_0 = 0;

    for (int v : adj[u]) {
        if (v != p) {
            dfs_dp(v, u);
            keep_0 += 1 + spliced[v];
            deltas.push_back({connected[v] - spliced[v] - 1, v});
        }
    }

    int S = deltas.size();
    sort(begin(deltas), end(deltas));
    if (S >= 0) {
        spliced[u] = connected[u] = keep_0;
    }
    if (S >= 1 && deltas[0][0] < 0) {
        spliced[u] = connected[u] = keep_0 + deltas[0][0];
        keep_connected[u][0] = deltas[0][1];
    }
    if (S >= 2 && deltas[1][0] < 0) {
        spliced[u] = keep_0 + deltas[0][0] + deltas[1][0];
        keep_connected[u][1] = deltas[1][1];
    }
}

auto solve() {
    cin >> N;
    adj.assign(N, {});
    spliced.assign(N, {});
    connected.assign(N, {});
    keep_connected.assign(N, {});
    endpoints.clear(), removed.clear();

    for (int e = 0; e < N - 1; e++) {
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs_dp(0);
    dfs_spliced(0);

    int M = endpoints.size(), k = removed.size();
    assert(k == M - 1); // pray to the math gods

    vector<array<int, 2>> added;
    for (int i = 1; i < M; i++) {
        auto [_a, b] = endpoints[i - 1];
        auto [c, _d] = endpoints[i];
        added.push_back({b, c});
    }

    cout << k << endl;
    for (int i = 0; i < k; i++) {
        auto [a, b] = removed[i];
        auto [c, d] = added[i];
        cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << ' ' << d + 1 << endl;
    }
    return 0;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        solve();
    }
    return 0;
}