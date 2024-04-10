#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename Node>
struct iterative_segtree {
    int N, size, start;
    vector<Node> node;

    iterative_segtree() = default;
    iterative_segtree(int L, int R, Node init) { assign(L, R, init); }

    iterative_segtree(int L, int R, const string &arr, int s = 0) {
        assign(L, R, arr, s);
    }

    void assign(int L, int R, Node init) {
        int N = R - L;
        size = 1 << (N > 1 ? 8 * sizeof(N) - __builtin_clz(N - 1) : 0);
        start = L;
        node.assign(2 * size, Node());
        for (int i = 0; i < N; i++) {
            node[i + size] = init;
        }
        for (int i = size - 1; i > 0; i--) {
            pushup(i);
        }
    }

    void assign(int L, int R, const string &arr, int s = 0) {
        int N = R - L;
        size = 1 << (N > 1 ? 8 * sizeof(N) - __builtin_clz(N - 1) : 0);
        start = L;
        node.assign(2 * size, Node());
        for (int i = 0; i < N; i++) {
            node[i + size] = Node(arr[i - s]);
        }
        for (int i = size - 1; i > 0; i--) {
            pushup(i);
        }
    }

    auto query_point(int p) const { return node[p + size - start]; }

    template <typename Update>
    void update_point(int i, Update &&update) {
        i += size - start;
        apply(i, update);
        for (i >>= 1; i > 0; i >>= 1) {
            pushup(i);
        }
    }

    auto query_range(int L, int R) const {
        Node ans;
        L -= start, R -= start;
        for (int t = R - L; t >= 1; t = R - L) {
            int x = L | ((1U << 31) >> __builtin_clz(t));
            int u = x & (-x);
            int k = __builtin_ctz(x);
            ans = combine(ans, node[(size | L) >> k]);
            L += u;
        }
        return ans;
    }

    auto query_all() const { return node[1]; }

  private:
    static Node combine(const Node &x, const Node &y) {
        Node ans;
        ans.pushup(x, y);
        return ans;
    }
    template <typename Update>
    void apply(int u, Update &&update) {
        if constexpr (Node::RANGES) {
            node[u].apply(update, 1);
        } else {
            node[u].apply(update);
        }
    }
    void pushup(int u) { node[u].pushup(node[u << 1], node[u << 1 | 1]); }
};

struct node {
    static constexpr bool RANGES = false;
    int a = 0, b = 0, c = 0, ab = 0, bc = 0, abc = 0;

    node() = default;
    node(char id) { apply(id); }

    void pushup(const node &lhs, const node &rhs) {
        a = lhs.a + rhs.a;
        b = lhs.b + rhs.b;
        c = lhs.c + rhs.c;
        ab = min(lhs.a + rhs.ab, lhs.ab + rhs.b);
        bc = min(lhs.b + rhs.bc, lhs.bc + rhs.c);
        abc = min({lhs.a + rhs.abc, lhs.ab + rhs.bc, lhs.abc + rhs.c});
    }

    void apply(char id) {
        a = id == 'a';
        b = id == 'b';
        c = id == 'c';
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;

    iterative_segtree<node> seg(0, N, s);

    while (Q--) {
        int i;
        char c;
        cin >> i >> c, i--;
        seg.update_point(i, c);
        cout << seg.query_all().abc << '\n';
    }

    return 0;
}