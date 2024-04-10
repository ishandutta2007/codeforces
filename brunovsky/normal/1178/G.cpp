#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

#ifdef LOCAL
#include "code/random.hpp"
#include "code/lib/graph_generator.hpp"

void generate() {
    int N = 20000;
    int Q = 40000;
    int C = 5000;
    auto tree = random_tree(N);
    vector<int> parent(N - 1);
    for (int i = 0; i < N - 1; i++) {
        parent[i] = tree[i][0] + 1;
    }
    vector<int> a = rands_unif<int>(N, -C, C);
    vector<int> b = rands_unif<int>(N, -C, C);
    putln(N, Q);
    putln(parent);
    putln(a);
    putln(b);
    for (int q = 0; q < Q; q++) {
        if (cointoss(0.5)) {
            putln(1, rand_unif<int>(1, N), rand_unif<int>(1, C));
        } else {
            putln(2, rand_unif<int>(1, N));
        }
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

void setmax(int64_t& a, int64_t b) { a = max(a, b); }

struct Block {
    int S = 0, A = 0, F = 0, B = 0;
    vector<int> a, b, order, forw, back;
    // compute max (a[i]+A)b[i] and min (a[i]+A)b[i] with increasing A
    // maximum: as a[i] increases we prefer larger b[i]
    // increment: add A b[i] to each element

    int64_t get(int i) const { return int64_t(a[i] + A) * b[i]; }
    int64_t allmin() const { return get(back[B]); }
    int64_t allmax() const { return get(forw[F]); }
    int64_t get() const { return max(abs(allmin()), abs(allmax())); }
    int64_t get_range(int l, int r) const {
        int64_t ans = 0;
        for (int i = l; i < r; i++) {
            setmax(ans, abs(get(i)));
        }
        return ans;
    }

    // How much do we have to add to j for it to get better than i?
    int64_t maxswp(int i, int j) const {
        assert(b[i] < b[j] && get(i) > get(j));
        // (a[i]+A)b[i] <= (a[j]+A)b[j] <==> A>=(a[i]b[i]-a[j]b[j])/D
        int D = b[j] - b[i];
        return (get(i) - get(j) + D - 1) / D;
    }

    // How much do we have to add to j for it to be better than i?
    int64_t minswp(int i, int j) const {
        assert(b[i] > b[j] && get(i) < get(j));
        // (a[i]+A)b[i] >= (a[j]+A)b[j] <==> A>=(a[j]b[j]-a[i]b[i])/D
        int D = b[i] - b[j];
        return (get(j) - get(i) + D - 1) / D;
    }

    void prepare(int l, int r, const vector<int>& ain, const vector<int>& bin) {
        assert(0 <= l && l < r && r <= int(ain.size()));
        S = r - l;
        a.assign(begin(ain) + l, begin(ain) + r);
        b.assign(begin(bin) + l, begin(bin) + r);
        order.resize(S);
        iota(begin(order), end(order), 0);
        sort(begin(order), end(order), [&](int i, int j) { return b[i] < b[j]; });
        rebuild();
    }

    void add_all(int add) {
        A += add;
        int size = forw.size();
        while (F + 1 < size && get(forw[F]) <= get(forw[F + 1])) {
            F++;
        }
        size = back.size();
        while (B + 1 < size && get(back[B]) >= get(back[B + 1])) {
            B++;
        }
    }

    void add_middle(int l, int r, int add) {
        assert(0 <= l && l < r && r <= S);
        for (int i = 0; i < S; i++) {
            a[i] += l <= i && i < r ? add + A : A;
        }
        A = 0;
        rebuild();
    }

    void rebuild() {
        F = B = 1;
        forw = {order[0]};
        back = {order[S - 1]};
        for (int i = 1; i < S; i++) {
            int u = order[i];
            int64_t v = get(u);
            if (b[u] == b[forw.back()] && a[u] < a[forw.back()]) {
                continue;
            }
            while (F > 0 && get(forw.back()) <= v) {
                forw.pop_back(), F--;
            }
            while (F > 1 && maxswp(forw[F - 2], forw[F - 1]) >= maxswp(forw[F - 1], u)) {
                forw.pop_back(), F--;
            }
            forw.push_back(u), F++;
        }
        for (int i = S - 2; i >= 0; i--) {
            int u = order[i];
            int64_t v = get(u);
            if (b[u] == b[back.back()] && a[u] > a[back.back()]) {
                continue;
            }
            while (B > 0 && get(back.back()) >= v) {
                back.pop_back(), B--;
            }
            while (B > 1 && minswp(back[B - 2], back[B - 1]) >= minswp(back[B - 1], u)) {
                back.pop_back(), B--;
            }
            back.push_back(u), B++;
        }
        F = B = 0;
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
            return (void)s, node[u].can_break(update...);
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

constexpr int64_t inf = INT64_MAX / 4;

struct Fn {
    int a = 0, b = 0;

    int64_t operator()() const { return 1LL * a * b; }

    // When does time flip?
    static int64_t improv(Fn f, Fn g) {
        if (f() < g()) {
            swap(f, g);
        }
        if (f.b >= g.b) {
            return inf;
        } else {
            return (f() - g() + g.b - f.b - 1) / (g.b - f.b);
        }
    }
};

struct Segnode {
    static constexpr bool LAZY = true, RANGES = false;
    Fn fn;
    int lazy = 0;
    int64_t time = inf;

    Segnode() = default;
    Segnode(Fn fn) : fn(fn) {}

    void pushup(const Segnode& lhs, const Segnode& rhs) {
        fn = lhs.fn() >= rhs.fn() ? lhs.fn : rhs.fn;
        time = min({lhs.time, rhs.time, Fn::improv(lhs.fn, rhs.fn)});
    }

    void pushdown(Segnode& lhs, Segnode& rhs) {
        if (lazy) {
            lhs.apply(lazy);
            rhs.apply(lazy);
            lazy = 0;
        }
    }

    void apply(int add) {
        assert(add < time);
        fn.a += add;
        lazy += add;
        time -= add;
    }

    bool can_break(int) const { return false; }
    bool can_update(int x) const { return x < time; }

    void apply(int A, int B) { fn = {A, B}; }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> parent(N);
    vector<vector<int>> tree(N);
    for (int i = 1; i < N; i++) {
        cin >> parent[i], parent[i]--;
        tree[parent[i]].push_back(i);
    }
    vector<int> a_init(N), b_init(N);
    for (int i = 0; i < N; i++) {
        cin >> a_init[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b_init[i];
    }
    vector<int> a(N), b(N), tin(N), tout(N);
    int timer = 0;
    y_combinator([&](auto self, int u, int A, int B) -> void {
        int i = timer++;
        tin[u] = i;
        a[i] = a_init[u] + A;
        b[i] = b_init[u] + B;
        for (int v : tree[u]) {
            self(v, a[i], b[i]);
        }
        tout[u] = timer;
    })(0, 0, 0);

    vector<Fn> funs(2 * N);
    for (int i = 0; i < N; i++) {
        funs[i << 1 | 0] = Fn{a[i], +b[i]};
        funs[i << 1 | 1] = Fn{a[i], -b[i]};
    }
    segtree<Segnode> seg(2 * N, funs);

    while (Q--) {
        if (int t; cin >> t, t == 1) {
            int u, x;
            cin >> u >> x, u--;
            int l = 2 * tin[u], r = 2 * tout[u];
            seg.update_beats(l, r, x);
        } else if (t == 2) {
            int u;
            cin >> u, u--;
            int l = 2 * tin[u], r = 2 * tout[u];
            cout << seg.query_range(l, r).fn() << '\n';
        } else {
            assert(false);
        }
    }

    return 0;
}