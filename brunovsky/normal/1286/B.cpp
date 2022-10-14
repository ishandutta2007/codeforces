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
    vector<int> parent(N + 1);
    vector<vector<int>> children(N + 1);
    vector<int> c(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> parent[i] >> c[i];
        children[parent[i]].push_back(i);
    }
    int root = children[0][0];

    vector<int> subtree(N + 1);
    y_combinator([&](auto self, int u) -> void {
        subtree[u] = 1;
        for (int v : children[u]) {
            self(v);
            subtree[u] += subtree[v];
        }
    })(root);
    for (int i = 1; i <= N; i++) {
        subtree[i] -= c[i] + 1;
    }

    vector<bool> vis(N + 1);
    vector<int> val(N + 1);
    int count_visited = 0;
    int current_value = N;

    auto dfs = y_combinator([&](auto self, int u) -> int {
        if (subtree[u] == 0 && !vis[u]) {
            vis[u] = true;
            val[u] = current_value;
            return 1;
        } else {
            for (int v : children[u]) {
                if (self(v)) {
                    subtree[u]--;
                    return 1;
                }
            }
            return 0;
        }
    });

    while (count_visited < N) {
        int increment = dfs(root);
        if (increment == 0) {
            break;
        } else {
            count_visited += increment;
            current_value--;
        }
    }

    if (count_visited == N) {
        cout << "YES\n";
        for (int i = 1; i <= N; i++) {
            cout << val[i] << " \n"[i == N];
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}