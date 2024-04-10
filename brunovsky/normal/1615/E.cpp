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

int64_t ccost(int r, int b, int N) {
    int w = N - b - r;
    return 1LL * w * (r - b);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, K;
    cin >> N >> K;

    vector<vector<int>> tree(N + 1);
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> parent(N + 1), depth(N + 1);

    y_combinator([&](auto self, int u, int p) -> void {
        parent[u] = p;
        depth[u] = depth[p] + 1;
        for (int v : tree[u]) {
            if (v != p) {
                self(v, u);
            }
        }
    })(1, 0);

    vector<int> bfs(N), colored(N + 1), weight(N + 1);
    iota(begin(bfs), end(bfs), 1);
    sort(begin(bfs), end(bfs), [&](int u, int v) { return depth[u] > depth[v]; });

    for (int u : bfs) {
        int v = u;
        while (v && !colored[v]) {
            colored[v] = 1, weight[u]++;
            v = parent[v];
        }
    }

    sort(begin(bfs), end(bfs), [&](int u, int v) { return weight[u] > weight[v]; });
    fill(begin(colored), end(colored), 0);

    int64_t ans = ccost(0, N / 2, N);
    int blues = N;

    for (int i = 0; i < K; i++) {
        int u = bfs[i], v = u;
        while (v && !colored[v]) {
            colored[v] = 1, blues--;
            v = parent[v];
        }
        ans = max(ans, ccost(i + 1, min(blues, N / 2), N));
    }

    cout << ans << '\n';
    return 0;
}

// Can red make positive score?
// You color up from the leaves red
// The rootpaths become white
// Everything else becomes blue
// Maximize w(r-b). Maybe compute r-b for every w?
// Or compute w(r-b) for every r that's probably better
// For every red you add on a blue cell you increase w and decrease b
// For every red you add on a white cell you decrease w (by 1) and don't change b