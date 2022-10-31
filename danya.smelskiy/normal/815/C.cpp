#include <bits/stdc++.h>
using namespace std;

vector<int> v[5005];
int sz[5005];
long long b,dp[5005][5005][2];
int n;
long long c[5005],d[5005];
inline bool cmp(int a,int b){
    return sz[a]>sz[b];
}
void dfs(int x){
    sz[x]=1;
    dp[x][1][0]=c[x];
    dp[x][1][1]=c[x]-d[x];
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        dfs(to);
    }
    sort(v[x].begin(),v[x].end());
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        for (int j=sz[x];j+1;--j) {
            for (int k=1;k<=sz[to];++k) {
                if (j) dp[x][j+k][1]=min(dp[x][j+k][1],dp[x][j][1]+min(dp[to][k][0],dp[to][k][1]));
                dp[x][j+k][0]=min(dp[x][j+k][0],dp[to][k][0]+dp[x][j][0]);
            }
        }
        sz[x]+=sz[to];
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>b;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            dp[i][j][0]=dp[i][j][1]=1e18;
    for (int i=1;i<=n;++i) {
        cin>>c[i]>>d[i];
        if (i>1) {
            int x;
            cin>>x;
            v[x].push_back(i);
        }
    }
    dfs(1);
    int ans=0;
    for (int i=1;i<=n;++i)
        if (dp[1][i][0]<=b || dp[1][i][1]<=b) ans=i;
    cout<<ans;
}