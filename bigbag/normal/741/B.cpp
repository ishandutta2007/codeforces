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

const int max_n = 1111, inf = 1111111111;

int n, m, w, cnt, dp[max_n][max_n], used[max_n];
int a[max_n], b[max_n], sumw[max_n], sumc[max_n];
vector<int> g[max_n], comp[max_n];

void dfs(int v) {
    used[v] = 1;
    sumw[cnt] += a[v];
    sumc[cnt] += b[v];
    comp[cnt].push_back(v);
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] == 0) {
            dfs(g[v][i]);
        }
    }
}

void update(int i, int j, int x) {
    if (j > w) {
        return;
    }
    dp[i][j] = max(dp[i][j], x);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &w);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            dfs(i);
            //cout << sumw[cnt] << " " << sumc[cnt] << endl;
            ++cnt;
        }
    }
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j <= w; ++j) {
            update(i + 1, j, dp[i][j]);
            update(i + 1, j + sumw[i], dp[i][j] + sumc[i]);
            for (int k = 0; k < comp[i].size(); ++k) {
                int v = comp[i][k];
                update(i + 1, j + a[v], dp[i][j] + b[v]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= w; ++i) {
        ans = max(ans, dp[cnt][i]);
    }
    printf("%d\n", ans);
    return 0;
}