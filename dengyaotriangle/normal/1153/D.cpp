#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=300005;

int n;
int op[maxn];
vector<int> adj[maxn];
int dp[maxn];
int cnt=0;
void dfs(int u){
    if(adj[u].size()==0u){
        cnt++;
        dp[u]=1;return;
    }
    if(op[u])dp[u]=0x3fff3fff;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        dfs(v);
        if(op[u]==0)dp[u]+=dp[v];
        else dp[u]=min(dp[u],dp[v]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>op[i];
    for(int i=2;i<=n;i++){
        int p;cin>>p;
        adj[p].push_back(i);
    }
    dfs(1);
    cout<<cnt-dp[1]+1;
    return 0;
}