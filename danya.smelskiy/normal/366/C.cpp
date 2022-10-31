#include <bits/stdc++.h>
using namespace std;
int n,k;
int x,y;
int dp[105][200005];
int xx[105];
int yy[105];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    dp[0][100000]=1;
    for (int i=1;i<=n;++i)
        cin>>xx[i];
    for (int i=1;i<=n;++i)
        cin>>yy[i];
    for (int i=1;i<=n;++i) {
        x=xx[i];
        y=yy[i];
        y*=k;
        for (int j=1;j<=200000;++j)
            if (dp[i-1][j]) {
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                dp[i][j+x-y]=max(dp[i][j+x-y],dp[i-1][j]+x);
            }
    }
    if (dp[n][100000]==1) cout<<"-1"; else
    cout<<dp[n][100000]-1;
}