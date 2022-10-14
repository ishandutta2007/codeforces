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
    iterative_segtree(const vector<T> &arr) {
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
    void assign(const vector<T> &arr) {
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
    void update_point(int i, Update &&update) {
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
    void apply(int u, Update &&update) {
        if constexpr (Node::RANGES) {
            node[u].apply(update, u - Q, u - Q + 1);
        } else {
            node[u].apply(update);
        }
    }
    void pushup(int u) { node[u].pushup(node[u << 1], node[u << 1 | 1]); }
};

struct segnode {
    static constexpr bool RANGES = false, RANGES_MERGE = false;

    long count = 0;
    int len = 0;
    int prefix_len = 0;
    int prefix = 0;
    int suffix_len = 0;
    int suffix = 0;

    segnode() = default;
    segnode(int v)
        : count(1), len(1), prefix_len(1), prefix(v), suffix_len(1), suffix(v) {}

    bool full() const { return len == prefix_len; }

    void pushup(const segnode &lhs, const segnode &rhs) {
        count = lhs.count + rhs.count;
        len = lhs.len + rhs.len;
        prefix = lhs.prefix;
        suffix = rhs.suffix;
        if (lhs.suffix <= rhs.prefix) {
            count += 1LL * lhs.suffix_len * rhs.prefix_len;
        }
        if (lhs.suffix <= rhs.prefix && lhs.full()) {
            prefix_len = lhs.len + rhs.prefix_len;
        } else {
            prefix_len = lhs.prefix_len;
        }
        if (lhs.suffix <= rhs.prefix && rhs.full()) {
            suffix_len = lhs.suffix_len + rhs.len;
        } else {
            suffix_len = rhs.suffix_len;
        }
    }
    void apply(int set) {
        assert(len == 1);
        prefix = suffix = set;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    iterative_segtree<segnode> st(arr);

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y, x--;
            st.update_point(x, y);
        } else {
            int l, r;
            cin >> l >> r, l--;
            cout << st.query_range(l, r).count << '\n';
        }
    }
    return 0;
}