#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=105;
const int dic=26;

int n;
vector<pair<int,int> > adj[maxn];
int dp[maxn][maxn][dic];

bool dfs(int u,int v,int c){
    if(dp[u][v][c]!=-1)return dp[u][v][c];
    for(int i=0;i<adj[u].size();i++){
        if(adj[u][i].second>=c){
            if(!dfs(v,adj[u][i].first,adj[u][i].second))return dp[u][v][c]=1;
        }
    }
    return dp[u][v][c]=0;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;char c;cin>>u>>v>>c;w=c-'a';
        adj[u].push_back(make_pair(v,w));
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<(char)('B'-dfs(i,j,0));
        }cout<<'\n';
    }
    return 0;
}