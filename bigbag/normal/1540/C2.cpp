/**
 *  created: 25/06/2021, 19:44:15
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, mod = 1000000007, inf = 1000111222;

inline void inc(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

inline void dec(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += mod;
    }
}

int n, c[max_n], a[max_n], b[max_n], q;

const int max_sum = max_n * max_n;
const int max_x = 202222;

int dp[2][max_sum], ans[max_x];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
    }
    for (int i = 0; i + 1 < n; ++i) {
        scanf("%d", &b[i]);
    }
    int sb = 0, mn = 0, mnx = inf;
    for (int i = 0; i < n; ++i) {
        mn += sb;
        sb += b[i];
        mnx = min(mnx, -((mn + i) / (i + 1)));
    }
    for (int x = mnx - 2; x <= mnx + 102; ++x) {
        int q1 = 0, q2 = 1;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        sb = 0;
        mn = 0;
        for (int i = 0; i < n; ++i) {
            memset(dp[q2], 0, sizeof(dp[q2]));
            int tot = 0, from = 0;
            mn += x + sb;
            sb += b[i];
            for (int sum = 0; sum < max_sum; ++sum) {
                inc(tot, dp[q1][sum]);
                while (from + c[i] < sum) {
                    dec(tot, dp[q1][from++]);
                }
                dp[q2][sum] = tot;
                if (sum < mn) {
                    dp[q2][sum] = 0;
                }
            }
            swap(q1, q2);
        }
        int res = accumulate(dp[q1], dp[q1] + max_sum, 0LL) % mod;
        ans[x + max_x / 2] = res;
    }
    scanf("%d", &q);
    while (q--) {
        int x;
        scanf("%d", &x);
        x = max(x, mnx - 2);
        printf("%d\n", ans[x + max_x / 2]);
    }
    return 0;
}