#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long dp[510][510];
long long pow2[510*510+5];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;
    pow2[0] = 1;
    dp[0][0] = 1;
    for(int i = 1; i<=(n+1)*(n+1); i++) pow2[i] = pow2[i-1]*2%MOD;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=k; j++){
            dp[i][j] = 0;
            for(int m = 0; m < i; m++){
                dp[i][j] = (dp[i][j]+dp[m][j-1]*pow2[m*(i-m)]%MOD*(pow2[i-m]-1))%MOD;
            }
        }
    }
    long long ans = 0;
    for(int i = 0; i<=n; i++) ans = (ans+dp[i][k]*pow2[(n-i)*i])%MOD;
    cout << ans << endl;
}