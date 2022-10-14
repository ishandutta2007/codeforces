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
        vector<int> b(N + 1);
        int root = -1, L = 0, R = N;
        for (int i = 1; i <= N; i++) {
            cin >> b[i];
            if (b[i] == 0) {
                assert(root != N + 1);
                root = 0;
                R = min(R, i - 1);
            } else if (b[i] == N + 1) {
                assert(root != 0);
                root = N + 1;
                L = max(L, i);
            } else if (b[i] < i) {
                L = max(L, b[i]);
                R = min(R, i - 1);
            } else if (b[i] > i) {
                L = max(L, i);
                R = min(R, b[i] - 1);
            } else {
                assert(false);
            }
        }
        debug(root, L, R);
        assert(L <= R);
        assert(root != -1);
        int K = L;

        vector<vector<int>> kids(N + 2);
        for (int i = 1; i <= N; i++) {
            kids[b[i]].push_back(i);
        }

        vector<int> depth(N + 2);
        y_combinator([&](auto self, int u) -> void {
            for (int v : kids[u]) {
                self(v);
                depth[u] = max(depth[u], depth[v] + 1);
            }
        })(root);

        vector<int> a;
        y_combinator([&](auto self, int u) -> void {
            sort(begin(kids[u]), end(kids[u]), [&](int x, int y) {
                return depth[x] < depth[y]; //
            });
            for (int v : kids[u]) {
                a.push_back(v);
                self(v);
            }
        })(root);

        cout << K << '\n';
        for (int i = 0; i < N; i++) {
            cout << a[i] << " \n"[i + 1 == N];
        }
    }
    return 0;
}