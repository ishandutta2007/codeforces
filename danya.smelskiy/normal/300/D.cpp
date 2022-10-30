#include <bits/stdc++.h>
using namespace std;
const long long md=7340033;

long long dp[35][1005];
long long f[1005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    dp[1][0]=1;
    for (int i=2;i<=30;++i) {
        for (int j=0;j<=1000;++j)
            f[j]=0;
        dp[i][0]=1;
        for (int j=0;j<=1000;++j)
            for (int k=0;k<=1000-j;++k)
                f[j+k]+=(dp[i-1][j]*dp[i-1][k]);
        for (int j=0;j<=1000;++j)
            f[j]%=md;
        for (int j=0;j<=1000;++j)
            for (int k=0;k<=1000-j-1;++k)
                dp[i][j+k+1]+=f[j]*f[k];
        for (int j=0;j<=1000;++j)
            dp[i][j]%=md;
    }
    int n;
    cin>>n;
    for (int i=1;i<=n;++i) {
        int sz=1;
        int x,y;
        cin>>x>>y;
        while (x>2 && x%2) {
            x>>=1;
            ++sz;
        }
        cout<<dp[sz][y]<<'\n';
    }
}