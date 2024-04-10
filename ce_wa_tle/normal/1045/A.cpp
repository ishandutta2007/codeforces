#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
bool p1;typedef int ll;const ll N=2e6+7,inf=998244353;typedef ll aN[N];aN a,b,c;ll ans=0;
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN next,to,head,w,dis,q,cur;ll cnt=1;void add_(ll u,ll v,ll c){next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;}
void add(ll u,ll v,ll w){/*printf("->%lld %lld %lld\n",u,v,w);*/add_(u,v,w),add_(v,u,0);}ll max;aN s,cz;bool p2;
int bfs(ll s,ll e,ll n){
    ll sz=sizeof(ll)*(n+1);memset(dis,-1,sz),memcpy(cur,head,sz),dis[q[1]=s]=0;rfor(ll h=1,t=1,u;h<=t;)
    rfor(ll i=head[u=q[h++]];i;i=next[i])if(w[i]&&!~dis[to[i]])dis[q[++t]=to[i]]=dis[u]+1;return!!~dis[e];
}ll dfs(ll u,ll t,ll flow){
    if(u==t)return flow;ll now=flow,f;rfor(ll i=cur[u];i&&now;i=next[i])if(w[i]&&dis[to[i]]==dis[u]+1)
    cur[u]=i,f=dfs(to[i],t,std::min(now,w[i])),w[i]-=f,w[i^1]+=f,now-=f;return flow-now;
}ll build(ll u,ll l,ll r,ll n,ll t){//printf("%lld %lld %lld %lld %lld\n",u,l,r,n,t);
    max=std::max(max,l==r?l+n:u+t);if(l==r)return l+n;ll mid=(l+r)>>1;add(u+t,build(u<<1,l,mid,n,t),inf),
    add(u+t,build(u<<1|1,mid+1,r,n,t),inf);return u+t;
}void update(ll u,ll l,ll r,ll ql,ll qr,ll fr,ll n,ll t){
    if(ql<=l&&r<=qr)return add(fr,l==r?l+n:u+t,1);ll mid=(l+r)>>1;
    if(ql<=mid)update(u<<1,l,mid,ql,qr,fr,n,t);if(qr>=mid+1)update(u<<1|1,mid+1,r,ql,qr,fr,n,t);
}ll find(ll u,ll s){rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(i&1&&w[i])return w[i]-=1,v==s?u:find(v,s);return 0;}
int main(){fprintf(stderr,"%.2lfMiB\n",(&p2-&p1)/1048576.0); 
    ll n=readll(),m=readll(),s=0,t=n+m+1,k,x,y;build(1,1,m,n,t);/*exit(0);*/rep(i,1,m)add(i+n,t,1);
    rep(i,1,n)switch(cz[i]=readll()){
        case 0:k=readll(),add(s,i,1);rep(j,1,k)add(i,readll()+n,1);break;
        case 1:x=readll(),y=readll(),add(s,i,1),update(1,1,m,x,y,i,n,t);break;
        case 2:add(s,i,2);rep(j,1,3)add(i,readll()+n,1);
    }ll flow=0;while(bfs(s,t,max))flow+=dfs(s,t,inf);printf("%d\n",flow);
    rfor(ll i=head[t];i;i=next[i])if(w[i])::s[to[i]]=find(to[i],s);//,printf("%lld\n",to[i]);
    rfor(ll i=head[s];i;i=next[i])if(cz[to[i]]==2){ll flag=0,lst=0;
    rfor(ll j=head[to[i]];j;j=next[j])if(to[j]!=s)::s[to[j]]==to[i]?flag++:lst=to[j];if(flag==1)::s[lst]=to[i];}
    rep(i,n+1,n+m)if(::s[i])printf("%d %d\n",::s[i],i-n);return 0;
}