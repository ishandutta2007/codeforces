#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct disjoint_set {
    int N, S;
    vector<int> nxt, siz;

    explicit disjoint_set(int N = 0) : N(N), S(N), nxt(N), siz(N, 1) {
        iota(begin(nxt), end(nxt), 0);
    }

    void assign(int n) { *this = disjoint_set(n); }
    void reset() { *this = disjoint_set(N); }
    bool same(int i, int j) { return find(i) == find(j); }
    int size(int i) { return siz[find(i)]; }

    void reroot(int u) {
        if (int r = find(u); u != r) {
            siz[u] = siz[r];
            nxt[u] = nxt[r] = u;
        }
    }

    int find(int i) { return i != nxt[i] ? nxt[i] = find(nxt[i]) : i; }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (siz[i] < siz[j]) {
                swap(i, j);
            }
            nxt[j] = i;
            siz[i] += siz[j];
            S--;
            return true;
        }
        return false;
    }
};

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

// Generic edge line tree, returns {u, v, edge index}
auto build_edge_line_tree(int N, const vector<array<int, 2>>& tree, vector<int> order) {
    disjoint_set dsu(N);
    reverse(begin(order), end(order));

    vector<int> left(N), right(N);
    iota(begin(left), end(left), 0);
    iota(begin(right), end(right), 0);

    vector<array<int, 3>> line;

    for (int e : order) {
        int u = tree[e][0], v = tree[e][1];
        u = dsu.find(u), v = dsu.find(v);
        dsu.join(u, v);
        int y = dsu.find(u);
        line.push_back({right[u], left[v], e});
        left[y] = left[u], right[y] = right[v];
    }

    return line;
}

// min edge line array for less<T> (i.e. array retains the minimum weight edge on path)
template <typename T, typename Compare = less<T>>
auto build_min_edge_line(int N, const vector<array<int, 2>>& edges,
                         const vector<T>& weight, const Compare& cmp = Compare()) {
    int E = N - 1;
    assert(E == int(edges.size()) && E == int(weight.size()));

    vector<int> order(E);
    iota(begin(order), end(order), 0);
    sort(begin(order), end(order),
         [&](int a, int b) { return cmp(weight[a], weight[b]); });

    auto line = build_edge_line_tree(N, edges, order);

    vector<array<int, 2>> adj(N, {-1, -1});
    for (int i = 0; i < E; i++) {
        auto [u, v, e] = line[i];
        adj[u][adj[u][0] != -1] = adj[v][adj[v][0] != -1] = i;
    }

    vector<int> index(N), edge(E);
    vector<T> value(E);

    for (int s = 0; s < N; s++) {
        if (adj[s][1] == -1) {
            int u = s, j = adj[s][0];
            for (int i = 0; i < E; i++) {
                index[u] = i, edge[i] = line[j][2];
                value[i] = weight[edge[i]];
                u = line[j][u == line[j][0]];
                j = adj[u][j == adj[u][0]];
            }
            assert(j == -1);
            index[u] = N - 1;
            break;
        }
    }

    return make_tuple(move(index), move(edge), move(value));
}

template <typename T, typename BinOp>
struct sparse_table {
    vector<vector<T>> table;
    BinOp binop;

    explicit sparse_table() = default;

    template <typename It>
    sparse_table(It first, It last, const BinOp& op = BinOp()) : binop(op) {
        table.emplace_back(first, last);
        int N = table[0].size();
        for (int len = 1, k = 1; 2 * len <= N; len *= 2, k++) {
            int J = N - 2 * len + 1;
            table.emplace_back(J);
            for (int j = 0; j < J; j++) {
                table[k][j] = binop(table[k - 1][j], table[k - 1][j + len]);
            }
        }
    }

    sparse_table(const vector<T>& v, const BinOp& op = BinOp())
        : sparse_table(begin(v), end(v), op) {}

    // query range [a,b)
    auto query(int a, int b) const {
        static constexpr int BITS = CHAR_BIT * sizeof(int) - 1;
        // assert(0 <= a && a < b && b <= int(table[0].size()));
        if (a + 1 == b) {
            return table[0][a];
        } else {
            int bits = BITS - __builtin_clz(b - a);
            return binop(table[bits][a], table[bits][b - (1 << bits)]);
        }
    }
};

struct maxop {
    int operator()(int a, int b) const { return max(a, b); }
};
struct minop {
    int operator()(int a, int b) const { return min(a, b); }
};

using min_rmq = sparse_table<int, minop>;
using max_rmq = sparse_table<int, maxop>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, M, Q;
        cin >> N >> M >> Q;
        vector<array<int, 2>> graph(M);
        for (auto& [u, v] : graph) {
            cin >> u >> v, u--, v--;
        }
        disjoint_set dsu(N);
        vector<array<int, 2>> tree_edges;
        vector<int> weight;
        for (int e = 0; e < M; e++) {
            auto [u, v] = graph[e];
            if (dsu.join(u, v)) {
                tree_edges.push_back({u, v});
                weight.push_back(e + 1);
            }
        }

        auto [index, edge, value] = build_min_edge_line(N, tree_edges, weight,
                                                        greater<int>{});
        max_rmq max_index(index);
        min_rmq min_index(index);
        max_rmq max_value(value);
        vector<int> ans(Q);
        for (int q = 0; q < Q; q++) {
            int l, r;
            cin >> l >> r, l--;
            if (r - l == 1) {
                ans[q] = 0;
            } else {
                int a = min_index.query(l, r);
                int b = max_index.query(l, r);
                int v = max_value.query(a, b);
                ans[q] = v;
            }
        }
        for (int q = 0; q < Q; q++) {
            cout << ans[q] << " \n"[q + 1 == Q];
        }
    }
    return 0;
}