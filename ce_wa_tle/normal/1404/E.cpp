#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=2916333,e7=1e7+7,inf=1e17;typedef ll aN[N];ll cnt=1;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
#define fl fflush(stdout)
aN head,next,to,w,dis,cur,q,vis;
void add_(ll u,ll v,ll c){next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;}
void add(ll u,ll v,ll w){/*printf("%lld %lld\n",u,v),*/add_(u,v,w),add_(v,u,0);}
int bfs(ll s,ll t){
    memset(dis,-1,sizeof(ll)*(t+1)),memcpy(cur,head,sizeof(ll)*(t+1)),dis[q[1]=s]=0;rfor(ll h=1,t=1,u;h<=t;)
    rfor(ll i=head[u=q[h++]],v;v=to[i],i;i=next[i])if(w[i]&&!~dis[v])dis[q[++t]=v]=dis[u]+1;return~dis[t];
}
ll dfs(ll u,ll t,ll flow){
//printf("%lld %lld\n",u,flow);
    ll now=u==t?0:flow;rfor(ll&i=cur[u],f;i&&now;i=next[i])if(w[i]&&dis[to[i]]==dis[u]+1)
    f=dfs(to[i],t,std::min(w[i],now)),w[i]-=f,w[i^1]+=f,now-=f;return flow-now;
}
#define ms(a,b,c,d)(a|b<<1|c<<2|d<<3)
const ll c[4]={3,12,5,10};ll a[222][222];
#define h(a,b) (((a)-1)*m+(b))
#define z(a,b) (((a)-1)*(m-1)+(b)+sh)
int main(){
    ll n=readll(),m=readll(),s=0,sh=(n-1)*m,sz=n*(m-1),t=z(n,m-1)+1,snm=0;
    rep(i,1,n)rep(j,1,m)snm+=a[i][j]=readchar('#','.')=='#';
    rep(i,1,sh)add(s,i,1);rep(i,1,sz)add(i+(n-1)*m,t,1);
    rep(i,1,n)rep(j,1,m){
        ll s=ms(a[i][j],a[i][j+1],a[i+1][j],a[i+1][j+1]);
        ll p[]={z(i,j),z(i+1,j),h(i,j),h(i,j+1)};rep(i,0,1)rep(j,2,3)if(!(c[i]&~s)&&!(c[j]&~s))add(p[j],p[i],1);
        rep(i,0,3)if(!vis[p[i]]&&!(c[i]&~s))snm--,vis[p[i]]=1;
    }for(;bfs(s,t);snm+=dfs(s,t,inf));printf("%lld\n",snm);return 0;
}
/*
3 4
#.##
####
##..
*/
/*
4 3
.##
..#
###
###

*/
/*
1 10
##..##..##
*/