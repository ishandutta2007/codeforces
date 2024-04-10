#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

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

auto build_euler_tour_tree_index(const vector<vector<int>>& tree, int root) {
    int V = tree.size();
    vector<array<int, 2>> index(V);
    int timer = 0;

    auto dfs = y_combinator([&](auto self, int u, int p) -> void {
        index[u][0] = timer++;
        for (int v : tree[u]) {
            if (v != p) {
                self(v, u);
            }
        }
        index[u][1] = timer++;
    });

    dfs(root, -1);
    return index;
}

auto solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    vector<vector<int>> atree(N), btree(N);
    for (int u = 1; u < N; u++) {
        cin >> A[u], A[u]--;
        atree[A[u]].push_back(u);
    }
    for (int u = 1; u < N; u++) {
        cin >> B[u], B[u]--;
        btree[B[u]].push_back(u);
    }

    auto index = build_euler_tour_tree_index(btree, 0);
    int ans = 1;
    set<array<int, 2>> leaves;

    auto dfs = y_combinator([&](auto self, int u) -> void {
        auto it = leaves.lower_bound(index[u]);
        bool has_child = false, has_parent = false;
        array<int, 2> parent;
        if (it != leaves.end()) {
            auto [lo, hi] = *it;
            if (index[u][0] < lo && hi < index[u][1]) {
                has_child = true;
            }
        }
        if (!has_child && it != leaves.begin()) {
            auto [lo, hi] = parent = *prev(it);
            if (lo < index[u][0] && index[u][1] < hi) {
                has_parent = true;
                leaves.erase(parent);
            }
        }
        if (!has_child) {
            leaves.insert(index[u]);
        }
        ans = max(ans, int(leaves.size()));
        for (int v : atree[u]) {
            self(v);
        }
        leaves.erase(index[u]);
        if (has_parent) {
            leaves.insert(parent);
        }
    });
    dfs(0);

    return ans;
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