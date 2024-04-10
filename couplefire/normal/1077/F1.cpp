#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n, k, x;
    cin >> n >> k >> x;
    long long arr[n+1];
    for(long long i = 0; i<n; i++){
        cin >> arr[i+1];
    }
    long long dp[n+1][x+1];
    for(long long i = 0; i<=n; i++){
        for(long long j = 0; j<=x; j++){
            dp[i][j] = -1;
        }
    }
    for(long long i = 1; i<=n; i++){
        if(i <= k) dp[i][1] = arr[i];
        for(long long j = 2; j<=min(i, x); j++){
            for(long long a = i-1; a+k >= i && a > 0; a--){
                if(dp[a][j-1] < 0) continue;
                dp[i][j] = max(dp[i][j], arr[i]+dp[a][j-1]);
            }
        }
    }
    long long ans = -1;
    for(long long i = n; i+k>n; i--){
        ans = max(ans, dp[i][x]);
    }
    cout << ans << endl;
}