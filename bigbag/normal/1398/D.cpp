#include <bits/stdc++.h>

using namespace std;

const int max_n = 222, inf = 1000111222;

int n[3], a[3][max_n], dp[max_n][max_n][max_n];
int pos[3];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n[0], &n[1], &n[2]);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n[i]; ++j) {
            scanf("%d", &a[i][j]);
        }
        sort(a[i], a[i] + n[i]);
        reverse(a[i], a[i] + n[i]);
    }
    int ans = 0;
    for (int i = 0; i <= n[0]; ++i) {
        for (int j = 0; j <= n[1]; ++j) {
            for (int k = 0; k <= n[2]; ++k) {
                ans = max(ans, dp[i][j][k]);
                //cout << i << " " << j << " " << k << ": " << dp[i][j][k] << endl;
                for (int q = 0; q < 3; ++q) {
                    for (int w = q + 1; w < 3; ++w) {
                        pos[0] = i;
                        pos[1] = j;
                        pos[2] = k;
                        if (pos[q] < n[q] && pos[w] < n[w]) {
                            int add = a[q][pos[q]] * a[w][pos[w]];
                            ++pos[q];
                            ++pos[w];
                            dp[pos[0]][pos[1]][pos[2]] = max(dp[pos[0]][pos[1]][pos[2]], dp[i][j][k] + add);
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}