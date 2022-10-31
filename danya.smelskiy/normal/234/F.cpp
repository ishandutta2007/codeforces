#include <bits/stdc++.h>
using namespace std;
int a,b,n;
int c[205];
int kol;
int dp[205][40005][2];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>a>>b;
    for (int i=1;i<=n;++i) {
        cin>>c[i];
        kol+=c[i];
    }
    if (a+b<kol) {
        cout<<"-1";
        return 0;
    }
    if (a>b) swap(a,b);
    for (int i=0;i<=n;++i)
        for (int j=0;j<=a;++j)
        dp[i][j][0]=dp[i][j][1]=1e9;
    dp[0][0][0]=dp[0][0][1]=0;
    int lastkol=0;
    for (int i=1;i<=n;++i) {
        lastkol+=c[i];
        for (int j=0;j<=a-c[i];++j){
            dp[i][j+c[i]][0]=min(dp[i][j+c[i]][0],min(dp[i-1][j][0],dp[i-1][j][1]+min(c[i],c[i-1])));
        }
        for (int j=0;j<=a;++j)
            if (lastkol-j<=b)
            dp[i][j][1]=min(dp[i][j][1],min(dp[i-1][j][1],dp[i-1][j][0]+min(c[i],c[i-1])));
    }
    int ans=1e9;
    for (int i=0;i<=a;++i)
        ans=min(ans,min(dp[n][i][1],dp[n][i][0]));
    cout<<(ans==1e9? -1: ans);
}