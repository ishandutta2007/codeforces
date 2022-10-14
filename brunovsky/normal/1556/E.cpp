#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

template <typename Node>
struct iterative_segtree {
    int N, Q;
    vector<Node> node;

    iterative_segtree() = default;
    iterative_segtree(int N, Node init) { assign(N, init); }

    template <typename T>
    iterative_segtree(const vector<T>& arr) {
        assign(arr);
    }

    void assign(int N, Node init) {
        this->N = N;
        this->Q = 1 << (N > 1 ? 8 * sizeof(N) - __builtin_clz(N - 1) : 0);
        node.assign(2 * Q, Node());
        for (int i = 0; i < N; i++) {
            node[i + Q] = init;
        }
        for (int i = Q - 1; i > 0; i--) {
            pushup(i);
        }
    }

    template <typename T>
    void assign(const vector<T>& arr) {
        this->N = arr.size();
        this->Q = 1 << (N > 1 ? 8 * sizeof(N) - __builtin_clz(N - 1) : 0);
        node.assign(2 * Q, Node());
        for (int i = 0; i < N; i++) {
            node[i + Q] = Node(arr[i]);
        }
        for (int i = Q - 1; i > 0; i--) {
            pushup(i);
        }
    }

    auto query_point(int i) const { return node[i + Q]; }

    template <typename Update>
    void update_point(int i, Update&& update) {
        i += Q;
        apply(i, update);
        for (i >>= 1; i > 0; i >>= 1) {
            pushup(i);
        }
    }

    auto query_range(int L, int R) const {
        Node ans;
        for (int t = R - L; t >= 1; t = R - L) {
            int x = L | ((1U << 31) >> __builtin_clz(t));
            int u = x & (-x);
            int k = __builtin_ctz(x);
            Node v;
            v.pushup(ans, node[(Q | L) >> k]);
            ans = move(v);
            L += u;
        }
        return ans;
    }

    auto query_all() const { return node[1]; }

  private:
    template <typename Update>
    void apply(int u, Update&& update) {
        if constexpr (Node::RANGES) {
            node[u].apply(update, u - Q, u - Q + 1);
        } else {
            node[u].apply(update);
        }
    }
    void pushup(int u) { node[u].pushup(node[u << 1], node[u << 1 | 1]); }
};

template <typename T>
struct segnode {
    static constexpr bool RANGES = false, RANGES_MERGE = false;
    static constexpr T MIN = numeric_limits<T>::lowest() / 2;
    static constexpr T MAX = numeric_limits<T>::max() / 2;

    T range_min = MAX;
    T range_max = MIN;
    T range_sum = 0;

    segnode() = default;
    segnode(T v) : range_min(v), range_max(v), range_sum(v) {}

    void pushup(const segnode& lhs, const segnode& rhs) {
        range_min = min(lhs.range_min, lhs.range_sum + rhs.range_min);
        range_max = max(lhs.range_max, lhs.range_sum + rhs.range_max);
        range_sum = lhs.range_sum + rhs.range_sum;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<long> a(N + 1), b(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> b[i];
    }

    vector<long> diff(N + 1);
    for (int i = 1; i <= N; i++) {
        diff[i] = a[i] - b[i];
    }

    iterative_segtree<segnode<long>> st(diff);

    while (Q--) {
        int l, r;
        cin >> l >> r, r++;
        auto node = st.query_range(l, r);
        if (node.range_sum != 0 || node.range_max > 0) {
            cout << -1 << '\n';
            continue;
        }
        cout << -node.range_min << '\n';
    }
    return 0;
}