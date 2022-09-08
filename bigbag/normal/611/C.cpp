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

const int max_n = 555, inf = 1111111111;

int n, m, q, dp[max_n][max_n], cnt[max_n][max_n], cnt2[max_n][max_n];
char s[max_n][max_n];

int solve(int lx, int rx, int ly, int ry) {
    int res = dp[rx][ry];
    if (lx) {
        res -= dp[lx - 1][ry];
    }
    if (ly) {
        res -= dp[rx][ly - 1];
    }
    if (lx && ly) {
        res += dp[lx - 1][ly - 1];
    }
    //cout << lx << " " << rx << "  " << ly << " " << ry << " : " << dp[rx][ry] << endl;
    //return res;
    res -= cnt[lx][ry];
    if (ly) {
        res += cnt[lx][ly - 1];
    }
    //return res;
    res -= cnt2[ly][rx];
    if (lx) {
        res += cnt2[ly][lx - 1];
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i) {
                dp[i][j] += dp[i - 1][j];
            }
            if (j) {
                dp[i][j] += dp[i][j - 1];
            }
            if (i && j) {
                dp[i][j] -= dp[i - 1][j - 1];
            }
            if (i && s[i][j] == '.' && s[i - 1][j] == '.') {
                ++dp[i][j];
            }
            if (j && s[i][j] == '.' && s[i][j - 1] == '.') {
                ++dp[i][j];
            }
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j) {
                cnt[i][j] = cnt[i][j - 1];
            }
            if (s[i][j] == '.' && s[i - 1][j] == '.') {
                ++cnt[i][j];
            }
        }
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j) {
                cnt2[i][j] = cnt2[i][j - 1];
            }
            if (s[j][i] == '.' && s[j][i - 1] == '.') {
                ++cnt2[i][j];
            }
        }
    }
    scanf("%d", &q);
    while (q--) {
        int lx, rx, ly, ry;
        scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
        --lx;
        --rx;
        --ly;
        --ry;
        printf("%d\n", solve(lx, rx, ly, ry));
    }
    return 0;
}