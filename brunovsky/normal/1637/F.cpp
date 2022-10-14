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

struct Cell {
    int height, node, leaf;
    friend bool operator<(Cell a, Cell b) {
        return make_tuple(a.height, a.leaf) > make_tuple(b.height, b.leaf);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;

    vector<int> height(N);
    for (int i = 0; i < N; i++) {
        cin >> height[i];
    }

    vector<vector<int>> tree(N);
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int root = max_element(begin(height), end(height)) - begin(height);

    vector<set<Cell>> leaves(N);

    y_combinator([&](auto self, int u, int p) -> void {
        if (tree[u].size() == 1u) {
            leaves[u].insert({height[u], u, u});
        }
        for (int v : tree[u]) {
            if (v != p) {
                self(v, u);
                int h = max(leaves[v].begin()->height, height[v]);
                leaves[u].insert(Cell{h, v, leaves[v].begin()->leaf});
            }
        }
    })(root, -1);

    y_combinator([&](auto self, int u, int p) -> void {
        for (int v : tree[u]) {
            if (v != p) {
                int h = max(leaves[v].begin()->height, height[v]);
                Cell cell = {h, v, leaves[v].begin()->leaf};
                leaves[u].erase(cell);
                int me = max(leaves[u].begin()->height, height[u]);
                leaves[v].insert({me, u, leaves[u].begin()->leaf});
                leaves[u].insert(cell);
                self(v, u);
            }
        }
    })(root, -1);

    for (int u = 0; u < N; u++) {
        int a = leaves[u].begin()->leaf;
        int b = (++leaves[u].begin())->leaf;
        height[a] = max(height[a], height[u]);
        height[b] = max(height[b], height[u]);
    }

    int64_t ans = 0;
    for (int u = 0; u < N; u++) {
        if (tree[u].size() == 1u) {
            ans += height[u];
        }
    }
    cout << ans << '\n';
    return 0;
}