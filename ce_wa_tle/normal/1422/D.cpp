#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i++)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=6e5+9,inf=1e9,mod=1e9+7;typedef ll aN[N];
ll iabs(ll u){return u>0?u:-u;}
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct pt{ll x,y;}p[N];void read(pt&b){b.x=readll(),b.y=readll();}aN head,next,to,w,dis,c,vis;ll cnt=0;
void add(ll u,ll v,ll c){next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;}ll cmpx(ll a,ll b){return p[a].x<p[b].x;}
struct node{ll u,dis;operator ll()const{return-dis;}};std::priority_queue<node>q;ll cmpy(ll a,ll b){return p[a].y<p[b].y;}
int main(){
    ll m=readll(),n=readll(),s=0,t=n+1;read(p[s]),read(p[t]);rep(i,1,n)read(p[c[i]=i]),
    add(s,i,std::min(iabs(p[i].x-p[s].x),iabs(p[i].y-p[s].y))),add(i,t,iabs(p[i].x-p[t].x)+iabs(p[i].y-p[t].y));
    std::sort(c+1,c+n+1,cmpx);ref(i,1,n)add(c[i],c[i+1],p[c[i+1]].x-p[c[i]].x),add(c[i+1],c[i],p[c[i+1]].x-p[c[i]].x);
    std::sort(c+1,c+n+1,cmpy);ref(i,1,n)add(c[i],c[i+1],p[c[i+1]].y-p[c[i]].y),add(c[i+1],c[i],p[c[i+1]].y-p[c[i]].y);
    memset(dis,0x3f,sizeof dis),dis[s]=0,q.push((node){s,dis[s]}),add(s,t,iabs(p[s].x-p[t].x)+iabs(p[s].y-p[t].y));(void)m;
    while(!q.empty()){
        while(!q.empty()&&vis[q.top().u])q.pop();if(q.empty())break;ll u=q.top().u;vis[u]=1;
        q.pop();rfor(ll i=head[u];i;i=next[i])if(!vis[to[i]]&&dis[to[i]]>dis[u]+w[i])
        dis[to[i]]=dis[u]+w[i],q.push((node){to[i],dis[to[i]]});
    }printf("%lld\n",dis[t]);return 0;
}