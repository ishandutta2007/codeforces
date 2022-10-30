#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;



int n,m,k;
int qq[1000005];
int c[2005][2005];
long long ans;
inline long long p(long long x,long long y){
    long long res=1;
    while (y) {
        if (y&1) res=(res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}
int f[1000005];
int dp[1005][1005];
long long ck[2005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    if (m==1) {
        cout<<p(k,n);
        return 0;
    }
    c[0][0]=1;
    for (int i=1;i<=2000;++i) {
        for (int j=0;j<=i;++j) {
            c[i][j]=c[i-1][j];
            if (j) {
                c[i][j]+=c[i-1][j-1];
                if (c[i][j]>=md) c[i][j]-=md;
            }
        }
    }
    f[0]=1;
    for (int i=1;i<=1e6;++i)
        f[i]=(f[i-1]*(long long)i)%md;
    for (int i=0;i<=2000;++i) {
        ck[i]=f[k];
        ck[i]=(ck[i]*p(f[i],md-2))%md;
        ck[i]=(ck[i]*p(f[k-i],md-2))%md;
    }
    qq[0]=1;
    if (m>2) qq[0]=0;
    for (int i=1;i<=k;++i)
        qq[i]=p(i,(n*(m-2)));
    dp[0][0]=1;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=min(i,k);++j) {
            dp[i][j]=((long long)dp[i-1][j]*(long long)j)%md;
            dp[i][j]+=dp[i-1][j-1];
            if (dp[i][j]>=md) dp[i][j]-=md;
        }
    }
    for (int i=1;i<=min(n,k);++i) {
        for (int j=0;j<=i;++j) {
            if (i+i-j>k) continue;
            long long res=ck[i+i-j];
            res=(res*(long long)c[i+i-j][i-j])%md;
            res=(res*(long long)c[i][i-j])%md;
            long long z=dp[n][i];
            z=(z*(long long)f[i])%md;
            res=(res*z)%md;
            res=(res*z)%md;
            res=(res*(long long)qq[j])%md;
            ans+=res;
            if (ans>=md) ans-=md;
        }
    }
    cout<<ans;
}