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

struct hld_forest {
    vector<int> subsize, parent, depth, roots, order;
    vector<int> heavy; // heavy child of this node, tree[u][0]
    vector<int> head;  // top of heavy path
    vector<int> time;  // index of node in preorder tour with no repetition

    explicit hld_forest(vector<vector<int>>& tree, int root, bool sortkids = false) {
        int N = tree.size();
        subsize.assign(N, 0);
        parent.assign(N, -1);
        heavy.assign(N, -1);
        depth.assign(N, 0);
        head.assign(N, 0);
        time.assign(N, 0);
        order.assign(N, 0);
        int timer = 0;

        auto dfs = y_combinator([&](auto self, int u, int p) -> void {
            subsize[u] = 1;
            int biggest = 0;
            for (int& v : tree[u]) {
                if (v != p) {
                    parent[v] = u;
                    depth[v] = depth[u] + 1;
                    self(v, u);
                    subsize[u] += subsize[v];
                    if (biggest < subsize[v]) {
                        biggest = subsize[v];
                        heavy[u] = v;
                        if (sortkids) {
                            swap(tree[u][0], v);
                        }
                    }
                }
            }
        });

        auto decompose = y_combinator([&](auto self, int u, int h) -> void {
            order[timer] = u;
            head[u] = h;
            time[u] = timer++;
            if (heavy[u] != -1) {
                self(heavy[u], h);
            }
            for (int v : tree[u]) {
                if (v != parent[u] && v != heavy[u]) {
                    self(v, v);
                }
            }
        });

        if (root != -1) {
            dfs(root, -1);
            decompose(root, root);
            roots.push_back(root);
        }
        for (int u = 0; u < N; u++) {
            if (subsize[u] == 0) {
                dfs(u, -1);
                decompose(u, u);
                roots.push_back(u);
            }
        }
    }

    int num_nodes() const { return subsize.size(); }

    int max_depth() const { return *max_element(begin(depth), end(depth)); }

    int kth_ancestor(int u, int k) const {
        if (k < 0 || depth[u] < k) {
            return -1;
        }
        int dest = depth[u] - k;
        while (depth[u] > dest) {
            if (depth[head[u]] > dest) {
                u = parent[head[u]];
            } else {
                int up = depth[u] - dest;
                u = order[time[u] - up];
            }
        }
        return u;
    }

    int below(int u, int a) const { return kth_ancestor(u, depth[u] - depth[a] - 1); }

