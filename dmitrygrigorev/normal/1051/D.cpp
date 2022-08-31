#include <bits/stdc++.h>
#define int long long
using namespace std;
int MOD = 998244353;
int dp[1000][2001][4];
int calc[4][4];
signed main(){
    calc[0][0] = 0, calc[0][1] = 1, calc[0][2] = 1, calc[0][3] = 1, calc[1][0] = 0, calc[1][1] = 0, calc[1][2] = 2, calc[1][3] = 0, calc[2][0] = 0, calc[2][1] = 2, calc[2][2] = 0, calc[2][3] = 0, calc[3][0] = 1, calc[3][1] = 1, calc[3][2] = 1, calc[3][3] = 0;
    int n, k;
    cin >> n >> k;
    for (int i=0; i < n; i++) for (int j=0; j <= k; j++) for (int p=0; p < 4; p++) dp[i][j][p] = 0;
    dp[0][1][0]++;
    dp[0][2][1]++;
    dp[0][2][2]++;
    dp[0][1][3]++;
    for (int i=0; i < n-1; i++){
        for (int j=0; j <= k; j++){
            for (int p=0; p < 4; p++){
                for (int e=0; e < 4; e++){
                    if (j+calc[p][e] <= k) dp[i+1][j+calc[p][e]][e] += dp[i][j][p];
                    if (j+calc[p][e] <= k) dp[i+1][j+calc[p][e]][e] %= MOD;
                }
            }
        }
    }
    int S = 0;
    for (int i=0; i < 4; i++) S += dp[n-1][k][i];
    cout << S%MOD;
}