#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

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

template <typename Flow = int64_t, typename FlowSum = Flow>
struct circulation {
    using MaxflowSolver = tidal_flow<Flow, FlowSum>;

    explicit circulation(int V = 0) : V(V), supply(V) {}

    int add(int u, int v, Flow lower, Flow upper) {
        assert(0 <= u && u < V && 0 <= v && v < V && lower <= upper);
        return edges.push_back({u, v, lower, upper}), E++;
    }
    int add_node() { return supply.push_back(0), V++; }

    void update_edge(int e, Flow lower, Flow upper) {
        edges[e] = {edges[e].u, edges[e].v, lower, upper};
    }

    void add_supply(int u, FlowSum supply) { this->supply[u] += supply; }
    void add_demand(int u, FlowSum demand) { this->supply[u] -= demand; }
    void set_supply(int u, FlowSum supply) { this->supply[u] = supply; }
    auto get_flow(int e) const { return mf.get_flow(e) + edges[e].lower; }

    // Run for feasibility: return true if a feasible circulation exists
    auto feasible_circulation() {
        mf = MaxflowSolver(V + 2);
        int s = V, t = V + 1;

        vector<FlowSum> excess = supply;
        FlowSum pos = 0, neg = 0;

        for (auto [u, v, lower, upper] : edges) {
            excess[u] -= lower;
            excess[v] += lower;
            mf.add(u, v, upper - lower);
        }
        for (int u = 0; u < V; u++) {
            if (excess[u] > 0) {
                mf.add(s, u, excess[u]);
                pos += excess[u];
            } else if (excess[u] < 0) {
                mf.add(u, t, -excess[u]);
                neg -= excess[u];
            }
        }

        auto f = mf.maxflow(s, t);
        return make_pair(f == pos && f == neg, f);
    }

    // Run for maximum circulation value: return maxflow on given edge
    auto max_circulation(int me) {
        mf = MaxflowSolver(V + 2);
        int s = V, t = V + 1, a = edges[me].v, b = edges[me].u;

        vector<FlowSum> excess = supply;
        FlowSum source = 0, target = 0;

        for (int e = 0; e < E; e++) {
            auto [u, v, lower, upper] = edges[e];
            excess[u] -= lower;
            excess[v] += lower;
            mf.add(u, v, upper - lower);
        }
        for (int u = 0; u < V; u++) {
            if (excess[u] > 0) {
                mf.add(s, u, excess[u]);
                source += excess[u];
            } else if (excess[u] < 0) {
                mf.add(u, t, -excess[u]);
                target -= excess[u];
            }
        }

        auto F = mf.maxflow(s, t);
        if (F < min(source, target)) {
            return make_pair(false, FlowSum(0));
        }

        return make_pair(true, mf.maxflow(a, b));
    }

  private:
    int V, E = 0;
    struct Edge {
        int u, v;
        Flow lower, upper;
    };
    vector<Edge> edges;
    vector<FlowSum> supply;
    MaxflowSolver mf;
};

auto compress(vector<int>& v) {
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M, R, B;
    cin >> N >> M >> R >> B;
    // if R<=B, maximize #reds, else #blues
    vector<array<int, 2>> pts(N);
    vector<int> xs, ys;
    for (auto& [x, y] : pts) {
        cin >> x >> y;
        xs.push_back(x);
        ys.push_back(y);
    }
    compress(xs);
    compress(ys);
    int X = xs.size();
    int Y = ys.size();
    vector<int> xc(X), yc(Y);
    for (auto& [x, y] : pts) {
        x = lower_bound(begin(xs), end(xs), x) - begin(xs);
        y = lower_bound(begin(ys), end(ys), y) - begin(ys);
        xc[x]++, yc[y]++;
    }

    int s = X + Y, t = s + 1;
    circulation<int> circ(X + Y + 2);

    for (auto [x, y] : pts) {
        circ.add(x, y + X, 0, 1);
    }

    vector<int> xb = xc, yb = yc;

    while (M--) {
        int t, l, d;
        cin >> t >> l >> d;
        if (t == 1) {
            int x = lower_bound(begin(xs), end(xs), l) - begin(xs);
            if (x >= X || xs[x] != l) {
                continue;
            }
            xb[x] = min(xb[x], d);
        } else if (t == 2) {
            int y = lower_bound(begin(ys), end(ys), l) - begin(ys);
            if (y >= Y || ys[y] != l) {
                continue;
            }
            yb[y] = min(yb[y], d);
        } else {
            assert(false);
        }
    }

    for (int x = 0; x < X; x++) {
        int a = max(0, (xc[x] - xb[x] + 1) / 2);
        int b = min(xc[x], (xc[x] + xb[x]) / 2);
        if (a > b) {
            cout << -1 << '\n';
            return 0;
        }
        circ.add(s, x, a, b);
    }
    for (int y = 0; y < Y; y++) {
        int a = max(0, (yc[y] - yb[y] + 1) / 2);
        int b = min(yc[y], (yc[y] + yb[y]) / 2);
        if (a > b) {
            cout << -1 << '\n';
            return 0;
        }
        circ.add(y + X, t, a, b);
    }

    int e = circ.add(t, s, 0, N);

    auto [ok, mf] = circ.max_circulation(e);
    if (!ok) {
        cout << -1 << '\n';
        return 0;
    }

    char cheap = R <= B ? 'r' : 'b';
    char large = R <= B ? 'b' : 'r';
    string ans(N, large);
    for (int e = 0; e < N; e++) {
        if (circ.get_flow(e)) {
            ans[e] = cheap;
        }
    }

    cout << 1LL * mf * min(R, B) + 1LL * (N - mf) * max(R, B) << '\n';
    cout << ans << '\n';
    return 0;
}