    int lca(int u, int v) const {
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                u = parent[head[u]];
            } else {
                v = parent[head[v]];
            }
        }
        return depth[u] < depth[v] ? u : v;
    }

    int findroot(int u) const {
        while (parent[head[u]] != -1) {
            u = parent[head[u]];
        }
        return head[u];
    }

    int dist(int u, int v) const { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }

    bool conn(int u, int v) const { return findroot(u) == findroot(v); }

    bool is_above(int u, int a) const {
        return time[a] <= time[u] && time[u] < time[a] + subsize[a];
    }

    bool is_above_on_heavy_path(int u, int a) const {
        return head[a] == head[u] && time[a] <= time[u];
    }

    bool on_path(int x, int u, int v) const {
        return is_above(x, lca(u, v)) && (is_above(u, x) || is_above(v, x));
    }

    int kth_on_path(int u, int v, int k) const {
        int a = lca(u, v);
        if (k <= depth[u] - depth[a]) {
            return kth_ancestor(u, k);
        } else if (k -= depth[u] - depth[a]; k <= depth[v] - depth[a]) {
            return kth_ancestor(v, depth[v] - depth[a] - k);
        } else {
            return -1;
        }
    }

    int join_node(int a, int b, int c) const {
        int x = lca(a, b), y = lca(b, c), z = lca(c, a);
        return x ^ y ^ z;
    }

    auto get_path(int u, int v) const {
        int a = lca(u, v);
        int D = depth[u] - depth[a] + 1;
        vector<int> path;
        while (u != a) {
            path.push_back(u), u = parent[u];
        }
        path.push_back(a);
        while (v != a) {
            path.push_back(v), v = parent[v];
        }
        reverse(begin(path) + D, end(path));
        return path;
    }

    int seg_edge_index(int u, int v) const { return parent[u] == v ? time[u] : time[v]; }

    auto seg_vertex_range(int u) const {
        return make_pair(time[u], time[u] + subsize[u]);
    }

    // Split the path from u to v into sorted heavy path segments [l,r), 0<=l<r<=N
    auto vertex_segments(int u, int v) const {
        vector<array<int, 2>> ranges;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                ranges.push_back({time[head[u]], time[u] + 1});
                u = parent[head[u]];
            } else {
                ranges.push_back({time[head[v]], time[v] + 1});
                v = parent[head[v]];
            }
        }
        if (depth[u] < depth[v]) {
            ranges.push_back({time[u], time[v] + 1});
        } else {
            ranges.push_back({time[v], time[u] + 1});
        }
        return ranges;
    }

    // Split the path from u to v into sorted heavy path segments [l,r), 0<=l<r<=N
    // down: l appears first on the path; up: l appears last on the path
    auto oriented_vertex_segments(int u, int v) const {
        vector<array<int, 2>> up, down;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                up.push_back({time[head[u]], time[u] + 1});
                u = parent[head[u]];
            } else {
                down.push_back({time[head[v]], time[v] + 1});
                v = parent[head[v]];
            }
        }
        if (depth[u] < depth[v]) {
            down.push_back({time[u], time[v] + 1});
        } else {
            up.push_back({time[v], time[u] + 1});
        }
        reverse(begin(down), end(down));
        return make_pair(move(up), move(down));
    }

    // Split the edge path from u to v into sorted heavy path segments [l,r), 1<=l<r<=N
    // We consider edges here, so that vertex u is responsible for its parent edge
    auto edge_segments(int u, int v) const {
        vector<array<int, 2>> ranges;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                ranges.push_back({time[head[u]], time[u] + 1});
                u = parent[head[u]];
            } else {
                ranges.push_back({time[head[v]], time[v] + 1});
                v = parent[head[v]];
            }
        }
        if (depth[u] < depth[v]) {
            ranges.push_back({time[u] + 1, time[v] + 1});
        } else if (depth[v] < depth[u]) {
            ranges.push_back({time[v] + 1, time[u] + 1});
        }
        return ranges;
    }

    // Split the edge path from u to v into sorted heavy path segments [l,r), 1<=l<r<=N
    // We consider edges here, so that vertex u is responsible for its parent edge
    // down: l appears first on the path; up: l appears last on the path
    auto oriented_edge_segments(int u, int v) const {
        vector<array<int, 2>> up, down;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                up.push_back({time[head[u]], time[u] + 1});
                u = parent[head[u]];
            } else {
                down.push_back({time[head[v]], time[v] + 1});
                v = parent[head[v]];
            }
        }
        if (depth[u] < depth[v]) {
            down.push_back({time[u] + 1, time[v] + 1});
        } else if (depth[v] < depth[u]) {
            up.push_back({time[v] + 1, time[u] + 1});
        }
        reverse(begin(down), end(down));
        return make_pair(move(up), move(down));
    }

    // Split the edge path from u to v into sorted heavy path segments [l,r), 1<=l<r<=N
    // Return inclusive bounds and merge heavy paths with their parent light edges.
    // Includes an extra 0-edge interval for the lca if it lies on a separate heavy path
    auto cut_segments(int u, int v) const {
        vector<array<int, 3>> ranges;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                ranges.push_back({head[u], time[parent[head[u]]], time[u]});
                u = parent[head[u]];
            } else {
                ranges.push_back({head[v], time[parent[head[v]]], time[v]});
                v = parent[head[v]];
            }
        }
        if (depth[u] < depth[v]) {
            ranges.push_back({head[v], time[u], time[v]});
        } else if (depth[v] < depth[u]) {
            ranges.push_back({head[u], time[v], time[u]});
        } else {
            ranges.push_back({head[u], time[u], time[u]}); // up or down doesn't matter
        }
        return ranges;
    }

    // Split the edge path from u to v into sorted heavy path segments [l,r), 1<=l<r<=N
    // Return inclusive bounds and merge heavy paths with their parent light edges.
    // Includes an extra 0-edge interval for the lca if it lies on a separate heavy path
    // down: l appears first on the path; up: l appears last on the path
    auto oriented_cut_segments(int u, int v) const {
        vector<array<int, 3>> down, up;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                up.push_back({head[u], time[head[u]] - 1, time[u]});
                u = parent[head[u]];
            } else {
                down.push_back({head[v], time[head[v]] - 1, time[v]});
                v = parent[head[v]];
            }
        }
        if (depth[u] < depth[v]) {
            down.push_back({head[v], time[u], time[v]});
        } else if (depth[v] < depth[u]) {
            up.push_back({head[u], time[v], time[u]});
        } else {
            up.push_back({head[u], time[u], time[u]}); // up or down doesn't matter
        }
        reverse(begin(down), end(down));
        return make_pair(move(up), move(down));
    }

    // Compute a minimal subtree that contains all the nodes with at most 2k-1 nodes
    auto compress_tree(vector<int> nodes) const {
        int k = nodes.size();
        auto cmp = [&](int a, int b) { return time[a] < time[b]; };
        sort(begin(nodes), end(nodes), cmp);

        for (int i = 0; i < k - 1; i++) {
            nodes.push_back(lca(nodes[i], nodes[i + 1]));
        }

        sort(begin(nodes) + k, end(nodes), cmp);
        inplace_merge(begin(nodes), begin(nodes) + k, end(nodes), cmp);
        nodes.erase(unique(begin(nodes), end(nodes)), end(nodes));
        k = nodes.size();

        vector<pair<int, int>> ctree;
        for (int i = 1; i < k; i++) {
            ctree.emplace_back(nodes[i], lca(nodes[i - 1], nodes[i]));
        }
        return make_pair(nodes[0], move(ctree));
    }
};

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

