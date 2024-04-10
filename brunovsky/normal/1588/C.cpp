#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename Node>
struct lazy_segtree {
    vector<Node> node;
    vector<array<int, 2>> range;

    lazy_segtree() = default;
    lazy_segtree(int L, int R, Node init) { assign(L, R, init); }

    template <typename T>
    lazy_segtree(int L, int R, const vector<T>& arr, int s = 0) {
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
        update_range(1, L, R, update);
    }

    auto query_all() const { return node[1]; }

    template <typename Update>
    void update_all(Update&& update) {
        apply(1, update);
    }

    // Find first i>=k such that fn([L,i]) holds, or R otherwise
    // Fn is F F F F T T T T ...
    template <typename Fn>
    int prefix_binary_search(int k, Fn&& fn) {
        auto [L, R] = range[1];
        Node ans;
        int i = 1, N = R - L;
        while (i < N) {
            pushdown(i);
            Node v = combine(ans, node[i << 1]);
            if (range[i << 1][1] <= k || !fn(v)) {
                ans = move(v);
                i = i << 1 | 1;
            } else {
                i = i << 1;
            }
        }
        Node v = combine(ans, node[i]);
        return range[i][0] + !fn(v);
    }

    // Find last i<=k such that fn([i,R)) holds, or L-1 otherwise
    // Fn is T T T T F F F F ...
    template <typename Fn>
    int suffix_binary_search(int k, Fn&& fn) {
        auto [L, R] = range[1];
        Node ans;
        int i = 1, N = R - L;
        while (i < N) {
            pushdown(i);
            Node v = combine(node[i << 1 | 1], ans);
            if (k < range[i << 1][1] || !fn(v)) {
                ans = move(v);
                i = i << 1;
            } else {
                i = i << 1 | 1;
            }
        }
        Node v = combine(ans, node[i]);
        return range[i][0] - !fn(v);
    }

    template <typename Fn>
    int prefix_binary_search(Fn&& fn) {
        return prefix_binary_search(range[1][0], forward<Fn>(fn));
    }

    template <typename Fn>
    int suffix_binary_search(Fn&& fn) {
        return suffix_binary_search(range[1][1] - 1, forward<Fn>(fn));
    }

  private:
    static Node combine(const Node& x, const Node& y) {
        Node ans;
        ans.pushup(x, y);
        return ans;
    }
    template <typename Update>
    void apply(int u, Update&& update) {
        if constexpr (Node::RANGES) {
            node[u].apply(update, range[u][1] - range[u][0]);
        } else {
            node[u].apply(update);
        }
    }
    void pushup(int u) {
        node[u].pushup(node[u << 1], node[u << 1 | 1]); //
    }
    void pushdown(int u) {
        if constexpr (Node::RANGES) {
            int l = range[u << 1][1] - range[u << 1][0];
            int r = range[u << 1 | 1][1] - range[u << 1 | 1][0];
            node[u].pushdown(node[u << 1], node[u << 1 | 1], l, r);
        } else {
            node[u].pushdown(node[u << 1], node[u << 1 | 1]);
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
            return combine(query_range(u << 1, L, m), query_range(u << 1 | 1, m, R));
        }
    }

    template <typename Update>
    void update_range(int u, int L, int R, Update&& update) {
        if (L <= range[u][0] && range[u][1] <= R) {
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
            update_range(u << 1, L, m, update);
            update_range(u << 1 | 1, m, R, update);
        }
        pushup(u);
    }
};

template <typename T>
struct min_segnode {
    static constexpr bool LAZY = true, RANGES = false, REVERSE = false;
    static constexpr T MAX = numeric_limits<T>::max() / 2;

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
        value += add;
        lazy += add;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<int64_t> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        if (N == 1) {
            cout << (a[0] == 0 ? 1 : 0) << '\n';
            continue;
        }

        // First starting on odd positions
        int D = N - 1;
        vector<int64_t> diffs(D);
        map<int64_t, vector<int>> by_diff[2];

