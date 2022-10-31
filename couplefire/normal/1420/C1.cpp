#include <bits/stdc++.h>
using namespace std;
#define INF 1000000009

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        long long dp[n+1][2];
        int arr[n+1];
        for(int i = 0; i<n; i++) cin >> arr[i+1];
        dp[0][0] = 0;
        dp[0][1] = -INF;
        for(int i = 1; i<=n; i++){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][0] = max(dp[i][0], -arr[i]+dp[i-1][1]);
            dp[i][1] = max(dp[i][1], dp[i-1][0]+arr[i]);
        }
        cout << max(dp[n][0], dp[n][1]) << endl;
    }
}