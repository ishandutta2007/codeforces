#include <bits/stdc++.h>

#define MAXN (2010)

int n, k;
int dp[MAXN][MAXN];
std::vector<std::pair<int, int>> war[MAXN + MAXN];
bool vis[MAXN][MAXN];
char s[MAXN][MAXN];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            war[i + j].emplace_back(i, j);
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1][1] = s[1][1] != 'a';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 1 && j == 1) continue;
            if (i - 1) {
                dp[i][j] = std::min(dp[i][j], dp[i - 1][j]);
            }
            if (j - 1) {
                dp[i][j] = std::min(dp[i][j], dp[i][j - 1]);
            }
            dp[i][j] += s[i][j] != 'a';
        }
    }
    int max = 2;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dp[i][j] <= k) {
                max = std::max(max, i + j);
            }
        }
    }
    if (k == 0) {
        putchar(s[1][1]);
        vis[1][1] = true;
        max = 2;
    } else {
        for (int i = 1; i < max; ++i) {
            putchar('a');
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dp[i][j] <= k && max == i + j) {
                vis[i][j] = true;
            }
        }
    }
    for (int k = max; k < n + n; ++k) {
        char min = 'z';
        for (auto p : war[k]) {
            int a = p.first;
            int b = p.second;
            if (!vis[a][b]) continue;
            if (a < n) min = std::min(min, s[a + 1][b]);
            if (b < n) min = std::min(min, s[a][b + 1]);
        }
        putchar(min);
        for (auto p : war[k]) {
            int a = p.first;
            int b = p.second;
            if (!vis[a][b]) continue;
            if (a < n && s[a + 1][b] == min) vis[a + 1][b] = true;
            if (b < n && s[a][b + 1] == min) vis[a][b + 1] = true;
        }
    }
    putchar('\n');
    return 0;
}
//fsjl