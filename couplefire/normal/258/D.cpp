// https://codeforces.com/problemset/problem/258/D
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(9);
    cout << fixed;
    int n, m; cin >> n >> m;
    double dp[n][n];
    int arr[n];
    for(int i = 0; i<n; i++) cin >> arr[i];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(arr[i] > arr[j]) dp[i][j] = 1;
            else dp[i][j] = 0;
        }
    }
    for(int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        double adp[n], dpa[n], bdp[n], dpb[n];
        for(int j = 0; j<n; j++){
            if(j == a || j == b) continue;
            adp[j] = 0.5*(dp[a][j]+dp[b][j]);
            dpa[j] = 0.5*(dp[j][a]+dp[j][b]);
            bdp[j] = 0.5*(dp[b][j]+dp[a][j]);
            dpb[j] = 0.5*(dp[j][b]+dp[j][a]);
        }
        for(int j = 0; j<n; j++){
            if(j == a || j == b) continue;
            dp[a][j] = adp[j];
            dp[j][a] = dpa[j];
            dp[b][j] = bdp[j];
            dp[j][b] = dpb[j];
        }
        dp[a][b] = 0.5;
        dp[b][a] = 0.5;
    }
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    double ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++) ans += dp[i][j];
    }
    cout << ans << endl;
}