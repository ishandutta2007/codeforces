#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, max_lev = 21, inf = 1000111222;

int ans, n, k, dp[max_n][2];
int h[max_n], highest[max_n];
vector<int> g[max_n];

void dfs(int v) {
    highest[v] = inf;
    if (g[v].empty()) {
        highest[v] = h[v];
        dp[v][0] = 1;
        dp[v][1] = 1;
    }
    for (int to : g[v]) {
        h[to] = h[v] + 1;
        dfs(to);
        highest[v] = min(highest[v], highest[to]);
        if (h[v] + k >= highest[to]) {
            dp[v][1] += dp[to][1];
            dp[v][0] += dp[to][1];
        }
    }
    for (int to : g[v]) {
        int mn = 0;
        if (h[v] + k >= highest[to]) {
            mn = dp[to][1];
        }
        dp[v][0] = max(dp[v][0], dp[v][1] - mn + dp[to][0]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 2; i <= n; ++i) {
        int p;
        scanf("%d", &p);
        g[p].push_back(i);
    }
    dfs(1);
    printf("%d\n", dp[1][0]);
    return 0;
}