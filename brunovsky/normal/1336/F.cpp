#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename Fun>
class y_combinator_result {
    Fun fun_;

  public:
    template <typename T>
    explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}

    template <typename... Args>
    decltype(auto) operator()(Args&&... args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <typename Fun>
auto y_combinator(Fun&& fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

template <typename T, typename BinOp>
struct bitree {
    int N;
    vector<T> tree;
    BinOp binop;

    explicit bitree(int N, T id = T()) : N(N), tree(N + 1, id), binop(BinOp()) {}

    explicit bitree(int N, const BinOp& op, T id = T())
        : N(N), tree(N + 1, id), binop(op) {}

    template <typename A>
    explicit bitree(int N, const vector<A>& arr, const BinOp& op = BinOp(), T id = T())
        : bitree(N, op, id) {
        for (int i = 1; i <= N; i++) {
            tree[i] = binop(arr[i - 1], tree[i]);
            if (int j = i + (i & -i); j <= N) {
                tree[j] = binop(tree[i], tree[j]);
            }
        }
    }

    void combine(int i, T v) {
        for (++i; i <= N; i += i & -i) {
            tree[i] = binop(tree[i], v);
        }
    }

    T prefix(int r) const { // [0..r)
        T accum = tree[0];
        for (int i = r; i > 0; i -= i & -i) {
            accum = binop(tree[i], accum);
        }
        return accum;
    }

    // Find smallest i such that fn(prefix(i)) is true, or N otherwise.
    // fn should be F F F F ... T T T T, e.g. fn(sum) := x <= sum if sum is increasing
    template <typename Fn>
    int lower_bound(Fn&& fn) const {
        int i = 0;
        T accum = tree[0];
        for (int bit = 8 * sizeof(int) - __builtin_clz(N << 1); bit >= 0; bit--) {
            int next = i + (1 << bit);
            if (next <= N) {
                T combined = binop(accum, tree[next]);
                if (!fn(combined)) {
                    i = next;
                    accum = combined;
                }
            }
        }
        return i;
    }
};

struct hld_forest {
    vector<int> subsize, parent, depth, roots, order;
    vector<int> heavy; // heavy child of this node, tree[u][0]
    vector<int> head;  // top of heavy path
    vector<int> time;  // index of node in preorder tour with no repetition

    explicit hld_forest(vector<vector<int>>& tree, int root = -1) {
        int N = tree.size();
        subsize.assign(N, 0);
        parent.assign(N, -1);
        heavy.assign(N, -1);
        depth.assign(N, 0);
        head.assign(N, 0);
        time.assign(N, 0);
        order.assign(N, 0);
        int timer = 0;

        auto dfs = y_combinator([&](auto self, int u, int p) -> void {
            subsize[u] = 1;
            int biggest = 0;
            for (int& v : tree[u]) {
                if (v != p) {
                    parent[v] = u;
                    depth[v] = depth[u] + 1;
                    self(v, u);
                    subsize[u] += subsize[v];
                    if (biggest < subsize[v]) {
                        biggest = subsize[v];
                        heavy[u] = v;
                        swap(tree[u][0], v);
                    }
                }
            }
        });

        auto decompose = y_combinator([&](auto self, int u, int h) -> void {
            order[timer] = u;
            head[u] = h;
            time[u] = timer++;
            for (int v : tree[u]) {
                if (v != parent[u]) {
                    self(v, v == heavy[u] ? h : v);
                }
            }
        });

        if (root != -1) {
            dfs(root, -1);
            decompose(root, root);
            roots.push_back(root);
        }
        for (int u = 0; u < N; u++) {
            if (subsize[u] == 0) {
                dfs(u, -1);
                decompose(u, u);
                roots.push_back(u);
            }
        }
    }

    int num_nodes() const { return subsize.size(); }

    int max_depth() const { return *max_element(begin(depth), end(depth)); }

    int kth_ancestor(int u, int k) const {
        if (k < 0 || depth[u] < k) {
            return -1;
        }
        int dest = depth[u] - k;
        while (depth[u] > dest) {
            if (depth[head[u]] > dest) {
                u = parent[head[u]];
            } else {
                int up = depth[u] - dest;
                u = order[time[u] - up];
            }
        }
        return u;
    }

    int below(int u, int a) const { return kth_ancestor(u, depth[u] - depth[a] - 1); }

    int lca(int u, int v) const {
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                u = parent[head[u]];
            } else {
                v = parent[head[v]];
            }
        }
        return depth[u] < depth[v] ? u : v;
    }

    int findroot(int u) const {
        while (parent[head[u]] != -1) {
            u = parent[head[u]];
        }
        return head[u];
    }

    int dist(int u, int v) const { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }

    bool conn(int u, int v) const { return findroot(u) == findroot(v); }

    bool is_above(int a, int u) const {
        return time[a] <= time[u] && time[u] < time[a] + subsize[a];
    }

    bool is_above_on_heavy_path(int a, int u) const {
        return head[a] == head[u] && time[a] <= time[u];
    }

    bool on_path(int x, int u, int v) const {
        return is_above(lca(u, v), x) && (is_above(x, u) || is_above(x, v));
    }

    int seg_edge_index(int u, int v) const { return parent[u] == v ? time[u] : time[v]; }

    int kth_on_path(int u, int v, int k) const {
        int a = lca(u, v);
        if (k <= depth[u] - depth[a]) {
            return kth_ancestor(u, k);
        } else if (k -= depth[u] - depth[a]; k <= depth[v] - depth[a]) {
            return kth_ancestor(v, depth[v] - depth[a] - k);
        } else {
            return -1;
        }
    }

    // Centroid and join of three nodes
    int join_node(int a, int b, int c) const {
        int x = lca(a, b), y = lca(b, c), z = lca(c, a);
        return x ^ y ^ z;
    }

    // Split the path from u to v into sorted heavy path segments [l,r), 0<=l<r<=N
    auto vertex_segments(int u, int v) const {
        vector<array<int, 2>> ranges;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                ranges.push_back({time[head[u]], time[u] + 1});
                u = parent[head[u]];
            } else {
                ranges.push_back({time[head[v]], time[v] + 1});
                v = parent[head[v]];
            }
        }
        if (depth[u] < depth[v]) {
            ranges.push_back({time[u], time[v] + 1});
        } else {
            ranges.push_back({time[v], time[u] + 1});
        }
        return ranges;
    }

    // Split the path from u to v into sorted heavy path segments [l,r), 0<=l<r<=N
    // down: l appears first on the path; up: l appears last on the path
    auto oriented_vertex_segments(int u, int v) const {
        vector<array<int, 2>> up, down;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                up.push_back({time[head[u]], time[u] + 1});
                u = parent[head[u]];
            } else {
                down.push_back({time[head[v]], time[v] + 1});
                v = parent[head[v]];
            }
        }
        if (depth[u] < depth[v]) {
            down.push_back({time[u], time[v] + 1});
        } else {
            up.push_back({time[v], time[u] + 1});
        }
        reverse(begin(down), end(down));
        return make_pair(move(up), move(down));
    }

    // Split the edge path from u to v into sorted heavy path segments [l,r), 1<=l<r<=N
    // We consider edges here, so that vertex u is responsible for its parent edge
    auto edge_segments(int u, int v) const {
        vector<array<int, 2>> ranges;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                ranges.push_back({time[head[u]], time[u] + 1});
                u = parent[head[u]];
            } else {
                ranges.push_back({time[head[v]], time[v] + 1});
                v = parent[head[v]];
            }
        }
        if (depth[u] < depth[v]) {
            ranges.push_back({time[u] + 1, time[v] + 1});
        } else if (depth[v] < depth[u]) {
            ranges.push_back({time[v] + 1, time[u] + 1});
        }
        return ranges;
    }

    // Split the edge path from u to v into sorted heavy path segments [l,r), 1<=l<r<=N
    // We consider edges here, so that vertex u is responsible for its parent edge
    // down: l appears first on the path; up: l appears last on the path
    auto oriented_edge_segments(int u, int v) const {
        vector<array<int, 2>> up, down;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                up.push_back({time[head[u]], time[u] + 1});
                u = parent[head[u]];
            } else {
                down.push_back({time[head[v]], time[v] + 1});
                v = parent[head[v]];
            }
        }
        if (depth[u] < depth[v]) {
            down.push_back({time[u] + 1, time[v] + 1});
        } else if (depth[v] < depth[u]) {
            up.push_back({time[v] + 1, time[u] + 1});
        }
        reverse(begin(down), end(down));
        return make_pair(move(up), move(down));
    }

    // Split the edge path from u to v into sorted heavy path segments [l,r), 1<=l<r<=N
    // Return inclusive bounds and merge heavy paths with their parent light edges.
    // Includes an extra 0-edge interval for the lca if it lies on a separate heavy path
    auto cut_segments(int u, int v) const {
        vector<array<int, 3>> ranges;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                ranges.push_back({head[u], time[parent[head[u]]], time[u]});
                u = parent[head[u]];
            } else {
                ranges.push_back({head[v], time[parent[head[v]]], time[v]});
                v = parent[head[v]];
            }
        }
        if (depth[u] < depth[v]) {
            ranges.push_back({head[v], time[u], time[v]});
        } else if (depth[v] < depth[u]) {
            ranges.push_back({head[u], time[v], time[u]});
        } else {
            ranges.push_back({head[u], time[u], time[u]}); // up or down doesn't matter
        }
        return ranges;
    }

    // Split the edge path from u to v into sorted heavy path segments [l,r), 1<=l<r<=N
    // Return inclusive bounds and merge heavy paths with their parent light edges.
    // Includes an extra 0-edge interval for the lca if it lies on a separate heavy path
    // down: l appears first on the path; up: l appears last on the path
    auto oriented_cut_segments(int u, int v) const {
        vector<array<int, 3>> down, up;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                up.push_back({head[u], time[head[u]] - 1, time[u]});
                u = parent[head[u]];
            } else {
                down.push_back({head[v], time[head[v]] - 1, time[v]});
                v = parent[head[v]];
            }
        }
        if (depth[u] < depth[v]) {
            down.push_back({head[v], time[u], time[v]});
        } else if (depth[v] < depth[u]) {
            up.push_back({head[u], time[v], time[u]});
        } else {
            up.push_back({head[u], time[u], time[u]}); // up or down doesn't matter
        }
        reverse(begin(down), end(down));
        return make_pair(move(up), move(down));
    }

    // Compute a minimal subtree that contains all the nodes with at most 2k-1 nodes
    auto compress_tree(vector<int> nodes) const {
        int k = nodes.size();
        auto cmp = [&](int a, int b) { return time[a] < time[b]; };
        sort(begin(nodes), end(nodes), cmp);

        for (int i = 0; i < k - 1; i++) {
            nodes.push_back(lca(nodes[i], nodes[i + 1]));
        }

        sort(begin(nodes) + k, end(nodes), cmp);
        inplace_merge(begin(nodes), begin(nodes) + k, end(nodes), cmp);
        nodes.erase(unique(begin(nodes), end(nodes)), end(nodes));
        k = nodes.size();

        vector<pair<int, int>> ctree;
        for (int i = 1; i < k; i++) {
            ctree.emplace_back(nodes[i], lca(nodes[i - 1], nodes[i]));
        }
        return make_pair(nodes[0], move(ctree));
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> tree(N);
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    hld_forest hld(tree, 0);

    vector<vector<int>> downfrom(N);
    vector<vector<pair<int, int>>> forks(N);
    vector<vector<int>> singles(N);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y, x--, y--;
        int c = hld.lca(x, y);
        if (hld.time[x] > hld.time[y]) {
            swap(x, y);
        }
        if (hld.depth[x] - hld.depth[c] >= K) {
            downfrom[c].push_back(x);
        }
        if (hld.depth[y] - hld.depth[c] >= K) {
            downfrom[c].push_back(y);
        }
        if (x != c && y != c) {
            forks[c].push_back({x, y});
        } else {
            singles[c].push_back(x ^ y ^ c);
        }
    }

    bitree<int, plus<int>> seg(N, 0);
    int64_t ans = 0;

    // First solve for different tops
    y_combinator([&](auto self, int u, int p) -> void {
        for (int x : downfrom[u]) {
            int y = hld.kth_on_path(u, x, K);
            int l = hld.time[y];
            int r = hld.time[y] + hld.subsize[y];
            ans += seg.prefix(r) - seg.prefix(l);
        }
        for (int x : downfrom[u]) {
            seg.combine(hld.time[x], +1);
        }
        for (int v : tree[u]) {
            if (v != p) {
                self(v, u);
            }
        }
        for (int x : downfrom[u]) {
            seg.combine(hld.time[x], -1);
        }
    })(0, -1);

    assert(seg.prefix(N) == 0);

    vector<vector<int>> virtree(N);
    vector<list<int>> here(N);
    vector<int> weight(N);

    for (int c = 0; c < N; c++) {
        vector<int> nodes = {c};
        for (auto [x, y] : forks[c]) {
            nodes.push_back(x);
            nodes.push_back(y);
            weight[x]++;
            here[x].push_back(y);
        }
        for (int x : singles[c]) {
            nodes.push_back(x);
            weight[x]++;
            here[x].push_back(c);
        }

        sort(begin(nodes), end(nodes), [&](int u, int v) {
            return hld.time[u] < hld.time[v]; //
        });
        nodes.erase(unique(begin(nodes), end(nodes)), end(nodes));

        auto [virtroot, edges] = hld.compress_tree(nodes);
        assert(virtroot == c);

        vector<int> virt_nodes = {c};
        for (auto [x, y] : edges) {
            virtree[y].push_back(x);
            virt_nodes.push_back(x);
        }

        y_combinator([&](auto self, int u, int p) -> void {
            for (int v : virtree[u]) {
                assert(v != p);
                self(v, u);
                weight[u] += weight[v];
            }
        })(c, -1);

        // Cheapest first, for postorder small-to-large
        for (int u : virt_nodes) {
            sort(begin(virtree[u]), end(virtree[u]), [&](int a, int b) {
                return weight[a] < weight[b]; //
            });
        }

        // Now add proper overlaps, postorder
        auto seen = y_combinator([&](auto self, int u, int p) -> list<int> {
            vector<list<int>> kids;
            for (int v : virtree[u]) {
                assert(v != p);
                if (kids.size()) {
                    for (int y : kids.back()) {
                        seg.combine(hld.time[y], -1);
                    }
                }
                kids.push_back(self(v, u));
            }
            int V = kids.size();
            int d = hld.depth[u] - hld.depth[c];
            list<int> sub;
            if (V > 0) {
                sub.splice(end(sub), kids[V - 1]);
            }
            for (int i = V - 2; i >= 0; i--) {
                for (int y : kids[i]) {
                    if (d >= K) {
                        ans += seg.prefix(N);
                    } else if (int a = hld.kth_on_path(c, y, K - d); a != -1) {
                        int l = hld.time[a];
                        int r = hld.time[a] + hld.subsize[a];
                        ans += seg.prefix(r) - seg.prefix(l);
                    }
                }
                for (int y : kids[i]) {
                    seg.combine(hld.time[y], +1);
                }
                sub.splice(end(sub), kids[i]);
            }
            for (int y : here[u]) {
                if (d >= K) {
                    ans += seg.prefix(N);
                } else if (int a = hld.kth_on_path(c, y, K - d); a != -1) {
                    int l = hld.time[a];
                    int r = hld.time[a] + hld.subsize[a];
                    ans += seg.prefix(r) - seg.prefix(l);
                }
                seg.combine(hld.time[y], +1);
            }
            sub.splice(end(sub), here[u]);
            return sub;
        })(c, -1);

        for (int y : seen) {
            seg.combine(hld.time[y], -1);
        }
        for (auto [x, _] : forks[c]) {
            seg.combine(hld.time[x], +1);
        }
        for (int x : singles[c]) {
            seg.combine(hld.time[x], +1);
        }
        for (auto [_, y] : forks[c]) {
            if (int a = hld.kth_on_path(c, y, K); a != -1) {
                int l = hld.time[a];
                int r = hld.time[a] + hld.subsize[a];
                ans += seg.prefix(r) - seg.prefix(l);
            }
        }
        for (auto [x, _] : forks[c]) {
            seg.combine(hld.time[x], -1);
        }
        for (int x : singles[c]) {
            seg.combine(hld.time[x], -1);
        }

        for (int u : virt_nodes) {
            virtree[u].clear();
            here[u].clear();
            weight[u] = 0;
        }
    }

    cout << ans << '\n';
    return 0;
}