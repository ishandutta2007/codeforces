#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

/**
 * Likewise, but report which colored intervals were overwritten or cut.
 * Processor is called as processor({L, R}, old_color)
 *
 * Complexity: O(log N) amortized per write/cut
 */
template <typename T, typename V>
struct merging_interval_processor : map<array<T, 2>, V> {
    static constexpr inline T inf = numeric_limits<T>::max();
    using run_t = array<T, 2>;
    using base_t = map<array<T, 2>, V>;

    run_t universe() const {
        return {base_t::begin()->first[0], base_t::rbegin()->first[1]};
    }

    template <typename Fn>
    void write(run_t intv, V color, Fn&& processor) {
        auto& [L, R] = intv;
        if (L >= R) {
            return;
        }
        auto lo = base_t::lower_bound({L, L});
        auto hi = base_t::upper_bound({R, inf});
        if (hi != base_t::begin()) {
            if (auto phi = prev(hi); phi->first[1] > R) {
                if (phi->second == color) { // extend new rightwards, removing old
                    R = phi->first[1];
                } else if (phi->first[0] < L) { // splice
                    auto [x, y] = phi->first;
                    auto red = phi->second;
                    processor(intv, red);
                    base_t::erase(phi);
                    base_t::emplace_hint(hi, run_t{x, L}, red);
                    base_t::emplace_hint(hi, run_t{L, R}, color);
                    base_t::emplace_hint(hi, run_t{R, y}, red);
                    return;
                } else { // cut old rightwards and don't remove it
                    if (phi->first[0] < R) {
                        processor(run_t{phi->first[0], R}, phi->second);
                        const_cast<T&>(phi->first[0]) = R;
                    }
                    hi = phi;
                }
            }
        }
        if (lo != base_t::begin()) {
            if (auto plo = prev(lo); plo->first[1] >= L) {
                if (plo->second == color) { // extend new leftwards, removing old
                    L = plo->first[0], lo = plo;
                } else if (plo->first[0] < L) { // cut old leftwards and don't remove it
                    if (plo->first[1] > L) {
                        processor(run_t{L, plo->first[1]}, plo->second);
                        const_cast<T&>(plo->first[1]) = L;
                    }
                } else { // just cut old
                    lo = plo;
                }
            }
        }
        for (auto it = lo; it != hi; ++it) {
            if (it->second != color) {
                processor(it->first, it->second);
            }
        }
        base_t::erase(lo, hi);
        base_t::emplace_hint(hi, intv, color);
    }

    template <typename Fn>
    void cut(run_t intv, Fn&& processor) {
        auto& [L, R] = intv;
        if (L >= R) {
            return;
        }
        auto lo = base_t::lower_bound({L, L});
        auto hi = base_t::lower_bound({R, R});
        if (hi != base_t::begin()) {
            if (auto phi = prev(hi); phi->first[0] < L && phi->first[1] > R) { // splice
                auto [x, y] = phi->first;
                auto color = phi->second;
                processor(intv, color);
                base_t::erase(phi);
                base_t::emplace_hint(hi, run_t{x, L}, color);
                base_t::emplace_hint(hi, run_t{R, y}, color);
                return;
            } else if (phi->first[1] > R) { // cut old rightwards and don't remove it
                if (phi->first[0] < R) {
                    processor(run_t{phi->first[0], R}, phi->second);
                    const_cast<T&>(phi->first[0]) = R;
                }
                hi = phi;
            }
        }
        if (lo != base_t::begin()) {
            if (auto plo = prev(lo); plo->first[1] > L) { // cut old leftwards
                processor(run_t{L, plo->first[1]}, plo->second);
                const_cast<T&>(plo->first[1]) = L;
            }
        }
        for (auto it = lo; it != hi; ++it) {
            processor(it->first, it->second);
        }
        base_t::erase(lo, hi);
    }

    optional<run_t> get_run(T x) const {
        auto it = base_t::upper_bound({x, inf});
        if (it != base_t::begin() && prev(it)->first[0] <= x && x < prev(it)->first[1]) {
            return prev(it)->first;
        }
        return std::nullopt;
    }

    optional<V> get(T x) const {
        auto it = base_t::upper_bound({x, inf});
        if (it != base_t::begin() && prev(it)->first[0] <= x && x < prev(it)->first[1]) {
            return prev(it)->second;
        }
        return std::nullopt;
    }

    V& val(T x) { return prev(base_t::upper_bound({x, inf}))->second; }

    bool contains(T x) const { return get_run(x).has_value(); }

    bool contains(run_t intv) const {
        auto wrap = get_run(intv[0]);
        return wrap.has_value() && wrap->first[1] >= intv[1];
    }

    bool overlaps(run_t intv) const {
        auto lo = base_t::lower_bound({intv[0], intv[0]});
        return !(lo == base_t::end() || lo->first[0] >= intv[1]) ||
               !(lo == base_t::begin() || prev(lo)->first[1] <= intv[0]);
    }

    // Get run including x, or the one closest before x (or end() if none)
    auto before(T x) const {
        auto it = base_t::upper_bound({x, inf});
        return it != base_t::begin() ? prev(it) : base_t::end();
    }

    // Get run strictly before x (or end() if none)
    auto before_strict(T x) const {
        auto it = base_t::upper_bound({x, x});
        if (it != base_t::begin() && prev(it)->first[1] > x)
            --it;
        return it != base_t::begin() ? prev(it) : base_t::end();
    }

    // Get run including x, or the one closest after x (or end() if none)
    auto after(T x) const {
        auto it = base_t::upper_bound({x, inf});
        return it != base_t::begin() && prev(it)->first[1] > x ? prev(it) : it;
    }

    // Get run strictly after x (or end() if none)
    auto after_strict(T x) const {
        return base_t::upper_bound({x, inf}); //
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

struct Segnode {
    static constexpr bool LAZY = true, RANGES = true;
    int64_t value = 0, lazy = 0;

    Segnode(int64_t value = 0) : value(value) {}

    void pushup(const Segnode& lhs, const Segnode& rhs) {
        assert(lazy == 0);
        value = lhs.value + rhs.value;
    }

    void pushdown(Segnode& lhs, Segnode& rhs, int a, int b) {
        if (lazy) {
            lhs.apply(lazy, a);
            rhs.apply(lazy, b);
            lazy = 0;
        }
    }

    void apply(int64_t add, int s) {
        value += s * add;
        lazy += add;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;

    vector<int64_t> weight(N);
    segtree<Segnode> base(N, 0);
    merging_interval_processor<int, int> mip;
    mip[{0, N}] = 0;

    while (Q--) {
        string command;
        cin >> command;
        if (command == "Color") {
            int l, r, c;
            cin >> l >> r >> c, l--, c--;
            mip.write({l, r}, c, [&](auto intv, int p) {
                base.update_range(intv[0], intv[1], weight[p] - weight[c]);
            });
        } else if (command == "Add") {
            int c, x;
            cin >> c >> x, c--;
            weight[c] += x;
        } else if (command == "Query") {
            int i;
            cin >> i, i--;
            cout << base.query_point(i).value + weight[mip.val(i)] << '\n';
        } else {
            assert(false);
        }
    }
    return 0;
}