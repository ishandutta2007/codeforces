#include <bits/stdc++.h>
using namespace std;

int n,m;
int used[1005][1005];
string s[1005];
int dp[1005][1005];
int ans;
char nxt[300];


void dfs(int x,int y){
    if (used[x][y]==2) return;
    if (used[x][y]==1) {
        cout<<"Poor Inna!";
        exit(0);
    }
    dp[x][y]=1;
    used[x][y]=1;
    char c=s[x][y];
    c=nxt[c];
    if (y+1<m && s[x][y+1]==c) { dfs(x,y+1); dp[x][y]=max(dp[x][y],dp[x][y+1]+1);}
    if (y && s[x][y-1]==c) { dfs(x,y-1); dp[x][y]=max(dp[x][y],dp[x][y-1]+1);}
    if (x<n && s[x+1][y]==c) { dfs(x+1,y); dp[x][y]=max(dp[x][y],dp[x+1][y]+1);}
    if (x>1 && s[x-1][y]==c) { dfs(x-1,y); dp[x][y]=max(dp[x][y],dp[x-1][y]+1);}
    ans=max(ans,dp[x][y]/4);
    used[x][y]=2;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>s[i];
    nxt['D']='I';
    nxt['I']='M';
    nxt['M']='A';
    nxt['A']='D';
    for (int i=1;i<=n;++i)
        for (int j=0;j<m;++j)
        if (used[i][j]==0 && s[i][j]=='D') dfs(i,j);
    if (!ans) cout<<"Poor Dima!";
    else cout<<ans;
}