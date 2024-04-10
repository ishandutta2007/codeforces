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
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        vector<vector<int>> tree(N);
        for (int i = 1; i < N; i++) {
            int u, v;
            cin >> u >> v, u--, v--;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        int ans = N;

        for (int s : {1, 2}) {
            vector<int> bfs, other;
            for (int i = 0; i < N; i++) {
                if (tree[i].size() == 1u) {
                    if (a[i] == 0 || a[i] == s) {
                        bfs.push_back(i);
                    } else {
                        other.push_back(i);
                    }
                }
            }
            if (bfs.empty()) {
                continue;
            }

            vector<int> deg(N);
            for (int u = 0; u < N; u++) {
                deg[u] = tree[u].size();
            }
            for (int u : bfs) {
                deg[u] = 0;
            }
            for (int v : other) {
                deg[v] = 0;
            }
            int side = s;

            int D = 0;
            do {
                D++;
                for (int i = 0, B = bfs.size(); i < B; i++) {
                    int u = bfs[i];
                    for (int v : tree[u]) {
                        if (deg[v] && --deg[v] == 1) {
                            if (a[v] != 3 - side) {
                                bfs.push_back(v), B++;
                            } else {
                                other.push_back(v);
                            }
                        }
                    }
                }
                side = 3 - side;
                bfs.clear();
                swap(other, bfs);
            } while (bfs.size());

            ans = min(ans, D);
        }

        cout << ans << '\n';
    }
    return 0;
}