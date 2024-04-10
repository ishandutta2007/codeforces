/**
 *  created: 18/03/2021, 17:42:25
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 5055, mod = 998244353;

void inc(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int n, k, mxh[max_n], dp[max_n][max_n], tmp[2][max_n];
vector<int> g[max_n];

void calc_dp(int v, int p) {
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        calc_dp(to, v);
    }
    int q1 = 0, q2 = 1;
    tmp[q1][0] = 1;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        int nh = max(mxh[v], mxh[to] + 1);
        for (int len = 0; len <= nh; ++len) {
            tmp[q2][len] = 0;
        }
        int tot = accumulate(dp[to], dp[to] + mxh[to] + 1, 0LL) % mod;
        for (int cur_len = 0; cur_len <= mxh[v]; ++cur_len) {
            inc(tmp[q2][cur_len], mul(tmp[q1][cur_len], tot));
            for (int len = 0; len <= mxh[to] && len + 1 + cur_len <= k; ++len) {
                inc(tmp[q2][max(cur_len, len + 1)], mul(tmp[q1][cur_len], dp[to][len]));
            }
        }
        swap(q1, q2);
        mxh[v] = nh;
    }
    copy(tmp[q1], tmp[q1] + mxh[v] + 1, dp[v]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    calc_dp(0, -1);
    int ans = accumulate(dp[0], dp[0] + mxh[0] + 1, 0LL) % mod;
    printf("%d\n", ans);
    return 0;
}