        const int64_t inf = 1e17;
        vector<int64_t> parity[2];
        int64_t sum[2] = {0, a[0]};
        parity[0].assign(D, inf);
        parity[1].assign(D, inf);

        auto count_diffs = [&](int i, int64_t v, int L, int R) -> int {
            if (by_diff[i].count(v) && L < R) {
                const auto& idx = by_diff[i].at(v);
                auto lit = lower_bound(begin(idx), end(idx), L);
                auto rit = lower_bound(begin(idx), end(idx), R);
                return rit - lit;
            } else {
                return 0;
            }
        };

        for (int i = 0; i < D; i++) {
            int x = i % 2, y = 1 - x;
            sum[x] += a[i + 1];
            parity[x][i] = diffs[i] = sum[x] - sum[y];
            by_diff[x][diffs[i]].push_back(i);
        }

        lazy_segtree<min_segnode<int64_t>> even_st(0, D, parity[0]);
        lazy_segtree<min_segnode<int64_t>> odd_st(0, D, parity[1]);
        int64_t even_delta = 0, odd_delta = 0, ans = 0;

        // value at odd positions is val + odd_delta
        // value at even positions is val + even_delta

        for (int i = 0; i < D; i++) {
            // All diffs should be >=0, bs
            int re = even_st.prefix_binary_search(i, [&](auto node) {
                return node.value + even_delta < 0;
            });
            int ro = odd_st.prefix_binary_search(i, [&](auto node) {
                return node.value + odd_delta < 0;
            });

            int R = min(re, ro);

            // Odd diff should be equal to -odd_delta
            // Even diff should be equal to +odd_delta

            ans += count_diffs(0, -even_delta, i, R);
            ans += count_diffs(1, -odd_delta, i, R);

            if (i % 2 == 0) {
                even_delta += a[i];
                odd_delta -= a[i];
                even_st.update_point(i, inf);
            } else {
                even_delta -= a[i];
                odd_delta += a[i];
                odd_st.update_point(i, inf);
            }
        }

        ans += count(begin(a), end(a), 0);
        cout << ans << '\n';
    }
    return 0;
}

// You might as well play L to R or R to L
// So we must have a[1] <= a[2]
// Then a[2]-a[1]<=a[3] <=> a[2]<=a[1]+a[3]
// Then a[3]-(a[2]-a[1])<=a[4] <=> a[1]+a[3]<=a[2]+a[4]
// Then a[4]-(a[3]-a[2]+a[1])<=a[5] <=> a[2]+a[4]<=a[1]+a[3]+a[5]
// So a[1],a[2],a[1]+a[3],a[2]+a[4],a[1]+a[3]+a[5],... must be sorted
// Number of stones on even and odd piles must also match
// The a[i] can be zero, but then the games just become independent?
// There's no queries, only the entire sequence
// a[1]
// a[2]
// a[1]+a[3]
// a[2]+a[4]
// a[1]+a[3]+a[5]
// a[2]+a[4]+a[6]
// a[1]+a[3]+a[5]+a[7]
// a[2]+a[4]+a[6]+a[8]
// a[1]+a[3]+a[5]+a[7]+a[9]
// a[2]+a[4]+a[6]+a[8]+a[10]
// Now suppose we don't play a[1],a[2]
// (1) a[3]
// (2) a[4]
// (3) a[3]+a[5]
// (4) a[4]+a[6]
// (5) a[3]+a[5]+a[7]
// (6) a[4]+a[6]+a[8]
// (7) a[3]+a[5]+a[7]+a[9]
// (8) a[4]+a[6]+a[8]+a[10]
// So suppose we keep track of all consecutive differences
// To count an answer beginning here, need to count valid ending indices
// All differences between should be >=0 -> binary search first minimum>0
// Last element should be 0 -> need to count zeros
// To advance:
// Subtract a[i] from odd (or even) positions after a[i]
// Maybe just a deque and offset value?
// Then you want to count values in a range