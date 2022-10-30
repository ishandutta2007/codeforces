#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int n,m;
long long a[205];
long long dp[2][205][1005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    dp[0][1][0]=1;
    dp[0][0][0]=1;
    int x,y;
    x=0, y=1;
    for (int i=1;i<n;++i) {
        swap(x,y);
        memset(dp[x],0,sizeof(dp[x]));
        for (int j=i;j>=0;--j) {
            for (int k=0;k<=m;++k) {
                int len=a[i+1]-a[i];
                if (k+len*j<=m) dp[x][j][k+len*j]=(dp[x][j][k+len*j]+dp[y][j][k])%md;
                if (k+len*j<=m) dp[x][j][k+len*j]=(dp[x][j][k+len*j]+j*dp[y][j][k])%md;
                if (k+len*j<=m) dp[x][j+1][k+len*j]=(dp[x][j+1][k+len*j]+dp[y][j][k])%md;
                if (j && k+len*j<=m) dp[x][j-1][k+len*j]=(dp[x][j-1][k+len*j]+dp[y][j][k]*j)%md;
            }
        }
    }
    long long ans=0;
    for (int i=0;i<=m;++i)
        ans=(ans+dp[x][0][i])%md;
    cout<<ans;
}