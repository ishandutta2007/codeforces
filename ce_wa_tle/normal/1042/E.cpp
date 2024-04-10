#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=1e6+9,mod=998244353;typedef ll aN[N];
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct node{ll x,y,w;operator ll()const{return w;}}s[N];ll f[N],ny[N];ll cnt=0;
int main(){
    ll n=readll(),m=readll();rep(i,1,n)rep(j,1,m)s[++cnt]=(node){i,j,readll()};ny[1]=1,n*=m;
    rep(i,2,n)ny[i]=(mod-mod/i)*ny[mod%i]%mod;ll cx=readll(),cy=readll();std::sort(s+1,s+n+1);
    ll sumx2=0,sumy2=0,sumx=0,sumy=0,p=0,sumf=0,sum=0;rep(i,1,n){if(s[i].w!=s[i-1].w)
    while(p!=i-1)++p,sumx+=s[p].x,sumy+=s[p].y,sumx2+=s[p].x*s[p].x,sumy2+=s[p].y*s[p].y,sum++,sumf+=f[p];
//    printf("%lld %lld %lld %lld %lld %lld\n",sumx,sumy,sumx2,sumy2,sumf,sum);
    if(sum)f[i]=((sumf+sumx2+sumy2-2*sumx*s[i].x%mod-2*sumy*s[i].y%mod+mod*3)%mod*ny[sum]+s[i].x*s[i].x+s[i].y*s[i].y)%mod;
    if(s[i].x==cx&&s[i].y==cy)return printf("%lld\n",f[i]),0;}return 0;
}