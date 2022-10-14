#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename Node>
struct link_cut_tree_subtree {
    struct LCTNode {
        int parent = 0, kids[2] = {};
        int8_t flip = 0; // splay tree is flipped due to reroot
        Node data;
    };

    vector<LCTNode> st;

    explicit link_cut_tree_subtree(int N = 0) : st(N + 1) {}

    template <typename T>
    link_cut_tree_subtree(int N, const vector<T>& arr) : st(N + 1) {
        for (int u = 1; u <= N; u++) {
            st[u].data = Node(arr[u]);
        }
    }

    // ***** Node updates
  protected:
    void flip(int u) {
        if (u == 0) {
            return;
        }
        auto& [l, r] = st[u].kids;
        swap(l, r);
        st[u].flip ^= 1;
        st[u].data.flip_path();
    }

    void pushdown(int u) {
        if (u != 0) {
            auto& [l, r] = st[u].kids;
            if (st[u].flip) {
                flip(l);
                flip(r);
                st[u].flip = 0;
            }
            st[u].data.pushdown(st[l].data, st[r].data);
        }
    }

    void pushup(int u) {
        auto [l, r] = st[u].kids;
        st[u].data.pushup(st[l].data, st[r].data);
    }

    void add_virtual_subtree(int u, int c) {
        if (c == 0) {
            return;
        } else if constexpr (Node::VIRTUAL_PUSHUP) {
            auto [l, r] = st[u].kids;
            st[u].data.add_virtual_subtree(st[l].data, st[r].data, st[c].data);
        } else {
            st[u].data.add_virtual_subtree(st[c].data);
        }
    }

    void rem_virtual_subtree(int u, int c) {
        if (c == 0) {
            return;
        } else if constexpr (Node::VIRTUAL_PUSHUP) {
            auto [l, r] = st[u].kids;
            st[u].data.rem_virtual_subtree(st[l].data, st[r].data, st[c].data);
        } else {
            st[u].data.rem_virtual_subtree(st[c].data);
        }
    }

    // ***** Interface
  public:
    bool link(int u, int v) {
        reroot(u), access(v);
        if (st[u].parent)
            return false;
        st[u].parent = v;
        add_virtual_subtree(v, u);
        return true;
    }

    bool cut(int u, int v) {
        reroot(u), access(v);
        if (!st[u].parent || st[u].kids[1] || u != st[v].kids[0])
            return false;
        st[u].parent = st[v].kids[0] = 0;
        return true;
    }

    void reroot(int u) {
        access(u);
        flip(u);
    }

    int findroot(int u) {
        access(u);
        while (st[u].kids[0])
            u = st[u].kids[0], pushdown(u);
        return u;
    }

    int lca(int u, int v) {
        if (u == v)
            return u;
        access(u), v = access(v);
        return st[u].parent ? v : 0;
    }

    bool conn(int u, int v) { return lca(u, v) != 0; }

    Node* access_node(int u) {
        access(u);
        return &st[u].data;
    }

    Node* access_path(int u, int v) {
        reroot(v), access(u);
        return &st[u].data;
    }

    Node* access_subtree(int u, int v) {
        reroot(v), access(u);
        return &st[u].data;
    }

    Node* access_tree(int u) {
        reroot(u), access(u);
        return &st[u].data;
    }

  protected:
    bool is_root(int u) const {
        return st[st[u].parent].kids[0] != u && st[st[u].parent].kids[1] != u;
    }

    void adopt(int parent, int child, int8_t side) {
        if (side >= 0)
            st[parent].kids[side] = child;
        if (child)
            st[child].parent = parent;
    }

    void rotate(int u) {
        int p = st[u].parent, g = st[p].parent;
        bool uside = u == st[p].kids[1];
        adopt(p, st[u].kids[!uside], uside);
        adopt(g, u, !is_root(p) ? p == st[g].kids[1] : -1);
        adopt(u, p, !uside);
        pushup(p);
    }

    void splay(int u) {
        int p = st[u].parent, g = st[p].parent;
        while (!is_root(u) && !is_root(p)) {
            pushdown(g), pushdown(p), pushdown(u);
            bool zigzig = (u == st[p].kids[1]) == (p == st[g].kids[1]);
            rotate(zigzig ? p : u), rotate(u);
            p = st[u].parent, g = st[p].parent;
        }
        if (!is_root(u)) {
            pushdown(p), pushdown(u), rotate(u);
        }
        pushdown(u), pushup(u);
    }

