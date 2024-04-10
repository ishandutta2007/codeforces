#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=4e5+7,inf=998244353;typedef ll aN[N];
#define ms(x,y,z)memset(x,y,sizeof(ll)*((z)+1))
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN next,head,cur,dis,to,w,p,q,d;ll cnt;void add_(ll u,ll v,ll c){next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;}
void add(ll u,ll v,ll w){/*printf("%lld %lld %lld\n",u,v,w);*/add_(u,v,w),add_(v,u,0);}
int bfs(ll s,ll e){
    memcpy(cur,head,sizeof(ll)*(e+1)),ms(dis,-1,e);dis[q[1]=s]=0;rfor(ll h=1,t=1,u;h<=t;)
    rfor(ll i=head[u=q[h++]];i;i=next[i])if(w[i]&&!~dis[to[i]])dis[q[++t]=to[i]]=dis[u]+1;return!!~dis[e];
}ll dfs(ll u,ll t,ll flow){//printf("%lld %lld %lld\n",u,t,flow);
    if(u==t)return flow;ll now=flow,f;rfor(ll&i=cur[u],v;v=to[i],i&&now;i=next[i])if(w[i]&&dis[v]==dis[u]+1)
    f=dfs(v,t,std::min(w[i],now)),now-=f,w[i]-=f,w[i^1]+=f;return flow-now;
}void calc(){
    ll n=readll(),m=readll(),k=readll(),s=0,t=n+m+1,x=0,u,v,f=0,c=1,fl=0;cnt=1,ms(head,0,t),ms(d,0,n),ms(p,0,m);
    rep(i,1,m)d[u=readll()]++,d[v=readll()]++,add(u,i+n,1),add(v,i+n,1);rep(i,1,n)f+=x=d[i]>k?2*(d[i]-k):0,add(s,i,x);
    rep(i,1,m)add(i+n,t,1);while(bfs(s,t))fl+=dfs(s,t,inf);rep(i,1,m)p[i]=0;if(fl!=f){rep(i,1,m)printf("0 ");return;}
    rep(i,1,n)rfor(ll j=head[i];j;j=next[j])to[j]^s&&!w[j]&&(p[to[j]-n]=++c/2);c/=2;rep(i,1,m)printf("%lld ",p[i]?:++c);
}int main(){ll T=readll();while(T --> 0)calc(),puts("");return 0;}