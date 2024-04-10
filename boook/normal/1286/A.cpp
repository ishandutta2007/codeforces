#include <bits/stdc++.h>
using namespace std;
#define maxn 110
int n, x[maxn], u[maxn];

int dp[maxn][maxn][maxn][2];
int32_t main(){
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> x[i], u[x[i]] = 1;

    int v0 = 0, v1 = 0;
    for (int i = 1; i <= n; ++ i) {
        if (u[i] == 0 && i % 2 == 0) v0 ++; 
        if (u[i] == 0 && i % 2 == 1) v1 ++; 
    }
    // cout << v0 << " " << v1 << endl;
    memset(dp, 0x3f3f3f3f, sizeof dp);
    dp[0][0][0][0] = 0;
    dp[0][0][0][1] = 0;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j <= v0; ++ j) {
            for (int k = 0; k <= v1; ++ k) {
                for (int now = 0; now <= 1; now ++) {
                    if (x[i + 1] != 0) {
                        // cout << i << " " << j << " " << k << " " << now << " " << x[i + 1] % 2 << endl;
                        dp[i + 1][j][k][x[i + 1] % 2] = 
                            min(dp[i + 1][j][k][x[i + 1] % 2], dp[i][j][k][now] + (now != x[i + 1] % 2));
                    }
                    else {
                        dp[i + 1][j + 1][k][0] = min(dp[i + 1][j + 1][k][0], dp[i][j][k][now] + (now != 0));
                        dp[i + 1][j][k + 1][1] = min(dp[i + 1][j][k + 1][1], dp[i][j][k][now] + (now != 1));
                    }
                }
            }
        }
    }
    // cout << dp[1][1][0][0] << endl;
    // cout << dp[2][1][0][1] << endl;
    cout << min(dp[n][v0][v1][0], dp[n][v0][v1][1]) << "\n";
    return 0;
}