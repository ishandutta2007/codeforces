#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename Node, typename Update>
struct segtree {
    vector<Node> node;
    vector<Update> update;
    vector<bool> has_lazy;
    vector<array<int, 2>> range;

    segtree() = default;
    segtree(int L, int R) { assign(L, R); }

    template <typename Arr>
    segtree(int L, int R, const Arr& arr) {
        assign(L, R, arr);
    }

    template <typename Arr>
    void assign(int L, int R, const Arr& arr) {
        int N = R - L;
        node.assign(2 * N, Node());
        update.assign(2 * N, Update());
        has_lazy.assign(2 * N, false);
        range.resize(2 * N);
        int Q = 1 << (N > 1 ? 8 * sizeof(N) - __builtin_clz(N - 1) : 0);
        for (int i = 0; i < N; i++) {
            range[i + N] = {L + i, L + i + 1};
            node[i + N] = Node(arr[L + i]);
        }
        rotate(begin(node) + N, begin(node) + (3 * N - Q), end(node));
        rotate(begin(range) + N, begin(range) + (3 * N - Q), end(range));
        for (int u = N - 1; u >= 1; u--) {
            int cl = u << 1, cr = u << 1 | 1;
            range[u] = {range[cl][0], range[cr][1]};
            node[u].merge(node[cl], node[cr]);
        }
    }

    void assign(int L, int R) {
        int N = R - L;
        node.assign(2 * N, Node());
        update.assign(2 * N, Update());
        has_lazy.assign(2 * N, false);
        range.resize(2 * N);
        int Q = 1 << (N > 1 ? 8 * sizeof(N) - __builtin_clz(N - 1) : 0);
        for (int i = 0; i < N; i++) {
            range[i + N] = {L + i, L + i + 1};
        }
        rotate(begin(range) + N, begin(range) + (3 * N - Q), end(range));
        for (int u = N - 1; u >= 1; u--) {
            int cl = u << 1, cr = u << 1 | 1;
            range[u] = {range[cl][0], range[cr][1]};
        }
    }

    auto query_range(int L, int R) { return query_range(1, L, R); }
    void update_range(int L, int R, const Update& add) { update_range(1, L, R, add); }

  private:
    void pushdown(int u) {
        if (has_lazy[u]) {
            int cl = u << 1, cr = u << 1 | 1;
            has_lazy[cl] = has_lazy[cr] = 1;
            update[u].apply(node[cl], range[cl]);
            update[u].apply(node[cr], range[cr]);
            update[cl].merge(update[u], range[cl]);
            update[cr].merge(update[u], range[cr]);
            has_lazy[u] = 0;
            update[u] = Update();
        }
    }

    void update_range(int u, int L, int R, const Update& add) {
        if (R <= range[u][0] || range[u][1] <= L) {
            return;
        }
        if (L <= range[u][0] && range[u][1] <= R) {
            add.apply(node[u], range[u]);
            update[u].merge(add, range[u]);
            has_lazy[u] = 1;
            return;
        }
        pushdown(u);
        int cl = u << 1, cr = u << 1 | 1;
        update_range(cl, L, R, add);
        update_range(cr, L, R, add);
        node[u].merge(node[cl], node[cr]);
    }

    auto query_range(int u, int L, int R) {
        if (R <= range[u][0] || range[u][1] <= L) {
            return Node();
        }
        if (L <= range[u][0] && range[u][1] <= R) {
            return node[u];
        }
        pushdown(u);
        int cl = u << 1, cr = u << 1 | 1;
        Node ans;
        ans.merge(query_range(cl, L, R), query_range(cr, L, R));
        return ans;
    }
};

struct segnode {
    int max_diff; // maximum of 2k-size in the range
    int min_diff; // minimum of 2k-size in the range
    int fi;
    explicit segnode() : max_diff(INT_MIN), min_diff(INT_MAX), fi(0) {}
    explicit segnode(int i) : max_diff(i), min_diff(i), fi(i) {}
    void merge(const segnode& lhs, const segnode& rhs) {
        max_diff = max(lhs.max_diff, rhs.max_diff);
        min_diff = min(lhs.min_diff, rhs.min_diff);
        fi = lhs.fi + rhs.fi;
    }
};

struct segupdate {
    int value = 0;
    segupdate(int value = 0) : value(value) {}
    void merge(const segupdate& parent, array<int, 2>) { value += parent.value; }
    void apply(segnode& node, array<int, 2>) const {
        node.max_diff -= 2 * value;
        node.min_diff -= 2 * value;
        node.fi -= 2 * value;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> a(N);
    vector<vector<int>> by_val(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        by_val[a[i]].push_back(i);
    }

    vector<int> iota_arr(N + 1);
    iota(begin(iota_arr), end(iota_arr), 0);
    segtree<segnode, segupdate> st(0, N + 1, iota_arr);

    vector<int> ans(N, 0);

    for (int v = 1; v <= N; v++) {
        // first, furthest to the left
        for (int i : by_val[v]) {
            int minl = st.query_range(0, i + 1).min_diff;
            int maxr = st.query_range(i + 1, N + 1).max_diff;
            int fi0 = st.query_range(i, i + 1).fi;
            int fi1 = st.query_range(i + 1, i + 2).fi;
            int l = minl - fi0;
            int r = fi1 - maxr;
            int diff = l + r;
            if (diff <= 0) {
                int ward = (-diff + 1) / 2;
                ans[i] = max(ans[i], ward);
            }
        }

        for (int i : by_val[v]) {
            st.update_range(i + 1, N + 1, 1);
        }

        // second, furthest to the right
        for (int i : by_val[v]) {
            int maxl = st.query_range(0, i + 1).max_diff;
            int minr = st.query_range(i + 1, N + 1).min_diff;
            int fi0 = st.query_range(i, i + 1).fi;
            int fi1 = st.query_range(i + 1, i + 2).fi;
            int l = maxl - fi0;
            int r = fi1 - minr;
            int diff = l + r;
            if (diff >= 0) {
                int ward = diff / 2;
                ans[i] = max(ans[i], ward);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i + 1 == N];
    }

    return 0;
}