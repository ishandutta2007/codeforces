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

    explicit dinitz_flow(int V) : V(V), res(V) {}

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

auto max_weight_closure(const vector<array<int, 2>>& G, const vector<int>& weight) {
    using Solver = dinitz_flow<int64_t>;

    int N = weight.size();
    int s = N, t = N + 1;
    Solver mf(N + 2);

    int64_t positive = 0;

    for (int u = 0; u < N; u++) {
        if (weight[u] > 0) {
            mf.add(s, u, weight[u]);
            positive += weight[u];
        } else if (weight[u] < 0) {
            mf.add(u, t, -weight[u]);
        }
    }
    for (auto [u, v] : G) {
        mf.add(u, v, Solver::flowinf);
    }

    auto maxflow = mf.maxflow(s, t);
    return positive - maxflow;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;

    vector<array<int, 2>> G;
    vector<int> weight(N + M);

    for (int i = 0; i < N; i++) {
        cin >> weight[i], weight[i] = -weight[i];
    }
    for (int e = 0; e < M; e++) {
        int u, v;
        cin >> u >> v >> weight[N + e], u--, v--;
        G.push_back({N + e, u});
        G.push_back({N + e, v});
    }

    cout << max_weight_closure(G, weight) << '\n';
    return 0;
}