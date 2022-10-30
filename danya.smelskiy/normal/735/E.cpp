#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;


long long dp[105][50];
long long f[105];
int n,k,x,y;
vector<int> v[105];
void dfs(int x,int y){
    dp[x][0]=dp[x][k+1]=1;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dfs(to,x);
        for (int j=0;j<=k+k;++j) {
            for (int z=0;z<=k+k;++z) {
                int nw;
                if (j+z<=k+k) nw=min(j,z+1);
                else nw=max(j,z+1);
                f[nw]=(f[nw]+dp[x][j]*dp[to][z])%md;
            }
        }
        for (int j=0;j<=k+k;++j){
            dp[x][j]=f[j];
            f[j]=0;
        }
    }

}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<n;++i) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,-1);
    long long ans=0;
    for (int i=0;i<=k;++i)
        ans=(ans+dp[1][i])%md;
    cout<<ans;
}