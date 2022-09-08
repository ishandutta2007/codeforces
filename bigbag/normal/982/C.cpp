#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, dp[max_n][2][2];
vector<int> g[max_n];

void dfs(int v, int p) {
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
    }
    int q1 = 0, q2 = 1;
    memset(dp[v], -1, sizeof(dp[v]));
    dp[v][q1][1] = 0;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        memset(dp[v][q2], -1, sizeof(dp[v][q2]));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (dp[v][q1][i] == -1 || dp[to][0][j] == -1) {
                    continue;
                }
                dp[v][q2][(i + j) % 2] = max(dp[v][q2][(i + j) % 2], dp[v][q1][i] + dp[to][0][j]);
                if (j == 0) {
                    dp[v][q2][i] = max(dp[v][q2][i], dp[v][q1][i] + dp[to][0][j] + 1);
                }
            }
        }
        swap(q1, q2);
    }
    for (int i = 0; i < 2; ++i) {
        dp[v][q2][i] = dp[v][q1][i];
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
        g[v].push_back(u);
    }
    dfs(1, -1);
    printf("%d\n", dp[1][0][0]);
    return 0;
}