#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

#ifdef LOCAL

#include "code/lib/graph_generator.hpp"
#include "code/algo/y_combinator.hpp"

void generate() {
    int N = 300'000, Q = 300'000;
    auto tree = random_tree(N);
    auto rands = rands_unif<int>(N, 1, 17);
    putln(N, Q);
    putln(rands);
    for (auto [u, v] : tree) {
        putln(u + 1, v + 1);
    }
    for (int q = 0; q < Q; q++) {
        int u = rand_unif<int>(1, N);
        int v = rand_unif<int>(1, N);
        auto [l, r] = minmax(rand_unif<int>(1, N), rand_unif<int>(1, N));
        putln(u, v, l, r);
    }
}

#else

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

#endif

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

template <typename Node>
struct persistent_segtree {
    vector<Node> node;
    vector<array<int, 2>> kids;
    vector<int> roots;
    vector<int8_t> lazy;

    persistent_segtree() = default;

    int num_nodes() const { return node.size(); }
    int versions() const { return roots.size(); }

    // After you're done building the dynamic tree, add a root to use
    int add_root(int u) {
        int version = roots.size();
        roots.push_back(u);
        return version;
    }

    // Sparse: build an arbitrary sized tree where nodes just point back to themselves
    int build_sparse(Node init) {
        int u = node.size();
        node.push_back(init);
        kids.push_back({u, u});
        lazy.push_back(false);
        return u;
    }

    // Concatenation: # nodes must be a power of two and all have the same length
    int build_concat(const vector<int>& leaves) {
        return build_concat_dfs(0, leaves.size(), leaves);
    }

    // Levels: # levels nodes are added
    int build_levels(int leaf, int levels) {
        int u = leaf;
        while (levels--) {
            u = add_node(u, u, combine(node[u], node[u]));
        }
        return u;
    }

    // Array: For an array of size N=R-L, build a straightforward segtree with 2N-1 nodes
    template <typename T>
    int build_array(int N, const vector<T>& arr, int s = 0) {
        return build_array_dfs(s, s + N, arr);
    }

    template <typename... Us>
    int update_point(int version, int L, int R, int i, Us&&... update) {
        assert(0 <= version && version < versions() && L <= i && i < R);
        return add_root(update_point_node(roots[version], L, R, i, update...));
    }

    template <typename... Us>
    int update_range(int version, int L, int R, int l, int r, Us&&... update) {
        assert(0 <= version && version < versions() && L <= l && l <= r && r <= R);
        if (l < r) {
            return add_root(update_range_node(roots[version], L, R, l, r, update...));
        } else {
            return add_root(clone_node(roots[version]));
        }
    }

    auto query_point(int version, int L, int R, int i) {
        assert(0 <= version && version < versions() && L <= i && i < R);
        return query_point_node(roots[version], L, R, i);
    }

    auto query_range(int version, int L, int R, int l, int r) {
        assert(0 <= version && version < versions() && L <= l && l <= r && r <= R);
        return l == r ? Node() : query_range_node(roots[version], L, R, l, r);
    }

    auto query_all(int version) { return node[roots[version]]; }

    template <typename Vis>
    auto visit_parents_up(int version, int L, int R, int i, Vis&& vis) {
        assert(0 <= version && version < versions() && L <= i && i < R);
        return visit_upwards(roots[version], L, R, i, vis);
    }

    template <typename Vis>
    auto visit_parents_down(int version, int L, int R, int i, Vis&& vis) {
        assert(0 <= version && version < versions() && L <= i && i < R);
        return visit_downwards(roots[version], L, R, i, vis);
    }

    template <bool rootpath, typename Vis>
    void visit_range_l_to_r(int version, int L, int R, int l, int r, Vis&& vis) {
        assert(0 <= version && version < versions() && L <= l && l <= r && r <= R);
        if (l < r) {
            visit_range_l_to_r_dfs<rootpath>(roots[version], L, R, l, r, vis);
        }
    }

    template <bool rootpath, typename Vis>
    void visit_range_r_to_l(int version, int L, int R, int l, int r, Vis&& vis) {
        assert(0 <= version && version < versions() && L <= l && l <= r && r <= R);
        if (l < r) {
            visit_range_r_to_l_dfs<rootpath>(roots[version], L, R, l, r, vis);
        }
    }

