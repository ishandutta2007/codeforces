#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=6e5+7,inf=998244353;typedef ll aN[N];aN next,head,u,v,to,q,f,d;ll cnt=0;
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
void add(ll u,ll v){next[++cnt]=head[u],d[to[head[u]=cnt]=v]++;}
void calc(ll n){
    ll t=0;rep(i,1,n)if(!d[i])q[++t]=i;rep(h,1,t){ll u=q[h];if(h>=t-1)f[u]+=n-t;
    if(h==t-1)rfor(ll i=head[q[t]];i;i=next[i])if(d[to[i]]==1){f[u]-=inf;break;}
    rfor(ll i=head[q[h]];i;i=next[i])if(!--d[to[i]])q[++t]=to[i];} 
}int main(){
    ll n=readll(),m=readll(),sz=sizeof(ll)*(n+1);rep(i,1,m)u[i]=readll(),v[i]=readll(),add(u[i],v[i]);calc(n);
    memset(head,cnt=0,sz),memset(d,0,sz);rep(i,1,m)add(v[i],u[i]);calc(n);ll res=0;
    rep(i,1,n)res+=f[i]>=n-2/*,printf("%lld\n",f[i])*/;printf("%lld\n",res);return 0;
}