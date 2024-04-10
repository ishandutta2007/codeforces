#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define log fss
typedef long long ll;typedef long double ld;const ll N=(1<<18)+7,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];
inline ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
inline ll readb(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'1';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='1';x=x*2+(c^48),c=getchar());return x*w;
}aN next,head,dis,cur,to,w,f,q,in,st,log;ll cnt=1,top=0;int qmin(ll&a,ll b){return a>b?a=b,1:0;}
void add_(ll u,ll v,ll c,ll g){next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c,f[cnt]=g;}
void add(ll u,ll v,ll c,ll g){add_(u,v,c,g),add_(v,u,0,-g);}
int bfs(ll s,ll e,ll n){
	ll sz=(n+1)<<3;memset(dis,0x3f,sz),memcpy(cur,head,sz);dis[q[1]=s]=0,in[s]=1;
	rfor(ll h=1,t=1,u;h<=t;)rfor(ll i=head[in[u=q[h++]]=0,u],v;v=to[i],i;i=next[i])
	if(w[i]&&qmin(dis[v],dis[u]+f[i])&&!in[v])in[q[++t]=v]=1;return dis[e]!=inf;
}ll dfs(ll u,ll t,ll flow){
	if(u==t)return flow;ll now=flow,l;rfor(ll i=cur[u],v;cur[u]=next[i],v=to[i],i&&now;i=cur[u])
	if(w[i]&&dis[v]==dis[u]+f[i])l=dfs(v,t,std::min(now,w[i])),w[i]-=l,w[i^1]+=l,now-=l;return flow-now;
}ll yc;void dfs(ll u){
	rfor(ll i=head[u],v;v=to[i],i;head[u]=next[i],i=head[u])while(w[i^1]&&f[i]==1)w[i^1]--,dfs(v),st[++top]=v;u+=yc;
	rfor(ll i=head[u],v;v=to[i],i;head[u]=next[i],i=head[u])while(w[i^1]&&f[i]==1)w[i^1]--,dfs(v),st[++top]=v;
}int main(){
	ll k=readll(),n=readll(),u,v,s=2<<k,e=s+1,yc=::yc=1<<k,f,flow=0,sum=0;add(s,0,1,0);
	ref(j,0,k)ref(i,0,yc>>1)u=i+(i>>j<<j),v=u|1<<j,add(u,v,inf,1),add(u+yc,v,inf,1);
	ref(i,0,yc)add(i,0,inf,1),add(i+yc,0,inf,1);rep(i,1,n)u=readb(),add(s,u+yc,1,0),add(u,e,1,0);
	while(bfs(s,e,e))f=dfs(s,e,inf),flow+=f,sum+=f*dis[e];printf("%lld\n",sum);dfs(0);rep(i,2,yc)log[i]=log[i>>1]+1;
	per(i,top,1)st[i]?printf("%lld ",k-1-log[st[i]-st[i+1]]):printf("R ");return 0;
}/*per(i,top,1)printf("%lld\n",st[i]);*//*printf("%lld %lld %lld,%lld\n",u,v,c==inf?-1:c,g);*///,printf("%lld %lld\n",f,dis[e]);//exit(0);
//	ref(u,0,yc){
//	rfor(ll i=head[u],v;head[u]=next[i],v=to[i],i;i=head[u])if(w[i^1]&&::f[i]==1)printf("%lld %lld %lld\n",u,v,w[i^1]);
//	u+=yc;
//	rfor(ll i=head[u],v;head[u]=next[i],v=to[i],i;i=head[u])if(w[i^1]&&::f[i]==1)printf("%lld %lld %lld\n",u-yc,v,w[i^1]);
//	u-=yc;
//	}