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
    void reroot(int u) {
        if (u != find(u)) {
            size[u] = size[find(u)];
            next[u] = next[find(u)] = u;
        }
    }

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

auto build_scc(const vector<vector<int>>& adj) {
    int V = adj.size(), C = 0; // C = number of scc

    vector<vector<int>> cset;
    vector<int> cmap(V, -1);
    vector<int> index(V);
    vector<int> lowlink(V);
    int timer = 1;

    stack<int> S;

    auto dfs = y_combinator([&](auto self, int u) -> void {
        index[u] = lowlink[u] = timer++;
        S.push(u);

        for (int v : adj[u]) {
            if (index[v] && cmap[v] == -1) { // <-- skip cmap'd nodes
                lowlink[u] = min(lowlink[u], index[v]);
            } else if (!index[v]) {
                self(v);
                lowlink[u] = min(lowlink[u], lowlink[v]);
            }
        }

        // found a strongly connected component
        if (index[u] == lowlink[u]) {
            int c = C++;
            cset.push_back({});
            int v;
            do {
                v = S.top(), S.pop();
                cmap[v] = c, cset[c].push_back(v);
            } while (u != v);
        }
    });

    for (int u = 0; u < V; u++) {
        if (!index[u]) {
            dfs(u);
        }
    }

    return make_pair(cset, cmap);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> adj(N);
    vector<vector<int>> out(N);
    for (int i = 0; i < M; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        u--, v--;
        adj[u].push_back({v, l});
        out[u].push_back(v);
    }

    auto [cset, cmap] = build_scc(out);
    int C = cset.size();

    vector<long> dfs_entry(N);
    vector<long> cycle_dist(N);
    vector<long> cycle_gcd(C);
    vector<bool> vis(N), onstack(N);

    vector<int> dsu_next(N);
    iota(begin(dsu_next), end(dsu_next), 0);
    vector<int> stack;

    auto find = [&](int i) {
        while (dsu_next[i] != dsu_next[dsu_next[i]]) {
            cycle_dist[i] += cycle_dist[dsu_next[i]];
            dsu_next[i] = dsu_next[dsu_next[i]];
        }
        return dsu_next[i];
    };
    auto join = [&](int i, int r, long distance) {
        assert(i == dsu_next[i] && r == dsu_next[r]);
        dsu_next[i] = r;
        cycle_dist[i] = distance;
    };

    debug(cset);
    debug(cmap);

    auto dfs = y_combinator([&](auto self, int u, long trail) -> void {
        debug("DFS", u, trail);

        vis[u] = true;
        onstack[u] = true;
        stack.push_back(u);
        dfs_entry[u] = trail;
        long& g = cycle_gcd[cmap[u]];

        for (auto [v, w] : adj[u]) {
            if (cmap[u] == cmap[v]) {
                if (!vis[v]) {
                    self(v, w + trail);
                } else {
                    int x = find(v);
                    assert(onstack[x]);

                    // we can form a cycle of this length u->v->...->x->...->u
                    long cycle = dfs_entry[u] - dfs_entry[x] + w + cycle_dist[v];
                    g = gcd(g, cycle);
                    debug("OPTIMIZE", u, v, x, cycle);

                    // compress this cycle into x
                    while (stack.back() != x) {
                        int y = stack.back();
                        stack.pop_back();

                        // y to u, then u to v
                        long distance = dfs_entry[u] - dfs_entry[y] + w + cycle_dist[v];
                        join(y, x, distance);

                        debug("JOIN", x, y, distance);
                    }
                }
            }
        }

        onstack[u] = false;
        if (stack.back() == u) {
            stack.pop_back();
        }
    });

    for (int c = 0; c < C; c++) {
        dfs(cset[c][0], 0);
    }

    debug(dfs_entry);
    debug(cycle_gcd);
    debug(cycle_dist);

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int u, s, t;
        cin >> u >> s >> t;
        u--;
        long g = cycle_gcd[cmap[u]];
        // gcd(g,t) needs to divide t-s
        if ((t - s) % gcd(g, t) == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}