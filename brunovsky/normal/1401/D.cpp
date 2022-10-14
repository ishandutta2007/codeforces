#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

constexpr long mod = 1e9 + 7;
int N;
vector<long> edge_weight;
vector<int> subtree_size;
vector<vector<array<int, 2>>> adj;

void dfs(int u, int p = -1) {
    subtree_size[u] = 1;
    for (auto [v, e] : adj[u]) {
        if (v != p) {
            dfs(v, u);
            subtree_size[u] += subtree_size[v];
        }
    }
    for (auto [v, e] : adj[u]) {
        if (v != p) {
            int lo = subtree_size[v];
            int hi = N - lo;
            edge_weight[e] = 1LL * lo * hi;
        }
    }
}

auto solve() {
    cin >> N;
    adj.assign(N + 1, {});
    subtree_size.assign(N + 1, 0);
    edge_weight.assign(N - 1, 0);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    dfs(1);
    vector<int> ids(N - 1);
    iota(begin(ids), end(ids), 0);
    sort(begin(ids), end(ids),
         [&](int a, int b) { return edge_weight[a] > edge_weight[b]; });

    int M;
    cin >> M;
    vector<int> primes(M);
    for (int i = 0; i < M; i++) {
        cin >> primes[i];
    }
    sort(rbegin(primes), rend(primes));
    vector<long> assigned(N - 1, 1);
    if (M <= N - 1) {
        for (int i = 0; i < M; i++) {
            assigned[ids[i]] = primes[i];
        }
    } else {
        int j = M - 1;
        for (int i = N - 2; i >= 0; i--, j--) {
            assigned[ids[i]] = primes[j];
        }
        while (j >= 0) {
            assigned[ids[0]] = assigned[ids[0]] * primes[j--] % mod;
        }
    }
    long ans = 0;
    for (int i = 0; i < N - 1; i++) {
        ans = (ans + assigned[ids[i]] * (edge_weight[ids[i]] % mod)) % mod;
    }
    return ans;
}

// *****

int main() {
    // ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}