#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

template <typename Fun>
class y_combinator_result {
    Fun fun_;

  public:
    template <typename T>
    explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}

    template <typename... Args>
    decltype(auto) operator()(Args&&... args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <typename Fun>
auto y_combinator(Fun&& fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

struct disjoint_set {
    int N, S;
    vector<int> next, size;

    explicit disjoint_set(int N = 0) : N(N), S(N), next(N), size(N, 1) {
        iota(begin(next), end(next), 0);
    }

    void assign(int N) { *this = disjoint_set(N); }
    bool same(int i, int j) { return find(i) == find(j); }
    bool unit(int i) { return i == next[i] && size[i] == 1; }
    bool root(int i) { return find(i) == i; }
    void reroot(int u) { next[u] = next[find(u)] = u; }

    int find(int i) {
        while (i != next[i]) {
            i = next[i] = next[next[i]];
        }
        return i;
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (size[i] < size[j]) {
                swap(i, j);
            }
            next[j] = i;
            size[i] += size[j];
            S--;
            return true;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> edges(E);
    vector<vector<pair<int, int>>> adj(V + 1);
    for (int e = 0; e < E; e++) {
        int u, v;
        cin >> u >> v;
        edges[e] = {u, v};
        adj[u].emplace_back(e, v);
        adj[v].emplace_back(e, u);
    }

    vector<int> index(V + 1);
    vector<int> lowlink(V + 1);
    vector<int> bridges;
    vector<bool> bridge_edge(E);
    int dfs_timer = 1;

    y_combinator([&](auto self, int u, int p) -> void {
        index[u] = lowlink[u] = dfs_timer++;

        for (auto [e, v] : adj[u]) {
            if (v != p) {
                if (index[v]) {
                    edges[e] = {v, u}; // back edges goes up
                    lowlink[u] = min(lowlink[u], index[v]);
                } else {
                    edges[e] = {u, v}; // tree edges goes down
                    self(v, u);
                    lowlink[u] = min(lowlink[u], lowlink[v]);
                    if (lowlink[v] > index[u]) {
                        bridge_edge[e] = true;
                        bridges.push_back(e);
                    }
                }
            }
        }
    })(1, 0);

    // find the largest two-connected component
    disjoint_set dsu(V + 1);
    for (int e = 0; e < E; e++) {
        if (!bridge_edge[e]) {
            auto [u, v] = edges[e];
            dsu.join(u, v);
        }
    }

    vector<vector<int>> bcc_by_rep(V + 1);
    for (int u = 1; u <= V; u++) {
        bcc_by_rep[dsu.find(u)].push_back(u);
    }

    vector<vector<int>> bset;
    vector<int> bmap(V + 1, -1);
    for (int r = 1; r <= V; r++) {
        if (!bcc_by_rep[r].empty()) {
            int b = bset.size();
            for (int u : bcc_by_rep[r]) {
                bmap[u] = b;
            }
            bset.emplace_back(move(bcc_by_rep[r]));
        }
    }
    int B = bset.size();
    assert(B == 1 + int(bridges.size()));

    vector<vector<pair<int, int>>> bcc_adj(B);
    for (int e : bridges) {
        auto [u, v] = edges[e];
        assert(bmap[u] != bmap[v]);
        bcc_adj[bmap[u]].emplace_back(e, bmap[v]);
        bcc_adj[bmap[v]].emplace_back(e, bmap[u]);
    }

    int maxb = 0;
    for (int b = 0; b < B; b++) {
        if (bset[b].size() > bset[maxb].size()) {
            maxb = b;
        }
    }
    int ans = bset[maxb].size();

    y_combinator([&](auto self, int a, int p) -> void {
        for (auto [e, b] : bcc_adj[a]) {
            if (b != p) {
                auto& [u, v] = edges[e];
                if (bmap[u] == a) {
                    swap(u, v);
                }
                self(b, a);
            }
        }
    })(maxb, -1);

    cout << ans << '\n';
    for (auto [u, v] : edges) {
        cout << u << ' ' << v << '\n';
    }
    return 0;
}