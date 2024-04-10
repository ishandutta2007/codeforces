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

struct max_segnode {
    static constexpr bool LAZY = true, RANGES = false, REVERSE = false;
    static constexpr int MIN = 0;

    int value = MIN;
    int lazy = 0;

    max_segnode() = default;
    max_segnode(int v) : value(v) {}
    operator int const &() const { return value; }

    void pushup(const max_segnode& lhs, const max_segnode& rhs) {
        value = max(lhs.value, rhs.value);
    }
    void pushdown(max_segnode& lhs, max_segnode& rhs) {
        if (lazy != 0) {
            lhs.apply(lazy);
            rhs.apply(lazy);
            lazy = 0;
        }
    }
    void apply(int add) {
        value += add;
        lazy += add;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N, D;
    cin >> N >> D;

    // SKILL,NEAT
    vector<array<int, 2>> alps(N);
    vector<int> c = {D};
    for (int i = 0; i < N; i++) {
        cin >> alps[i][0] >> alps[i][1];
        c.push_back(alps[i][0]);
        c.push_back(alps[i][1]);
    }

    sort(begin(c), end(c));
    c.erase(unique(begin(c), end(c)), end(c));

    for (int i = 0; i < N; i++) {
        alps[i][0] = lower_bound(begin(c), end(c), alps[i][0]) - begin(c);
        alps[i][1] = lower_bound(begin(c), end(c), alps[i][1]) - begin(c);
    }
    D = lower_bound(begin(c), end(c), D) - begin(c);
    int S = c.size();

    int count = 0;
    vector<int> index;

    for (int i = 0; i < N; i++) {
        if (alps[i][0] >= D) {
            if (alps[i][1] > D) {
                index.push_back(i);
            } else {
                count++; // just send right away
            }
        }
    }
    sort(begin(index), end(index), [&](int a, int b) {
        auto [as, af] = alps[a];
        auto [bs, bf] = alps[b];
        if (min(as, af) != min(bs, bf)) {
            return min(as, af) < min(bs, bf);
        } else if (af != bf) {
            return af < bf;
        } else {
            return as < bs;
        }
    });

    lazy_segtree<max_segnode> st(0, S, count);

    for (int i : index) {
        auto [skill, after] = alps[i];
        int x = st.query_range(0, min(after, skill) + 1);
        int y = st.query_point(after);
        st.update_point(after, max(x + 1 - y, 0));
        if (after < skill) {
            st.update_range(after + 1, skill + 1, +1);
        }
    }

    cout << st.query_all() << '\n';
    return 0;
}