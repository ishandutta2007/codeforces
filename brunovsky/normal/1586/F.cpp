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
    int N, K;
    cin >> N >> K;

    // u->v  color[u][v]
    vector<vector<int>> color(N, vector<int>(N));
    vector<int> where(N);
    int C = 0;

    y_combinator([&](auto self, int L, int R, int c) -> void {
        int S = R - L;
        if (S > K) {
            int E = (S + K - 1) / K;
            for (int u = L; u < R; u++) {
                where[u] = (u - L) / E;
            }
            for (int u = L; u < R; u++) {
                for (int v = u + 1; v < R; v++) {
                    if (where[u] != where[v]) {
                        color[u][v] = c;
                    }
                }
            }
            for (int u = L; u < R; u += E) {
                self(u, min(u + E, R), c + 1);
            }
        } else {
            for (int u = L; u < R; u++) {
                for (int v = u + 1; v < R; v++) {
                    color[u][v] = c;
                }
            }
        }
        C = max(C, c);
    })(0, N, 1);

    cout << C << '\n';
    for (int u = 0; u < N; u++) {
        for (int v = u + 1; v < N; v++) {
            cout << color[u][v] << " \n"[u + 1 == N && v + 1 == N];
        }
    }

    return 0;
}