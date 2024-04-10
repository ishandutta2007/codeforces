#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

#define MAX 300'000

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int BITS = 8 * sizeof(int) - __builtin_clz(MAX - 1);

    vector<vector<int>> with_bit(BITS);
    for (int i = 0; i < N; i++) {
        for (int b = 0; b < BITS; b++) {
            if ((a[i] >> b) & 1) {
                with_bit[b].push_back(i);
            }
        }
    }

    auto next_in_line = [&](int b, int i) {
        auto it = upper_bound(begin(with_bit[b]), end(with_bit[b]), i);
        return it == end(with_bit[b]) ? N : *it;
    };

    // dp[i][b]: smallest j>i that is reachable from i with b-th bit set
    vector<vector<int>> dp(N + 1, vector<int>(BITS, N));
    for (int i = N - 1; i >= 0; i--) {
        for (int b = 0; b < BITS; b++) {
            if ((a[i] >> b) & 1) {
                auto j = next_in_line(b, i);
                for (int c = 0; c < BITS; c++) {
                    dp[i][c] = min(dp[i][c], dp[j][c]);
                }
                dp[i][b] = i;
            }
        }
    }

    for (int q = 0; q < Q; q++) {
        int x, y;
        cin >> x >> y, x--, y--;
        bool found_path = false;
        for (int b = 0; b < BITS; b++) {
            if ((a[y] >> b) & 1) {
                found_path |= dp[x][b] <= y;
            }
        }
        cout << (found_path ? "Shi\n" : "Fou\n");
    }
    return 0;
}