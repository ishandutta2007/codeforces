#include <bits/stdc++.h>
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#define int long long
//#define double long double
using namespace std;
int dp[5001][2511][2];
int INF = 1e16;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    for (int i=0; i <= n; i++) for (int j=0; j <= (n+1)/2; j++) for (int p=0; p < 2; p++) dp[i][j][p] = INF;
    dp[0][0][0] = 0;
    for (int i=0; i < n; i++){
        for (int j=0; j <= (n+1)/2; j++){
            dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][0]);
            dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][1]);
        //if (j==3) cout << i << " " << dp[i][j][0] << " " << dp[i][j][1] << endl;
            if (i >= 2){
                int op = 0;
                op += max((int) 0, v[i-1] + 1 - v[i]);
                if (i < n-1) op += max((int) 0, v[i+1] + 1 - v[i]);
                dp[i+1][j][1] = min(dp[i+1][j][1], dp[i-1][j-1][0] + op);
                int rl = min(v[i-1], v[i-2]-1);
                op = max((int) 0, rl+1-v[i]);
                //if (i==4 && j==2) cout << rl << endl;
                if (i < n-1) op += max((int) 0, v[i+1] + 1 - v[i]);
                dp[i+1][j][1] = min(dp[i+1][j][1], dp[i-1][j-1][1] + op);
            }
            else{
                if (j > 1) continue;
                int op = 0;
                if (i >= 1) op += max((int) 0, v[i-1] + 1 - v[i]);
                if (i < n-1) op += max((int) 0, v[i+1] + 1 - v[i]);
                dp[i+1][j][1] = min(dp[i+1][j][1], op);
            }
        }
    }
    //cout << dp[5][2][1] << endl;
    for (int j=1; j <= (n+1)/2; j++){
        cout << min(dp[n][j][0], dp[n][j][1]) << " ";
    }
    return 0;
}