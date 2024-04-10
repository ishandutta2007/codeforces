#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

long inf = 1e17;
long dp[101][101];
// dp[n][k]: distinct in s[1..n] with length k

auto solve() {
    int N;
    long Kth;
    string s;
    cin >> N >> Kth >> s;
    s = "$" + s;

    array<int, 26> last = {};
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        int c = s[i] - 'a';
        dp[i][0] = 1;
        for (int k = 1; k <= i; k++) {
            dp[i][k] += dp[i - 1][k - 1]; // append c and end here
            dp[i][k] += dp[i - 1][k];     // do not append c
            if (last[c]) {
                dp[i][k] -= dp[last[c] - 1][k - 1];
            }
            dp[i][k] = min(dp[i][k], inf);
        }
        last[c] = i;
    }

    long ans = 0;
    for (int k = N; k >= 0 && Kth > 0; k--) {
        long take = min(Kth, dp[N][k]);
        Kth -= take;
        ans += take * (N - k);
    }
    return Kth > 0 ? -1LL : ans;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}