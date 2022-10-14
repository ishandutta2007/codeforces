#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct twosat_scc {
    int N, C = 0; // N is the number of variables, C number of components
    vector<array<int, 2>> g;
    vector<int> off, assignment, cmap;

    explicit twosat_scc(int N = 0) : N(N) {}

    int add_var() { return N++; }

    void either(int u, int v) {
        u = u < 0 ? 2 * ~u : 2 * u + 1;
        v = v < 0 ? 2 * ~v : 2 * v + 1;
        assert(0 <= u && u < 2 * N && 0 <= v && v < 2 * N);
        g.push_back({u ^ 1, v});
        g.push_back({v ^ 1, u});
    }

    void equal(int u, int v) { either(u, ~v), either(~u, v); }
    void opposite(int u, int v) { either(u, v), either(~u, ~v); }
    void implies(int u, int v) { either(~u, v); }
    void set(int u) { either(u, u); }

    void at_most_one(const vector<int>& vars) {
        int V = vars.size();
        if (V <= 1) {
            return;
        }
        int cur = ~vars[0];
        for (int i = 2; i < V; i++) {
            int next = add_var();
            either(cur, ~vars[i]);
            either(cur, next);
            either(~vars[i], next);
            cur = ~next;
        }
        either(cur, ~vars[1]);
    }

    vector<int> index, lowlink;
    vector<bool> onstack;
    stack<int> S;
    int depth;

    void dfs(int u) {
        index[u] = lowlink[u] = depth++;
        S.push(u), onstack[u] = true;

        for (int e = off[u]; e < off[u + 1]; e++) {
            int v = g[e][1];
            if (!index[v]) {
                dfs(v);
                lowlink[u] = min(lowlink[u], lowlink[v]);
            } else if (onstack[v]) {
                lowlink[u] = min(lowlink[u], index[v]);
            }
        }

        if (index[u] == lowlink[u]) {
            int v, c = C++;
            do {
                v = S.top(), S.pop(), onstack[v] = false;
                cmap[v] = c;
                if (assignment[v >> 1] == -1)
                    assignment[v >> 1] = v & 1;
            } while (u != v);
        }
    }

    bool solve() {
        assignment.assign(N, -1);
        cmap.assign(2 * N, 0);
        index.assign(2 * N, 0);
        lowlink.assign(2 * N, 0);
        onstack.assign(2 * N, false);
        off.assign(2 * N + 1, 0);
        S = stack<int>();
        depth = 1, C = 0;

        sort(begin(g), end(g));

        for (auto [u, v] : g) {
            off[u + 1]++;
        }
        for (int u = 1; u <= 2 * N; u++) {
            off[u] += off[u - 1];
        }
        for (int u = 0; u < 2 * N; u++) {
            if (!index[u]) {
                dfs(u);
            }
        }
        for (int u = 0; u < N; u++) {
            assert(assignment[u] >= 0);
            if (cmap[2 * u] == cmap[2 * u + 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<array<int, 4>> roads(M);
    vector<vector<int>> adj(N), kill(N);
    vector<int> times = {0};
    for (int i = 0; i < M; i++) {
        auto& [t, c, u, v] = roads[i];
        cin >> u >> v >> c >> t, u--, v--, c--;
        adj[u].push_back(i);
        adj[v].push_back(i);
        kill[u].push_back(~i);
        kill[v].push_back(~i);
        times.push_back(t);
    }
    for (int u = 0; u < N; u++) {
        sort(begin(adj[u]), end(adj[u]), [&](int i, int j) {
            return make_pair(roads[i][1], -roads[i][0]) <
                   make_pair(roads[j][1], -roads[j][0]);
        });
    }
    sort(begin(times), end(times));
    times.erase(unique(begin(times), end(times)), end(times));
    int T = times.size();

    twosat_scc base(M);
    for (int u = 0; u < N; u++) {
        base.at_most_one(kill[u]);
    }
    for (int u = 0; u < N; u++) {
        int A = adj[u].size();
        for (int l = 0, r = 1; l < A; l = r++) {
            while (r < A && roads[adj[u][l]][1] == roads[adj[u][r]][1])
                r++;
            if (r - l > 1) {
                vector<int> edges(begin(adj[u]) + l, begin(adj[u]) + r);
                base.at_most_one(edges);
            }
        }
    }
    if (!base.solve()) {
        cout << "No\n";
        return 0;
    }

    auto build = [&](int x) {
        twosat_scc sat = base;
        for (int e = 0; e < M; e++) {
            auto [t, c, u, v] = roads[e];
            if (t > times[x]) {
                sat.set(e);
            }
        }
        return sat;
    };

    int L = -1, R = T;
    while (L + 1 < R) {
        int x = (L + R) / 2;
        auto sat = build(x);
        sat.solve() ? R = x : L = x;
    }

    auto sat = build(R);
    sat.solve();

    vector<int> edges;
    for (int e = 0; e < M; e++) {
        if (sat.assignment[e] == 0) {
            edges.push_back(e);
        }
    }
    int K = edges.size();

    cout << "Yes\n";
    cout << times[R] << ' ' << K << '\n';
    for (int i = 0; i < K; i++) {
        cout << edges[i] + 1 << " \n"[i + 1 == K];
    }
    return 0;
}