#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define nxt y=(y+k[x]%2520+2520)%2520,x=to[x][y%m[x]]
typedef long long ll;const ll N=1e6+7,inf=0x3f3f3f3f3f3f3f3f,mod=998244353;typedef ll aN[N];
inline ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}inline int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN next,to,head,w,q,dis;ll cnt=1;void add_(ll u,ll v,ll c){next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;}
aN cur,x,y;ll a[111][111];struct matrix{ll x1,y1,x2,y2;}f[55];void add(ll u,ll v,ll w){add_(u,v,w),add_(v,u,0);}
int bfs(ll s,ll e){
	memset(dis,-1,sizeof(ll)*(e+1)),memcpy(cur,head,sizeof(ll)*(e+1));dis[q[1]=s]=0;
	rfor(ll h=1,t=1,u;h<=t;)rfor(ll i=head[u=q[h++]],v;v=to[i],i;i=next[i])
	if(w[i]&&!~dis[v])dis[q[++t]=v]=dis[u]+1;return!!~dis[e];
}ll dfs(ll u,ll t,ll flow){
	if(!flow||u==t)return flow;ll now=flow,f;rfor(ll i=head[u],v;v=to[i],now&&i;i=next[i])
	if(w[i]&&dis[v]==dis[u]+1)f=dfs(v,t,std::min(now,w[i])),w[i]-=f,w[i^1]+=f,now-=f;return flow-now;
}int main(){
	ll n=readll(),m=readll(),x1,y1,x2,y2,tx=0,ty=0;rep(i,1,m)x[++tx]=x1=readll(),y[++ty]=y1=readll(),
	x[++tx]=x2=readll()+1,y[++ty]=y2=readll()+1,f[i]=(matrix){x1,y1,x2,y2};
	std::sort(x+1,x+tx+1),std::sort(y+1,y+ty+1),tx=std::unique(x+1,x+tx+1)-x-1,ty=std::unique(y+1,y+ty+1)-y-1;
	rep(i,1,m)x1=std::lower_bound(x+1,x+tx+1,f[i].x1)-x,y1=std::lower_bound(y+1,y+ty+1,f[i].y1)-y,
	x2=std::lower_bound(x+1,x+tx+1,f[i].x2)-x,y2=std::lower_bound(y+1,y+ty+1,f[i].y2)-y,
	a[x1][y1]+=1,a[x1][y2]-=1,a[x2][y1]-=1,a[x2][y2]+=1;(void)n;
	ll s=0,t=tx+ty+1;ref(i,1,tx)add(s,i,x[i+1]-x[i]);ref(i,1,ty)add(tx+i,t,y[i+1]-y[i]);
	ref(i,1,tx)ref(j,1,ty)if((a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1]))add(i,tx+j,inf);
	ll flow=0;while(bfs(s,t))flow+=dfs(s,t,inf);printf("%lld\n",flow);return 0; 
}