    int access(int u) {
        int last = 0, v = u;
        do {
            splay(v);
            add_virtual_subtree(v, st[v].kids[1]);
            rem_virtual_subtree(v, last);
            st[v].kids[1] = last;
            pushup(v);
            last = v, v = st[v].parent;
        } while (v);
        splay(u);
        assert(!st[u].kids[1] && !st[u].flip);
        return last;
    }
};

using i64 = int64_t;

struct Data {
    int full = 1;
    int lsum = 0;
    int rsum = 0;
    i64 blob = 0;
    i64 cold = 0;

    Data() = default;
    Data(int self) : full(self), lsum(self), rsum(self) {}

    static i64 sq(i64 x) { return x * x; }

    i64 rblob() const { return full ? blob : blob + sq(lsum); }
    i64 lblob() const { return full ? blob : blob + sq(rsum); }
    i64 query() const { return lblob() + sq(lsum); }

    void flip() { swap(lsum, rsum); }

    void add(Data node) {
        blob += node.lblob();
        lsum += node.lsum;
        rsum += node.lsum;
        cold += sq(node.lsum);
    }

    void rem(Data node) {
        blob -= node.lblob();
        lsum -= node.lsum;
        rsum -= node.lsum;
        cold -= sq(node.lsum);
    }

    void make_node(Data virt) {
        blob = full ? virt.blob : virt.blob + virt.cold;
        lsum = rsum = full ? 1 + virt.lsum : 0;
        cold = 0;
    }

    // [la...ra] [lb...rb] to [la...rb]
    static Data merge(Data a, Data b) {
        Data c;
        c.full = a.full & b.full;
        c.lsum = a.full ? a.lsum + b.lsum : a.lsum;
        c.rsum = b.full ? a.rsum + b.rsum : b.rsum;
        c.blob = a.blob + b.blob + (a.full || b.full ? 0 : sq(a.rsum + b.lsum));
        return c;
    }
};

struct Node {
    static constexpr bool VIRTUAL_PUSHUP = false;

    int self = 0;
    Data data, virt;

    Node() = default;
    Node(bool) {}

    i64 query() { return data.query(); }

    void flip_path() { data.flip(); }

    void add_virtual_subtree(const Node& kid) { virt.add(kid.data); }

    void rem_virtual_subtree(const Node& kid) { virt.rem(kid.data); }

    void pushup(const Node& lhs, const Node& rhs) {
        data.full = self;
        data.make_node(virt);
        data = Data::merge(lhs.data, data);
        data = Data::merge(data, rhs.data);
    }

    void pushdown(Node&, Node&) {}
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> color(N + 1);
    link_cut_tree_subtree<Node> tree(N);
    for (int u = 1; u <= N; u++) {
        cin >> color[u];
        tree.access_node(u)->self = 1;
    }
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        tree.link(u, v);
    }
    vector<vector<int>> front(N + 1), back(N + 1);
    vector<vector<array<int, 3>>> events(N + 1);
    for (int u = 1; u <= N; u++) {
        front[color[u]].push_back(u);
    }
    for (int q = 0; q < Q; q++) {
        int u, c;
        cin >> u >> c;
        if (c != color[u]) {
            events[color[u]].push_back({u, q, 1});
            color[u] = c;
            events[color[u]].push_back({u, q, 0});
        }
    }
    for (int u = 1; u <= N; u++) {
        back[color[u]].push_back(u);
    }
    i64 ans = 0;
    vector<i64> delta(Q);
    for (int c = 1; c <= N; c++) {
        for (int u : front[c]) {
            tree.access_node(u)->self = 0;
        }
        i64 f = tree.access_tree(1)->query();
        ans += f;
        for (auto [u, q, x] : events[c]) {
            tree.access_node(u)->self = x;
            i64 g = tree.access_tree(1)->query();
            delta[q] += g - f, f = g;
        }
        for (int u : back[c]) {
            tree.access_node(u)->self = 1;
        }
    }
    i64 F = 1LL * N * N * N;
    cout << F - ans << '\n';
    for (int q = 0; q < Q; q++) {
        ans += delta[q];
        cout << F - ans << '\n';
    }
    return 0;
}