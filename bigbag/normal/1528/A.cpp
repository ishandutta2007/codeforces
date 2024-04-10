/**
 *  created: 24/05/2021, 17:38:30
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 101111, inf = 1000111222;

int t, n, a[max_n][2];
long long dp[max_n][2];
vector<int> g[max_n];

void dfs(int v, int p) {
    dp[v][0] = dp[v][1] = 0;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
        for (int i = 0; i < 2; ++i) {
            long long mx = 0;
            for (int j = 0; j < 2; ++j) {
                mx = max(mx, abs(a[v][i] - a[to][j]) + dp[to][j]);
            }
            dp[v][i] += mx;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a[i][0], &a[i][1]);
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u;
            --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0, -1);
        printf("%I64d\n", max(dp[0][0], dp[0][1]));
        for (int i = 0; i < n; ++i) {
            g[i].clear();
        }
    }
    return 0;
}