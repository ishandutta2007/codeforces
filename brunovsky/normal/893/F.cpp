#pragma GCC optimize "O3"
#include <bits/stdc++.h>

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
            return run_prefix_psearch(vers, L, R, l, r, init, bs);
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
                assert(0 <= vers[i] && vers[i] < versions());
                vers[i] = roots[vers[i]];
            }
            return run_suffix_psearch(vers, L, R, l, r, init, bs);
        }
    }

    int meld(int v1, int v2, int L, int R, int zero) {
        assert(L < R && v1 != v2);
        return add_root(run_meld(roots[v1], roots[v2], L, R, zero));
    }

    int meld(const vector<int>& vers, int L, int R, int zero) {
        static_assert(!Node::LAZY && "Unimplemented you moron");
        assert(L < R);
        vector<int> pts;
        for (int v : vers) {
            if (v != zero) {
                pts.push_back(roots[v]);
            }
        }
        return add_root(run_meld(pts, L, R, zero));
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
        for (int B = dfs.size(), j = B - 1; j >= 0; j--) {
            pushup(dfs[j]);
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
        if (L + 1 == R) {
            Node full = combine(prefix, node[u]);
            return bs(full) ? make_pair(L, move(prefix)) : make_pair(R, move(full));
        }
        pushdown(u, R - L);
        int x, M = (L + R) / 2;
        auto [a, b] = kids[u];
        if (ql <= L && R <= qr) {
            Node middle = combine(prefix, node[a]);
            if (bs(middle)) {
                return run_prefix_search(a, L, M, ql, qr, move(prefix), bs);
            } else {
                return run_prefix_search(b, M, R, ql, qr, move(middle), bs);
            }
        }
        if (qr <= M) {
            return run_prefix_search(a, L, M, ql, qr, move(prefix), bs);
        } else if (M <= ql) {
            return run_prefix_search(b, M, R, ql, qr, move(prefix), bs);
        }
        tie(x, prefix) = run_prefix_search(a, L, M, ql, qr, move(prefix), bs);
        if (x < M) {
            return make_pair(x, move(prefix));
        } else {
            return run_prefix_search(b, M, R, M, qr, move(prefix), bs);
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
        auto [a, b] = kids[u];
        if (ql <= L && R <= qr) {
            Node middle = combine(node[b], suffix);
            if (bs(middle)) {
                return run_suffix_search(a, L, M, ql, qr, move(middle), bs);
            } else {
                return run_suffix_search(b, M, R, ql, qr, move(suffix), bs);
            }
        }
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
    auto get_kids(const array<int, A>& who, int s) {
        array<int, A> under;
        for (unsigned i = 0; i < A; i++) {
            under[i] = kids[who[i]][s];
        }
        return under;
    }

    template <size_t A, typename Bs>
    auto run_prefix_psearch(array<int, A> who, int L, int R, int ql, int qr,
                            array<Node, A> prefix, Bs&& bs) {
        if (L + 1 == R) {
            array<Node, A> full;
            for (unsigned i = 0; i < A; i++) {
                full[i] = combine(prefix[i], node[who[i]]);
            }
            return bs(full) ? make_pair(L, move(prefix)) : make_pair(R, move(full));
        }
        for (unsigned i = 0; i < A; i++) {
            pushdown(who[i], R - L);
        }
        int x, M = (L + R) / 2;
        if (ql <= L && R <= qr) {
            array<Node, A> middle;
            for (unsigned i = 0; i < A; i++) {
                auto [a, b] = kids[who[i]];
                middle[i] = combine(prefix[i], node[a]);
            }
            if (bs(middle)) {
                return run_prefix_psearch(aget(who, 0), L, M, ql, qr, move(prefix), bs);
            } else {
                return run_prefix_psearch(aget(who, 1), M, R, ql, qr, move(middle), bs);
            }
        }
        if (qr <= M) {
            return run_prefix_psearch(aget(who, 0), L, M, ql, qr, move(prefix), bs);
        } else if (M <= ql) {
            return run_prefix_psearch(aget(who, 1), M, R, ql, qr, move(prefix), bs);
        }
        tie(x, prefix) = run_prefix_psearch(aget(who, 0), L, M, ql, qr, move(prefix), bs);
        if (x < M) {
            return make_pair(x, move(prefix));
        } else {
            return run_prefix_psearch(aget(who, 1), M, R, M, qr, move(prefix), bs);
        }
    }

    template <size_t A, typename Bs>
    auto run_suffix_psearch(array<int, A> who, int L, int R, int ql, int qr,
                            array<Node, A> suffix, Bs&& bs) {
        if (L + 1 == R) {
            array<Node, A> full;
            for (unsigned i = 0; i < A; i++) {
                full[i] = combine(node[who[i]], suffix[i]);
            }
            return bs(full) ? make_pair(L, move(full)) : make_pair(R, move(suffix));
        }
        for (unsigned i = 0; i < A; i++) {
            pushdown(who[i], R - L);
        }
        int x, M = (L + R) / 2;
        if (ql <= L && R <= qr) {
            array<Node, A> middle;
            for (unsigned i = 0; i < A; i++) {
                auto [a, b] = kids[who[i]];
                middle[i] = combine(node[b], suffix[i]);
            }
            if (bs(middle)) {
                return run_suffix_psearch(aget(who, 0), L, M, ql, qr, move(middle), bs);
            } else {
                return run_suffix_psearch(aget(who, 1), M, R, ql, qr, move(suffix), bs);
            }
        }
        if (qr <= M) {
            return run_suffix_psearch(aget(who, 0), L, M, ql, qr, move(suffix), bs);
        } else if (M <= ql) {
            return run_suffix_psearch(aget(who, 1), M, R, ql, qr, move(suffix), bs);
        }
        tie(x, suffix) = run_suffix_psearch(aget(who, 1), M, R, M, qr, move(suffix), bs);
        if (x > M) {
            return make_pair(x, move(suffix));
        } else {
            return run_suffix_psearch(aget(who, 0), L, M, ql, M, move(suffix), bs);
        }
    }

    int run_meld(int u, int v, int L, int R, int zero) {
        if (u == zero || v == zero) {
            return u ^ v ^ zero;
        } else if (L + 1 == R) {
            int x = clone_node(zero);
            node[x].meld(node[u]);
            node[x].meld(node[v]);
            return x;
        } else {
            pushdown(u, R - L);
            pushdown(v, R - L);
            int M = (L + R) / 2;
            int a = run_meld(kids[u][0], kids[v][0], L, M, kids[zero][0]);
            int b = run_meld(kids[u][1], kids[v][1], M, R, kids[zero][1]);
            return add_node(a, b, combine(node[a], node[b]));
        }
    }

    int run_meld(const vector<int>& pts, int L, int R, int zero) {
        if (int D = pts.size(); D == 0) {
            return zero;
        } else if (D == 1) {
            return pts[0];
        } else if (L + 1 == R) {
            int u = clone_node(zero);
            for (int i = 0; i < D; i++) {
                node[u].meld(node[pts[i]]);
            }
            return u;
        } else {
            vector<int> left, right;
            for (int i = 0; i < D; i++) {
                auto [a, b] = kids[pts[i]];
                if (a != kids[zero][0]) {
                    left.push_back(a);
                }
                if (b != kids[zero][1]) {
                    right.push_back(b);
                }
            }
            int M = (L + R) / 2;
            int a = run_meld(left, L, M, kids[zero][0]);
            int b = run_meld(right, M, R, kids[zero][1]);
            return add_node(a, b, combine(node[a], node[b]));
        }
    }
};

struct Segnode {
    static constexpr bool LAZY = false, RANGES = false;
    static constexpr int inf = INT_MAX;
    int value = inf;

    Segnode(int value = inf) : value(value) {}

    void pushup(const Segnode& lhs, const Segnode& rhs) {
        value = min(lhs.value, rhs.value);
    }

    void apply(int add) { value = add; }
};

int main() {
    ios::sync_with_stdio(false), cout.tie(nullptr), cin.tie(nullptr);
    int N, root;
    cin >> N >> root, root--;
    vector<int> val(N);
    for (int i = 0; i < N; i++) {
        cin >> val[i];
    }
    vector<vector<int>> tree(N);
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> depth(N), tin(N), tout(N);
    int timer = 0;
    y_combinator([&](auto self, int u, int p) -> void {
        tin[u] = timer++;
        for (int v : tree[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                self(v, u);
            }
        }
        tout[u] = timer;
    })(root, -1);

    vector<int> order(N);
    iota(begin(order), end(order), 0);
    sort(begin(order), end(order), [&](int i, int j) { return depth[i] < depth[j]; });

    persistent_segtree<Segnode> seg;
    int ver = seg.add_root(seg.build_sparse(Segnode()));
    int d = 0;
    vector<int> version(N);

    for (int i : order) {
        if (depth[i] > d) {
            version[d++] = ver;
        }
        ver = seg.update_point(ver, 0, N, tin[i], val[i]);
    }
    while (d < N) {
        version[d++] = ver;
    }

    int Q, last = 0;
    cin >> Q;

    while (Q--) {
        int p, q;
        cin >> p >> q;
        int x = (p + last) % N;
        int k = (q + last) % N;
        int d = min(N - 1, depth[x] + k);
        last = seg.query_range(version[d], 0, N, tin[x], tout[x]).value;
        cout << last << '\n';
    }

    return 0;
}