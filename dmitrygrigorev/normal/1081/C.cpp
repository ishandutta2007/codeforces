#include <bits/stdc++.h>

using namespace std;

#define int long long
int dp[2005][2005];
int MOD = 998244353;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0; i <= n; i++) for (int j=0; j <= k;j++) dp[i][j] = 0;
    dp[1][0] = m;
    for (int i=1; i < n; i++){
        for (int j=0; j <= k; j++){
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= MOD;
            if (j+1 <= k){
                dp[i+1][j+1] += dp[i][j] * (m-1);
                dp[i+1][j+1] %= MOD;
            }
        }
    }
    cout << dp[n][k];
    return 0;
}