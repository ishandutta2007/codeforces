#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int fa[2005][2005];
vector <int> v[2005];
char s[2005];
void dfs(int x,int from,int st){
    fa[x][st]=from;
    for(auto t:v[x])
        if(t!=from)
            dfs(t,x,st);
}
int solve(int x,int y){
    if(dp[x][y]!=-1) return dp[x][y];
    if(x==y) return dp[x][y]=1;
    if(fa[x][y]==y) return dp[x][y]=s[x]==s[y]?2:1;
    return dp[x][y]=max({solve(fa[x][y],fa[y][x])+(s[x]==s[y]?2:0),solve(fa[x][y],y),solve(x,fa[y][x])});
}
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
        for(int i=1;i<=n;i++) dfs(i,0,i);
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]=-1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                ans=max(ans,solve(i,j));
        printf("%d\n",ans);
    }
    return 0;
}