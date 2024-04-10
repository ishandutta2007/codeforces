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

const int max_n = 222222, inf = 1111111111;

int n, cnt[max_n], dp[max_n][2];
vector<int> g[max_n];

void dfs1(int v) {
    if (g[v].size() == 0) {
        cnt[v] = 1;
    }
    for (int i = 0; i < g[v].size(); ++i) {
        dfs1(g[v][i]);
        cnt[v] += cnt[g[v][i]];
    }
}

void dfs2(int v, int lev) {
    for (int i = 0; i < g[v].size(); ++i) {
        dfs2(g[v][i], lev + 1);
    }
    if (g[v].size() == 0) {
        dp[v][0] = dp[v][1] = 1;
        return;
    }
    if (lev % 2 == 0) {
        dp[v][1] = 0;
        dp[v][0] = cnt[v];
        for (int i = 0; i < g[v].size(); ++i) {
            dp[v][1] = max(dp[v][1], cnt[v] - cnt[g[v][i]] + dp[g[v][i]][1]);
            dp[v][0] -= cnt[g[v][i]] - dp[g[v][i]][0];
        }
    } else {
        dp[v][1] = 1;
        dp[v][0] = inf;
        for (int i = 0; i < g[v].size(); ++i) {
            dp[v][0] = min(dp[v][0], dp[g[v][i]][0]);
            dp[v][1] += dp[g[v][i]][1] - 1;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
    }
    dfs1(1);
    dfs2(1, 0);
    printf("%d %d\n", dp[1][1], dp[1][0]);
    return 0;
}