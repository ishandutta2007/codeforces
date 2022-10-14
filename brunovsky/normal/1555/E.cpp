#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename Node, typename Update>
struct segtree {
    struct TreeNode {
        Node node;
        Update update;
        bool has_lazy = false;
        array<int, 2> range = {};
    };
    vector<TreeNode> st;

    segtree() = default;
    segtree(int L, int R, Node init = Node()) { assign(L, R, init); }

    template <typename T>
    segtree(int L, int R, const vector<T>& arr) {
        assign(L, R, arr);
    }

    void assign(int L, int R, Node init) {
        int N = R - L;
        st.assign(2 * N, {init, Update()});
        int Q = 1 << (N > 1 ? 8 * sizeof(N) - __builtin_clz(N - 1) : 0);
        for (int i = 0; i < N; i++) {
            st[i + N].range = {L + i, L + i + 1};
        }
        rotate(begin(st) + N, begin(st) + (3 * N - Q), end(st));
        for (int u = N - 1; u >= 1; u--) {
            st[u].range = {st[u << 1].range[0], st[u << 1 | 1].range[1]};
            st[u].node.merge(st[u << 1].node, st[u << 1 | 1].node);
        }
    }

    template <typename T>
    void assign(int L, int R, const vector<T>& arr) {
        int N = R - L;
        st.assign(2 * N, {Node(), Update()});
        int Q = 1 << (N > 1 ? 8 * sizeof(N) - __builtin_clz(N - 1) : 0);
        for (int i = 0; i < N; i++) {
            st[i + N].range = {L + i, L + i + 1};
            st[i + N].node = Node(arr[L + i]);
        }
        rotate(begin(st) + N, begin(st) + (3 * N - Q), end(st));
        for (int u = N - 1; u >= 1; u--) {
            st[u].range = {st[u << 1].range[0], st[u << 1 | 1].range[1]};
            st[u].node.merge(st[u << 1].node, st[u << 1 | 1].node);
        }
    }

    auto query_point(int i) {
        assert(st[1].range[0] <= i && i < st[1].range[1]);
        int u = 1;
        while (st[u].range[0] + 1 < st[u].range[1]) {
            pushdown(u);
            int M = st[u << 1].range[1];
            u = u << 1 | int(i >= M);
        }
        return st[u].node;
    }
    void update_point(int i, const Update& add) {
        assert(st[1].range[0] <= i && i < st[1].range[1]);
        int u = 1;
        while (st[u].range[0] + 1 < st[u].range[1]) {
            pushdown(u);
            int M = st[u << 1].range[1];
            u = u << 1 | int(i >= M);
        }
        add.apply(st[u].node, st[u].range);
        while ((u >>= 1) > 1) {
            st[u].node.merge(st[u << 1].node, st[u << 1 | 1].node);
        }
    }

    auto query_range(int L, int R) {
        assert(st[1].range[0] <= L && R <= st[1].range[1]);
        return query_range(1, L, R);
    }
    void update_range(int L, int R, const Update& add) {
        assert(st[1].range[0] <= L && R <= st[1].range[1]);
        update_range(1, L, R, add);
    }

  private:
    void pushdown(int u) {
        if (st[u].has_lazy) {
            int a = u << 1, b = u << 1 | 1;
            st[a].has_lazy = st[b].has_lazy = 1;
            st[u].update.apply(st[a].node, st[a].range);
            st[u].update.apply(st[b].node, st[b].range);
            st[a].update.merge(st[u].update, st[a].range);
            st[b].update.merge(st[u].update, st[b].range);
            st[u].has_lazy = 0;
            st[u].update = Update();
        }
    }

    void update_range(int u, int L, int R, const Update& add) {
        if (R <= st[u].range[0] || st[u].range[1] <= L) {
            return;
        }
        if (L <= st[u].range[0] && st[u].range[1] <= R) {
            add.apply(st[u].node, st[u].range);
            st[u].update.merge(add, st[u].range);
            st[u].has_lazy = 1;
            return;
        }
        int a = u << 1, b = u << 1 | 1;
        pushdown(u);
        update_range(a, L, R, add);
        update_range(b, L, R, add);
        st[u].node.merge(st[a].node, st[b].node);
    }

    auto query_range(int u, int L, int R) {
        if (R <= st[u].range[0] || st[u].range[1] <= L) {
            return Node();
        }
        if (L <= st[u].range[0] && st[u].range[1] <= R) {
            return st[u].node;
        }
        pushdown(u);
        int a = u << 1, b = u << 1 | 1;
        Node ans;
        ans.merge(query_range(a, L, R), query_range(b, L, R));
        return ans;
    }
};

template <typename T = long>
struct min_segnode {
    T value = numeric_limits<T>::max();
    min_segnode(T v = numeric_limits<T>::max()) : value(v) {}
    operator T const &() const { return value; }
    void merge(const min_segnode& lhs, const min_segnode& rhs) {
        value = min(lhs.value, rhs.value);
    }
}; // add_segupdate, set_segupdate, affine_add_segupdate

template <typename T = long> // f(n,v) = n+v
struct add_segupdate {
    T value = 0;
    add_segupdate(T value = 0) : value(value) {}
    void merge(const add_segupdate& parent, array<int, 2> /*range*/) {
        value += parent.value;
    }
    void apply(min_segnode<T>& node, array<int, 2>) const { node.value += value; }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    // BS twice

    int N, M;
    cin >> N >> M;

    vector<tuple<int, int, int>> intvs(N);
    for (auto& [w, l, r] : intvs) {
        cin >> l >> r >> w;
    }
    sort(begin(intvs), end(intvs));

    segtree<min_segnode<int>, add_segupdate<int>> st(1, M, 0);

    for (auto [w, l, r] : intvs) {
        if (l == 1 && r == M + 1) {
            cout << 0 << '\n';
            return 0;
        }
    }

    int L = 0, R = 0;
    int ans = INT_MAX;
    auto diff = [&]() { return get<0>(intvs[R - 1]) - get<0>(intvs[L]); };

    auto push_left = [&]() {
        while (L < R && st.query_range(1, M) > 0) {
            debug(L, R, N);
            ans = min(ans, diff());
            auto [w, l, r] = intvs[L++];
            st.update_range(l, r, -1);
        }
    };
    auto push_right = [&]() {
        while (R < N && st.query_range(1, M) == 0) {
            auto [w, l, r] = intvs[R++];
            st.update_range(l, r, 1);
        }
    };

    while (R < N) {
        push_right();
        push_left();
    }

    cout << ans << '\n';
    return 0;
}