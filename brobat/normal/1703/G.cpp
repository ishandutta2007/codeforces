#include <bits/stdc++.h>
using namespace std;
#define int long long

const int M = 34;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int dp[n + 1][M];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + v[i - 1] - k;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j < M && j <= i; j++) {
                dp[i][j] = max(dp[i - 1][j] - k, dp[i - 1][j - 1]) + (v[i - 1]>>j);
            }
        }
        // for(int i = 0; i <= n; i++) {
        //     for(int j = 0; j < M; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        int ans = -(int)1E18;
        for(int j = 0; j < M; j++) {
            ans = max(ans, dp[n][j]);
        }
        for(int i = 1; i <= n; i++) {
            ans = max(ans, dp[i][M - 1]);
        }
        cout << max(ans, 0ll) << '\n';
    }
    
    return 0;
}