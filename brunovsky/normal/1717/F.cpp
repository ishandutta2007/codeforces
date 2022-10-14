#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename Flow = int64_t, typename FlowSum = Flow>
struct dinitz_flow {
    static inline default_random_engine rng = default_random_engine(random_device{}());
    struct Edge {
        int node[2];
        Flow cap, flow = 0;
    };
    int V, E = 0;
    vector<vector<int>> res;
    vector<Edge> edge;

    explicit dinitz_flow(int V = 0) : V(V), res(V) {}

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

    vector<int> level, Q, head_edge, next_edge;
    static constexpr Flow flowinf = numeric_limits<Flow>::max() / 2;

    bool bfs(int s, int t) {
        level.assign(V, -1);
        head_edge.assign(V, -1);
        next_edge.assign(E, -1);
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
                        next_edge[e] = head_edge[u], head_edge[u] = e;
                    }
                }
            }
        }
        return level[t] != -1;
    }

    auto dfs(int u, int t, Flow mincap) {
        if (u == t) {
            return mincap;
        }
        Flow preflow = 0;
        int& e = head_edge[u];
        while (e != -1 && mincap > 0) {
            int v = edge[e].node[1];
            if (Flow df = dfs(v, t, min(mincap, edge[e].cap - edge[e].flow))) {
                edge[e].flow += df;
                edge[e ^ 1].flow -= df;
                preflow += df;
                mincap -= df;
            }
            if (edge[e].flow == edge[e].cap || mincap > 0) {
                e = next_edge[e];
            }
        }
        return preflow;
    }

    FlowSum maxflow(int s, int t) {
        Q.resize(V);
        FlowSum max_flow = 0;
        while (bfs(s, t)) {
            max_flow += dfs(s, t, flowinf);
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
    using MaxflowSolver = dinitz_flow<Flow, FlowSum>;

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
        } else {
            return make_pair(true, mf.maxflow(a, b));
        }
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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> need(n), a(n);
    for (int i = 0; i < n; i++) {
        cin >> need[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<array<int, 2>> graph(m);
    for (auto& [u, v] : graph) {
        cin >> u >> v, u--, v--;
        assert(u != v);
    }
    vector<int> took(n);
    for (auto [u, v] : graph) {
        took[u]--, took[v]--;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (need[i]) {
            if (took[i] > a[i] || (a[i] - took[i]) % 2 == 1) {
                debug("Parity error", i);
                cout << "NO\n";
                return 0;
            } else {
                a[i] = (a[i] - took[i]) / 2;
                sum += a[i];
            }
        }
    }
    debug(n, m, sum, a);

    if (sum > m) {
        debug("Sum error");
        cout << "NO\n";
        return 0;
    }

    const int s = n + m, t = n + m + 1;
    circulation<int> solver(n + m + 2);
    vector<array<int, 2>> edges(m);

    for (int i = 0; i < m; i++) {
        auto [u, v] = graph[i];
        solver.add(s, i, 0, 1);
        int a = solver.add(i, m + u, 0, 1);
        int b = solver.add(i, m + v, 0, 1);
        edges[i] = {a, b};
    }

    vector<int> out(n);
    for (int i = 0; i < n; i++) {
        if (need[i]) {
            solver.add(m + i, t, a[i], a[i]);
        } else {
            solver.add(m + i, t, 0, m);
        }
    }

    solver.add_supply(s, m);
    solver.add_demand(t, m);

    if (!solver.feasible_circulation().first) {
        debug("Flow error");
        cout << "NO\n";
        return 0;
    }

    vector<int> b(n);

    cout << "YES\n";
    for (int i = 0; i < m; i++) {
        auto [x, y] = edges[i];
        auto [u, v] = graph[i];
        if (solver.get_flow(x)) {
            cout << v + 1 << ' ' << u + 1 << '\n';
            b[v]--, b[u]++;
        } else {
            cout << u + 1 << ' ' << v + 1 << '\n';
            b[u]--, b[v]++;
        }
    }

    debug(b);
    return 0;
}