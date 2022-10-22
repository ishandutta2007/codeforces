#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2e5+7,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct pt{ll x,y,w,id,rk;void read(ll i){x=readll(),y=readll(),w=readll(),id=i,rk=((y&1)^1)<<1|((x^y)&1);}}p[N];
int cmpx(const pt&a,const pt&b){return a.x==b.x?a.y<b.y:a.x<b.x;}
int cmpy(const pt&a,const pt&b){return a.y==b.y?a.x<b.x:a.y<b.y;}
aN next,to,head,w,cur,dis,q;ll cnt=1;void add_(ll u,ll v,ll c){next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;}
void add(ll u,ll v,ll w){/*printf("%lld %lld %lld\n",u,v,w);*/add_(u,v,w),add_(v,u,0);}
int bfs(ll s,ll e){
    ll sz=sizeof(ll)*(e+1);memcpy(cur,head,sz),memset(dis,-1,sz),dis[q[1]=s]=0;rfor(ll h=1,t=1,u;h<=t;)
    rfor(ll i=head[u=q[h++]];i;i=next[i])if(w[i]&&!~dis[to[i]])dis[q[++t]=to[i]]=dis[u]+1;return!!~dis[e];
}ll dfs(ll u,ll t,ll flow){ 
    if(u==t)return flow;ll now=flow,f;rfor(ll i=cur[u];i&&now;i=cur[u]=next[i])if(w[i]&&dis[to[i]]==dis[u]+1)
    f=dfs(to[i],t,std::min(now,w[i])),now-=f,w[i]-=f,w[i^1]+=f;return flow-now;
}int main(){
    ll n=readll(),x,s=0,t=2*n+1,d=0;rep(i,1,n)p[i].read(i),d+=p[i].w;
    rep(i,1,n){add(p[i].id,p[i].id+n,p[i].w);if(!p[i].rk)add(s,p[i].id,inf);else if(p[i].rk==3)add(p[i].id+n,t,inf);}
    std::sort(p+1,p+n+1,cmpx);rep(i,1,n-1)if(p[i].x==p[i+1].x&&p[i+1].y==p[i].y+1&&(p[i].x&1)==0)
    x=p[i].rk<p[i+1].rk,add(p[i+!x].id+n,p[i+x].id,inf);
    std::sort(p+1,p+n+1,cmpy);rep(i,1,n-1)if(p[i].y==p[i+1].y&&p[i+1].x==p[i].x+1)
    x=p[i].rk<p[i+1].rk,add(p[i+!x].id+n,p[i+x].id,inf);//exit(0); 
    ll flow=0;while(bfs(s,t))flow+=dfs(s,t,inf);printf("%lld\n",d-flow);return 0;
}