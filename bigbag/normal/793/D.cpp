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

const int max_n = 88, inf = 1011111111;

int n, k, m, dp[max_n][max_n][max_n][2];
vector<int> g[max_n], d[max_n];
map<pair<int, int>, int> D;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 0; i < m; ++i) {
        int u, v, dd;
        scanf("%d%d%d", &u, &v, &dd);
        if (!D.count(make_pair(u, v))) {
            D[make_pair(u, v)] = dd;
        } else {
            D[make_pair(u, v)] = min(D[make_pair(u, v)], dd);
        }
    }
    for (auto it = D.begin(); it != D.end(); ++it) {
        pair<pair<int, int>, int> p = *it;
        g[p.first.first].push_back(p.first.second);
        d[p.first.first].push_back(p.second);
    }
    for (int len = 1; len <= n; ++len) {
        for (int l = 1; l + len <= n + 1; ++l) {
            int r = l + len - 1;
            for (int tp = 0; tp < 2; ++tp) {
                dp[l][r][0][tp] = 0;
                int v = l;
                if (tp == 1) {
                    v = r;
                }
                for (int i = 1; i < k; ++i) {
                    dp[l][r][i][tp] = inf;
                    for (int j = 0; j < g[v].size(); ++j) {

                        if (tp == 0) {
                            if (g[v][j] > v && g[v][j] <= r) {
                                int upd = dp[g[v][j]][r][i - 1][0];
                                upd = min(upd, dp[l + 1][g[v][j]][i - 1][1]);
                                upd += d[v][j];
                                dp[l][r][i][tp] = min(dp[l][r][i][tp], upd);
                            }
                        } else {
                            if (l <= g[v][j] && g[v][j] < r) {
                                int upd = dp[l][g[v][j]][i - 1][1];
                                upd = min(upd, dp[g[v][j]][r - 1][i - 1][0]);
                                upd += d[v][j];
                                dp[l][r][i][tp] = min(dp[l][r][i][tp], upd);
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = inf;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, dp[i][n][k - 1][0]);
        ans = min(ans, dp[1][i][k - 1][1]);
    }
    if (ans == inf) {
        ans = -1;
    }
    printf("%d\n", ans);
    return 0;
}