#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

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
    void assign_iota(int L, int R) {
        int N = R - L;
        node.assign(2 * N, Node());
        update.assign(2 * N, Update());
        has_lazy.assign(2 * N, false);
        range.resize(2 * N);
        int Q = 1 << (N > 1 ? 8 * sizeof(N) - __builtin_clz(N - 1) : 0);
        for (int i = 0; i < N; i++) {
            range[i + N] = {L + i, L + i + 1};
            node[i + N] = Node(L + i);
        }
        rotate(begin(node) + N, begin(node) + (3 * N - Q), end(node));
        rotate(begin(range) + N, begin(range) + (3 * N - Q), end(range));
        for (int u = N - 1; u >= 1; u--) {
            int cl = u << 1, cr = u << 1 | 1;
            range[u] = {range[cl][0], range[cr][1]};
            node[u].merge(node[cl], node[cr]);
        }
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
        int cl = u << 1, cr = u << 1 | 1;
        pushdown(u);
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

struct min_segnode {
    long value = LLONG_MAX / 2;
    explicit min_segnode(long value = LLONG_MAX / 2) : value(value) {}
    void merge(const min_segnode& lhs, const min_segnode& rhs) {
        value = min(lhs.value, rhs.value);
    }
};

struct add_segupdate {
    long value = 0;
    add_segupdate(long value = 0) : value(value) {}
    void merge(const add_segupdate& parent, array<int, 2>) { value += parent.value; }
    void apply(min_segnode& node, array<int, 2>) const { node.value += value; }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<long> a(N + 1);
    vector<int> b(M + 1), p(M + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= M; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= M; i++) {
        cin >> p[i];
    }
    map<int, int> ais;
    for (int i = 1; i <= N; i++) {
        ais[a[i]] = i;
    }
    for (auto it = rbegin(ais), jit = next(it); jit != rend(ais); ++it, ++jit) {
        jit->second = max(jit->second, it->second);
    }
    vector<int> month(M + 1, -1);
    for (int i = 1; i <= M; i++) {
        auto it = ais.lower_bound(b[i]);
        if (it != end(ais)) {
            month[i] = it->second;
        }
    }
    vector<int> pin(M);
    iota(begin(pin), end(pin), 1);
    sort(begin(pin), end(pin), [&](int u, int v) { return p[u] < p[v]; });
    for (int i = 2; i <= N; i++) {
        a[i] += a[i - 1];
    }
    segtree<min_segnode, add_segupdate> st(1, N + 1, a);
    int ans = 0;
    for (int u : pin) {
        if (month[u] != -1) {
            if (st.query_range(month[u], N + 1).value >= p[u]) {
                st.update_range(month[u], N + 1, -p[u]);
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}