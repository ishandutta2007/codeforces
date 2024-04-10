#include <bits/stdc++.h>

using namespace std;

// *****

// ->     |  |  |  |  |  |  |  |
//  0     1  2  3  4  5  6  7  N
// dp[n]: number of D(k) leaving plane n, 1<=n<=N
// prefix[n]: number of D(k) leaving plane [1..n)
// suffix[n]: number of D(k) leaving plane [n+1...)

constexpr unsigned MOD = 1e9 + 7;

auto solve() {
    int N, K;
    cin >> N >> K;
    if (K == 1)
        return 1u;

    vector<unsigned> dp(N + 1, 0), prefix(N + 2, 1), suffix(N + 2, 0);
    bool right = true;
    unsigned ans = 1;
    for (int k = K - 1; k >= 1; k--) {
        if (right) {
            for (int n = 1; n <= N; n++) {
                dp[n] = prefix[n];
                ans = (ans + dp[n]) % MOD;
            }
        } else {
            for (int n = 1; n <= N; n++) {
                dp[n] = suffix[n];
                ans = (ans + dp[n]) % MOD;
            }
        }
        prefix[0] = prefix[1] = suffix[N] = suffix[N + 1] = 0;
        for (int n = 1; n <= N; n++) {
            prefix[n + 1] = (prefix[n] + dp[n]) % MOD;
        }
        for (int n = N; n >= 1; n--) {
            suffix[n - 1] = (suffix[n] + dp[n]) % MOD;
        }
        right = !right;
    }
    return ans;
}

// *****

int main() {
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}