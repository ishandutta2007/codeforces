#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[1503][1503];
long long dp[1503][1503];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j){
            cin>>a[i][j];
            a[i][j]+=a[i][j-1];
        }
    }
    int x=0,y=1;
    for (int i=1;i<=m;++i) {
        dp[0][i]=a[1][i];
    }
    for (int i=2;i<=n;++i) {
        swap(x,y);
        if ((i&1)==0) {
            for (int j=m-1;j>0;--j)
                dp[y][j]=max(dp[y][j],dp[y][j+1]);
            dp[x][m]=-1e15;
            for (int j=1;j<m;++j)
                dp[x][j]=a[i][j]+dp[y][j+1];
            } else {
                for (int j=2;j<=m;++j) {
                    dp[y][j]=max(dp[y][j],dp[y][j-1]);
                }
                dp[x][1]=-1e15;
                for (int j=2;j<=m;++j)
                    dp[x][j]=a[i][j]+dp[y][j-1];
            }
    }
    long long ans=-1e18;
    for (int i=1;i<=m;++i)
        ans=max(ans,dp[x][i]);
    cout<<ans;
}