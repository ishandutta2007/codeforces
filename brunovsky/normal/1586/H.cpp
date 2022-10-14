#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

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

struct centroid_forest {
    vector<int> parent, depth, roots;

    explicit centroid_forest(const vector<vector<int>>& tree) {
        int N = tree.size();
        parent.assign(N, -1);
        depth.assign(N, -1);

        vector<int> subsize(N);

        auto subsize_dfs = y_combinator([&](auto self, int u, int p) -> void {
            subsize[u] = 1;
            for (int v : tree[u]) {
                if (v != p) {
                    self(v, u);
                    subsize[u] += subsize[v];
                }
            }
        });

        auto centroid_dfs = y_combinator(
            [&](auto self, int u, int p, int cp, int S) -> pair<int, int> {
                int processed = 0;

                bool changed;
                do {
                    changed = false;
                    for (int v : tree[u]) {
                        while (v != p && depth[v] == -1 && subsize[v] > S / 2) {
                            auto [more, root] = self(v, u, cp, S);
                            subsize[u] -= more;
                            S -= more;
                            processed += more;
                            cp = root;
                            changed = true;
                        }
                    }
                } while (changed);

                // backtrack if u is not a centroid child of cp; else recurse on children
                if (S - subsize[u] > S / 2) {
                    return make_pair(processed, cp);
                }

                parent[u] = cp;
                depth[u] = cp != -1 ? depth[cp] + 1 : 0;

                for (int v : tree[u]) {
                    if (v != p && depth[v] == -1) {
                        self(v, u, u, subsize[v]);
                    }
                }

                return make_pair(processed + subsize[u], u);
            });

        for (int u = 0; u < N; u++) {
            if (depth[u] == -1) {
                subsize_dfs(u, -1);
                centroid_dfs(u, -1, -1, subsize[u]);
            }
            if (parent[u] == -1) {
                roots.push_back(u);
            }
        }
    }

    int num_nodes() const { return parent.size(); }

    int ancestor(int u, int steps) const {
        while (steps--)
            u = parent[u];
        return u;
    }

    int below(int u, int a) const { return ancestor(u, depth[u] - depth[a] - 1); }

    int lca(int u, int v) const {
        while (depth[u] > depth[v])
            u = parent[u];
        while (depth[u] < depth[v])
            v = parent[v];
        while (u != v)
            u = parent[u], v = parent[v];
        return u;
    }

    int findroot(int u) const {
        while (parent[u] != -1)
            u = parent[u];
        return u;
    }

    bool conn(int u, int v) const { return findroot(u) == findroot(v); }
};

template <typename T, typename BinaryFn>
struct centroid_any_sparse_table : centroid_forest {
    vector<vector<T>> table;
    BinaryFn combine;

    centroid_any_sparse_table(vector<vector<int>>& tree, const vector<T>& val,
                              const vector<vector<pair<int, T>>>& val_tree,
                              const BinaryFn& op = BinaryFn())
        : centroid_forest(tree), combine(op) {
        int N = num_nodes(), D = *max_element(begin(depth), end(depth));
        table.assign(D + 1, vector<T>(N));

        vector<int> bfs(N), prev(N);

        for (int root = 0; root < N; root++) {
            int d = depth[root];
            table[d][root] = val[root];
            prev[root] = -1;
            bfs[0] = root;
            for (int i = 0, S = 1; i < S; i++) {
                int u = bfs[i];
                for (auto [v, w] : val_tree[u]) {
                    if (depth[v] > d && v != prev[u]) {
                        table[d][v] = op(table[d][u], w);
                        prev[v] = u;
                        bfs[S++] = v;
                    }
                }
            }
        }
    }

    auto query(int u, int v) const {
        int a = lca(u, v), d = depth[a];
        return combine(table[d][u], table[d][v]);
    }
};

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

struct Query {
    int id, u, capacity;

    friend bool operator<(const Query& a, const Query& b) {
        return make_pair(a.capacity, a.id) > make_pair(b.capacity, b.id);
    }
};

struct Edge {
    int capacity, toll, u, v;

    friend bool operator<(const Edge& a, const Edge& b) {
        return make_pair(a.capacity, a.toll) > make_pair(b.capacity, b.toll);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> enjoyment(N);
    for (int i = 0; i < N; i++) {
        cin >> enjoyment[i];
    }

    vector<vector<int>> tree(N);
    vector<vector<pair<int, int>>> val_tree(N);
    vector<Edge> edges(N - 1);
    for (auto& [capacity, toll, u, v] : edges) {
        cin >> u >> v >> capacity >> toll, u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
        val_tree[u].push_back({v, toll});
        val_tree[v].push_back({u, toll});
    }
    sort(begin(edges), end(edges));

    vector<Query> queries(Q);
    for (int q = 0; q < Q; q++) {
        cin >> queries[q].capacity >> queries[q].u, queries[q].u--;
        queries[q].id = q;
    }
    sort(begin(queries), end(queries));

    centroid_any_sparse_table ctd(tree, vector<int>(N, 0), val_tree,
                                  [](int a, int b) { return max(a, b); });

    // dsu tree
    disjoint_set dsu(N);
    vector<int> dsu_toll(N);

    auto join = [&](int u, int v, int toll) {
        int a = dsu.find(u), b = dsu.find(v);
        dsu.join(a, b);

        if (enjoyment[a] > enjoyment[b]) {
            dsu.reroot(a);
        } else if (enjoyment[a] < enjoyment[b]) {
            dsu.reroot(b);
        } else {
            dsu_toll[a] = max({dsu_toll[a], dsu_toll[b], toll, ctd.query(a, b)});
            dsu.reroot(a);
        }
    };

    int i = 0;
    vector<pair<int, int>> ans(Q);

    for (auto& [id, s, capacity] : queries) {
        while (i < N - 1 && edges[i].capacity >= capacity) {
            auto [cap, toll, u, v] = edges[i++];
            join(u, v, toll);
        }
        int t = dsu.find(s);
        int toll = max({dsu_toll[t], ctd.query(s, t)});
        ans[id] = {enjoyment[t], toll};
    }

    for (int q = 0; q < Q; q++) {
        auto [enjoy, toll] = ans[q];
        cout << enjoy << ' ' << toll << '\n';
    }

    return 0;
}