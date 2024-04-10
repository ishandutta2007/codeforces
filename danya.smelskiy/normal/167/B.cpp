#include <bits/stdc++.h>
using namespace std;
int n,l,m;
long double p[205];
int a[205];
long double dp[205][205][205];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>l>>m;
    for (int i=1;i<=n;++i){
        cin>>p[i];
    }
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        ++a[i];
    }
    dp[0][0][0]=1;
    for (int i=0;i<n;++i) {
        for (int j=0;j<=i;++j)
        for (int k=0;k<=200;++k) {
            dp[i+1][j][k]+=dp[i][j][k]*(1-p[i+1]/100);
            dp[i+1][j+1][min(200,k+a[i+1])]+=dp[i][j][k]*(p[i+1]/100);
        }
    }
    long double ans=0;
    for (int i=l;i<=n;++i)
        for (int j=0;j<=200;++j)
        if (i<=j+m) ans+=dp[n][i][j];
    cout<<fixed<<setprecision(6);
    cout<<ans;
}