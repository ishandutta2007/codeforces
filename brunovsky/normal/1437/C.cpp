#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

inline namespace {

template <typename Compare = less<>>
struct pairing_int_heap {
    struct node_t {
        int parent = 0, child = 0, next = 0, prev = 0;
    };
    vector<node_t> node;
    int root = 0;
    Compare comp;

    explicit pairing_int_heap(int N = 0, const Compare& comp = Compare())
        : node(N + 1), comp(comp) {}

    bool empty() const { return root == 0; }
    bool contains(int u) const { return u++, node[u].parent != 0; }
    int top() const { return root - 1; }

    void push(int u) {
        assert(!contains(u)), u++;
        node[u].parent = -1;
        root = empty() ? u : meld(root, u);
    }
    int pop() {
        assert(!empty());
        int u = root;
        root = two_pass_pairing(u);
        node[u] = node_t();
        return u - 1;
    }
    void improve(int u) {
        assert(!empty() && contains(u)), u++;
        if (u != root && do_comp(u, node[u].parent)) {
            take(u), root = meld(root, u);
        }
    }
    void push_or_improve(int u) { contains(u) ? improve(u) : push(u); }

    void clear() {
        if (!empty()) {
            clear_dive(root), root = 0;
        }
    }

  private:
    bool do_comp(int u, int v) const { return comp(u - 1, v - 1); }
    int meld(int u, int v) { return do_comp(u, v) ? splice(u, v) : splice(v, u); }
    int splice(int u, int v) {
        node[node[u].child].prev = v;
        node[v].next = node[u].child, node[u].child = v;
        return node[v].prev = node[v].parent = u;
    }
    void take(int u) {
        assert(node[u].parent > 0);
        if (node[node[u].parent].child == u)
            node[node[u].parent].child = node[u].next;
        else
            node[node[u].prev].next = node[u].next;
        node[node[u].next].prev = node[u].prev;
    }
    int two_pass_pairing(int n) {
        if (node[n].child == 0)
            return 0;
        int u = node[n].child, v = node[u].next, w;
        while (v && node[v].next) {
            w = node[node[v].next].next;
            u = node[u].next = v = meld(v, node[v].next);
            v = node[v].next = w;
        }
        u = node[n].child, v = node[u].next;
        while (v) {
            w = node[v].next, u = meld(u, v), v = w;
        }
        return u;
    }
    void clear_dive(int u) {
        for (int v = node[u].child; v; v = node[v].next)
            clear_dive(v);
        node[u] = node_t();
    }
};

template <typename Container>
struct less_container {
    const Container& cont;
    less_container(const Container& cont) : cont(cont) {}
    inline bool operator()(int u, int v) const { return cont[u] < cont[v]; }
};

template <typename Cost = long, typename CostSum = Cost>
struct mincost_hungarian {
    using edges_t = vector<array<int, 2>>;
    int U = 0, V = 0, W = 0, E = 0;
    vector<vector<pair<int, Cost>>> adj;
    vector<int> m[2];

    mincost_hungarian() = default;
    mincost_hungarian(int U, int V, const edges_t& g = {}, const vector<Cost>& cost = {})
        : U(U), V(V), W(max(U, V)), adj(W) {
        for (int e = 0, n = g.size(); e < n; e++) {
            auto [u, v] = g[e];
            add(u, v, cost[e]);
        }
        for (int v = V; v < U; v++) // edges if padding V side
            for (int u = 0; u < U; u++)
                adj[u].push_back({v, cost_inf}), E++;
        for (int u = U; u < V; u++) // edges if padding U side
            for (int v = 0; v < V; v++)
                adj[u].push_back({v, cost_inf}), E++;
    }

    void add(int u, int v, long w) {
        assert(0 <= u && u < U && 0 <= v && v < V && w >= 0);
        adj[u].push_back({v, w});
    }

    vector<int> prev[2];
    vector<CostSum> pi[2], dist[2];
    static inline constexpr Cost cost_inf = numeric_limits<Cost>::max() / 3;
    static inline constexpr CostSum inf = numeric_limits<CostSum>::max() / 3;

    bool dijkstra() {
        dist[0].assign(W + 1, inf);
        dist[1].assign(W, inf);
        prev[0].assign(W + 1, -1);
        prev[1].assign(W, -1);

        vector<bool> vis(W, false);
        pairing_int_heap<less_container<vector<CostSum>>> Q(W + 1, dist[0]);

        for (int u = 0; u < W; u++)
            if (m[0][u] == W)
                dist[0][u] = 0, Q.push(u);

        while (!Q.empty()) {
            int u = Q.pop();
            if (u == W || vis[u]) {
                continue;
            }
            vis[u] = true;
            for (auto [v, w] : adj[u]) {
                int y = m[1][v];
                w = min(dist[0][u] + w + pi[0][u] - pi[1][v], inf);
                if (dist[0][y] > w) {
                    dist[0][y] = w, prev[0][y] = v;
                    Q.push_or_improve(y);
                }
                if (dist[1][v] > w) {
                    dist[1][v] = w, prev[1][v] = u;
                }
            }
        }
        reprice();
        return prev[0][W] != -1;
    }

    void reprice() {
        for (int i : {0, 1}) {
            for (int u = 0; u < W; u++) {
                pi[i][u] = min(dist[i][u] + pi[i][u], inf);
            }
        }
    }

    auto path() const {
        edges_t nodes;
        int v = prev[0][W];
        while (v != -1) {
            nodes.push_back({prev[1][v], v});
            v = prev[0][prev[1][v]];
        }
        return nodes;
    }

    auto mincost_max_matching() {
        m[0].assign(W, W);
        m[1].assign(W, W);
        pi[0].assign(W, 0);
        pi[1].assign(W, 0);

        int matchings = 0;
        while (matchings < W && dijkstra()) {
            for (auto [u, v] : path()) {
                m[0][u] = v, m[1][v] = u;
            }
            matchings++;
        }
        if (matchings < W)
            return -1;

        CostSum min_cost = 0;
        for (int u = 0; u < U; u++) {
            if (int v = m[0][u]; v < V) {
                for (auto [t, w] : adj[u]) {
                    if (v == t) {
                        min_cost += w;
                        break;
                    }
                }
            }
        }
        return min_cost;
    }
};

} // namespace

auto solve() {
    int U, V;
    cin >> V;
    vector<int> t(V);
    for (int i = 0; i < V; i++) {
        cin >> t[i], t[i]--;
    }
    U = 2 * V;
    mincost_hungarian<int> g(U, V);
    for (int u = 0; u < U; u++) {
        for (int v = 0; v < V; v++) {
            g.add(u, v, abs(u - t[v]));
        }
    }
    return g.mincost_max_matching();
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}