template <typename Node>
struct segtree {
    int n = 0;
    vector<Node> node;

    segtree() = default;
    segtree(int N, Node init) { assign(N, init); }
    template <typename T>
    segtree(int N, const vector<T>& arr, int s = 0) {
        assign(N, arr, s);
    }

    void assign(int N, Node init) {
        n = N;
        node.assign(2 * next_two(N), init);
        if (n > 0) {
            build_init_dfs(1, 0, n);
        }
    }

    template <typename T>
    void assign(int N, const vector<T>& arr, int s = 0) {
        assert(int(arr.size()) >= N + s);
        n = N;
        node.resize(2 * next_two(N));
        if (n > 0) {
            build_array_dfs(1, s, s + n, arr);
        }
    }

    template <typename... Us>
    void update_point(int i, Us&&... update) {
        static thread_local vector<int> dfs;
        assert(0 <= i && i < n);
        int u = 1, L = 0, R = n;
        while (L + 1 < R) {
            pushdown(u, R - L);
            dfs.push_back(u);
            int M = (L + R) / 2;
            if (i < M) {
                u = u << 1, R = M;
            } else {
                u = u << 1 | 1, L = M;
            }
        }
        apply(u, 1, update...);
        for (int B = dfs.size(), j = B - 1; j >= 0; j--) {
            pushup(dfs[j]);
        }
        dfs.clear();
    }

    template <typename... Us>
    void update_range(int l, int r, Us&&... update) {
        assert(0 <= l && l <= r && r <= n);
        if (l < r) {
            update_range_dfs(1, 0, n, l, r, update...);
        }
    }

    template <typename... Us>
    void update_beats(int l, int r, Us&&... update) {
        assert(0 <= l && l <= r && r <= n);
        if (l < r) {
            update_beats_dfs(1, 0, n, l, r, update...);
        }
    }

    template <typename Vis>
    void visit_beats(int l, int r, Vis&& vis) {
        assert(0 <= l && l <= r && r <= n);
        if (l < r) {
            visit_beats_dfs(1, 0, n, l, r, vis);
        }
    }

