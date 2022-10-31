#include <bits/stdc++.h>
using namespace std;
int n,m,k;
long long d[305][305];
long long dp[305][305];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i)
        for (int j=i;j<=n;++j)
            d[i][j]=1e15;
    for (int i=1;i<=m;++i) {
        int x,y;
        long long z;
        cin>>x>>y>>z;
        for (int j=x;j<=y;++j)
            d[j][y]=min(d[j][y],z);
    }
    for (int i=0;i<=n;++i)
        for (int j=1;j<=n;++j)
            dp[i][j]=1e15;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=i;++j) {
            dp[i][j]=dp[i-1][j];
            for (int k=i-1;k>=0 && i-k<=j;--k)
                dp[i][j]=min(dp[i][j],dp[k][j-i+k]+d[k+1][i]);
        }
    }
    cout<<(dp[n][k]==1e15 ? -1 : dp[n][k]);
}