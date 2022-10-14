#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

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
            if (bs(extra)) {
                while (L + 1 < R) {
                    pushdown(u, R - L);
                    int M = (L + R) / 2;
                    auto [a, b] = kids[u];
                    Node v = combine(prefix, node[a]);
                    if (bs(v)) {
                        u = a, R = M;
                    } else {
                        prefix = move(v);
                        u = b, L = M;
                    }
                }
                Node v = combine(prefix, node[u]);
                return bs(v) ? make_pair(L, move(prefix)) : make_pair(R, move(v));
            } else {
                return make_pair(R, move(extra));
            }
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
            if (!bs(extra)) {
                while (L + 1 < R) {
                    pushdown(u, R - L);
                    int M = (L + R) / 2;
                    auto [a, b] = kids[u];
                    Node v = combine(node[b], suffix);
                    if (bs(v)) {
                        suffix = move(v);
                        u = a, R = M;
                    } else {
                        u = b, L = M;
                    }
                }
                Node v = combine(node[u], suffix);
                return bs(v) ? make_pair(L, move(v)) : make_pair(R, move(suffix));
            } else {
                return make_pair(L, move(extra));
            }
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
};

struct Segnode {
    static constexpr bool LAZY = false, RANGES = false;
    int value = 0;

    Segnode(int value = 0) : value(value) {}

    void pushup(const Segnode& lhs, const Segnode& rhs) { value = lhs.value + rhs.value; }

    void apply(int add) { value += add; }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i], a[i]--;
    }

    vector<int> prev(N), val(N, -1);
    for (int i = 0; i < N; i++) {
        prev[i] = val[a[i]], val[a[i]] = i;
    }

    vector<int> indices(N);
    iota(begin(indices), end(indices), 0);
    sort(begin(indices), end(indices), [&](int i, int j) { return prev[i] < prev[j]; });

    persistent_segtree<Segnode> seg;
    int root = seg.add_root(seg.build_sparse(0));

    vector<int> ver(N + 1);
    ver[0] = root;
    int current = 0;

    for (int i : indices) {
        while (prev[i] >= current) {
            ver[current + 1] = ver[current], current++;
        }
        ver[current] = seg.update_point(ver[current], 0, N, i, +1);
    }
    while (current < N) {
        ver[current + 1] = ver[current], current++;
    }

    auto find = [&](int l, int k) {
        auto [i, n] = seg.prefix_range_search(ver[l], 0, N, l, N,
                                              [k](auto x) { return x.value > k; });
        return i;
    };

    vector<int> ans(N + 1);

    for (int k = 1; k < N; k++) {
        int l = 0;
        while (l < N) {
            l = find(l, k), ans[k]++;
        }
    }
    for (int k = N; k > 0 && ans[k] == 0; k--) {
        ans[k] = 1;
    }
    for (int k = 1; k <= N; k++) {
        cout << ans[k] << " \n"[k == N];
    }
    return 0;
}

// number of intervals is <=n/k so you can brute force with online range distinct query