    auto query_point(int i) {
        assert(0 <= i && i < n);
        int u = 1, L = 0, R = n;
        while (L + 1 < R) {
            pushdown(u, R - L);
            int M = (L + R) / 2;
            if (i < M) {
                u = u << 1, R = M;
            } else {
                u = u << 1 | 1, L = M;
            }
        }
        return node[u];
    }

    auto query_range(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        return l == r ? Node() : query_range_dfs(1, 0, n, l, r);
    }

    auto query_all() { return node[1]; }

    template <typename Vis>
    auto visit_parents_up(int i, Vis&& vis) {
        assert(0 <= i && i < n);
        return visit_upwards(1, 0, n, i, vis);
    }

    template <typename Vis>
    auto visit_parents_down(int i, Vis&& vis) {
        assert(0 <= i && i < n);
        return visit_downwards(1, 0, n, i, vis);
    }

    template <bool rootpath, typename Vis>
    void visit_range_l_to_r(int l, int r, Vis&& vis) {
        assert(0 <= l && l <= r && r <= n);
        if (l < r) {
            visit_range_l_to_r_dfs<rootpath>(1, 0, n, l, r, vis);
        }
    }

    template <bool rootpath, typename Vis>
    void visit_range_r_to_l(int l, int r, Vis&& vis) {
        assert(0 <= l && l <= r && r <= n);
        if (l < r) {
            visit_range_r_to_l_dfs<rootpath>(1, 0, n, l, r, vis);
        }
    }

    // Binary search with Bs(prefix) on the range [0,N) for the False/True split
    // Aggregates the entire segment tree prefix.  F F F F >T< T T T [N=T)
    // Returns {index i of first truth, prefix aggregate [0,u)}
    template <typename Bs>
    auto prefix_binary_search(Bs&& bs) {
        int u = 1, L = 0, R = n;
        Node prefix = Node();
        while (L + 1 < R) {
            pushdown(u, R - L);
            int M = (L + R) / 2;
            Node v = combine(prefix, node[u << 1]);
            if (bs(v)) {
                u = u << 1, R = M;
            } else {
                prefix = move(v);
                u = u << 1 | 1, L = M;
            }
        }
        Node v = combine(prefix, node[u]);
        return bs(v) ? make_pair(L, move(prefix)) : make_pair(R, move(v));
    }

    // Binary search with Bs(suffix) on the range [0,N) for the False/True split
    // Aggregates the segment tree suffix. F F F F >T< T T T [N=T)
    // Returns {index i of first truth, suffix aggregate [u,N)}
    template <typename Bs>
    auto suffix_binary_search(Bs&& bs) {
        int u = 1, L = 0, R = n;
        Node suffix = Node();
        while (L + 1 < R) {
            pushdown(u, R - L);
            int M = (L + R) / 2;
            Node v = combine(node[u << 1 | 1], suffix);
            if (bs(v)) {
                suffix = move(v);
                u = u << 1, R = M;
            } else {
                u = u << 1 | 1, L = M;
            }
        }
        Node v = combine(node[u], suffix);
        return bs(v) ? make_pair(L, move(v)) : make_pair(R, move(suffix));
    }

    // Binary search with Bs(prefix) on the range [l,r) for the False/True split
    // Aggregate only values within this range. F F F F >T< T T [r=T)
    // Returns {index i of first truth, prefix aggregate [l,i)}
    template <typename Bs>
    auto prefix_range_search(int l, int r, Bs&& bs) {
        assert(0 <= l && l <= r && r <= n);
        return l == r ? make_pair(r, Node())
                      : run_prefix_search(1, 0, n, l, r, Node(), bs);
    }

    // Binary search with Bs(suffix) on the range [l,r) for the False/True split
    // Aggregate only values within this range. F F F F >T< T T [r=T)
    // Returns {index i of first truth, suffix aggregate [i,r)}
    template <typename Bs>
    auto suffix_range_search(int l, int r, Bs&& bs) {
        assert(0 <= l && l <= r && r <= n);
        return l == r ? make_pair(r, Node())
                      : run_suffix_search(1, 0, n, l, r, Node(), bs);
    }

  private:
    static int next_two(int N) {
        return 1 << (N > 1 ? 8 * sizeof(int) - __builtin_clz(N - 1) : 0);
    }

