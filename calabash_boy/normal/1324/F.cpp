#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
int a[maxn],n;
vector<int> E[maxn];
int dp[maxn];
int ans[maxn];
void dfs1(int u,int father){
    dp[u] = a[u];
    for (int v : E[u]){
        if (v == father)continue;
        dfs1(v,u);
        dp[u] += max(0,dp[v]);
    }
}
void dfs2(int root,int father){
    ans[root] = dp[root] + max(0,dp[father]);
    for (int v: E[root]){
        if (v == father)continue;
        dp[root] -= max(dp[v],0);
        dp[root] += max(0,dp[father]);
        dfs2(v,root);
        dp[root] += max(dp[v],0);
        dp[root] -= max(0,dp[father]);
    }
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i] == 0)a[i] = -1;
    }
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,0);
    for (int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}