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

template <typename T>
struct setmin_segnode {
    static constexpr bool RANGES = false;
    static constexpr T MIN = numeric_limits<T>::lowest();
    static constexpr T MAX = numeric_limits<T>::max();

    T sum = 0;
    T maximum = MIN;
    T second_max = MIN;
    T count_max = 0;
    T lazy = MAX;

    setmin_segnode() = default;
    setmin_segnode(T v) : sum(v), maximum(v), count_max(1) {}

    bool can_break(T setmin) const { return maximum <= setmin; }
    bool can_update(T setmin) const { return second_max < setmin; }

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
            lhs.apply(lazy);
            rhs.apply(lazy);
            lazy = MAX;
        }
    }
    void apply(T setmin) {
        if (setmin < maximum) {
            assert(second_max < setmin);
            sum -= count_max * (maximum - setmin);
            maximum = setmin;
            lazy = setmin;
        }
    }
};

template <typename T, typename BinaryOperation>
struct sparse_table {
    vector<vector<T>> table;
    BinaryOperation binop;

    template <typename It>
    sparse_table(It first, It last, const BinaryOperation& op) : binop(op) {
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

    sparse_table(const vector<T>& v, const BinaryOperation& op)
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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q, K;
    cin >> N >> Q >> K;
    constexpr int MAX = 1e9;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<vector<int>> by_left(N);
    vector<array<int, 3>> queries(Q);
    vector<int64_t> ans(Q);

    for (int q = 0; q < Q; q++) {
        int l, r;
        cin >> l >> r, l--;
        queries[q] = {l, r, q};
        ans[q] = a[l];
        if (l + K < r) {
            by_left[l].push_back(q);
        }
    }

    sparse_table rmq(a, [&](int x, int y) { return min(x, y); });

    for (int s = 0; s < K; s++) {
        vector<int> ls;
        for (int l = s; l + K <= N; l += K) {
            ls.push_back(l);
        }
        reverse(begin(ls), end(ls));
        int S = ls.size();
        if (S == 0) {
            continue;
        }

        segtree_beats<setmin_segnode<int64_t>> beats(0, S, MAX);

        for (int i = 0; i < S; i++) {
            int l = ls[i];
            int v = rmq.query(l, min(l + K + 1, N));
            beats.update_range(0, i + 1, v);
            for (int q : by_left[l]) {
                int r = queries[q][1];
                int tickets = (r - l - 1) / K;
                ans[q] += beats.query_range(i - tickets + 1, i + 1).sum;
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}

// [L,R)
// You will buy ceil(R-L / k) tickets
// cost is a[L] + min(a[L],...,a[L+k]) + min(a[L],...,a[L+2k]) + ...
// the last range does not need to be cut.
// handle first ticket separately
// now we want to answer queries
// (1) SUM(i=1...x) min(a[L],...,a[L+xk])
// in log time, how do
// it's annoying if it is dominantly decreasing
// ML suggests sparse table, how do. nevermind
// Suppose we scan in order of L decreasing, we can answer (1) for every x>=1 at L
// How to advance to L+k?
//