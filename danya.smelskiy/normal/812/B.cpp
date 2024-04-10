#include <bits/stdc++.h>
using namespace std;

int n,m;

int dp[1001][1001];
string s[1001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    m+=2;
    for (int i=1;i<=n;++i)
        cin>>s[n-i+1];
    while (n) {
        bool t=false;
        for (int i=1;i<=m;++i)
        if (s[n][i-1]=='1') {
            t=true;
            break;
        }
        if (t==false) --n;
        else break;
    }
    if (n==0) {
        cout<<"0";
        return 0;
    }
    dp[1][1]=0;
    dp[1][m]=(m-1);
    for (int i=1;i<n;++i) {
        int p1=-1,p2=-1;
        for (int j=1;j<=m;++j) {
            if (s[i][j-1]=='1' && p1==-1) p1=j;
            if (s[i][j-1]=='1') p2=j;
        }
        if (p1==-1) {
            dp[i+1][1]=dp[i][1]+1;
            dp[i+1][m]=dp[i][m]+1;
            continue;
        }
        dp[i+1][1]=min(dp[i][1]+p2-1+p2-1+1,dp[i][m]+m);
        dp[i+1][m]=min(dp[i][m]+(m-p1+1)-1+(m-p1+1)-1+1,dp[i][1]+m);
    }
    int p1=-1;
    int p2=-1;
    for (int i=1;i<=m;++i)
    if (s[n][i-1]=='1') {
        p2=i;
        if (p1==-1) p1=i;
    }
    int ans=min(dp[n][m]+(m-p1),dp[n][1]+p2-1);
    cout<<ans;
}