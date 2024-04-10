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
    int N;
    cin >> N;
    vector<int> lodge(N);
    for (int i = 0; i < N; i++) {
        cin >> lodge[i];
    }

    vector<vector<int>> tree(N);
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> height(N, -1);
    vector<int> bfs, lodges;
    for (int u = 0; u < N; u++) {
        if (lodge[u]) {
            bfs.push_back(u);
            lodges.push_back(u);
            height[u] = 0;
        }
    }
    for (int i = 0, B = bfs.size(); i < B; i++) {
        int u = bfs[i];
        for (int v : tree[u]) {
            if (height[v] < 0) {
                height[v] = height[u] + 1;
                bfs.push_back(v), B++;
            }
        }
    }

    vector<vector<int>> down(N), same(N);
    for (int u = 0; u < N; u++) {
        for (int v : tree[u]) {
            if (height[v] < height[u]) {
                down[u].push_back(v);
            } else if (height[v] == height[u]) {
                same[u].push_back(v);
            }
        }
    }

    vector<int> spam(N, N);
    for (int u = 0; u < N; u++) {
        spam[u] = same[u].empty() ? N : height[u];
    }
    for (int u : bfs) {
        for (int v : down[u]) {
            spam[u] = min(spam[u], spam[v]);
        }
    }

    int H = 1 + *max_element(begin(height), end(height));
    vector<vector<int>> at_height(H);
    for (int u = 0; u < N; u++) {
        at_height[height[u]].push_back(u);
    }

    vector<vector<pair<int, int>>> spots(N);
    for (int u : lodges) {
        if (spam[u] == 0) {
            spots[u].emplace_back(1, 0);
        }
    }

    vector<int> visited(N);
    int counter = 1;

    vector<int> ans = height;
    for (int h = 1; h < H; h++) {
        for (int s : at_height[h]) {
            if (visited[s]) {
                continue;
            }

            vector<int> nodes;
            y_combinator([&](auto self, int u, int p) -> void {
                nodes.push_back(u);
                for (int v : same[u]) {
                    if (v != p) {
                        self(v, u);
                    }
                }
            })(s, -1);
            int V = nodes.size();

            vector<array<int, 3>> exits;
            for (int u : nodes) {
                for (int v : down[u]) {
                    for (auto [c, x] : spots[v]) {
                        exits.push_back({x, c, u});
                        if (c <= 1) {
                            ans[u] = max(ans[u], 2 * height[u] - x);
                        }
                    }
                }
            }
            sort(begin(exits), end(exits));

            for (int l = 0, r = 1, E = exits.size(); l < E; l = r++) {
                int x = exits[l][0];
                counter++;
                while (r < E && exits[r][0] == x) {
                    r++;
                }

                int B = 0;
                int D = exits[l][1];
                vector<int> layer;

                while (B < V) {
                    vector<int> next_layer;
                    while (l < r && exits[l][1] == D) {
                        if (int v = exits[l++][2]; visited[v] < counter) {
                            visited[v] = counter;
                            next_layer.push_back(v), B++;
                            spots[v].push_back({max(D - 1, 1), x});
                        }
                    }
                    for (int u : layer) {
                        for (int v : same[u]) {
                            if (visited[v] < counter) {
                                visited[v] = counter;
                                next_layer.push_back(v), B++;
                                spots[v].push_back({max(D - 1, 1), x});
                            }
                        }
                    }
                    swap(layer, next_layer);
                    D++;
                }
            }

            for (int u : nodes) {
                vector<pair<int, int>> filtered;
                for (auto [c, x] : spots[u]) {
                    if (filtered.empty() || c < filtered.back().first) {
                        assert(filtered.empty() || x > filtered.back().second);
                        filtered.push_back({c, x});
                    }
                }
                swap(filtered, spots[u]);
                if (V > 1) {
                    spots[u].push_back({1, h});
                }
                visited[u] = true;
            }
        }
    }

    for (int u = 0; u < N; u++) {
        cout << ans[u] << " \n"[u + 1 == N];
    }

    return 0;
}

// A connected component at height H will have at most N/H elements
// So you can amortize the processing cost down the size of the subtree
// You do dfs on the same component I guess?