#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

long long n,m,k;
long long c[205][205];
long long dp[205][20005];
long long dp1[205][2];
inline long long p(long long x,long long y){
    long long res=1;
    while (y) {
        if (y&1) res=(res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}
int main(){
    //
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    c[0][0]=1;
    for (int i=1;i<=n;++i)
        for (int j=0;j<=n;++j)
            c[i][j]=(c[i-1][j] + ( j ? c[i-1][j-1] : 0ll))%md;
    dp[0][0]=1;
    for (int i=0;i<=n;++i)
        dp1[i][0]=p(c[n][i],m/n),dp1[i][1]=p(c[n][i],m/n+1);
    for (int i=1;i<=n;++i) {
        int y=(i<=m%n ? 1 : 0);
        for (int j=0;j<=k;++j){
            dp[i][j]=dp[i-1][j];
            for (int z=1;z<=min((long long)j,n);++z) {
                dp[i][j]=(dp[i][j]+(dp[i-1][j-z]*dp1[z][y]))%md;
            }
        }
    }
    cout<<dp[n][k];
}