#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename Node>
struct segtree {
    vector<Node> node;
    vector<array<int, 2>> range;
    vector<int> where;

    segtree() = default;
    segtree(int L, int R, Node init) { assign(L, R, init); }

    template <typename T>
    segtree(int L, int R, const vector<T>& arr, int s = 0) {
        assign(L, R, arr, s);
    }

    void assign(int L, int R, Node init) {
        int N = R - L;
        node.assign(2 * N, init);
        range.resize(2 * N);
        where.resize(N);
        int Q = 1 << (N > 1 ? 8 * sizeof(N) - __builtin_clz(N - 1) : 0);
        for (int i = 0; i < N; i++) {
            range[i + N] = {L + i, L + i + 1};
        }
        rotate(begin(range) + N, begin(range) + (3 * N - Q), end(range));
        for (int i = 0; i < N; i++) {
            where[range[i + N][0] - L] = i + N;
        }
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
        where.resize(N);
        int Q = 1 << (N > 1 ? 8 * sizeof(N) - __builtin_clz(N - 1) : 0);
        for (int i = 0; i < N; i++) {
            range[i + N] = {L + i, L + i + 1};
            node[i + N] = Node(arr[L + i - s]);
        }
        rotate(begin(range) + N, begin(range) + (3 * N - Q), end(range));
        rotate(begin(node) + N, begin(node) + (3 * N - Q), end(node));
        for (int i = 0; i < N; i++) {
            where[range[i + N][0] - L] = i + N;
        }
        for (int u = N - 1; u >= 1; u--) {
            range[u] = {range[u << 1][0], range[u << 1 | 1][1]};
            pushup(u);
        }
    }

    auto query_point(int i) const {
        assert(range[1][0] <= i && i < range[1][1]);
        int u = where[i - range[1][0]];
        return node[u];
    }

    template <typename Update>
    void update_point(int i, Update&& update) {
        assert(range[1][0] <= i && i < range[1][1]);
        int u = where[i - range[1][0]];
        apply(u, update);
        while ((u >>= 1) >= 1) {
            pushup(u);
        }
    }

    auto query_range(int L, int R) const {
        assert(range[1][0] <= L && R <= range[1][1]);
        return query_range(1, L, R);
    }

    auto query_all() const { return node[1]; }

    // Find first i>=k such that fn([L,i]) holds, or R otherwise
    // Fn is F F F F T T T T ...
    template <typename Fn>
    int prefix_binary_search(int k, Fn&& fn) {
        auto [L, R] = range[1];
        Node ans;
        int i = 1, N = R - L;
        while (i < N) {
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
            node[u].apply(update, 1);
        } else {
            node[u].apply(update);
        }
    }
    void pushup(int u) {
        node[u].pushup(node[u << 1], node[u << 1 | 1]); //
    }

    auto query_range(int u, int L, int R) const {
        if (L <= range[u][0] && range[u][1] <= R) {
            return node[u];
        }
        int m = range[u << 1][1];
        if (R <= m) {
            return query_range(u << 1, L, R);
        } else if (m <= L) {
            return query_range(u << 1 | 1, L, R);
        } else {
            return combine(query_range(u << 1, L, m), query_range(u << 1 | 1, m, R));
        }
    }
};

struct min_segnode {
    static constexpr bool LAZY = false, RANGES = false, REVERSE = false;
    static constexpr int MAX = numeric_limits<int>::max() / 2;

    int value = MAX;
    int id = MAX;

    min_segnode() = default;
    min_segnode(int v) : value(v) {}
    operator int const &() const { return value; }

    void pushup(const min_segnode& lhs, const min_segnode& rhs) {
        if (lhs.value <= rhs.value) {
            value = lhs.value;
            id = lhs.id;
        } else {
            value = rhs.value;
            id = rhs.id;
        }
    }
    void apply(pair<int, int> valid) { value = valid.first, id = valid.second; }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> a(N + 1), b(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        assert(a[i] <= i);
    }
    for (int i = 1; i <= N; i++) {
        cin >> b[i];
        assert(i + b[i] <= N);
    }

    vector<int> bfs(N + 1), prev(N + 1, -1), head(N + 1);
    bfs[0] = N, prev[N] = 0, head[N] = N;
    set<int> heads;
    for (int i = 0; i < N; i++) {
        heads.insert(end(heads), i);
    }

    for (int i = 0, S = 1; i < S; i++) {
        int u = bfs[i];
        auto s = heads.lower_bound(u - a[u]);
        auto e = heads.upper_bound(u);
        for (auto it = s; it != e; ++it) {
            if (int v = *it, w = v + b[v]; prev[w] == -1) {
                head[w] = v;
                prev[w] = u;
                bfs[S++] = w;
            }
        }
        heads.erase(s, e);
    }

    if (prev[0] == -1) {
        cout << -1 << '\n';
    } else {
        vector<int> path;
        int u = 0;
        do {
            path.push_back(head[u]);
            u = prev[u];
        } while (u != N);
        reverse(begin(path), end(path));
        int P = path.size();
        cout << P << '\n';
        for (int i = 0; i < P; i++) {
            cout << path[i] << " \n"[i + 1 == P];
        }
    }

    return 0;
}