#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=5005;
const int mdn=998244353;

int n,k;
vector<int> adj[maxn];
int dp[maxn][maxn];
int dpt[maxn],dsz[maxn];

void dfs(int u,int f){
    dp[u][0]=1;
    dsz[u]=1;
    for(int v:adj[u])if(v!=f){
        dfs(v,u);
        for(int j=0;j<=k;j++)dpt[j]=0;
        for(int j=0;j<=k&&j<=dsz[v];j++){
            int vv=(j==0?accumulate(dp[v],dp[v]+min(k+1,dsz[v]),0ll)%mdn:dp[v][j-1]);
            for(int j1=0;j+j1<=k&&j1<dsz[u];j1++){
                int j2=max(j,j1);
                dpt[j2]=(dpt[j2]+dp[u][j1]*(long long)vv)%mdn;
            }
        }
        dsz[u]=max(dsz[u],dsz[v]+1);
        for(int j=0;j<dsz[u]&&j<=k;j++)dp[u][j]=dpt[j];
    }
}
int main(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);adj[v].push_back(u);
    }
    dfs(1,0);
    cout<<accumulate(dp[1],dp[1]+k+1,0ll)%mdn;
    return 0;
}