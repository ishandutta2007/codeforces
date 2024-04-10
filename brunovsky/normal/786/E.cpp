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
auto rec(Fun&& fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

struct hld_forest {
    vector<int> subsize, parent, depth, roots;
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
        int timer = 0;

        auto dfs = rec([&](auto self, int u, int p) -> void {
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

        auto decompose = rec([&](auto self, int u, int h) -> void {
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

    int kth_ancestor(int u, int k) const {
        assert(0 <= k && k <= depth[u]);
        int dest = depth[u] - k;
        while (depth[u] > dest) {
            if (depth[head[u]] < dest) {
                u = parent[u];
            } else {
                u = head[u];
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

    int kth_on_path(int u, int v, int k) const {
        int a = lca(u, v);
        if (k <= depth[u] - depth[a]) {
            return kth_ancestor(u, k);
        } else {
            return kth_ancestor(v, depth[u] + depth[v] - 2 * depth[a] - k);
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
            down.push_back({time[u], time[v] + 1});
        } else if (depth[v] < depth[u]) {
            up.push_back({time[v], time[u] + 1});
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

        vector<pair<int, int>> compressed_tree = {{nodes[0], -1}};
        for (int i = 1; i < k; i++) {
            compressed_tree.push_back({nodes[i], lca(nodes[i - 1], nodes[i])});
        }
        return compressed_tree;
    }
};

template <typename Flow = int64_t, typename FlowSum = Flow>
struct tidal_flow {
    static inline default_random_engine rng = default_random_engine(random_device{}());
    struct Edge {
        int node[2];
        Flow cap, flow = 0;
    };
    int V, E = 0;
    vector<vector<int>> res;
    vector<Edge> edge;

    explicit tidal_flow(int V = 0) : V(V), res(V) {}

    int add(int u, int v, Flow capacity) {
        assert(0 <= u && u < V && 0 <= v && v < V && capacity >= 0);
        res[u].push_back(E++), edge.push_back({{u, v}, capacity, 0});
        res[v].push_back(E++), edge.push_back({{v, u}, 0, 0});
        return (E - 2) >> 1;
    }
    int add_node() { return res.emplace_back(), V++; }
    void update_edge(int e, Flow capacity) { edge[2 * e].cap = capacity; }

    void shuffle_edges() {
        for (int u = 0; u < V; u++) {
            shuffle(begin(res[u]), end(res[u]), rng);
        }
    }

    vector<int> level, edges, Q;
    vector<Flow> p;
    vector<FlowSum> h, l;
    static constexpr Flow flowinf = numeric_limits<Flow>::max() / 2;
    static constexpr FlowSum flowsuminf = numeric_limits<FlowSum>::max() / 2;

    bool bfs(int s, int t) {
        level.assign(V, -1);
        edges.clear();
        level[s] = 0;
        Q[0] = s;
        for (int i = 0, S = 1; i < S && level[Q[i]] != level[t]; i++) {
            int u = Q[i];
            for (int e : res[u]) {
                int v = edge[e].node[1];
                if (edge[e].flow < edge[e].cap) {
                    if (level[v] == -1) {
                        level[v] = level[u] + 1;
                        Q[S++] = v;
                    }
                    if (level[u] < level[v]) {
                        edges.push_back(e);
                    }
                }
            }
        }
        return level[t] != -1;
    }

    FlowSum tide(int s, int t) {
        fill(begin(h), end(h), 0);
        h[s] = flowsuminf;
        for (int e : edges) {
            auto [w, v] = edge[e].node;
            p[e] = min(FlowSum(edge[e].cap - edge[e].flow), h[w]);
            h[v] = h[v] + p[e];
        }
        if (h[t] == 0) {
            return 0;
        }
        fill(begin(l), end(l), 0);
        l[t] = h[t];
        for (auto it = edges.rbegin(); it != edges.rend(); it++) {
            int e = *it;
            auto [w, v] = edge[e].node;
            p[e] = min(FlowSum(p[e]), min(h[w] - l[w], l[v]));
            l[v] -= p[e];
            l[w] += p[e];
        }
        fill(begin(h), end(h), 0);
        h[s] = l[s];
        for (auto e : edges) {
            auto [w, v] = edge[e].node;
            p[e] = min(FlowSum(p[e]), h[w]);
            h[w] -= p[e];
            h[v] += p[e];
            edge[e].flow += p[e];
            edge[e ^ 1].flow -= p[e];
        }
        return h[t];
    }

    FlowSum maxflow(int s, int t) {
        h.assign(V, 0);
        l.assign(V, 0);
        p.assign(E, 0);
        Q.resize(V);
        FlowSum max_flow = 0, df;
        while (bfs(s, t)) {
            do {
                df = tide(s, t);
                max_flow += df;
            } while (df > 0);
        }
        return max_flow;
    }

    void clear_flow() {
        for (int e = 0; e < E; e++) {
            edge[e].flow = 0;
        }
    }
    Flow get_flow(int e) const { return edge[2 * e].flow; }
    bool left_of_mincut(int u) const { return level[u] >= 0; }
};

template <typename Solver>
auto decompose_dag_flow_matching(Solver& mf, int s, int t) {
    int V = mf.V;
    vector<int> reach = {s}, indeg(V);
    for (int i = 0, R = 1; i < R; i++) {
        for (int e : mf.res[reach[i]]) {
            if (int v = mf.edge[e].node[1]; !(e & 1) && mf.edge[e].flow && v != s) {
                if (v != t && indeg[v]++ == 0) {
                    reach.push_back(v), R++;
                }
            }
        }
    }
    vector<vector<array<int, 2>>> edgepaths(V);
    vector<int> bfs = {s};
    for (int i = 0, B = 1; i < B; i++) {
        int u = bfs[i];
        for (int e : mf.res[u]) {
            if (int v = mf.edge[e].node[1]; !(e & 1) && mf.edge[e].flow && v != s) {
                int k = mf.edge[e].flow;
                while (k--) {
                    if (u == s) {
                        edgepaths[v].push_back({e / 2, -1});
                    } else {
                        int f = edgepaths[u].back()[0];
                        edgepaths[u].pop_back();
                        edgepaths[v].push_back({f, e / 2});
                    }
                }
                if (v != t && --indeg[v] == 0) {
                    bfs.push_back(v), B++;
                }
            }
        }
    }
    return edgepaths[t];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> tree(N);
    map<array<int, 2>, int> edgemap;
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
        edgemap[{u, v}] = edgemap[{v, u}] = i;
    }

    hld_forest hld(tree, 0);
    vector<int> who(N, -1);
    for (int u = 1; u < N; u++) {
        int v = hld.parent[u];
        who[hld.time[u]] = edgemap.at({u, v});
    }

    int s = 4 * N + M + 1, t = s + 1;
    tidal_flow<int> tf(4 * N + M + 3);
    map<int, int> edgeid, dudeid;

    rec([&](auto self, int i, int l, int r) -> void {
        if (l + 1 < r) {
            int a = i << 1, b = i << 1 | 1, m = (l + r) / 2;
            tf.add(M + i, M + a, m - l);
            tf.add(M + i, M + b, r - m);
            self(a, l, m);
            self(b, m, r);
        } else {
            edgeid[tf.add(M + i, t, 1)] = l;
        }
    })(1, 1, N);

    auto insert = rec([&](auto self, int i, int l, int r, int L, int R, int c) -> void {
        if (r <= L || R <= l) {
            return;
        }
        if (L <= l && r <= R) {
            tf.add(c, M + i, 1);
            return;
        }
        int a = i << 1, b = i << 1 | 1, m = (l + r) / 2;
        self(a, l, m, L, R, c);
        self(b, m, r, L, R, c);
    });

    vector<array<int, 2>> cits(M);

    for (int i = 0; i < M; i++) {
        auto& [u, v] = cits[i];
        cin >> u >> v, u--, v--;
        for (auto [l, r] : hld.edge_segments(u, v)) {
            insert(1, 1, N, l, r, i);
        }
        dudeid[tf.add(s, i, 1)] = i;
    }

    int m = tf.maxflow(s, t);
    cout << m << '\n';

    auto edgepaths = decompose_dag_flow_matching(tf, s, t);
    vector<int> mu(M, -1), mv(N, -1);
    for (auto [u, v] : edgepaths) {
        u = dudeid.at(u), v = edgeid.at(v);
        mu[u] = v, mv[v] = u;
    }

    set<int> lopen, ropen;
    for (int i = 0; i < M; i++) {
        lopen.insert(end(lopen), i);
    }
    for (int e = 1; e < N; e++) {
        ropen.insert(end(ropen), e);
    }
    vector<int> A, B;

    auto dfs = rec([&](auto self, int u) -> void {
        lopen.erase(u);
        auto [a, b] = cits[u];
        for (auto [l, r] : hld.edge_segments(a, b)) {
            auto it = ropen.lower_bound(l);
            while (it != end(ropen) && *it < r) {
                if (int v = *it; v == mu[u]) {
                    l = mu[u] + 1;
                } else {
                    ropen.erase(it);
                    B.push_back(v);
                    if (mv[v] != -1) {
                        self(mv[v]);
                    }
                }
                it = ropen.lower_bound(l);
            }
        }
    });

    for (int u = 0; u < M; u++) {
        if (lopen.count(u) && mu[u] == -1) {
            dfs(u);
        }
    }
    for (int u = 0; u < M; u++) {
        if (lopen.count(u)) {
            A.push_back(u);
        }
    }

    int as = A.size(), bs = B.size();

    cout << as << " \n"[as == 0];
    for (int i = 0; i < as; i++) {
        cout << A[i] + 1 << " \n"[i + 1 == as];
    }
    cout << bs << " \n"[bs == 0];
    for (int i = 0; i < bs; i++) {
        cout << who[B[i]] << " \n"[i + 1 == bs];
    }
    return 0;
}