#include <bitset>
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

const int max_n = 505, max_lev = 61;
const long long inf = 1000000000000000000LL;

int n, m, f[max_n][max_n][2], used[max_n][2], mx[max_n][2];
long long dp[max_n][2];
bitset<max_n> dp1[max_lev][max_n][2], dp2[max_lev][max_n][2];
vector<int> g[max_n][2];

void get_dp(int v, int tp) {
    if (used[v][tp]) {
        return;
    }
    //cout << v << " " << tp << endl;
    used[v][tp] = 1;
    int lev = mx[v][tp];
    if (lev == -1) {
        dp[v][tp] = 0;
        return;
    }
    int ntp = tp;

    ntp ^= 1;
    for (int i = 1; i <= n; ++i) {
        if (dp1[lev][v][tp][i] == 1) {
            get_dp(i, ntp);
            dp[v][tp] = max(dp[v][tp], dp[i][ntp]);
        }
    }
    dp[v][tp] += (1LL << mx[v][tp]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v, col;
        scanf("%d%d%d", &u, &v, &col);
        f[u][v][col] = 1;
        g[u][col].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int tp = 0; tp < 2; ++tp) {
                if (f[i][j][tp]) {
                    dp1[0][i][tp][j] = 1;
                    dp2[0][j][tp][i] = 1;
                }
            }
        }
    }
    for (int lev = 1; lev < max_lev; ++lev) {
        //cout << lev << endl;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int tp = 0; tp < 2; ++tp) {
                    if ((dp1[lev - 1][i][tp] & dp2[lev - 1][j][tp ^ 1]).count()) {
                        dp1[lev][i][tp][j] = 1;
                        dp2[lev][j][tp][i] = 1;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int tp = 0; tp < 2; ++tp) {
            mx[i][tp] = -1;
            for (int lev = max_lev - 1; lev >= 0; --lev) {
                if (dp1[lev][i][tp].count()) {
                    mx[i][tp] = lev;
                    break;
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (mx[1][0] == max_lev - 1) {
            printf("-1\n");
            return 0;
        }
        //cout << i << " " << mx[i][0] << " " << mx[i][1] << endl;
    }
    for (int i = 1; i <= n; ++i) {
        for (int tp = 0; tp < 2; ++tp) {
            if (used[i][tp] == 0) {
                get_dp(i, tp);
            }
        }
    }
    ans = dp[1][0];
    if (ans > inf) {
        ans = -1;
    }
    printf("%I64d\n", ans);
    return 0;
}