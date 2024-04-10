#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename Node>
struct segtree_beats {
    vector<Node> node;
    vector<array<int, 2>> range;

    segtree_beats() = default;
    segtree_beats(int L, int R, Node init) { assign(L, R, init); }

    template <typename T>
    segtree_beats(int L, int R, const vector<T>& arr, int s = 0) {
        assign(L, R, arr, s);
    }

    void assign(int L, int R, Node init) {
        int N = R - L;
        node.assign(2 * N, init);
        range.resize(2 * N);
        int Q = 1 << (N > 1 ? 8 * sizeof(N) - __builtin_clz(N - 1) : 0);
        for (int i = 0; i < N; i++) {
            range[i + N] = {L + i, L + i + 1};
        }
        rotate(begin(range) + N, begin(range) + (3 * N - Q), end(range));
        for (int u = N - 1; u >= 1; u--) {
            range[u] = {range[u << 1][0], range[u << 1 | 1][1]};
            pushup(u);
        }
    }

    template <typename T>
    void assign(int L, int R, const vector<T>& arr, int s = 0) {
        int N = R - L;
        node.resize(2 * N);
        range.resize(2 * N);
        int Q = 1 << (N > 1 ? 8 * sizeof(N) - __builtin_clz(N - 1) : 0);
        for (int i = 0; i < N; i++) {
            range[i + N] = {L + i, L + i + 1};
            node[i + N] = Node(arr[L + i - s]);
        }
        rotate(begin(range) + N, begin(range) + (3 * N - Q), end(range));
        rotate(begin(node) + N, begin(node) + (3 * N - Q), end(node));
        for (int u = N - 1; u >= 1; u--) {
            range[u] = {range[u << 1][0], range[u << 1 | 1][1]};
            pushup(u);
        }
    }

    auto query_point(int i) {
        assert(range[1][0] <= i && i < range[1][1]);
        int u = 1;
        while (range[u][0] + 1 < range[u][1]) {
            pushdown(u);
            int M = range[u << 1][1];
            u = u << 1 | int(i >= M);
        }
        return node[u];
    }

    template <typename Update>
    void update_point(int i, Update&& update) {
        assert(range[1][0] <= i && i < range[1][1]);
        int u = 1;
        while (range[u][0] + 1 < range[u][1]) {
            pushdown(u);
            int M = range[u << 1][1];
            u = u << 1 | int(i >= M);
        }
        apply(u, update);
        while ((u >>= 1) >= 1) {
            pushup(u);
        }
    }

    auto query_range(int L, int R) {
        assert(range[1][0] <= L && R <= range[1][1]);
        return query_range(1, L, R);
    }

    template <typename Update>
    void update_range(int L, int R, Update&& update) {
        assert(range[1][0] <= L && R <= range[1][1]);
        return update_range(1, L, R, update);
    }

    auto query_all() const { return node[1]; }

    template <typename Update>
    void update_all(Update&& update) {
        return update_range(1, range[1][0], range[1][1], update);
    }

  private:
    void pushup(int u) {
        node[u].pushup(node[u << 1], node[u << 1 | 1]); //
    }
    void pushdown(int u) {
        if constexpr (Node::RANGES) {
            int l = range[u][0], m = range[u << 1][1], r = range[u][1];
            node[u].pushdown(node[u << 1], node[u << 1 | 1], m - l, r - m);
        } else {
            node[u].pushdown(node[u << 1], node[u << 1 | 1]);
        }
    }
    template <typename Update>
    void apply(int u, Update&& update) {
        if constexpr (Node::RANGES) {
            node[u].apply(update, range[u][1] - range[u][0]);
        } else {
            node[u].apply(update);
        }
    }
    template <typename Update>
    bool can_break(int u, Update&& update) const {
        if constexpr (Node::RANGES) {
            return node[u].can_break(update, range[u][1] - range[u][0]);
        } else {
            return node[u].can_break(update);
        }
    }
    template <typename Update>
    bool can_update(int u, Update&& update) const {
        if (range[u][1] - range[u][0] == 1) {
            return true;
        }
        if constexpr (Node::RANGES) {
            return node[u].can_update(update, range[u][1] - range[u][0]);
        } else {
            return node[u].can_update(update);
        }
    }

