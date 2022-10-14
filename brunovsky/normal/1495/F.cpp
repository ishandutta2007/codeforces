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

    bool is_above(int u, int a) const {
        return time[a] <= time[u] && time[u] < time[a] + subsize[a];
    }

    bool is_above_on_heavy_path(int u, int a) const {
        return head[a] == head[u] && time[a] <= time[u];
    }

    bool on_path(int x, int u, int v) const {
        return is_above(x, lca(u, v)) && (is_above(u, x) || is_above(v, x));
    }

    int seg_edge_index(int u, int v) const { return parent[u] == v ? time[u] : time[v]; }

    auto seg_vertex_range(int u) const {
        return make_pair(time[u], time[u] + subsize[u]);
    }

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
    int N, Q;
    cin >> N >> Q;
    vector<int> perm(N + 1, N);
    for (int i = 0; i < N; i++) {
        cin >> perm[i], perm[i]--;
    }
    vector<int64_t> A(N + 1), B(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    vector<int> parent(N + 1, N);
    {
        vector<int> stk = {N};
        for (int i = N - 1; i >= 0; i--) {
            while (perm[i] > perm[stk.back()]) {
                stk.pop_back();
            }
            parent[i] = stk.back();
            stk.push_back(i);
        }
    }

    vector<vector<int>> tree(N + 1);
    for (int i = 0; i < N; i++) {
        tree[parent[i]].push_back(i);
    }
    hld_forest hld(tree, N);

    vector<int> left(N + 1, -1), right(N + 1, -1);
    for (int p = 1; p <= N; p++) {
        sort(begin(tree[p]), end(tree[p]));
        for (int S = tree[p].size(), i = 0; i + 1 < S; i++) {
            int u = tree[p][i];
            int v = tree[p][i + 1];
            left[v] = u, right[u] = v;
        }
    }

    vector<int> leftmost(N + 1);
    for (int i = 0; i <= N; i++) {
        leftmost[i] = tree[i].size() ? leftmost[tree[i][0]] : i;
    }

    vector<int64_t> cost(N + 1);
    for (int i = N - 1; i >= 0; i--) {
        cost[i] = min(B[i] + cost[parent[i]], A[i] + cost[i + 1]);
    }

    constexpr int C = 19;
    vector<array<int, C>> ancestor(N + 1);
    for (int i = 0; i <= N; i++) {
        ancestor[i][0] = parent[i];
    }
    for (int b = 1; b < C; b++) {
        for (int i = 0; i <= N; i++) {
            ancestor[i][b] = ancestor[ancestor[i][b - 1]][b - 1];
        }
    }

    auto raise = [&](int u, int v) {
        assert(hld.is_above(u, v) && u <= v);
        return cost[u] - cost[v];
    };

    // skip[i][0]: move from leftmost of parent[i] to leftmost of i
    vector<array<int64_t, C>> skip(N + 1);
    for (int i = 0; i < N; i++) {
        if (int j = left[i]; j != -1) {
            skip[i][0] = skip[j][0] + A[j] + raise(leftmost[j], j);
        }
    }
    for (int b = 1; b < C; b++) {
        for (int i = 0; i < N; i++) {
            skip[i][b] = skip[i][b - 1] + skip[ancestor[i][b - 1]][b - 1];
        }
    }

    set<int> visit;
    int64_t ans = cost[0];

    auto jump = [&](int v, int k) {
        int64_t sum = 0;
        for (int b = C - 1; b >= 0; b--) {
            if (k >> b & 1) {
                sum += skip[v][b];
                v = ancestor[v][b];
            }
        }
        return sum;
    };
    auto advance = [&](int u, int v) {
        assert(u < v);
        int c = hld.lca(u, v);
        int d = hld.below(u, c);
        int e = hld.below(v, c);
        if (c == v) {
            return raise(u, v);
        } else {
            int k = hld.depth[v] - hld.depth[c] - 1;
            int64_t rightwards = skip[e][0] - skip[right[d]][0];
            return raise(u, d) + A[d] + rightwards + jump(v, k) + raise(leftmost[v], v);
        }
    };
    auto insert = [&](int u) {
        auto pos = visit.insert(u).first;
        if (u == 0 || u == N) {
            return;
        }
        int l = pos == begin(visit) ? 0 : *prev(pos);
        int r = next(pos) == end(visit) ? N : *next(pos);
        ans -= advance(l, r);
        ans += advance(l, u);
        ans += advance(u, r);
    };
    auto erase = [&](int u) {
        auto pos = visit.erase(visit.find(u));
        if (u == 0 || u == N) {
            return;
        }
        int l = pos == begin(visit) ? 0 : *prev(pos);
        int r = pos == end(visit) ? N : *pos;
        ans -= advance(l, u);
        ans -= advance(u, r);
        ans += advance(l, r);
    };

    while (Q--) {
        int x;
        cin >> x, x--;
        if (visit.count(x)) {
            erase(x);
        } else {
            insert(x);
        }
        cout << ans << '\n';
    }
    return 0;
}