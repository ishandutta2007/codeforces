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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;

    vector<set<pair<int, int>>> G[3];
    G[1].assign(N, {}), G[2].assign(N, {});

    vector<array<int, 2>> graph(2 * M);
    vector<int> parent(2 * M, -1), mask(2 * M), sum(N);
    int E = M;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w, u--, v--;
        graph[i] = {u, v};
        if (u != v) {
            G[w][u].emplace(i, v);
            G[w][v].emplace(i, u);
            sum[u] += w;
            sum[v] += w;
        }
    }

    int count = 0;
    for (int u = 0; u < N; u++) {
        count += sum[u] % 2 == 1;
    }

    for (int u = 0; u < N; u++) {
        for (int w : {1, 2}) {
            while (G[w][u].size() > 1u) {
                auto [i, a] = *G[w][u].begin();
                G[w][u].erase({i, a}), G[w][a].erase({i, u});
                auto [j, b] = *G[w][u].begin();
                G[w][u].erase({j, b}), G[w][b].erase({j, u});
                int e = E++;
                parent[i] = parent[j] = e;
                mask[i] = graph[i][0] != a || graph[i][1] != u;
                mask[j] = graph[j][0] != u || graph[j][1] != b;
                graph[e] = {a, b};
                G[w][a].emplace(e, b);
                G[w][b].emplace(e, a);
            }
        }
    }

    for (int u = 0; u < N; u++) {
        for (int w : {1, 2}) {
            if (G[w][u].size() && G[w][u].begin()->second == u) {
                G[w][u].clear();
            }
        }
    }

    string ans(E, '1');

    auto fix_trail = [&](int s, int u) {
        vector<int> trail, nodes = {u};
        int v = u, w = s;
        do {
            auto [i, x] = *G[w][v].begin();
            G[w][v].clear();
            G[w][x].clear();
            trail.push_back(i);
            nodes.push_back(x);
            w = 3 - w, v = x;
        } while (G[w][v].size());

        int S = trail.size();
        for (int i = 0; i < S; i++) {
            int x = nodes[i];
            int y = nodes[i + 1];
            int e = trail[i];
            auto& [a, b] = graph[e];
            ans[e] = a == x && b == y ? '1' : '2';
        }
    };

    for (int u = 0; u < N; u++) {
        for (int s : {1, 2}) {
            if (G[s][u].size() && G[3 - s][u].empty()) {
                fix_trail(s, u);
            }
        }
    }

    for (int u = 0; u < N; u++) {
        for (int s : {1, 2}) {
            if (G[s][u].size() && G[3 - s][u].size()) {
                fix_trail(s, u);
            }
        }
    }

    for (int e = E - 1; e >= 0; e--) {
        if (int f = parent[e]; f != -1) {
            ans[e] = mask[e] ? '1' + '2' - ans[f] : ans[f];
        }
    }
    ans.resize(M);
    cout << count << '\n';
    cout << ans << '\n';
    return 0;
}

// It's always possible so you just need to simplify progressively
// Eliminate weight 1 cycles
// Eliminate weight 2 cycles
//
// Eliminate weight 2 edges that close weight 1 paths