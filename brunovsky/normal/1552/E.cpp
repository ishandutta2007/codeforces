#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<int> c(N * K + 1);
    vector<vector<int>> byc(N + 1);
    for (int i = 1; i <= N * K; i++) {
        cin >> c[i];
        byc[c[i]].push_back(i);
    }
    vector<array<int, 2>> sol(N + 1);
    vector<bool> erased(N + 1);
    int M = N / (K - 1);
    int cnt_erased = 0;
    while (cnt_erased < N) {
        int i = 1;
        vector<int> cnt(N + 1);
        while (i <= N * K) {
            while (i <= N * K) {
                if (!erased[c[i]]) {
                    cnt[c[i]]++;
                    if (cnt[c[i]] == 2) {
                        break;
                    }
                }
                i++;
            }
            if (i <= N * K) {
                int color = c[i];
                erased[color] = true;
                int j = lower_bound(begin(byc[color]), end(byc[color]), i) -
                        begin(byc[color]);
                j = byc[color][j - 1];
                sol[color] = {j, i};
                cnt.assign(N + 1, 0);
                cnt_erased++;
            }
        }
    }
    debug(N, K, cnt_erased);
    for (int i = 1; i <= N; i++) {
        cout << sol[i][0] << ' ' << sol[i][1] << '\n';
    }
    return 0;
}