    auto query_range(int u, int L, int R) {
        if (L <= range[u][0] && range[u][1] <= R) {
            return node[u];
        }
        pushdown(u);
        int m = range[u << 1][1];
        if (R <= m) {
            return query_range(u << 1, L, R);
        } else if (m <= L) {
            return query_range(u << 1 | 1, L, R);
        } else {
            Node ans;
            ans.pushup(query_range(u << 1, L, m), query_range(u << 1 | 1, m, R));
            return ans;
        }
    }

    template <typename Update>
    void update_range(int u, int L, int R, Update&& update) {
        if (can_break(u, update)) {
            return;
        }
        if (L <= range[u][0] && range[u][1] <= R && can_update(u, update)) {
            apply(u, update);
            return;
        }
        pushdown(u);
        int m = range[u << 1][1];
        if (R <= m) {
            update_range(u << 1, L, R, update);
        } else if (m <= L) {
            update_range(u << 1 | 1, L, R, update);
        } else {
            update_range(u << 1, L, R, update);
            update_range(u << 1 | 1, L, R, update);
        }
        pushup(u);
    }
};

template <typename Node>
struct iterative_segtree {
    int N, size, start;
    vector<Node> node;

    iterative_segtree() = default;
    iterative_segtree(int L, int R, Node init) { assign(L, R, init); }

    template <typename T>
    iterative_segtree(int L, int R, const vector<T>& arr, int s = 0) {
        assign(L, R, arr, s);
    }

    void assign(int L, int R, Node init) {
        int N = R - L;
        size = 1 << (N > 1 ? 8 * sizeof(N) - __builtin_clz(N - 1) : 0);
        start = L;
        node.assign(2 * size, Node());
        for (int i = 0; i < N; i++) {
            node[i + size] = init;
        }
        for (int i = size - 1; i > 0; i--) {
            pushup(i);
        }
    }

    template <typename T>
    void assign(int L, int R, const vector<T>& arr, int s = 0) {
        int N = R - L;
        size = 1 << (N > 1 ? 8 * sizeof(N) - __builtin_clz(N - 1) : 0);
        start = L;
        node.assign(2 * size, Node());
        for (int i = 0; i < N; i++) {
            node[i + size] = Node(arr[i - s]);
        }
        for (int i = size - 1; i > 0; i--) {
            pushup(i);
        }
    }

    auto query_point(int p) const { return node[p + size - start]; }

    template <typename Update>
    void update_point(int i, Update&& update) {
        i += size - start;
        apply(i, update);
        for (i >>= 1; i > 0; i >>= 1) {
            pushup(i);
        }
    }

    auto query_range(int L, int R) const {
        Node ans;
        L -= start, R -= start;
        for (int t = R - L; t >= 1; t = R - L) {
            int x = L | ((1U << 31) >> __builtin_clz(t));
            int u = x & (-x);
            int k = __builtin_ctz(x);
            ans = combine(ans, node[(size | L) >> k]);
            L += u;
        }
        return ans;
    }

    auto query_all() const { return node[1]; }

  private:
    static Node combine(const Node& x, const Node& y) {
        Node ans;
        ans.pushup(x, y);
        return ans;
    }
    template <typename Update>
    void apply(int u, Update&& update) {
        if constexpr (Node::RANGES) {
            node[u].apply(update, 1);
        } else {
            node[u].apply(update);
        }
    }
    void pushup(int u) { node[u].pushup(node[u << 1], node[u << 1 | 1]); }
};

template <typename T>
struct sum_segnode {
    static constexpr bool LAZY = false, RANGES = false, REVERSE = false;
    T value = 0;

    sum_segnode() = default;
    sum_segnode(T v) : value(v) {}
    operator T const &() const { return value; }

    void pushup(const sum_segnode& lhs, const sum_segnode& rhs) {
        value = lhs.value + rhs.value;
    }
    void apply(T add) { value += add; }
};

iterative_segtree<sum_segnode<int64_t>> sum_seg;
iterative_segtree<sum_segnode<int>> count_seg;

