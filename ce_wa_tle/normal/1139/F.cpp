#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=3e5+7;typedef ll aN[N];aN ans,p,s,b,pref,inc;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct bit{
    aN f,x;ll n;void push(ll u){x[++n]=u;}void set(){std::sort(x+1,x+n+1),n=std::unique(x+1,x+n+1)-x-1;}
    void update(ll u,ll c){u=std::lower_bound(x+1,x+n+1,u)-x;while(u<=n)f[u]+=c,u+=u&-u;}
    ll query(ll u){u=std::lower_bound(x+1,x+n+1,u)-x;ll res=0;while(u)res+=f[u],u&=~-u;return res;}
}t[2];struct node{ll t,w,u,c;operator ll()const{return t;}void update()const{::t[w].update(u,c);}}g[N<<2];
struct que{ll t,w,u,id;operator ll()const{return t;}void getans()const{ans[id]+=::t[w].query(u);}}q[N];
int main(){
    ll n=readll(),m=readll();rep(i,1,n)p[i]=readll();rep(i,1,n)s[i]=readll();rep(i,1,n)b[i]=readll();
    ll top=0;rep(i,1,n)g[++top]=(node){p[i],0,b[i]-p[i]+1,-1},g[++top]=(node){s[i]+1,0,b[i]-p[i]+1,1},
    g[++top]=(node){p[i],1,b[i]+p[i],1},g[++top]=(node){s[i]+1,1,b[i]+p[i],-1};std::sort(g+1,g+top+1); 
    rep(i,1,top)t[g[i].w].push(g[i].u);rep(i,1,m)inc[i]=readll();rep(i,1,m)pref[i]=readll();
    ll tq=0;rep(i,1,m)q[++tq]=(que){inc[i],0,pref[i]-inc[i],i},q[++tq]=(que){inc[i],1,pref[i]+inc[i],i};
    std::sort(q+1,q+tq+1);rep(i,1,tq)t[q[i].w].push(q[i].u);rep(i,0,1)t[i].set();ll now=1;
    rep(i,1,top){while(now!=tq+1&&q[now].t<g[i].t)q[now++].getans();g[i].update();}
    rep(i,1,m)printf("%lld ",ans[i]);return 0; 
}