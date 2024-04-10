#include <bits/stdc++.h>
using namespace std;
int  n,t;
long double p;
long double dp[2005][2005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>p>>t;
    dp[0][0]=1;
    for (int i=0;i<t;++i){
        for (int j=0;j<n;++j) {
            dp[i+1][j+1]+=dp[i][j]*p;
            dp[i+1][j]+=dp[i][j]*(1-p);
        }
        dp[i+1][n]+=dp[i][n];
    }
    long double ans=0;
    for (int i=0;i<=n;++i){
        ans+=dp[t][i]*i;
    }
    cout<<fixed<<setprecision(6)<<ans;
}