#include <bits/stdc++.h>

using namespace std;

const int max_n = 55, inf = 1000111222;

int n, sz[max_n];
long double dp[max_n][max_n], dp2[max_n], ndp[max_n], c[max_n][max_n];
vector<int> g[max_n];

void get_all_c() {
    c[0][0] = 1;
    for (int i = 1; i < max_n; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
}

void get_dp(int v, int p) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to != p) {
            get_dp(to, v);
            sz[v] += sz[to];
        }
    }
    for (int cnt = 0; cnt < max_n; ++cnt) {
        dp[v][cnt] = 0;
    }
    dp[v][0] = 1;
    int cur_sz = 0;
    for (int to : g[v]) {
        if (to != p) {
            for (int cnt = 0; cnt <= sz[to]; ++cnt) {
                dp2[cnt] = 0;
                long double p = 0;
                if (cnt) {
                    p = c[sz[to] - 1][cnt - 1] / c[sz[to]][cnt];
                }
                if (cnt < sz[to]) {
                    for (int i = 0; i < sz[to] - cnt; ++i) {
                        dp2[cnt] += dp[to][cnt + i];
                    }
                    dp2[cnt] /= 2 * (sz[to] - cnt);
                }
                dp2[cnt] *= (1 - p);
                if (cnt) {
                    dp2[cnt] += p * dp[to][cnt - 1];
                }
            }
            for (int a = 0; a < sz[v]; ++a) {
                ndp[a] = 0;
            }
            for (int a = 0; a <= cur_sz; ++a) {
                for (int b = 0; b <= sz[to] && a + b < sz[v]; ++b) {
                    ndp[a + b] += dp[v][a] * dp2[b] * c[cur_sz][a] * c[sz[to]][b] / c[cur_sz + sz[to]][a + b];
                }
            }
            cur_sz += sz[to];
            for (int a = 0; a < sz[v]; ++a) {
                dp[v][a] = ndp[a];
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_c();
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        get_dp(i, -1);
        printf("%.10f\n", (double) dp[i][0]);
    }
    return 0;
}