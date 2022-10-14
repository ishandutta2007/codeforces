#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename V>
auto max_plus_one_convex(const vector<V>& a, const vector<V>& b) {
    int N = a.size();
    int M = b.size();
    if (N == 0 || M == 0) {
        return N ? a : b;
    }

    const int C = N + M - 1;
    vector<V> c(N + M - 1, numeric_limits<V>::lowest());
    vector<array<int, 2>> stk;

    auto cost = [&](int j, int i) { return a[j] + b[i - j]; };

    // Solve c[L,R] with prefix concave 1d1d
    auto solve_prefix = [&](int L, int R) {
        auto improv = [&](int j, int i, int t, int k) {
            int l = k - 1, r = t;
            while (l + 1 < r) {
                int m = (l + r) / 2;
                cost(j, m) >= cost(i, m) ? r = m : l = m;
            }
            return l;
        };

        for (int i = L, k = L, S = -1; k < R; i++, k++) {
            while (S >= 0 && i < N) {
                auto [j, t] = stk[S];
                if (cost(i, t) >= cost(j, t)) {
                    stk.pop_back(), S--;
                } else {
                    break;
                }
            }

            if (i < N) {
                int t = S < 0 ? R - 1 : improv(stk[S][0], i, stk[S][1], k);
                if (t >= k) {
                    stk.push_back({i, t}), S++;
                }
            }

            c[k] = max(c[k], cost(stk[S][0], k));

            if (stk[S][1] == k) {
                stk.pop_back(), S--;
            }
        }
    };

    // Solve c[L,R] with suffix concave 1d1d
    auto solve_suffix = [&](int L, int R) {
        auto improv = [&](int j, int i, int t, int k) {
            int l = t, r = k + 1;
            while (l + 1 < r) {
                int m = (l + r) / 2;
                cost(j, m) >= cost(i, m) ? l = m : r = m;
            }
            return r;
        };

        for (int k = R - 1, i = k - M + 1, S = -1; k >= L; i--, k--) {
            while (S >= 0 && i >= 0) {
                auto [j, t] = stk[S];
                if (cost(i, t) >= cost(j, t)) {
                    stk.pop_back(), S--;
                } else {
                    break;
                }
            }

            if (i >= 0) {
                int t = S < 0 ? L : improv(stk[S][0], i, stk[S][1], k);
                if (t <= k) {
                    stk.push_back({i, t}), S++;
                }
            }

            c[k] = max(c[k], cost(stk[S][0], k));

            if (stk[S][1] == k) {
                stk.pop_back(), S--;
            }
        }
    };

    solve_prefix(0, M);
    solve_suffix(C - M, C);

    // Still need to solve c[M,C-M)
    for (int K = M; K <= C - M; K += M) {
        solve_prefix(K, K + M);
        solve_suffix(K, K + M);
    }

    return c;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<int64_t> c = {0};
    for (int i = 0; i < N; i++) {
        int S;
        cin >> S;
        vector<int64_t> a(S + 1);
        for (int j = 1; j <= S; j++) {
            cin >> a[j];
            a[j] += a[j - 1];
        }
        a.resize(min(S + 1, K + 1));
        c = max_plus_one_convex(c, a);
        S = c.size();
        c.resize(min(S, K + 1));
    }
    cout << c[K] << '\n';
    return 0;
}