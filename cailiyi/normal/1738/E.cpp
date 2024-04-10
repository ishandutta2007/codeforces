#include<bits/stdc++.h>
#define N 100000
#define mod 998244353
using namespace std;
int T,n,ans;
long long s[N+5];
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
int fac[N+5],ifac[N+5];
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
inline int calc1(int a,int b)
{
    int ret=0;
    for(int i=0;i<=min(a,b);++i)
        ret=(ret+1ll*C(a,i)*C(b,i))%mod;
    return ret;
}
inline int calc2(int a)
{
    int ret=0;
    for(int i=0;i<=a;++i)
        add(ret,C(a,i));
    return ret;
}
int main()
{
    for(init(N+1),scanf("%d",&T);T--;)
    {
        scanf("%d",&n),ans=1;
        for(int i=1;i<=n;++i)
            scanf("%lld",s+i),s[i]+=s[i-1];
        for(int i=1,j=n-1;i<=j;)
        {
            while(j>=i && s[i]+s[j]>s[n]) --j;
            if(j<i) break;
            int i1=i,j1=j;
            while(i1<n-1 && s[i1+1]==s[i]) ++i1;
            while(j1>1 && s[j1-1]==s[j]) --j1;
            if(s[i]+s[j]==s[n])
            {
                if(i1<j1) ans=1ll*ans*calc1(i1-i+1,j-j1+1)%mod;
                else ans=1ll*ans*calc2(i1-i+1)%mod;
                j=j1-1;
            }
            i=i1+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}