template <typename T>
struct setmin_segnode {
    static constexpr bool RANGES = false;
    static constexpr T MIN = numeric_limits<T>::lowest();
    static constexpr T MAX = numeric_limits<T>::max();
    enum Operation { SETMIN = 0, SET = 1 };
    using Update = pair<Operation, T>;

    T sum = 0;
    T maximum = MIN;
    T second_max = MIN;
    T count_max = 0;
    T lazy = MAX;

    setmin_segnode() = default;
    setmin_segnode(T v) : sum(v), maximum(v), count_max(1) {}

    bool can_break(Update upd) const { return maximum <= upd.second; }
    bool can_update(Update upd) const { return second_max < upd.second; }

    void pushup(const setmin_segnode& lhs, const setmin_segnode& rhs) {
        sum = lhs.sum + rhs.sum;
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
    void pushdown(setmin_segnode& lhs, setmin_segnode& rhs) {
        if (lazy != MAX) {
            lhs.apply(make_pair(SETMIN, lazy), false);
            rhs.apply(make_pair(SETMIN, lazy), false);
            lazy = MAX;
        }
    }
    void apply(Update upd, bool updateseg = true) {
        auto [op, v] = upd;
        assert(op == SETMIN || (count_max == 1 && second_max == MIN));
        if ((op == SETMIN && v < maximum) || (op == SET)) {
            assert(second_max < v);
            if (updateseg) {
                sum_seg.update_point(maximum, -count_max * maximum);
                sum_seg.update_point(v, +count_max * v);
                count_seg.update_point(maximum, -count_max);
                count_seg.update_point(v, +count_max);
            }
            sum -= count_max * (maximum - v);
            maximum = v;
            lazy = v;
        }
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int64_t> aiota(N);
    iota(begin(aiota), end(aiota), 0);

    sum_seg.assign(0, N, aiota);
    count_seg.assign(0, N, 1);

    segtree_beats<setmin_segnode<int64_t>> beats(0, N, aiota);
    using Op = setmin_segnode<int64_t>::Operation;

    auto query = [&](int64_t R) -> int64_t {
        if (R <= 0) {
            return 0;
        }
        auto A = R - R * (R - 1) / 2 - (N - R) * (R - 1);
        auto B = (R - 1) * count_seg.query_range(R, N);
        auto C = sum_seg.query_range(0, R);
        return A + B + C;
    };

    for (int q = 0; q < Q; q++) {
        int p;
        cin >> p;
        if (p == 1) {
            int c, g;
            cin >> c >> g, c--, g--;
            beats.update_range(0, c + 1, make_pair(Op::SETMIN, c - 1));
            beats.update_point(c, make_pair(Op::SET, g));
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(r) - query(l - 1) << '\n';
        }
    }
    return 0;
}

// Each city i broadcasts up to w[i] inclusive.
// This range is 'cut' by later updates => segbeats setmin on prefix
// Then we want to answer queries like
// Station c can broadcast to station j if w[c]>=j at that time
// Answer to prefix query for R (strictly before R) is
// (Q) SUM(c<R) min(w[c],R)-c = SUM(c<R) min(w[c],R) - (R-1)R/2 = (A) - (R choose 2)
// (A) SUM(c<R) min(w[c],R) = SUM(c<R) (w[c] - max(0,w[c]-R)) = (B) - (C)
// (B) SUM(c<R) w[c]
// (C) SUM(c<R) max(0,w[c]-R)
// If we update segbeats with setmin(R) we'd answer this fast but that's amortized
// (C) = SUM(c) max(0,w[c]-R) - SUM(c>=R) (w[c]-R)
// (C) = SUM(c) max(0,w[c]-R) - SUM(c>=R) w[c] + (N-R)R
// (D) SUM(c) max(0,w[c]-R)
// This is more manageable, we can maintain this in a segtree alongside segbeats updates
// Final:
// (Q) = (E) + (D) - (R+1)R/2 - (N-R)R
// (E) = SUM(c) w[c]           (segbeats query)
// (D) = SUM(c) max(0,w[c]-R)  (suffix segtree query)
// Maintain:
//    Segbeats over startpoints with w[i], support range sum and setmin
//    Update a segtree while doing updates on the segbeats