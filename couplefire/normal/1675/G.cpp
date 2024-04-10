#include <bits/stdc++.h>
using namespace std;

const int N = 255;
const int INF = 0x3f3f3f3f;

int n, m, arr[N];
int dp[N][N][N<<1], pre[N][N*3];

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i<=n; ++i)
        cin >> arr[i];
    memset(dp, INF, sizeof dp);
    memset(pre, INF, sizeof pre);
    for(int i = 0; i<=m; ++i)
        dp[n][i][m] = 0, pre[i][i+m] = 0;
    for(int i = 1; i<=m; ++i)
        for(int j = 0; j<=3*m; ++j)
            pre[i][j] = min(pre[i][j], pre[i-1][j]);
    for(int i = n-1; i>=0; --i){
        for(int j = 0; j<=m; ++j)
            for(int k = 0; k<=2*m; ++k)
                dp[i][j][k] = pre[j][arr[i+1]+k];
        memset(pre, INF, sizeof pre);
        for(int j = 0; j<=m; ++j)
            for(int k = 0; k<=2*m; ++k)
                pre[j][j+k] = min(pre[j][j+k], dp[i][j][k]+abs(k-m));
        for(int j = 1; j<=m; ++j)
            for(int k = 0; k<=3*m; ++k)
                pre[j][k] = min(pre[j][k], pre[j-1][k]);
    }
    cout << dp[0][m][m] << '\n';
}