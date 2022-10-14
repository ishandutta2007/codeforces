#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

constexpr int inf = INT_MAX / 3;

inline namespace lib {

struct min_segnode {
    int value = inf;
    explicit min_segnode(int v = inf) : value(v) {}
    void merge(const min_segnode& lhs, const min_segnode& rhs) {
        value = min(lhs.value, rhs.value);
    }
};

struct add_segupdate {
    int value = 0;
    add_segupdate(int value = 0) : value(value) {}
    void merge(const add_segupdate& parent, array<int, 2> /*range*/) {
        value += parent.value;
    }
    void apply(min_segnode& node, array<int, 2> /*range*/) const { node.value += value; }
};

template <typename Node, typename Update>
struct segtree {
    vector<Node> node;
    vector<Update> update;
    vector<bool> lazy;
    vector<array<int, 2>> range;

    segtree() = default;

    template <typename Arr>
    explicit segtree(int L, int R, const Arr& arr) {
        assign(L, R, arr);
    }

    template <typename Arr>
    void assign(int L, int R, const Arr& arr) {
        int N = R - L;
        node.assign(4 * N, Node());
        update.assign(4 * N, Update());
        lazy.assign(4 * N, false);
        range.resize(4 * N);
        build(1, L, R, arr);
    }

    template <typename Arr>
    void build(int u, int L, int R, const Arr& arr) {
        range[u] = {L, R};
        if (L + 1 == R) {
            node[u] = Node(arr[L]);
        } else {
            int M = (L + R + 1) / 2;
            build(u << 1, L, M, arr);
            build(u << 1 | 1, M, R, arr);
            node[u].merge(node[u << 1], node[u << 1 | 1]);
        }
    }

    void pushdown(int u) {
        if (lazy[u]) {
            auto [L, R] = range[u];
            if (L + 1 < R) {
                lazy[u << 1] = lazy[u << 1 | 1] = 1;
                update[u << 1].merge(update[u], range[u << 1]);
                update[u << 1 | 1].merge(update[u], range[u << 1 | 1]);
            }
            update[u].apply(node[u], range[u]);
            lazy[u] = 0;
            update[u] = Update();
        }
    }

    void update_range(int u, int L, int R, const Update& add) {
        pushdown(u);
        if (R <= range[u][0] || range[u][1] <= L) /* no overlap */ {
            return;
        }
        if (L <= range[u][0] && range[u][1] <= R) /* full overlap */ {
            update[u].merge(add, range[u]);
            lazy[u] = true;
            pushdown(u);
            return;
        }
        update_range(u << 1, L, R, add);
        update_range(u << 1 | 1, L, R, add);
        node[u].merge(node[u << 1], node[u << 1 | 1]);
    }

    Node query_range(int u, int L, int R) {
        pushdown(u);
        if (R <= range[u][0] || range[u][1] <= L) /* no overlap */ {
            return Node();
        }
        if (L <= range[u][0] && range[u][1] <= R) /* full overlap */ {
            return node[u];
        }
        auto a = query_range(u << 1, L, R);
        auto b = query_range(u << 1 | 1, L, R);
        Node ans;
        ans.merge(a, b);
        return ans;
    }

    Node query_range(int L, int R) { return query_range(1, L, R); }
    Node query_index(int i) { return query_range(1, i, i + 1); }
    void update_range(int L, int R, const Update& add) { update_range(1, L, R, add); }
};

} // namespace lib

// Based on editorial

auto solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    vector<vector<int>> dp(K + 1, vector<int>(N + 1, inf));
    dp[0][0] = 0;
    segtree<min_segnode, add_segupdate> seg;

    for (int k = 1; k <= K; k++) {
        vector<int> last(N + 1, 0);
        dp[k][0] = 0;
        seg.assign(0, N + 1, dp[k - 1]);

        for (int i = 1; i <= N; i++) {
            if (last[A[i]] != 0) {
                seg.update_range(0, last[A[i]], i - last[A[i]]);
            }
            last[A[i]] = i;
            dp[k][i] = seg.query_range(0, i).value;
        }
        fprintf(stderr, "dp[%d][%d] = %d\n", k, N, dp[k][N]);
    }

    return dp[K][N];
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}