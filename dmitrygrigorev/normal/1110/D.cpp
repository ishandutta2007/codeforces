#include<bits/stdc++.h>
#define int long long
using namespace std;
int t[1000000];
int INF = -1e18;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        t[x-1]++;
    }
    int ans = 0;
    for (int i=0; i < m; i++){
        while (t[i] >= 9){
            ans ++;
            t[i] -= 3;
        }
    }
    int dp[9][9], dp2[9][9];
    for (int i=0; i < 9; i++) for (int j=0; j < 9; j++) dp[i][j] = INF;
    dp[0][0] = 0;
    int ses[20];
    for (int i=0;i<20;i++) ses[i] = i/3;
    for (int i=0; i < m; i++){
        for (int j=0;j<9;j++) for (int k=0;k<9;k++) dp2[j][k] = INF;
        for (int j=0; j < 9; j++) for (int k=0; k < 9; k++){
            if (dp[j][k] < 0) continue;
            int T = t[i];
            T = min(T, j);
            T = min(T, k);
            for (int e=0; e <= T; e++){
                //if (i==4 && j==3 && k==2) cout << T << endl;
                dp2[k-e][t[i]-e] = max(dp2[k-e][t[i]-e], dp[j][k] + e + ses[j-e]);
            }
        }
        for (int j=0;j<9;j++) for (int k=0;k<9;k++) dp[j][k] = dp2[j][k];
    }
    int tet =0;
    for (int i=0;i<9;i++) for (int j=0;j<9;j++) tet = max(tet, dp[i][j]+i/3+j/3);
    cout << ans+tet;
}