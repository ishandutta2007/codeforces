#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
long long a[100001];
long long kol[100001];
long long dp[5005][5005];
int main(){
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        kol[i]=kol[i-1]+a[i];
        if (i>=m) kol[i]-=a[i-m];
        dp[1][i]=max(kol[i],dp[1][i-1]);
    }
    for (int i=2;i<=k;++i){
        for (int j=m;j<=n;++j)
            dp[i][j]=max(dp[i][j-1],dp[i-1][j-m]+kol[j]);
    }
    cout<<dp[k][n];
}