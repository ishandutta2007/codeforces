#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i++)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=4e5+5,inf=1e9;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN f,g,next,to,head,x,y;ll cnt=0,ans=0;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
void dfs(ll u,ll fa){
    ll d=0,m=-inf,c=-inf;rfor(ll i=head[f[u]=0,g[u]=inf,u],v;v=to[i],i;i=next[i])if(v^fa)dfs(v,u),d++,
    f[u]=std::max(f[u],f[v]),((g[v]>m)&&(c=m,m=g[v],1))||((g[v]>c)&&(c=g[v])),g[u]=std::min(g[u],g[to[i]]+1);
    d||(g[u]=0),ans=std::max(std::max(f[u],m+1),c+2),f[u]=std::max(f[u],d==1?m+1:m+2);
}ll calc(int cases){
    ll n=readll(),u,v;rep(i,2,n)u=x[i]=readll(),v=y[i]=readll(),add(u,v),add(v,u);dfs(1,0),(void)cases;
    memset(head,0,sizeof(ll)*(n+1));while(cnt)next[cnt]=to[cnt]=0,cnt--;return ans;
}int main(){ll T=readll(),cnt=0;while(T --> 0)printf("%lld\n",calc(++cnt));return 0;}