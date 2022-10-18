#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=1000005;

int n;
vector<int> adj[maxn];
int dpp[maxn],*dp[maxn],*pt=dpp;
int dep[maxn],hvs[maxn],ans[maxn];

void dfs1(int u){
    dep[u]=1;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(!dep[v]){
            dfs1(v);
            dep[u]=max(dep[u],dep[v]+1);
            if(dep[v]>dep[hvs[u]])hvs[u]=v;
        }
    }
}

void dfs2(int u,int f){
    dp[u]=++pt;
    if(hvs[u]){
        dfs2(hvs[u],u);
        ans[u]=ans[hvs[u]]+1;
    }
    dp[u][0]=1;if(dp[u][0]>=dp[u][ans[u]])ans[u]=0;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v!=f&&v!=hvs[u]){
            dfs2(v,u);
            for(int j=0;j<dep[v];j++){
                dp[u][j+1]+=dp[v][j];
                if(dp[u][j+1]>dp[u][ans[u]]||(dp[u][j+1]==dp[u][ans[u]]&&j+1<ans[u]))ans[u]=j+1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);
    }
    dfs1(1);
    dfs2(1,0);
    for(int i=1;i<=n;i++)cout<<ans[i]<<'\n';
    return 0;
}