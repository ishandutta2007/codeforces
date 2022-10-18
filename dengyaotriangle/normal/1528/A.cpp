#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=100005;

int n;
vector<int> adj[maxn];
int a[maxn][2];
long long dp[maxn][2];
void dfs(int u,int f){
    dp[u][0]=dp[u][1]=0;
    for(int v:adj[u])if(v!=f){
        dfs(v,u);
        dp[u][0]+=max(dp[v][0]+abs(a[u][0]-a[v][0]),dp[v][1]+abs(a[u][0]-a[v][1]));
        dp[u][1]+=max(dp[v][0]+abs(a[u][1]-a[v][0]),dp[v][1]+abs(a[u][1]-a[v][1]));
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1];
        for(int i=1;i<=n;i++)adj[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);adj[v].push_back(u);
        }
        dfs(1,0);
        cout<<max(dp[1][0],dp[1][1])<<'\n';
    }
    return 0;
}