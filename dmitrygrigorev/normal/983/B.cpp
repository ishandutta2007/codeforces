#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[5000][5000];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    for (int i=0; i < n; i++) dp[i][i] = v[i];
    for (int d=1; d <= n-1; d++){
        for (int i=0; i < n; i++){
            int j = i+d;
            if (j >= n) break;
            dp[i][j] = dp[i][j-1] ^ dp[i+1][j];
        }
    }
    for (int i=0; i < n; i++){
        for (int j=1; j < n; j++) dp[i][j] = max(dp[i][j], dp[i][j-1]);
    }
    for (int i=0; i < n; i++){
        for (int j=n-2; j >= 0; j--) dp[j][i] = max(dp[j][i], dp[j+1][i]);
    }
    int q;
    cin >> q;
    for (int i=0; i < q; i++){
        int l, r;
        cin >> l >> r;
        cout << dp[l-1][r-1] << endl;
    }
}