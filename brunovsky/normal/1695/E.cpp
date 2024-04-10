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
    const int M = 2 * N;
    vector<set<pair<int, int>>> adj(M);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y, x--, y--;
        adj[x].insert({y, i});
        adj[y].insert({x, i});
    }

    vector<int> top(N), bot(N);
    array<string, 2> A = {string(N, '.'), string(N, '.')};
    array<string, 2> B = {string(N, '.'), string(N, '.')};
    int L = 0;

    vector<int> count(N);
    for (int r = 0; r < M; r++) {
        if (adj[r].empty()) {
            continue;
        }

        vector<int> trail;
        y_combinator([&](auto self, int u) -> void {
            trail.push_back(u);
            while (adj[u].size()) {
                auto [v, i] = *adj[u].begin();
                adj[u].erase({v, i});
                if (u != v) {
                    adj[v].erase({u, i});
                    self(v);
                } else {
                    trail.push_back(u);
                }
                trail.push_back(u);
            }
        })(r);

        trail.pop_back();
        int S = trail.size();
        assert(S % 2 == 0);
        S /= 2;
        if (S == 1) {
            cout << "-1\n";
            return 0;
        }

        for (int i = 0, j = 2 * S - 1; i < S; i++, j--) {
            top[L + i] = trail[i];
            bot[L + i] = trail[j];
        }
        for (int i = 0; i < S && S % 2 == 1; i++) {
            A[0][L + i] = i == 0 ? 'U' : i % 2 ? 'L' : 'R';
            A[1][L + i] = i == 0 ? 'D' : i % 2 ? 'L' : 'R';
            B[0][L + i] = i == S - 1 ? 'U' : i % 2 ? 'R' : 'L';
            B[1][L + i] = i == S - 1 ? 'D' : i % 2 ? 'R' : 'L';
        }
        for (int i = 0; i < S && S % 2 == 0; i++) {
            A[0][L + i] = i == 0 || i == S - 1 ? 'U' : i % 2 ? 'L' : 'R';
            A[1][L + i] = i == 0 || i == S - 1 ? 'D' : i % 2 ? 'L' : 'R';
            B[0][L + i] = i % 2 ? 'R' : 'L';
            B[1][L + i] = i % 2 ? 'R' : 'L';
        }
        L += S;
    }

    cout << 2 << ' ' << N << "\n\n";
    for (int i = 0; i < N; i++) {
        cout << top[i] + 1 << " \n"[i + 1 == N];
    }
    for (int i = 0; i < N; i++) {
        cout << bot[i] + 1 << " \n"[i + 1 == N];
    }
    cout << '\n';
    cout << A[0] << '\n' << A[1] << '\n';
    cout << '\n';
    cout << B[0] << '\n' << B[1] << '\n';
    return 0;
}

//  4 5
//   3
// 1 2 6
//   7
//   8
// 1 2 3 4 3 5 3 2 6 2 7 8 7 2 1
// 1 2 3 4 3 5 3
// 2 7 8 7 2 6 2