#include<bits/stdc++.h>
using namespace std;

int n,lvs;
vector<int> g[300005];
bool s[300005];
bool lf[300005];
int f[300005];
int dp[300005];

int dfs(int x){
    if(dp[x]!=-1)return dp[x];
    if(s[x]){
        dp[x]=1e9;
        for(int i=0;i<g[x].size();i++){
            int y=g[x][i];
            dp[x]=min(dp[x],dfs(y));
        }
        
    }else{
        dp[x]=0;
        for(int i=0;i<g[x].size();i++){
            int y=g[x][i];
            dp[x]+=dfs(y);
        }
    }
    return dp[x];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=2;i<=n;i++){
        cin>>f[i];
        g[f[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        if(g[i].size()==0){
            dp[i]=1;lvs++;
        }
    }
    cout<<lvs-dfs(1)+1;

    return 0;
}