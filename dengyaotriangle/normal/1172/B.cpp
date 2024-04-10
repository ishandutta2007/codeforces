#include<bits/stdc++.h>

using  namespace std;

const int maxn=200005;
const long long mdn=998244353;

vector<int> adj[maxn];

int n;
long long sze[maxn],dp[maxn];
int dep[maxn];
long long jc[maxn];

void dfs(int u){
    sze[u]=1;
    dp[u]=1;
    int cld=0;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(!dep[v]){
            cld++;
            dep[v]=dep[u]+1;
            dfs(v);
            sze[u]+=sze[v];
            dp[u]*=dp[v];
            dp[u]%=mdn;
        }
    }
    dp[u]*=jc[cld];
    dp[u]%=mdn;
    if(u==1) dp[u]*=n;
    else  dp[u]*=cld+1;
    dp[u]%=mdn;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    jc[0]=1;
    for(int i=1;i<=n;i++) jc[i]=(jc[i-1]*(long long)i)%mdn;
    dep[1]=1;
    dfs(1);
    cout<<(dp[1])%mdn;
    return 0;
}