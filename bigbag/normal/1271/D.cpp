#include <bits/stdc++.h>

using namespace std;

const int max_n = 5055, inf = 1000111222;

int n, m, k, a[max_n], b[max_n], c[max_n], mx[max_n];
int dp[max_n][max_n];
vector<int> g[max_n];

bool cmp(int a, int b) {
    return c[a] > c[b];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        mx[i] = i;
    }
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        mx[v] = max(mx[v], u);
    }
    for (int i = 0; i < n; ++i) {
        g[mx[i]].push_back(i);
        sort(g[i].begin(), g[i].end(), cmp);
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    int army = k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (army - j < a[i] || dp[i][j] == -1) {
                continue;
            }
            int w = army + b[i];
            int sum = 0;
            for (int cnt = 0; cnt <= g[i].size(); ++cnt) {
                dp[i + 1][j + cnt] = max(dp[i + 1][j + cnt], dp[i][j] + sum);
                if (cnt < g[i].size()) {
                    sum += c[g[i][cnt]];
                }
            }
        }
        army += b[i];
    }
    int ans = -1;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, dp[n][i]);
    }
    printf("%d\n", ans);
    return 0;
}