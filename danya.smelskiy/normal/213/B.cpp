#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int n;
int a[100];
long long dp[105][105];
long long f[10005];
inline long long p(long long x,long long y){
    long long res=1;
    while (y) {
        if (y&1) res=(res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}
inline long long cnk(long long x,long long y){
    if (y>=x) return 1;
    long long res=f[x];
    res=(res*p(f[y],md-2))%md;
    res=(res*p(f[x-y],md-2))%md;
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    f[0]=1;
    for (int i=1;i<=200;++i)
        f[i]=(f[i-1]*i)%md;
    for (int i=0;i<10;++i)
        cin>>a[i];
    for (int i=a[9];i<=n;++i)
        dp[9][i]=1;
    for (int i=8;i>0;--i) {
        for (int j=0;j<=n;++j)
            for (int k=a[i];k<=j;++k)
                dp[i][j]=(dp[i][j]+(dp[i+1][j-k]*cnk(j,k))%md)%md;
    }
    for (int i=1;i<=n;++i)
        for (int k=a[0];k<i;++k)
            dp[0][i]=(dp[0][i]+(dp[1][i-k]*cnk(i-1,k))%md)%md;
    long long ans=0;
    for (int i=1;i<=n;++i)
        ans=(ans+dp[0][i])%md;
    cout<<ans;
}