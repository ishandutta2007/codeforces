#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct disjoint_set {
    int N, S;
    vector<int> next, size;

    explicit disjoint_set(int N = 0) : N(N), S(N), next(N), size(N, 1) {
        iota(begin(next), end(next), 0);
    }

    void assign(int n) { *this = disjoint_set(n); }
    void reset() { *this = disjoint_set(N); }
    bool same(int i, int j) { return find(i) == find(j); }
    bool unit(int i) { return i == next[i] && size[i] == 1; }
    bool root(int i) { return find(i) == i; }
    void reroot(int u) {
        if (int r = find(u); u != r) {
            size[u] = size[r];
            next[u] = next[r] = u;
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

template <typename T, typename BinOp>
struct sparse_table {
    vector<vector<T>> table;
    BinOp binop;

    template <typename It>
    sparse_table(It first, It last, const BinOp& op) : binop(op) {
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

    sparse_table(const vector<T>& v, const BinOp& op)
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

// Generic edge-decomposed binary tree.
// Edge e is assigned vertex N+e, and the tree has 2N-1 vertices
auto build_edge_virtual_tree(int N, const vector<array<int, 2>>& tree,
                             vector<int> order) {
    disjoint_set dsu(N);
    reverse(begin(order), end(order));

    vector<int> top(N);
    iota(begin(top), end(top), 0);

    int V = 2 * N - 1;
    vector<array<int, 2>> kids(V, {-1, -1});
    vector<int> parent(V, -1);

    for (int e : order) {
        int u = tree[e][0], v = tree[e][1];
        u = dsu.find(u), v = dsu.find(v);
        dsu.join(u, v);
        int a = top[u], b = top[v];
        kids[N + e] = {a, b};
        top[u] = top[v] = parent[a] = parent[b] = N + e;
    }

    int root = N + order.back();
    return make_tuple(root, move(parent), move(kids));
}

// min edge-decomposed binary tree (i.e. root of tree is minimum weight edge)
template <typename T, typename Compare = greater<T>>
auto build_max_edge_virtual_tree(int N, const vector<array<int, 2>>& edges,
                                 const vector<T>& weight,
                                 const Compare& cmp = Compare()) {
    int E = N - 1;
    assert(E == int(edges.size()) && E == int(weight.size()));

    vector<int> order(E);
    iota(begin(order), end(order), 0);
    sort(begin(order), end(order),
         [&](int a, int b) { return cmp(weight[a], weight[b]); });

    return build_edge_virtual_tree(N, edges, order);
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
template <typename T, typename Compare = greater<T>>
auto build_max_edge_line(int N, const vector<array<int, 2>>& edges,
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

    for (int s = 0; s < N; s++) {
        if (adj[s][1] == -1) {
            vector<int> index(N), edge(E);
            vector<T> value(E);
            int u = s, j = adj[s][0];
            for (int i = 0; i < E; i++) {
                index[u] = i, edge[i] = line[j][2];
                value[i] = weight[edge[i]];
                u = line[j][u == line[j][0]];
                j = adj[u][j == adj[u][0]];
            }
            assert(j == -1);
            index[u] = N - 1;
            return make_tuple(move(index), move(edge), move(value));
        }
    }
    __builtin_unreachable();
}

void vec_merge(vector<int>& a, vector<int>& b) {
    if (a.size() < b.size()) {
        swap(a, b);
    }
    a.insert(end(a), begin(b), end(b));
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<array<int, 2>> edges(M);
        vector<int> weight(M);
        for (int i = 0; i < M; i++) {
            int a, b, c;
            cin >> a >> b >> c, a--, b--;
            edges[i] = {a, b};
            weight[i] = c;
        }

        vector<int> edge_order(M);
        iota(begin(edge_order), end(edge_order), 0);
        sort(begin(edge_order), end(edge_order),
             [&](int x, int y) { return weight[x] < weight[y]; });

        disjoint_set dsu(N);
        vector<array<int, 2>> mintree;
        vector<int> minweight;
        for (int e : edge_order) {
            auto [a, b] = edges[e];
            if (dsu.join(a, b)) {
                mintree.push_back({a, b});
                minweight.push_back(weight[e]);
            }
        }
        assert(dsu.S == 1);

        int root = -1;
        vector<array<int, 2>> kids;
        vector<int> parent;

        tie(root, parent, kids) = build_max_edge_virtual_tree(N, mintree, minweight);

        set<array<int, 2>> exists;
        for (auto [u, v] : edges) {
            auto [a, b] = minmax(u, v);
            exists.insert({a, b});
        }
        auto valid = [&](int u, int v) {
            assert(u != v);
            auto [a, b] = minmax(u, v);
            return !exists.count({a, b});
        };

        vector<map<int, vector<int>>> link(2 * N - 1);
        for (int u = 0; u < N; u++) {
            link[u][u].push_back(u);
        }

        dsu.reset();
        vector<array<int, 3>> check;

        y_combinator([&](auto self, int i) -> void {
            if (i >= N) {
                int cost = minweight[i - N];
                int a = kids[i][0];
                int b = kids[i][1];
                self(a), self(b);

                auto find = [&](const auto& as, const auto& bs){
                    for (int a : as) {
                        for (int b : bs) {
                            if (valid(a, b)) {
                                check.push_back({a, b, cost});
                                dsu.join(a, b);
                                return;
                            }
                        }
                    }
                };

                // Go through each set on the left and each set on the right, try to
                // match them. They won't be very big usually
                for (const auto& [ka, sa] : link[a]) {
                    for (const auto& [kb, sb] : link[b]) {
                        if (!dsu.same(ka, kb)) {
                            find(sa, sb);
                        }
                    }
                }
                for (int kid : {a, b}) {
                    for (auto& [k, s] : link[kid]) {
                        int r = dsu.find(k);
                        vec_merge(link[i][r], s);
                    }
                    link[kid].clear();
                }
            }
        })(root);
        assert(dsu.S == 1);

        sort(begin(check), end(check), [&](auto a, auto b) { return a[2] < b[2]; });

        mintree.clear();
        minweight.clear();
        dsu.reset();

        for (auto [a, b, c] : check) {
            if (dsu.join(a, b)) {
                mintree.push_back({a, b});
                minweight.push_back(c);
            }
        }
        assert(dsu.S == 1);

        vector<int> index, edge, value;
        tie(index, edge, value) = build_max_edge_line(N, mintree, minweight);
        sparse_table rmq(value, [](int a, int b) { return max(a, b); });

        vector<int> ans(M);
        for (int i = 0; i < M; i++) {
            auto [u, v] = edges[i];
            auto [a, b] = minmax(index[u], index[v]);
            ans[i] = rmq.query(a, b);
        }

        for (int i = 0; i < M; i++) {
            cout << ans[i] << " \n"[i + 1 == M];
        }
    }
    return 0;
}