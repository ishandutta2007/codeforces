#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

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
        build_init_dfs(1, 0, n);
    }

    template <typename T>
    void assign(int N, const vector<T>& arr, int s = 0) {
        assert(int(arr.size()) >= N + s);
        n = N;
        node.resize(2 * next_two(N));
        build_array_dfs(1, s, s + n, arr);
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
        for (int B = dfs.size(), i = B - 1; i >= 0; i--) {
            pushup(dfs[i]);
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

    template <typename Vis>
    void visit_range_l_to_r(int l, int r, Vis&& vis) {
        assert(0 <= l && l <= r && r <= n);
        if (l < r) {
            visit_range_l_to_r_dfs(1, 0, n, l, r, vis);
        }
    }

    template <typename Vis>
    void visit_range_r_to_l(int l, int r, Vis&& vis) {
        assert(0 <= l && l <= r && r <= n);
        if (l < r) {
            visit_range_r_to_l_dfs(1, 0, n, l, r, vis);
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
            node[u].apply(update...);
        }
    }

    inline void pushup(int u) { node[u].pushup(node[u << 1], node[u << 1 | 1]); }

    inline void pushdown(int u, int s) {
        if constexpr (!Node::LAZY) {
            return;
        } else if constexpr (Node::RANGES) {
            node[u].pushdown(node[u << 1], node[u << 1 | 1], s / 2, (s + 1) / 2);
        } else {
            node[u].pushdown(node[u << 1], node[u << 1 | 1]);
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
        if (ql <= L && R <= qr && vis(u, R - L)) {
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

    template <typename Vis>
    void visit_range_l_to_r_dfs(int u, int L, int R, int ql, int qr, Vis&& vis) {
        if (ql <= L && R <= qr) {
            vis(node[u]);
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

    template <typename Vis>
    void visit_range_r_to_l_dfs(int u, int L, int R, int ql, int qr, Vis&& vis) {
        if (ql <= L && R <= qr) {
            vis(node[u]);
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
        if (ql <= L && R <= qr) {
            Node extra = combine(prefix, node[u]);
            if (bs(extra)) {
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
            } else {
                return make_pair(R, move(extra));
            }
        }
        pushdown(u, R - L);
        int x, M = (L + R) / 2;
        if (qr <= M) {
            return run_prefix_search(u << 1, L, M, ql, qr, move(prefix), bs);
        } else if (M <= ql) {
            return run_prefix_search(u << 1 | 1, M, R, ql, qr, move(prefix), bs);
        }
        tie(x, prefix) = run_prefix_search(u << 1, L, M, ql, M, move(prefix), bs);
        if (x < M) {
            return make_pair(x, move(prefix));
        } else {
            return run_prefix_search(u << 1 | 1, M, R, M, qr, move(prefix), bs);
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
            } else {
                return make_pair(L, move(extra));
            }
        }
        pushdown(u, R - L);
        int x, M = (L + R) / 2;
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

template <typename T>
struct fullji_segnode {
    static constexpr bool LAZY = true, RANGES = true;
    static constexpr T MIN = numeric_limits<T>::lowest();
    static constexpr T MAX = numeric_limits<T>::max();
    enum Operation { SETMIN, SETMAX, ADD, SET };

    T sum = 0;
    T minimum = MAX;
    T maximum = MIN;
    T second_min = MAX;
    T second_max = MIN;
    int count_min = 0;
    int count_max = 0;

    bool has_set_lazy = false;
    T set_lazy = 0;
    T add_lazy = 0;

    fullji_segnode() = default;
    fullji_segnode(T v) : sum(v), minimum(v), maximum(v), count_min(1), count_max(1) {}

    bool can_break(Operation op, T v, int) const {
        if (op == SETMIN) {
            return v >= maximum;
        } else if (op == SETMAX) {
            return v <= minimum;
        } else {
            return false;
        }
    }
    bool can_update(Operation op, T v, int) const {
        if (op == SETMIN) {
            return v > second_max;
        } else if (op == SETMAX) {
            return v < second_min;
        } else {
            return true;
        }
    }

    void pushup(const fullji_segnode& lhs, const fullji_segnode& rhs) {
        sum = lhs.sum + rhs.sum;

        minimum = min(lhs.minimum, rhs.minimum);
        if (minimum == lhs.minimum && minimum == rhs.minimum) {
            second_min = min(lhs.second_min, rhs.second_min);
            count_min = lhs.count_min + rhs.count_min;
        } else if (minimum == lhs.minimum) {
            second_min = min(lhs.second_min, rhs.minimum);
            count_min = lhs.count_min;
        } else {
            second_min = min(lhs.minimum, rhs.second_min);
            count_min = rhs.count_min;
        }

        maximum = max(lhs.maximum, rhs.maximum);
        if (maximum == lhs.maximum && maximum == rhs.maximum) {
            second_max = max(lhs.second_max, rhs.second_max);
            count_max = lhs.count_max + rhs.count_max;
        } else if (maximum == lhs.maximum) {
            second_max = max(lhs.second_max, rhs.maximum);
            count_max = lhs.count_max;
        } else {
            second_max = max(lhs.maximum, rhs.second_max);
            count_max = rhs.count_max;
        }
    }
    void pushdown(fullji_segnode& lhs, fullji_segnode& rhs, int l, int r) {
        if (has_set_lazy) {
            lhs.apply_set(set_lazy, l);
            rhs.apply_set(set_lazy, r);
            add_lazy = set_lazy = has_set_lazy = 0;
        } else {
            if (add_lazy != 0) {
                lhs.apply_add(add_lazy, l);
                rhs.apply_add(add_lazy, r);
                add_lazy = 0;
            }
            lhs.apply_min(maximum, l);
            rhs.apply_min(maximum, r);
            lhs.apply_max(minimum, l);
            rhs.apply_max(minimum, r);
        }
    }
    void apply_set(T v, int s) {
        sum = v * s;
        minimum = v;
        maximum = v;
        second_min = MAX;
        second_max = MIN;
        count_min = s;
        count_max = s;
        has_set_lazy = true;
        set_lazy = v;
        add_lazy = 0;
    }
    void apply_min(T v, int s) {
        if (minimum >= v) {
            apply_set(v, s);
        } else if (maximum > v) {
            assert(second_max < v);
            if (second_min == maximum) {
                second_min = v;
            }
            sum -= (maximum - v) * count_max;
            maximum = v;
        }
    }
    void apply_max(T v, int s) {
        if (maximum <= v) {
            apply_set(v, s);
        } else if (minimum < v) {
            assert(second_min > v);
            if (second_max == minimum) {
                second_max = v;
            }
            sum += (v - minimum) * count_min;
            minimum = v;
        }
    }
    void apply_add(T v, int s) {
        if (minimum == maximum) {
            apply_set(minimum + v, s);
        } else {
            sum += v * s;
            minimum += v;
            maximum += v;
            second_min = second_min == MAX ? MAX : v + second_min;
            second_max = second_max == MIN ? MIN : v + second_max;
            add_lazy += v;
        }
    }
    void apply(Operation op, T v, int s) {
        if (op == SETMIN) {
            apply_min(v, s);
        } else if (op == SETMAX) {
            apply_max(v, s);
        } else if (op == ADD) {
            apply_add(v, s);
        } else if (op == SET) {
            apply_set(v, s);
        } else {
            assert(false && "Invalid operation");
        }
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> nums(N + 2);
    iota(begin(nums), end(nums), 0);
    set<int> possible(begin(nums), end(nums));
    segtree<fullji_segnode<int>> st(N + 2, N + 2);
    using Operation = fullji_segnode<int>::Operation;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, x;
            cin >> l >> r >> x, r++;
            if (x == 1) {
                st.update_point(l, Operation::SETMIN, r);
            } else if (x == 0) {
                auto it = possible.lower_bound(l);
                while (*it < r) {
                    it = possible.erase(it);
                }
            }
        } else {
            int i;
            cin >> i;
            if (!possible.count(i)) {
                cout << "NO\n";
                debug(i, "NO");
                continue;
            }
            int L = *--possible.lower_bound(i);
            int R = *possible.upper_bound(i);
            int close = st.query_range(L + 1, i + 1).minimum;
            assert(close >= i + 1);
            debug(i, L, R, close);
            cout << (close <= R ? "YES\n" : "N/A\n");
        }
    }
    return 0;
}

// x=0 you just set a bunch of zeros there
// x=1 you do setmin and setmax on a segtree?