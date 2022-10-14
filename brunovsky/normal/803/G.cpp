#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename Node>
struct lazy_dynamic_segtree {
    vector<Node> node;
    vector<bool> readonly;
    vector<array<int, 2>> kids;

    lazy_dynamic_segtree() = default;

    int num_nodes() const { return node.size(); }

    // Sparse: build an arbitrary sized tree where nodes just point back to themselves
    int build_sparse(Node init, bool mark_readonly) {
        if (mark_readonly) {
            int u = node.size();
            node.push_back(init);
            readonly.push_back(true);
            kids.push_back({u, u});
            return u;
        } else {
            int u = node.size();
            int v = u + 1;
            node.push_back(init);
            readonly.push_back(false);
            kids.push_back({v, v});
            node.push_back(init);
            readonly.push_back(true);
            kids.push_back({v, v});
            return u;
        }
    }

    // Concatenation: # nodes must be a power of two and all have the same length
    int build_concat(const vector<int>& leaves, bool mark_readonly) {
        int N = leaves.size();
        int u = node.size();
        int M = N / 2;
        assert((N & (N - 1)) == 0 && N > 1);
        node.resize(u + N);
        readonly.resize(u + N, mark_readonly);
        kids.resize(u + N);
        for (int i = 0; i < M; i++) {
            kids[u + i + M] = {leaves[i << 1], leaves[i << 1 | 1]};
            pushup(u + i + M);
        }
        for (int i = M - 1; i > 0; i--) {
            kids[u + i] = {u + (i << 1), u + (i << 1 | 1)};
            pushup(u + i);
        }
        return u + 1;
    }

    // Levels: # levels readonly nodes are added
    int build_levels(int leaf, int levels, bool mark_readonly) {
        assert(levels > 0 && leaf < int(node.size()));
        int r = node.size();
        node.resize(r + levels);
        readonly.resize(r + levels, true);
        kids.resize(r + levels);
        kids[r + levels - 1] = {leaf, leaf};
        pushup(r + levels - 1);
        for (int u = r + levels - 2; u >= r; u--) {
            kids[u] = {u + 1, u + 1};
            pushup(u);
        }
        readonly[r] = mark_readonly;
        return r;
    }

    // Array: For an array of size N=R-L, build a straightforward segtree with 2N-1 nodes
    template <typename T>
    int build_array(int L, int R, const vector<T>& arr, bool mark_readonly, int s = 0) {
        int N = R - L;
        int u = node.size();
        node.resize(u + 2 * N - 1);
        readonly.resize(u + 2 * N - 1, mark_readonly);
        kids.resize(u + 2 * N - 1);
        auto dfs = [&](const auto& self, int l, int r) -> int {
            if (l + 1 == r) {
                kids[u] = {-1, -1};
                node[u] = Node(arr[l - s]);
            } else {
                int m = l + (r - l) / 2;
                int a = self(self, l, m);
                int b = self(self, m, r);
                kids[u] = {a, b};
                pushup(u);
            }
            return u++;
        };
        return dfs(dfs, L, R);
    }

    auto query_point(int u, int l, int r, int Q) {
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            pushdown(u, l, m, r);
            if (Q < m) {
                u = kids[u][0], r = m;
            } else {
                u = kids[u][1], l = m;
            }
        }
        return node[u];
    }

    template <typename Update>
    void update_point(int u, int l, int r, int Q, Update&& update) {
        static thread_local vector<int> dfs;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            pushdown(u, l, m, r);
            dfs.push_back(u);
            if (Q < m) {
                u = kids[u][0], r = m;
            } else {
                u = kids[u][1], l = m;
            }
        }
        dfs.push_back(u);
        apply(u, update, Q, Q + 1);
        for (int B = dfs.size(), i = B - 2; i >= 0; i--) {
            pushup(dfs[i]);
        }
        dfs.clear();
    }

    auto query_range(int u, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR) {
            return node[u];
        }
        int m = l + (r - l) / 2;
        pushdown(u, l, m, r);
        auto [a, b] = kids[u];
        if (qR <= m) {
            return query_range(a, l, m, qL, qR);
        } else if (m <= qL) {
            return query_range(b, m, r, qL, qR);
        } else {
            return combine(query_range(a, l, m, qL, m), query_range(b, m, r, m, qR));
        }
    }

    template <typename Update>
    void update_range(int u, int l, int r, int qL, int qR, Update&& update) {
        if (qL <= l && r <= qR) {
            apply(u, update, l, r);
            return;
        }
        int m = l + (r - l) / 2;
        pushdown(u, l, m, r);
        auto [a, b] = kids[u];
        if (qR <= m) {
            update_range(a, l, m, qL, qR, update);
        } else if (m <= qL) {
            update_range(b, m, r, qL, qR, update);
        } else {
            update_range(a, l, m, qL, m, update);
            update_range(b, m, r, m, qR, update);
        }
        pushup(u);
    }

    auto query_all(int u) const { return node[u]; }

    template <typename Update>
    void update_all(int u, int l, int r, Update&& update) {
        apply(u, update, l, r);
    }

  private:
    static Node combine(const Node& x, const Node& y) {
        Node ans;
        ans.pushup(x, y);
        return ans;
    }
    template <typename Update>
    void apply(int u, Update&& update, int l, int r) {
        if constexpr (Node::RANGES) {
            node[u].apply(update, r - l);
        } else {
            node[u].apply(update), (void)l, (void)r;
        }
    }
    void pushup(int u) {
        node[u].pushup(node[kids[u][0]], node[kids[u][1]]); //
    }
    void pushdown(int u, int l, int m, int r) {
        int a = kids[u][0] = maybe_clone_node(kids[u][0]);
        int b = kids[u][1] = maybe_clone_node(kids[u][1]);
        if constexpr (Node::RANGES) {
            node[u].pushdown(node[a], node[b], m - l, r - m);
        } else {
            node[u].pushdown(node[a], node[b]), (void)l, (void)m, (void)r;
        }
    }

    int maybe_clone_node(int u) {
        if (readonly[u]) {
            int v = node.size();
            node.push_back(node[u]);
            readonly.push_back(false);
            kids.push_back(kids[u]);
            return v;
        } else {
            return u;
        }
    }
};

template <typename T>
struct min_segnode {
    static constexpr bool LAZY = true, RANGES = false, REVERSE = false;
    static constexpr T MAX = numeric_limits<T>::max();

    T value = MAX;
    T lazy = 0;

    min_segnode() = default;
    min_segnode(T v) : value(v) {}
    operator T const &() const { return value; }

    void pushup(const min_segnode& lhs, const min_segnode& rhs) {
        value = min(lhs.value, rhs.value);
    }
    void pushdown(min_segnode& lhs, min_segnode& rhs) {
        if (lazy != 0) {
            lhs.apply(lazy);
            rhs.apply(lazy);
            lazy = 0;
        }
    }
    void apply(T add) {
        value = add;
        lazy = add;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    K = K > 1 ? 8 * sizeof(int) - __builtin_clz(K - 1) : 1;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    using node = min_segnode<int>;
    lazy_dynamic_segtree<node> st;
    int root = st.build_levels(st.build_array(0, N, arr, true), K, false);
    const int L = 0, R = N * (1 << K);

    int Q;
    cin >> Q;
    while (Q--) {
        int type, l, r;
        cin >> type >> l >> r, l--;
        if (type == 1) {
            int x;
            cin >> x;
            st.update_range(root, L, R, l, r, x);
        } else {
            cout << st.query_range(root, L, R, l, r) << '\n';
        }
    }

    return 0;
}