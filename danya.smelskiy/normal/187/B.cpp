#include <bits/stdc++.h>
using namespace std;

int n,m,q;
int l[65][65][65];
int dp[65][65][65];
int dp2[65][65];
void solve(int x){
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            for (int k=1;k<=n;++k)
                l[x][j][k]=min(l[x][j][k],l[x][j][i]+l[x][i][k]);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>q;
    for (int i=1;i<=m;++i){
        for (int j=1;j<=n;++j)
            for (int k=1;k<=n;++k)
                cin>>l[i][j][k];
        solve(i);
    }
    for (int i=1;i<=n;++i)
    for (int j=1;j<=n;++j) {
        dp2[i][j]=1e9;
        for (int k=1;k<=m;++k)
            dp2[i][j]=min(dp2[i][j],l[k][i][j]);
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            for (int k=0;k<=n;++k)
            dp[i][j][k]=dp2[i][j];
    for (int k=1;k<=n;++k)
    for (int z=1;z<=n;++z)
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                dp[i][j][k]=min(dp[i][j][k],dp[i][z][k-1]+dp[z][j][0]);
    for (int i=1;i<=q;++i) {
        int x,y,z;
        cin>>x>>y>>z;
        z=min(z,n);
        cout<<min(dp2[x][y],dp[x][y][z])<<'\n';
    }
}