    static Node combine(const Node& x, const Node& y) {
        Node ans;
        ans.pushup(x, y);
        return ans;
    }

    template <typename... Us>
    inline bool can_break(int u, int s, Us&&... update) const {
        if constexpr (Node::RANGES) {
            return node[u].can_break(update..., s);
        } else {
            return node[u].can_break(update...);
        }
    }
    template <typename... Us>
    inline bool can_update(int u, int s, Us&&... update) const {
        if (s == 1) {
            return true;
        } else if constexpr (Node::RANGES) {
            return node[u].can_update(update..., s);
        } else {
            return node[u].can_update(update...);
        }
    }

    template <typename... Us>
    inline void apply(int u, int s, Us&&... update) {
        if constexpr (Node::RANGES) {
            node[u].apply(update..., s);
        } else {
            node[u].apply(update...), (void)s;
        }
    }

    inline void pushup(int u) { node[u].pushup(node[u << 1], node[u << 1 | 1]); }

    inline void pushdown(int u, int s) {
        if constexpr (!Node::LAZY) {
            return;
        } else if constexpr (Node::RANGES) {
            node[u].pushdown(node[u << 1], node[u << 1 | 1], s / 2, (s + 1) / 2);
        } else {
            node[u].pushdown(node[u << 1], node[u << 1 | 1]), (void)s;
        }
    }

    template <typename T>
    void build_array_dfs(int u, int L, int R, const vector<T>& arr) {
        if (L + 1 == R) {
            node[u] = arr[L];
        } else {
            int M = (L + R) / 2;
            build_array_dfs(u << 1, L, M, arr);
            build_array_dfs(u << 1 | 1, M, R, arr);
            pushup(u);
        }
    }

    void build_init_dfs(int u, int L, int R) {
        if (L + 1 < R) {
            int M = (L + R) / 2;
            build_init_dfs(u << 1, L, M);
            build_init_dfs(u << 1 | 1, M, R);
            pushup(u);
        }
    }

    template <typename... Us>
    void update_range_dfs(int u, int L, int R, int ql, int qr, Us&&... update) {
        if (ql <= L && R <= qr) {
            apply(u, R - L, update...);
            return;
        }
        pushdown(u, R - L);
        int M = (L + R) / 2;
        if (qr <= M) {
            update_range_dfs(u << 1, L, M, ql, qr, update...);
        } else if (M <= ql) {
            update_range_dfs(u << 1 | 1, M, R, ql, qr, update...);
        } else {
            update_range_dfs(u << 1, L, M, ql, M, update...);
            update_range_dfs(u << 1 | 1, M, R, M, qr, update...);
        }
        pushup(u);
    }

    template <typename... Us>
    void update_beats_dfs(int u, int L, int R, int ql, int qr, Us&&... update) {
        if (can_break(u, R - L, update...)) {
            return;
        }
        if (ql <= L && R <= qr && can_update(u, R - L, update...)) {
            apply(u, R - L, update...);
            return;
        }
        pushdown(u, R - L);
        int M = (L + R) / 2;
        if (qr <= M) {
            update_beats_dfs(u << 1, L, M, ql, qr, update...);
        } else if (M <= ql) {
            update_beats_dfs(u << 1 | 1, M, R, ql, qr, update...);
        } else {
            update_beats_dfs(u << 1, L, M, ql, M, update...);
            update_beats_dfs(u << 1 | 1, M, R, M, qr, update...);
        }
        pushup(u);
    }

    template <typename Vis>
    void visit_beats_dfs(int u, int L, int R, int ql, int qr, Vis&& vis) {
        if (ql <= L && R <= qr && vis(node[u], R - L)) {
            return;
        }
        pushdown(u, R - L);
        int M = (L + R) / 2;
        if (qr <= M) {
            visit_beats_dfs(u << 1, L, M, ql, qr, vis);
        } else if (M <= ql) {
            visit_beats_dfs(u << 1 | 1, M, R, ql, qr, vis);
        } else {
            visit_beats_dfs(u << 1, L, M, ql, M, vis);
            visit_beats_dfs(u << 1 | 1, M, R, M, qr, vis);
        }
        pushup(u);
    }

