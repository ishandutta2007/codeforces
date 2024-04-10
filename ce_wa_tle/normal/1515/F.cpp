#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=6e5+8;typedef ll aN[N];ll k,t,h;aN next,to,head,id,ans,a,vis;ll cnt=0;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
void add(ll u,ll v,ll i){next[++cnt]=head[u],to[head[u]=cnt]=v,id[cnt]=i;}
void dfs(ll u,ll fa){
	vis[u]=1;rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(!vis[v])dfs(v,u),ans[a[v]>=0?a[u]+=a[v],++t:--h]=id[i]; 
}int main(){
	ll n=readll(),m=readll(),u,v,s=0;::k=readll();rep(i,1,n)s+=a[i]=readll()-k;
	if(s<-k)return puts("NO");else puts("YES");rep(i,1,m)u=readll(),v=readll(),add(u,v,i),add(v,u,i);
	::t=0,::h=n;dfs(1,0);rep(i,1,n-1)printf("%lld\n",ans[i]);return 0;
}