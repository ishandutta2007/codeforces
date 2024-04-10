#include <bits/stdc++.h>

#define MAXN (80)

int n;
char s[MAXN];
std::vector<int> vv, kk, xx;
int totv, totk, totx;
int prev[MAXN], prek[MAXN], prex[MAXN];
int dp[MAXN][MAXN][MAXN][2];

void update(int &x, int y) { if (x > y) x = y; }

int main() {
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; ++i) {
        if (i) prev[i] = prev[i - 1], prek[i] = prek[i - 1], prex[i] = prex[i - 1];
        if (s[i] == 'V') vv.push_back(i), ++ prev[i];
        else if (s[i] == 'K') kk.push_back(i), ++ prek[i];
        else xx.push_back(i), ++ prex[i];
    }

    totv = prev[n - 1];
    totk = prek[n - 1];
    totx = prex[n - 1];

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0][0] = 0;
    for (int v = 0; v <= totv; ++v) {
        for (int k = 0; k <= totk; ++k) {
            for (int x = 0; x <= totx; ++x) {
                if (v == totv && k == totk && x == totx) continue;
                if (v + 1 <= totv) {
                    int sit = vv[v];
                    int cost = sit - v - std::min(prek[sit], k) - std::min(prex[sit], x);
                    update(dp[v + 1][k][x][1], dp[v][k][x][0] + cost);
                    update(dp[v + 1][k][x][1], dp[v][k][x][1] + cost);
                }
                if (k + 1 <= totk) {
                    int sit = kk[k];
                    int cost = sit - k - std::min(prev[sit], v) - std::min(prex[sit], x);
                    update(dp[v][k + 1][x][0], dp[v][k][x][0] + cost);
                }
                if (x + 1 <= totx) {
                    int sit = xx[x];
                    int cost = sit - x - std::min(prek[sit], k) - std::min(prev[sit], v);
                    update(dp[v][k][x + 1][0], dp[v][k][x][0] + cost);
                    update(dp[v][k][x + 1][0], dp[v][k][x][1] + cost);
                }
               // printf("dp[%d][%d][%d][%d] = %d\n", v, k, x, 0, dp[v][k][x][0]);
               // printf("dp[%d][%d][%d][%d] = %d\n", v, k, x, 1, dp[v][k][x][1]);
            }
        }
    }
    printf("%d\n", std::min(dp[totv][totk][totx][0], dp[totv][totk][totx][1]));
    return 0;
}