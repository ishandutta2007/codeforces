#include <bits/stdc++.h>
using namespace std;
int MOD = 998244353;
int dp[100000][201][2];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    for (int i=0; i < n; i++) for (int j=0; j <= 200; j++) for (int k=0; k <2 ; k++) dp[i][j][k] = 0;
    if (v[0] == -1){
        for (int j=0; j < 200; j++) dp[0][j+1][1] = 1;
    }
    else dp[0][v[0]][1] = 1;
    for (int i=1; i < n; i++){
        for (int it=0; it < 2; it++){
            for (int j=1; j <= 200; j++){
                dp[i-1][j][it] += dp[i-1][j-1][it];
                dp[i-1][j][it] %= MOD;
            }
        }
        for (int j=1; j <= 200; j++){
            if (v[i] != -1 && v[i] != j) continue;
            dp[i][j][1] += dp[i-1][j-1][0] + dp[i-1][j-1][1];
            if (dp[i][j][1] >= MOD) dp[i][j][1] -= MOD;
            dp[i][j][0] += dp[i-1][200][0] + dp[i-1][j][1] - dp[i-1][j-1][0] - dp[i-1][j-1][1];
            dp[i][j][0] %= MOD;
            if (dp[i][j][0] < 0) dp[i][j][0] += MOD;
        }
        //for (int j=0; j <= 200; j++) for (int k=0; k < 2; k++) if (dp[i][j][k]) cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
    }
    long long ans = 0;
    for (int i=0;i<=200;i++) ans += dp[n-1][i][0];
    cout << ans%MOD;
    return 0;
}