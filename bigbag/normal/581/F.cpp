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

const int max_n = 5055, inf = 1011111111;

int n, root, dp[max_n][max_n][2], cnt[max_n], a[max_n];
vector<int> g[max_n];

void dfs(int v, int p) {
    cnt[v] = 1;
    if (g[v].size() == 1) {
        dp[v][1][0] = 0;
        dp[v][0][1] = 0;
        return;
    }
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            dfs(g[v][i], v);
            cnt[v] += cnt[g[v][i]];
        }
    }
    for (int c = 0; c < 2; ++c) {
        int fff = 0;
        for (int i = 0; i < g[v].size(); ++i) {
            if (g[v][i] != p) {
                for (int x = 0; x <= cnt[v]; ++x) {
                    a[x] = inf;
                }
                for (int x = 0; x <= cnt[v]; ++x) {
                    if (fff == 0) {
                        a[x] = min(dp[g[v][i]][x][0] + (c != 0), dp[g[v][i]][x][1] + (c != 1));
                        continue;
                    }
                    for (int k = 0; k <= cnt[g[v][i]]; ++k) {
                        a[x] = min(a[x], dp[v][x - k][c] + dp[g[v][i]][k][0] + (c != 0));
                        a[x] = min(a[x], dp[v][x - k][c] + dp[g[v][i]][k][1] + (c != 1));
                    }
                }
                fff = 1;
                for (int x = 0; x <= cnt[v]; ++x) {
                    dp[v][x][c] = a[x];
                }
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < max_n; ++i) {
        for (int j = 0; j < max_n; ++j) {
            dp[i][j][0] = inf;
            dp[i][j][1] = inf;
        }
    }
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() > 1) {
            root = i;
        } else {
            ++cnt;
        }
    }
    dfs(root, -1);
    cout << min(dp[root][cnt / 2][0], dp[root][cnt / 2][1]) << endl;
    return 0;
}