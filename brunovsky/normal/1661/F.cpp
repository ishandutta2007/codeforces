#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    int64_t m;
    cin >> m;

    struct Cut {
        int a, b;
        int64_t cost;
    };

    auto optimum_cut = [&](int n, int c) {
        int k = n / (c + 1);
        int b = n - k * (c + 1);
        int a = c + 1 - b;
        return 1LL * a * k * k + 1LL * b * (k + 1) * (k + 1);
    };

    auto gain_cuts = [&](int64_t x) {
        int64_t spend = 0, cnt = 0;
        for (int i = 0; i < N; i++) {
            int D = a[i + 1] - a[i], L = 0, R = D - 1;
            while (L < R) {
                int M = (L + R) / 2;
                (optimum_cut(D, M) - optimum_cut(D, M + 1) >= x) ? L = M + 1 : R = M;
            }
            spend += optimum_cut(D, L);
            cnt += L;
        }
        return make_pair(spend, cnt);
    };

    int64_t L = 1, R = 1LL * a[N] * a[N] + 1;
    while (L + 1 < R) {
        int64_t M = (L + R) / 2;
        auto [val, cnt] = gain_cuts(M);
        val <= m ? L = M : R = M;
    }

    auto [val, cnt] = gain_cuts(R);

    int64_t rem = val - m;
    cout << cnt + (rem + L - 1) / L << '\n';
    return 0;
}