#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef unsigned long long ull;const ll N=1216333,inf=1e17,mod=1e9+7;typedef ll aN[N];
ll iabs(ll a){return a<0?-a:a;}
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN to,head,a,z,b,fr,tm,next,hs;ll cnt=0;
void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
int main(){
    ll n=readll(),m=readll(),u,v;
    rep(i,1,m)fr[i]=u=readll(),tm[i]=v=readll(),v>u&&(std::swap(u,v),0),add(u,v),z[u]++,z[v]++,b[i]=1;
    rep(u,1,n){
        rfor(ll i=head[u],v;v=to[i],i;i=next[i])hs[z[v]]=1,a[v]||(a[v]=1,b[i]--,z[u]--);
        rfor(ll i=head[u],v;hs[z[u]]&&(v=to[i],i);i=next[i])a[v]=0,b[i]++,z[u]++; 
        rfor(ll i=head[u],v;v=to[i],i;i=next[i])hs[z[v]]=0;
    }ll cnt=0;rep(i,1,n)cnt+=a[i];printf("%lld\n",cnt);rep(i,1,n)if(a[i])printf("%lld ",i);puts("");
    rep(i,1,m)printf("%lld %lld %lld\n",fr[i],tm[i],b[i]);return 0;
}