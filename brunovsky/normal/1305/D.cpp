#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto QUERY(int u, int v) {
    cout << "? " << u + 1 << ' ' << v + 1 << endl;
    int w;
    cin >> w;
    if (w == -1) {
        exit(0);
    }
    return w - 1;
}

auto ANSWER(int w) {
    cout << "! " << w + 1 << endl;
    exit(0);
}

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
    // Pick two leaves that are not connected by an edge
    vector<set<int>> tree(N);
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        tree[u].insert(v);
        tree[v].insert(u);
    }
    vector<int> deg(N), live(N, 1);
    for (int u = 0; u < N; u++) {
        deg[u] = tree[u].size();
    }
    int conn = -1;
    auto kill = y_combinator([&](auto self, int u, int p) -> void {
        live[u] = false;
        for (int v : tree[u]) {
            if (live[v]) {
                if (v != p) {
                    self(v, p);
                } else {
                    conn = v;
                }
            }
        }
    });
    while (count(begin(live), end(live), 1) > 1) {
        vector<int> leaves;
        for (int u = 0; u < N; u++) {
            if (live[u] && deg[u] == 1) {
                leaves.push_back(u);
            }
        }
        int S = leaves.size();
        int u = leaves[0];
        int x = *tree[u].begin();
        int v = S == 2 ? leaves[1] : (x == leaves[1] ? leaves[2] : leaves[1]);
        int w = QUERY(u, v);
        assert(live[w]);
        if (u == w) {
            kill(v, u);
            deg[u]--, tree[u].erase(conn);
        } else if (v == w) {
            kill(u, v);
            deg[v]--, tree[v].erase(conn);
        } else {
            kill(u, w);
            deg[w]--, tree[w].erase(conn);
            kill(v, w);
            deg[w]--, tree[w].erase(conn);
        }
    }
    int u = find(begin(live), end(live), 1) - begin(live);
    ANSWER(u);
    return 0;
}