    // Binary search with Bs(prefix) on the range [0,N) for the False/True split
    // Aggregates the entire segment tree prefix.  F F F F >T< T T T [N=T)
    // Returns {index i of first truth, prefix aggregate [0,u)}
    template <typename Bs>
    auto prefix_binary_search(int version, int L, int R, Bs&& bs) {
        assert(0 <= version && version < versions());
        int u = roots[version];
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
    auto suffix_binary_search(int version, int L, int R, Bs&& bs) {
        assert(0 <= version && version < versions());
        int u = roots[version];
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
    auto prefix_range_search(int version, int L, int R, int l, int r, Bs&& bs) {
        assert(0 <= version && version < versions() && L <= l && l <= r && r <= R);
        return l == r ? make_pair(r, Node())
                      : run_prefix_search(roots[version], L, R, l, r, Node(), bs);
    }

    // Binary search with Bs(suffix) on the range [l,r) for the False/True split
    // Aggregate only values within this range. F F F F >T< T T [r=T)
    // Returns {index i of first truth, suffix aggregate [i,r)}
    template <typename Bs>
    auto suffix_range_search(int version, int L, int R, int l, int r, Bs&& bs) {
        assert(0 <= version && version < versions() && L <= l && l <= r && r <= R);
        return l == r ? make_pair(r, Node())
                      : run_suffix_search(roots[version], L, R, l, r, Node(), bs);
    }

    // Same as prefix_range_search, but in parallel on several versions
    template <size_t A, typename Bs>
    auto prefix_parallel_search(array<int, A> vers, int L, int R, int l, int r, Bs&& bs) {
        assert(L <= l && l <= r && r <= R);
        array<Node, A> init;
        init.fill(Node());
        if (l == r) {
            return make_pair(r, move(init));
        } else {
            for (unsigned i = 0; i < A; i++) {
                int version = vers[i];
                assert(0 <= version && version < versions());
                vers[i] = roots[version];
            }
            return run_prefix_parallel_search(vers, L, R, l, r, init, bs);
        }
    }

    // Same as suffix_range_search, but in parallel on several versions
    template <size_t A, typename Bs>
    auto suffix_parallel_search(array<int, A> vers, int L, int R, int l, int r, Bs&& bs) {
        assert(L <= l && l <= r && r <= R);
        array<Node, A> init;
        init.fill(Node());
        if (l == r) {
            return make_pair(r, move(init));
        } else {
            for (unsigned i = 0; i < A; i++) {
                int version = vers[i];
                assert(0 <= version && version < versions());
                vers[i] = roots[version];
            }
            return run_suffix_parallel_search(vers, L, R, l, r, init, bs);
        }
    }

  private:
    static Node combine(const Node& x, const Node& y) {
        Node ans;
        ans.pushup(x, y);
        return ans;
    }

    inline int add_node(int l, int r, Node v) {
        int u = num_nodes();
        node.push_back(move(v));
        lazy.push_back(false);
        kids.push_back({l, r});
        return u;
    }

    inline int clone_node(int u) {
        int v = node.size();
        node.push_back(node[u]);
        kids.push_back(kids[u]);
        lazy.push_back(lazy[u]);
        return v;
    }

    template <typename... Us>
    void apply(int u, int s, Us&&... update) {
        if constexpr (Node::RANGES) {
            node[u].apply(update..., s);
        } else {
            node[u].apply(update...);
        }
    }

    void pushup(int u) { node[u].pushup(node[kids[u][0]], node[kids[u][1]]); }

    void pushdown(int u, int s) {
        if (s > 1 && lazy[u]) {
            int a = kids[u][0] = clone_node(kids[u][0]);
            int b = kids[u][1] = clone_node(kids[u][1]);
            lazy[a] = lazy[b] = true, lazy[u] = false;
            if constexpr (!Node::LAZY) {
                return;
            } else if constexpr (Node::RANGES) {
                node[u].pushdown(node[a], node[b], s / 2, (s + 1) / 2);
            } else {
                node[u].pushdown(node[a], node[b]);
            }
        }
    }

    template <typename T>
    int build_array_dfs(int L, int R, const vector<T>& arr) {
        if (L + 1 == R) {
            return add_node(-1, -1, Node(arr[L]));
        } else {
            int M = (L + R) / 2;
            int a = build_array_dfs(L, M, arr);
            int b = build_array_dfs(M, R, arr);
            return add_node(a, b, combine(node[a], node[b]));
        }
    }

    int build_concat_dfs(int L, int R, const vector<int>& leaves) {
        if (L + 1 == R) {
            return leaves[L];
        } else {
            int M = (L + R) / 2;
            int a = build_concat_dfs(L, M, leaves);
            int b = build_concat_dfs(M, R, leaves);
            return add_node(a, b, combine(node[a], node[b]));
        }
    }

    auto query_point_node(int u, int L, int R, int i) {
        while (L + 1 < R) {
            pushdown(u, R - L);
            int M = (L + R) / 2;
            if (i < M) {
                u = kids[u][0], R = M;
            } else {
                u = kids[u][1], L = M;
            }
        }
        return node[u];
    }

    template <typename... Us>
    int update_point_node(int u, int L, int R, int i, Us&&... update) {
        static thread_local vector<int> dfs;
        int x = u = clone_node(u);
        while (L + 1 < R) {
            pushdown(u, R - L);
            int M = (L + R) / 2;
            dfs.push_back(u);
            if (i < M) {
                u = kids[u][0] = clone_node(kids[u][0]), R = M;
            } else {
                u = kids[u][1] = clone_node(kids[u][1]), L = M;
            }
        }
        apply(u, 1, update...);
        for (int B = dfs.size(), i = B - 1; i >= 0; i--) {
            pushup(dfs[i]);
        }
        dfs.clear();
        return x;
    }

    auto query_range_node(int u, int L, int R, int ql, int qr) {
        if (ql <= L && R <= qr) {
            return node[u];
        }
        pushdown(u, R - L);
        int M = (L + R) / 2;
        auto [a, b] = kids[u];
        if (qr <= M) {
            return query_range_node(a, L, M, ql, qr);
        } else if (M <= ql) {
            return query_range_node(b, M, R, ql, qr);
        } else {
            return combine(query_range_node(a, L, M, ql, M),
                           query_range_node(b, M, R, M, qr));
        }
    }

    template <typename... Us>
    int update_range_node(int u, int L, int R, int ql, int qr, Us&&... update) {
        int M = (R + L) / 2;
        u = clone_node(u);
        if (ql <= L && R <= qr) {
            apply(u, R - L, update...);
            lazy[u] = true;
            return u;
        }
        pushdown(u, R - L);
        auto [a, b] = kids[u];
        if (qr <= M) {
            kids[u][0] = update_range_node(a, L, M, ql, qr, update...);
        } else if (M <= ql) {
            kids[u][1] = update_range_node(b, M, R, ql, qr, update...);
        } else {
            kids[u][0] = update_range_node(a, L, M, ql, M, update...);
            kids[u][1] = update_range_node(b, M, R, M, qr, update...);
        }
        pushup(u);
        return u;
    }

    template <typename Vis>
    void visit_upwards(int u, int L, int R, int q, Vis&& vis) {
        if (L + 1 < R) {
            pushdown(u, R - L);
            int M = (L + R) / 2;
            auto [a, b] = kids[u];
            q < M ? visit_upwards(a, L, M, q, vis) : visit_upwards(b, M, R, q, vis);
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
            auto [a, b] = kids[u];
            q < M ? visit_downwards(a, L, M, q, vis) : visit_downwards(b, M, R, q, vis);
            pushup(u);
        } else {
            vis(node[u], L, R);
        }
    }

    template <typename Vis>
    void visit_range_l_to_r_dfs(int u, int L, int R, int ql, int qr, Vis&& vis) {
        if (ql <= L && R <= qr) {
            vis(node[u], L, R);
            return;
        }
        pushdown(u, R - L);
        int M = (L + R) / 2;
        auto [a, b] = kids[u];
        if (qr <= M) {
            visit_range_l_to_r_dfs(a, L, M, ql, qr, vis);
        } else if (M <= ql) {
            visit_range_l_to_r_dfs(b, M, R, ql, qr, vis);
        } else {
            visit_range_l_to_r_dfs(a, L, M, ql, M, vis);
            visit_range_l_to_r_dfs(b, M, R, M, qr, vis);
        }
        pushup(u);
    }

    template <typename Vis>
    void visit_range_r_to_l_dfs(int u, int L, int R, int ql, int qr, Vis&& vis) {
        if (ql <= L && R <= qr) {
            vis(node[u]);
            return;
        }
        pushdown(u, R - L);
        int M = (L + R) / 2;
        auto [a, b] = kids[u];
        if (qr <= M) {
            visit_range_r_to_l_dfs(a, L, M, ql, qr, vis);
        } else if (M <= ql) {
            visit_range_r_to_l_dfs(b, M, R, ql, qr, vis);
        } else {
            visit_range_r_to_l_dfs(b, M, R, M, qr, vis);
            visit_range_r_to_l_dfs(a, L, M, ql, M, vis);
        }
        pushup(u);
    }

    template <typename Bs>
    auto run_prefix_search(int u, int L, int R, int ql, int qr, Node prefix, Bs&& bs) {
        if (ql <= L && R <= qr) {
            Node extra = combine(prefix, node[u]);
            if (!bs(extra, R)) {
                return make_pair(R, move(extra));
            }
            while (L + 1 < R) {
                pushdown(u, R - L);
                int M = (L + R) / 2;
                auto [a, b] = kids[u];
                Node v = combine(prefix, node[a]);
                if (bs(v, M)) {
                    u = a, R = M;
                } else {
                    prefix = move(v);
                    u = b, L = M;
                }
            }
            Node v = combine(prefix, node[u]);
            return bs(v, R) ? make_pair(L, move(prefix)) : make_pair(R, move(v));
        }
        pushdown(u, R - L);
        int x, M = (L + R) / 2;
        auto [a, b] = kids[u];
        if (qr <= M) {
            return run_prefix_search(a, L, M, ql, qr, move(prefix), bs);
        } else if (M <= ql) {
            return run_prefix_search(b, M, R, ql, qr, move(prefix), bs);
        }
        tie(x, prefix) = run_prefix_search(a, L, M, ql, M, move(prefix), bs);
        if (x < M) {
            return make_pair(x, move(prefix));
        } else {
            return run_prefix_search(b, M, R, M, qr, move(prefix), bs);
        }
    }

    template <typename Bs>
    auto run_suffix_search(int u, int L, int R, int ql, int qr, Node suffix, Bs&& bs) {
        if (ql <= L && R <= qr) {
            Node extra = combine(node[u], suffix);
            if (bs(extra, L)) {
                return make_pair(L, move(extra));
            }
            while (L + 1 < R) {
                pushdown(u, R - L);
                int M = (L + R) / 2;
                auto [a, b] = kids[u];
                Node v = combine(node[b], suffix);
                if (bs(v, M)) {
                    suffix = move(v);
                    u = a, R = M;
                } else {
                    u = b, L = M;
                }
            }
            Node v = combine(node[u], suffix);
            return bs(v, L) ? make_pair(L, move(v)) : make_pair(R, move(suffix));
        }
        pushdown(u, R - L);
        int x, M = (L + R) / 2;
        auto [a, b] = kids[u];
        if (qr <= M) {
            return run_suffix_search(a, L, M, ql, qr, move(suffix), bs);
        } else if (M <= ql) {
            return run_suffix_search(b, M, R, ql, qr, move(suffix), bs);
        }
        tie(x, suffix) = run_suffix_search(b, M, R, M, qr, move(suffix), bs);
        if (x > M) {
            return make_pair(x, move(suffix));
        } else {
            return run_suffix_search(a, L, M, ql, M, move(suffix), bs);
        }
    }

    template <size_t A, typename Bs>
    auto run_prefix_parallel_search(array<int, A> who, int L, int R, int ql, int qr,
                                    array<Node, A> prefix, Bs&& bs) {
        if (ql <= L && R <= qr) {
            array<Node, A> extra;
            for (unsigned i = 0; i < A; i++) {
                extra[i] = combine(prefix[i], node[who[i]]);
            }
            if (!bs(extra, R)) {
                return make_pair(R, move(extra));
            }
            while (L + 1 < R) {
                int M = (L + R) / 2;
                array<Node, A> query;
                for (unsigned i = 0; i < A; i++) {
                    int u = who[i];
                    pushdown(u, R - L);
                    auto [a, b] = kids[u];
                    query[i] = combine(prefix[i], node[a]);
                }
                if (bs(query, M)) {
                    for (unsigned i = 0; i < A; i++) {
                        who[i] = kids[who[i]][0];
                    }
                    R = M;
                } else {
                    for (unsigned i = 0; i < A; i++) {
                        who[i] = kids[who[i]][1];
                    }
                    prefix = move(query);
                    L = M;
                }
            }
            array<Node, A> query;
            for (unsigned i = 0; i < A; i++) {
                query[i] = combine(prefix[i], node[who[i]]);
            }
            return bs(query, R) ? make_pair(L, move(prefix)) : make_pair(R, move(query));
        }
        int x, M = (L + R) / 2;
        array<int, A> left, right;
        for (unsigned i = 0; i < A; i++) {
            int u = who[i];
            pushdown(u, R - L);
            auto [a, b] = kids[u];
            left[i] = a, right[i] = b;
        }
        if (qr <= M) {
            return run_prefix_parallel_search(left, L, M, ql, qr, move(prefix), bs);
        } else if (M <= ql) {
            return run_prefix_parallel_search(right, M, R, ql, qr, move(prefix), bs);
        }
        tie(x, prefix) = run_prefix_parallel_search(left, L, M, ql, M, move(prefix), bs);
        if (x < M) {
            return make_pair(x, move(prefix));
        } else {
            return run_prefix_parallel_search(right, M, R, M, qr, move(prefix), bs);
        }
    }

    template <size_t A, typename Bs>
    auto run_suffix_parallel_search(array<int, A> who, int L, int R, int ql, int qr,
                                    array<Node, A> suffix, Bs&& bs) {
        if (ql <= L && R <= qr) {
            array<Node, A> extra;
            for (unsigned i = 0; i < A; i++) {
                extra[i] = combine(node[who[i]], suffix[i]);
            }
            if (bs(extra, L)) {
                return make_pair(L, move(extra));
            }
            while (L + 1 < R) {
                int M = (L + R) / 2;
                array<Node, A> query;
                for (unsigned i = 0; i < A; i++) {
                    int u = who[i];
                    pushdown(u, R - L);
                    auto [a, b] = kids[u];
                    query[i] = combine(node[b], suffix[i]);
                }
                if (bs(query, M)) {
                    for (unsigned i = 0; i < A; i++) {
                        who[i] = kids[who[i]][0];
                    }
                    suffix = move(query);
                    R = M;
                } else {
                    for (unsigned i = 0; i < A; i++) {
                        who[i] = kids[who[i]][1];
                    }
                    L = M;
                }
            }
            array<Node, A> query;
            for (unsigned i = 0; i < A; i++) {
                query[i] = combine(node[who[i]], suffix[i]);
            }
            return bs(query, L) ? make_pair(L, move(query)) : make_pair(R, move(suffix));
        }
        int x, M = (L + R) / 2;
        array<int, A> left, right;
        for (unsigned i = 0; i < A; i++) {
            int u = who[i];
            pushdown(u, R - L);
            auto [a, b] = kids[u];
            left[i] = a, right[i] = b;
        }
        if (qr <= M) {
            return run_suffix_parallel_search(left, L, M, ql, qr, move(suffix), bs);
        } else if (M <= ql) {
            return run_suffix_parallel_search(right, M, R, ql, qr, move(suffix), bs);
        }
        tie(x, suffix) = run_suffix_parallel_search(right, M, R, M, qr, move(suffix), bs);
        if (x > M) {
            return make_pair(x, move(suffix));
        } else {
            return run_suffix_parallel_search(left, L, M, ql, M, move(suffix), bs);
        }
    }
};

struct Segnode {
    static constexpr bool LAZY = false, RANGES = false;
    uint32_t value = 0;

    Segnode(uint32_t value = 0) : value(value) {}

    void pushup(const Segnode& lhs, const Segnode& rhs) { value = lhs.value ^ rhs.value; }

    void apply(uint32_t v) { value ^= v; }
};

static mt19937 rng(random_device{}());
uniform_int_distribution<uint32_t> randhash(0, UINT32_MAX);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i], a[i]--;
    }
    vector<vector<int>> tree(N);
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    hld_forest hld(tree, 0);

    vector<basic_string<int>> pos(N);
    for (int u = 0; u < N; u++) {
        pos[a[u]].push_back(u);
    }
    vector<uint32_t> minhash(N);
    for (int i = 0; i < N; i++) {
        minhash[i] = randhash(rng);
    }

    persistent_segtree<Segnode> seg;
    vector<int> version(N);

    y_combinator([&](auto self, int u, int root, int p) -> void {
        version[u] = root = seg.update_point(root, 0, N, a[u], minhash[a[u]]);
        for (int v : tree[u]) {
            if (v != p) {
                self(v, root, u);
            }
        }
    })(0, seg.add_root(seg.build_sparse(0)), -1);

    for (int q = 0; q < Q; q++) {
        int u, v, l, r;
        cin >> u >> v >> l >> r, u--, v--, l--;
        int c = hld.lca(u, v);
        int root = minhash[a[c]];

        auto searcher = [&](auto qs, int m) {
            return 0 == (qs[0].value ^ qs[1].value ^ (m <= a[c] && a[c] < r ? root : 0));
        };
        array<int, 2> vers = {version[u], version[v]};
        int ans = seg.suffix_parallel_search(vers, 0, N, l, r, searcher).first;
        cout << (ans == l ? -1 : ans) << '\n';
    }

    return 0;
}