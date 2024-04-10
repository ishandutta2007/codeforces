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
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<set<int>> tree(N + 1);
        for (int i = 1; i < N; i++) {
            int u, v;
            cin >> u >> v;
            tree[u].insert(v);
            tree[v].insert(u);
        }
        vector<bool> leaf(N + 1);
        vector<bool> bud(N + 1);
        vector<int> parent(N + 1);
        vector<int> child(N + 1);
        vector<int> buds;

        y_combinator([&](auto self, int u, int p) -> void {
            parent[u] = p;
            leaf[u] = true;
            bud[u] = u != 1;
            vector<int> take;
            for (int v : tree[u]) {
                if (v != p) {
                    self(v, u);
                    if (bud[v]) {
                        take.push_back(v);
                    } else {
                        leaf[u] = false;
                        bud[u] = bud[u] && leaf[v];
                    }
                    if (leaf[v]) {
                        child[u] = v;
                    }
                }
            }
            for (int v : take) {
                tree[u].erase(v);
                tree[v].erase(u);
            }
            bud[u] = bud[u] && !leaf[u];
            if (bud[u]) {
                buds.push_back(u);
            }
        })(1, 0);

        int last = 1;
        for (int u = 2; u <= N; u++) {
            if (leaf[u] && !bud[parent[u]]) {
                last = u;
                break;
            }
        }
        debug(buds, last);
        for (int u : buds) {
            int p = parent[u];
            tree[p].erase(u);
            tree[u].erase(p);
            tree[u].insert(last);
            tree[last].insert(u);
            last = child[u];
            debug(u, last);
        }

        int L = 0;
        y_combinator([&](auto self, int u, int p) -> void {
            bool is = u != 1;
            for (int v : tree[u]) {
                if (v != p) {
                    self(v, u);
                    is = false;
                }
            }
            L += is;
        })(1, 0);
        cout << L << '\n';
    }
    return 0;
}