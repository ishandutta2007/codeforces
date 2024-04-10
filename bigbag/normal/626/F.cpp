#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 202, max_k = 1011, mod = 1000000007;

int n, k, a[max_n], dp[2][max_n][max_k + max_n * 500], sum[max_n];

int get_sum(int l, int r) {
    if (l == 0) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    sum[0] = a[0];
    for (int i = 1; i < n; ++i) {
        sum[i] = sum[i - 1] + a[i];
    }
    int q1 = 0, q2 = 1;
    int sd = sum[n - 1];
    dp[q1][0][0 + sd] = 1;
    for (int i = 0; i < n; ++i) {
        //memset(dp[q2], 0, sizeof(dp[q2]));
        for (int bal = 0; bal <= i + 1 && bal <= n - i + 1; ++bal) {
            int Q = get_sum(i + 1, i + bal);
            for (int s = 0; s - sd + Q <= k; ++s) {
                dp[q2][bal][s] = 0;
            }
        }
        for (int bal = 0; bal <= i && bal <= n - i; ++bal) {
            int Q = get_sum(i, i + bal - 1);
            for (int s = 0; s - sd + Q <= k; ++s) {
                if (dp[q1][bal][s]) {
                    //cout << i << " : " << bal << " " << s - sd << "  dp = " << dp[q1][bal][s] << endl;
                    dp[q2][bal][s] += dp[q1][bal][s];
                    dp[q2][bal][s] %= mod;
                    dp[q2][bal + 1][s - a[i]] += dp[q1][bal][s];
                    dp[q2][bal + 1][s - a[i]] %= mod;
                    if (bal) {
                        dp[q2][bal][s] += (1LL * dp[q1][bal][s] * bal) % mod;
                        dp[q2][bal][s] %= mod;
                        dp[q2][bal - 1][s + a[i]] += (1LL * dp[q1][bal][s] * bal) % mod;
                        dp[q2][bal - 1][s + a[i]] %= mod;
                    }
                }
            }
        }
        swap(q1, q2);
    }
    int ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans += dp[q1][0][i + sd];
        ans %= mod;
    }
    printf("%d\n", ans);
    return 0;
}