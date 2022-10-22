#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=422222,mod=1e9+7,inf=0x3f3f3f3f3f3f3f3f;ll head[N<<2],next[N*20],to[N*20],cnt=0,can[N];
ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());//N is max of te
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}ll otoe[N][2],ans[N],f,u,v;
struct ds{
    #define f(x...) f_114514(x)
    ll f[N],sz[N],cg[N];ll cnt,n;void set(ll n_){n=n_,cnt=0;rep(i,1,n)sz[f[i]=i]=1;}ll f(ll u){return f[u]^u?f(f[u]):u;}
    void add(ll u,ll v){/*printf("add %lld %lld\n",u,v);*/if((u=f(u))==(v=f(v))){cg[++cnt]=0;return;}if(sz[u]>sz[v])std::swap(u,v);sz[f[cg[++cnt]=u]=v]+=sz[u];}
    void del(){/*puts("del");*/ll u=cg[cnt--];if(u)sz[f[u]]-=sz[u],f[u]=u;}
}t;struct op{ll u,v,la,t;}o[N];int operator<(const op&a,const op&b){return a.u!=b.u?a.u<b.u:a.v!=b.v?a.v<b.v:a.t<b.t;}
struct que{ll u,v;}q[N];struct edge{ll u,v;}e[N];void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
void update(ll u,ll l,ll r,ll ql,ll qr,ll id){
    if(ql<=l&&r<=qr){add(u,id);return;}ll mid=(l+r)>>1;if(ql<=mid)update(u<<1,l,mid,ql,qr,id);
    if(qr>=mid+1)update(u<<1|1,mid+1,r,ql,qr,id);
}void solve(ll u,ll l,ll r,ll n){/*printf("s=%lld %lld %lld\n",u,l,r);*/
    ll lc=t.cnt;rfor(ll i=head[u];i;i=next[i])if(can[to[i]])t.add(e[to[i]].u,e[to[i]].v);ll mid=(l+r)>>1;
    if(l==r)!q[l].u?can[otoe[l][ans[l]=ans[l-1]]]^=1/*,printf("^%lld %lld %lld\n",otoe[l][ans[l]],l,ans[l])*/:/*(*/ans[l]=t.f(q[l].u+ans[l-1]==n+1?1:q[l].u+ans[l-1])==t.f(q[l].v+ans[l-1]==n+1?1:q[l].v+ans[l-1])/*,printf("query %lld %lld\n",q[l].u,q[l].v))*/;
    else solve(u<<1,l,mid,n),solve(u<<1|1,mid+1,r,n);while(t.cnt!=lc)t.del();//printf("cnt=%lld\n",t.cnt);
}int main(){
    ll n=readll(),m=readll(),to=0,te=0;t.set(n);rep(i,1,m)f=readll(),u=readll(),v=readll(),u>v&&(std::swap(u,v),0),
    f==1?o[++to]=(op){u,v,0,i},u=u%n+1,v=v%n+1,u>v&&(std::swap(u,v),0),o[++to]=(op){u,v,1,i},0:(q[i]=(que){u,v},0);
    std::sort(o+1,o+to+1);rep(i,1,to){if(o[i].u!=o[i-1].u||o[i].v!=o[i-1].v)e[++te]=(edge){o[i].u,o[i].v};
    ll ed=o[i].u!=o[i+1].u||o[i].v!=o[i+1].v?m:o[i+1].t-1;update(1,1,m,o[i].t+1,ed,otoe[o[i].t][o[i].la]=te)/*,printf("%lld %lld %lld %lld\n",o[i].t,ed,e[te].u,e[te].v)*/;}
//    rep(i,1,te)printf("%lld %lld\n",e[i].u,e[i].v);
    solve(1,1,m,n);rep(i,1,m)if(q[i].u)putchar(48^ans[i]);return 0; 
}