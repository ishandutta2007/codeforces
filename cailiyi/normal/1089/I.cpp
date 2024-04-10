#include<bits/stdc++.h>
#define N 400
using namespace std;
int T,mod,n,ans[N+5],g[N+5],f[N+5][N+5],fac[N+5];
int main()
{
    scanf("%d %d",&T,&mod);
    fac[0]=1;for(int i=1;i<=N;++i) fac[i]=1ll*fac[i-1]*i%mod;
    for(int i=1;i<=N;g[i]=(fac[i]-g[i]+mod)%mod,++i)
        for(int j=1;j<i;++j) g[i]=(g[i]+1ll*fac[i-j]*g[j])%mod;
    f[0][0]=1;for(int i=1;i<=N;++i)
        for(int j=i;j<=N;++j)
            for(int k=1;k<=j;++k)
                f[i][j]=(f[i][j]+1ll*f[i-1][j-k]*fac[k])%mod;
    ans[1]=1,ans[2]=2,ans[3]=0;
    for(int i=4;i<=N;++i)
    {
        for(int j=1;j<i;++j) ans[i]=(ans[i]+2ll*fac[i-j]*g[j])%mod;
        for(int j=4;j<i;++j) ans[i]=(ans[i]+1ll*f[j][i]*ans[j])%mod;
        ans[i]=(fac[i]-ans[i]+mod)%mod;
    }
    while(T--) scanf("%d",&n),printf("%d\n",ans[n]);
    return 0;
}