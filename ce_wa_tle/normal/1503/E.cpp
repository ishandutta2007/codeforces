#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgetchar
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define f(x...)asdf(x)
typedef long long ll;const ll N=1e6+7,mod=998244353,m2=mod*mod;typedef ll aN[N];int(*gc)()=getchar;
int fgetchar(){static char s[1<<23],*p1=s,*p2=s;return p1==p2&&(p2=(p1=s)+fread(s,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
ll readll(){
    ll x=0,w=1;char c=gc();for(;c<'0'||c>'9';c-'-'||(w=-w),c=gc());for(;c>='0'&&c<='9';x=x*10+(c^48),c=gc());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}
aN jc,njc,ny;inline ll C(ll n,ll m){return n<0||n>m?0:jc[m]*njc[n]%mod*njc[m-n]%mod;}
inline ll S(ll n,ll m){return C(n,n+m);}inline int qdel(ll&a,ll b){return a>=b?a-=b,1:0;}
int main(){
    ll n=readll(),m=readll(),ans=0;ny[1]=jc[1]=njc[1]=jc[0]=njc[0]=1;
    rep(i,2,n+m)jc[i]=jc[i-1]*i%mod,njc[i]=njc[i-1]*(ny[i]=(mod-mod/i)*ny[mod%i]%mod)%mod;
    rep(i,1,n-1){ll s=0;rep(j,1,m-1)qdel(ans+=S(n-i-1,j)*S(n-i,m-j-1)%mod*s,m2),s=(s+S(i,j-1)*S(i-1,m-j))%mod;}
    std::swap(n,m);
    rep(i,1,n-1){ll s=0;rep(j,1,m-1)qdel(ans+=S(n-i-1,j)*S(n-i,m-j-1)%mod*(s=(s+S(i,j-1)*S(i-1,m-j))%mod),m2);}
    printf("%lld\n",ans*2%mod);return 0;
}