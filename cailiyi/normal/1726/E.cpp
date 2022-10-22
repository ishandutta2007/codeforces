#include<bits/stdc++.h>
#define N 300000
#define mod 998244353
using namespace std;
int T,n,g[N+5],f[N+5];
const int inv2=(mod+1)>>1;
inline int fmod(const int &x) {return x<mod?x:x-mod;}
inline int qmod(const int &x) {return x<0?x+mod:x;}
inline void add(int &a,const int &b) {if((a+=b)>=mod) a-=mod;}
inline void sub(int &a,const int &b) {if((a-=b)<0) a+=mod;}
inline int quick_pow(int x,int b)
{
    int ret=1;
    while(b)
    {
        if(b&1) ret=1ll*ret*x%mod;
        x=1ll*x*x%mod,b>>=1;
    }
    return ret;
}
inline int inv(int x) {return quick_pow(x,mod-2);}
int fac[N+5],ifac[N+5],ans;
inline void init(int n=N)
{
    fac[0]=1;for(int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
    ifac[n]=inv(fac[n]);for(int i=n;i;--i) ifac[i-1]=1ll*ifac[i]*i%mod;
}
inline int C(int n,int m)
{
    if(!m) return 1;
    return n>=m && m>0?1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod:0;
}
int main()
{
    init(),g[0]=1,f[0]=1;
    for(int i=1;i<=N;++i)
        g[i]=(g[i-1]+1ll*(i-1)*g[i-2])%mod;
    for(int i=1;i<=N;++i)
        f[i]=2ll*f[i-1]*(i*2-1)%mod;
    for(scanf("%d",&T);T--;)
    {
        scanf("%d",&n),ans=0;
        for(int i=0;i*2<=n;i+=2)
            ans=(ans+1ll*C(n-i,i)*f[i/2]%mod*g[n-i*2])%mod;
        printf("%d\n",ans);
    }
    return 0;
}