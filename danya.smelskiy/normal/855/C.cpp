#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
long long n,m,kk,xx;
int x,y;
vector<int> v[100005];
long long dp[100005][12][3];


void dfs(int x,int y){
    dp[x][0][0]=kk-1;
    dp[x][1][1]=1;
    dp[x][0][2]=m-kk;
    long long dp2[xx+2][3];
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dfs(to,x);
        for (int i=0;i<=xx;++i)
            for (int j=0;j<3;++j)
                dp2[i][j]=0;
        for (int j=0;j<=xx;++j) {
            for (int k=0;k<=xx-j;++k) {
                dp2[j+k][0]=(dp2[j+k][0]+dp[x][j][0]*(dp[to][k][0]+dp[to][k][1]+dp[to][k][2])%md)%md;
                dp2[j+k][1]=(dp2[j+k][1]+dp[x][j][1]*(dp[to][k][0])%md)%md;
                dp2[j+k][2]=(dp2[j+k][2]+dp[x][j][2]*(dp[to][k][0]+dp[to][k][2])%md)%md;
            }
        }
        for (int j=0;j<=xx;++j)
            for (int k=0;k<3;++k)
                dp[x][j][k]=dp2[j][k];
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<n;++i) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cin>>kk>>xx;
    dfs(1,-1);
    long long ans=0;
    for (int i=0;i<=xx;++i)
        ans=(ans+dp[1][i][0]+dp[1][i][1]+dp[1][i][2])%md;
    cout<<ans;
}