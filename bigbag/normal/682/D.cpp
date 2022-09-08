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

const int max_n = 1011, inf = 1111111111;

int n, m, k, dp[max_n][max_n][11][2];
string s, t;

void update(int a, int b, int q, int f, int x) {
    dp[a][b][q][f] = max(dp[a][b][q][f], x);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k >> s >> t;
    memset(dp, -1, sizeof(dp));
    dp[0][0][0][0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int q = 0; q <= k; ++q) {
                for (int f = 0; f < 2; ++f) {
                    if (dp[i][j][q][f] == -1) {
                        continue;
                    }
                    int x = dp[i][j][q][f];
                    //cout << i << " " << j << " " << q << " " << f << " : " << x << endl;
                    update(i + 1, j, q, 0, x);
                    update(i, j + 1, q, 0, x);
                    if (q < k && s[i] == t[j]) {
                        update(i + 1, j + 1, q + 1, 1, x + 1);
                    }
                    if (f) {
                        if (s[i] == t[j]) {
                            update(i + 1, j + 1, q, 1, x + 1);
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", max(dp[n][m][k][0], dp[n][m][k][1]));
    return 0;
}