    auto query_range_dfs(int u, int L, int R, int ql, int qr) {
        if (ql <= L && R <= qr) {
            return node[u];
        }
        pushdown(u, R - L);
        int M = (L + R) / 2;
        if (qr <= M) {
            return query_range_dfs(u << 1, L, M, ql, qr);
        } else if (M <= ql) {
            return query_range_dfs(u << 1 | 1, M, R, ql, qr);
        } else {
            return combine(query_range_dfs(u << 1, L, M, ql, M),
                           query_range_dfs(u << 1 | 1, M, R, M, qr));
        }
    }

    template <typename Vis>
    void visit_upwards(int u, int L, int R, int q, Vis&& vis) {
        if (L + 1 < R) {
            pushdown(u, R - L);
            int M = (L + R) / 2;
            q < M ? visit_upwards(u << 1, L, M, q, vis)
                  : visit_upwards(u << 1 | 1, M, R, q, vis);
            pushup(u);
            vis(node[u], L, R);
        } else {
            vis(node[u], L, R);
        }
    }

    template <typename Vis>
    void visit_downwards(int u, int L, int R, int q, Vis&& vis) {
        if (L + 1 < R) {
            pushdown(u, R - L);
            vis(node[u], L, R);
            int M = (L + R) / 2;
            q < M ? visit_downwards(u << 1, L, M, q, vis)
                  : visit_downwards(u << 1 | 1, M, R, q, vis);
            pushup(u);
        } else {
            vis(node[u], L, R);
        }
    }

    template <bool rootpath, typename Vis>
    void visit_range_l_to_r_dfs(int u, int L, int R, int ql, int qr, Vis&& vis) {
        if constexpr (rootpath)
            vis(node[u], L, R);
        if (ql <= L && R <= qr) {
            if constexpr (!rootpath)
                vis(node[u], L, R);
            return;
        }
        pushdown(u, R - L);
        int M = (L + R) / 2;
        if (qr <= M) {
            visit_range_l_to_r_dfs(u << 1, L, M, ql, qr, vis);
        } else if (M <= ql) {
            visit_range_l_to_r_dfs(u << 1 | 1, M, R, ql, qr, vis);
        } else {
            visit_range_l_to_r_dfs(u << 1, L, M, ql, M, vis);
            visit_range_l_to_r_dfs(u << 1 | 1, M, R, M, qr, vis);
        }
        pushup(u);
    }

    template <bool rootpath, typename Vis>
    void visit_range_r_to_l_dfs(int u, int L, int R, int ql, int qr, Vis&& vis) {
        if constexpr (rootpath)
            vis(node[u], L, R);
        if (ql <= L && R <= qr) {
            if constexpr (!rootpath)
                vis(node[u], L, R);
            return;
        }
        pushdown(u, R - L);
        int M = (L + R) / 2;
        if (qr <= M) {
            visit_range_r_to_l_dfs(u << 1, L, M, ql, qr, vis);
        } else if (M <= ql) {
            visit_range_r_to_l_dfs(u << 1 | 1, M, R, ql, qr, vis);
        } else {
            visit_range_r_to_l_dfs(u << 1 | 1, M, R, M, qr, vis);
            visit_range_r_to_l_dfs(u << 1, L, M, ql, M, vis);
        }
        pushup(u);
    }

    template <typename Bs>
    auto run_prefix_search(int u, int L, int R, int ql, int qr, Node prefix, Bs&& bs) {
        if (L + 1 == R) {
            Node full = combine(prefix, node[u]);
            return bs(full) ? make_pair(L, move(prefix)) : make_pair(R, move(full));
        }
        pushdown(u, R - L);
        int x, M = (L + R) / 2;
        if (ql <= L && R <= qr) {
            Node middle = combine(prefix, node[u << 1]);
            if (bs(middle)) {
                return run_prefix_search(u << 1, L, M, ql, qr, move(prefix), bs);
            } else {
                return run_prefix_search(u << 1 | 1, M, R, ql, qr, move(middle), bs);
            }
        }
        if (qr <= M) {
            return run_prefix_search(u << 1, L, M, ql, qr, move(prefix), bs);
        } else if (M <= ql) {
            return run_prefix_search(u << 1 | 1, M, R, ql, qr, move(prefix), bs);
        }
        tie(x, prefix) = run_prefix_search(u << 1, L, M, ql, qr, move(prefix), bs);
        if (x < M) {
            return make_pair(x, move(prefix));
        } else {
            return run_prefix_search(u << 1 | 1, M, R, M, qr, move(prefix), bs);
        }
    }

