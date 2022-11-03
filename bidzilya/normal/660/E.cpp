#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

const int LIM = 1e6 + 1;

int dp[LIM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    if (m == 1) {
        cout << n + 1 << endl;
        return 0;
    }

    dp[0] = 1;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = (2LL * dp[i - 1]) % MOD;
        dp[i] -= sum;
        if (dp[i] < 0) {
            dp[i] += MOD;
        }
        dp[i] = (1LL * dp[i] * m) % MOD;
        sum = (1LL * sum * (m - 1)) % MOD;
        sum += dp[i - 1];
        if (sum >= MOD) {
            sum -= MOD;
        }
    }

    cout << dp[n] << endl;

    return 0;
}