#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2e5+7,mod=1e9+7,mod2=mod*mod;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN a,b,d,w,next,head,to,s,ans;ll vis[5003],cnt=0;void add_(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
void add(ll u,ll v){add_(u,v),add_(v,u);}
int EK(ll u){
    if(vis[u])return 0;vis[u]=1;rfor(ll i=head[u],v;v=to[i],i;i=next[i])
    if(!~w[v]||EK(w[v]))return w[w[u]=v]=u,1;return 0;
}int main(){
    const ll n=readll(),m=readll(),f=5002;rep(i,1,n)a[i]=readll();rep(i,1,n)b[i]=readll();(void)m;const ll k=readll();
    rep(i,1,k)s[d[i]=readll()]++;rep(i,1,n)if(!s[i])add(a[i],b[i]+f);ll now=0;memset(w,-1,sizeof(w));
    per(i,k,1){while(memset(vis,0,sizeof(vis)),EK(now))now++;ans[i]=now,add(a[d[i]],b[d[i]]+f);}
    rep(i,1,k)printf("%lld\n",ans[i]);return 0; 
}