    template <typename Bs>
    auto run_suffix_search(int u, int L, int R, int ql, int qr, Node suffix, Bs&& bs) {
        if (L + 1 == R) {
            Node full = combine(node[u], suffix);
            return bs(full) ? make_pair(L, move(full)) : make_pair(R, move(suffix));
        }
        pushdown(u, R - L);
        int x, M = (L + R) / 2;
        if (ql <= L && R <= qr) {
            Node middle = combine(node[u << 1 | 1], suffix);
            if (bs(middle)) {
                return run_suffix_search(u << 1, L, M, ql, qr, move(middle), bs);
            } else {
                return run_suffix_search(u << 1 | 1, M, R, ql, qr, move(suffix), bs);
            }
        }
        if (qr <= M) {
            return run_suffix_search(u << 1, L, M, ql, qr, move(suffix), bs);
        } else if (M <= ql) {
            return run_suffix_search(u << 1 | 1, M, R, ql, qr, move(suffix), bs);
        }
        tie(x, suffix) = run_suffix_search(u << 1 | 1, M, R, M, qr, move(suffix), bs);
        if (x > M) {
            return make_pair(x, move(suffix));
        } else {
            return run_suffix_search(u << 1, L, M, ql, M, move(suffix), bs);
        }
    }
};

struct Segnode {
    static constexpr bool LAZY = true, RANGES = false;
    int value = 1;

    Segnode(int value = 1) : value(value) {}

    void pushup(const Segnode&, const Segnode&) {}

    void pushdown(Segnode& lhs, Segnode& rhs) {
        lhs.apply(value);
        rhs.apply(value);
    }

    void apply(int v) { value &= v; }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<array<int, 2>> graph(M);
    for (int i = 0; i < M; i++) {
        auto& [u, v] = graph[i];
        cin >> u >> v, u--, v--;
    }
    disjoint_set dsu(N);
    vector<array<int, 2>> bad;
    vector<vector<int>> tree(N);
    for (int i = 0; i < M; i++) {
        auto [u, v] = graph[i];
        if (dsu.join(u, v)) {
            tree[u].push_back(v);
            tree[v].push_back(u);
        } else {
            bad.push_back({u, v});
        }
    }
    debug(bad);
    hld_forest hld(tree, 0, false);
    segtree<Segnode> seg(N, 1);
    for (auto [u, v] : bad) {
        int a = hld.lca(u, v);
        if (hld.time[u] > hld.time[v]) {
            swap(u, v);
        }
        if (a != u && a != v) {
            auto [l1, r1] = hld.seg_vertex_range(u);
            auto [l2, r2] = hld.seg_vertex_range(v);
            seg.update_range(0, l1, 0);
            seg.update_range(r1, l2, 0);
            seg.update_range(r2, N, 0);
        } else if (a == u) {
            int c = hld.below(v, a);
            auto [l1, r1] = hld.seg_vertex_range(c);
            auto [l2, r2] = hld.seg_vertex_range(v);
            seg.update_range(l1, l2, 0);
            seg.update_range(r2, r1, 0);
        } else if (a == v) {
            int c = hld.below(u, a);
            auto [l1, r1] = hld.seg_vertex_range(c);
            auto [l2, r2] = hld.seg_vertex_range(u);
            seg.update_range(l1, l2, 0);
            seg.update_range(r2, r1, 0);
        }
    }
    string ans(N, '0');
    for (int u = 0; u < N; u++) {
        ans[u] = '0' + (seg.query_point(hld.time[u]).value == 1);
    }
    cout << ans << '\n';
    return 0;
}