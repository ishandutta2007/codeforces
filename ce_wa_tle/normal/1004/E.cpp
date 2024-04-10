#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=2e6+9,inf=1e9+7;typedef ll aN[N];
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN next,to,head,w,deep,l,f,in,q,zj;ll cnt=0;void add(ll u,ll v,ll c){next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;}
ll dfs0(ll u,ll fa,ll c){
    ll m=u;deep[u]=deep[f[u]=fa]+c;rfor(ll i=head[u],v,f;v=to[i],i;i=next[i])
    if(to[i]^fa)f=dfs0(v,u,w[i]),deep[f]>deep[m]&&(m=f);return m;
}void dfs2(ll u,ll fa){
    rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(to[i]^fa)dfs2(v,u),!in[v]&&(l[u]=std::max(l[u],l[v]+w[i]));
}int main(){
    ll n=readll(),k=readll(),u,v,w,m=0;rep(i,2,n)u=readll(),v=readll(),w=readll(),add(u,v,w),add(v,u,w);
    u=dfs0(1,0,0),v=dfs0(u,0,0);rfor(ll now=v;now;now=f[now])in[zj[++m]=now]=1;dfs2(u,0);ll len=deep[v];ll h=1,t=0;
    ll ans=inf;rep(i,1,m){while(h<=t&&l[zj[q[t]]]<=l[zj[i]])t--;if(i>k){while(h<=t&&q[h]<=i-k)h++;}q[++t]=i;
    ans=std::min(ans,std::max(l[zj[q[h]]],std::max(i>k?len-deep[zj[i-k+1]]:0,deep[zj[i]])));}printf("%lld\n",ans);return 0;
}//printf("%lld %lld %lld\n",l[zj[q[h]]],i>k?le+deep[zj[i-k+1]]:0,deep[zj[i]]);