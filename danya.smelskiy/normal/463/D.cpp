#include <bits/stdc++.h>
using namespace std;


int n,m,ans;
int a[7][1001];
int dp[1001];
int b[1003][1003];
bool used[1003];
int dfs(int x,int d){
    used[x]=true;
    ans=max(ans,d);
    int dd=d;
    for (int i=1;i<=n;++i){
        if (b[x][i]>=m) {
                if (used[i]) {
                    dd=max(dd,d+dp[i]+1);
                } else {
                    dfs(i,d+1);
                    dd=max(dd,d+dp[i]+1);
                }
        }
    }
    ans=max(ans,dd);
    dp[x]=dd-d;
    return dd;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        for (int j=1;j<=n;++j)
        cin>>a[i][j];
    }
    ans=1;
    for (int i=1;i<=m;++i){
        for (int j=1;j<=n;++j){
            for (int z=j+1;z<=n;++z)
                ++b[a[i][j]][a[i][z]];
        }
    }
    for (int i=1;i<=n;++i)
         { dfs(i,1);}
    cout<<ans;
}