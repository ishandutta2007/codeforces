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

const int max_n = 5005;
const int inf = 1011111111;

int n, sum, sz[max_n], a[max_n], b[max_n];
int dp[max_n][max_n][2], c1[2][max_n][2], c2[2][max_n][2];
vector<int> g[max_n];

void dfs(int v) {
    sz[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        dfs(g[v][i]);
        sz[v] += sz[g[v][i]];
    }
}

void get_dp(int v) {
    for (int i = 0; i < g[v].size(); ++i) {
        get_dp(g[v][i]);
    }
    int q1 = 0, q2 = 1;
    for (int i = 0; i <= sz[v]; ++i) {
        c1[q1][i][0] = c2[q1][i][0] = inf;
        c1[q1][i][1] = c2[q1][i][1] = inf;
    }
    //take v
    c1[q1][1][1] = a[v] - b[v];
    //don't take v
    c2[q1][1][0] = a[v];
    c2[q1][0][0] = 0;
    c2[q1][0][1] = 0;
    int cnt = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        for (int j = 0; j <= cnt + sz[g[v][i]]; ++j) {
            c1[q2][j][0] = c2[q2][j][0] = inf;
            c1[q2][j][1] = c2[q2][j][1] = inf;
        }
        for (int j = 0; j <= cnt; ++j) {
            for (int k = 0; k <= sz[g[v][i]]; ++k) {
                for (int tp = 0; tp < 2; ++tp) {
                    /*if (v == 5) {
                        cout << k << " " << tp << " #" << c1[q1][j][tp] << " + " << dp[g[v][i]][k][1] << "   " << c2[q1][j][tp] << " + " << dp[g[v][i]][k][0] << endl;
                    }*/
                    c1[q2][j + k][tp] = min(c1[q2][j + k][tp], c1[q1][j][tp] + dp[g[v][i]][k][1]);
                    c2[q2][j + k][tp] = min(c2[q2][j + k][tp], c2[q1][j][tp] + dp[g[v][i]][k][0]);
                }
            }
        }
        cnt += sz[g[v][i]];
        swap(q1, q2);
    }
    for (int tp = 0; tp < 2; ++tp) {
        for (int i = 0; i <= sz[v]; ++i) {
            if (tp == 1) {
                //dp[v][i][tp] = c1[q1][i][tp];
                dp[v][i][tp] = min(c1[q1][i][tp], c2[q1][i][tp]);
            } else {
                dp[v][i][tp] = c2[q1][i][tp];
                //dp[v][i][tp] = min(c1[q1][i][tp], c2[q1][i][tp]);
            }
        }
    }
    if (0) {
        cout << v << ": ";
        for (int i = 0; i <= sz[v]; ++i) {
            cout << "(" << dp[v][i][0] << " " << dp[v][i][1] << ") ";
        }
        cout << endl;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &sum);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        if (i > 1) {
            int p;
            scanf("%d", &p);
            g[p].push_back(i);
        }
    }
    dfs(1);
    get_dp(1);
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        //cout << dp[1][i][1] << endl;
        int f = 0;
        if (min(dp[1][i][0], dp[1][i][1]) <= sum) {
            ans = i;
            f = 1;
        }
        //cout << f << " ";
    }
    //cout << endl;
    printf("%d\n", ans);
    return 0;
}