#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
bool p1;
typedef long long ll;typedef long double ld;const ll N=1e5+7,Q=5e5+7,K=N,V=42;
typedef ll aN[N],aQ[Q];typedef int aQlog[Q*40];aQ ans;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct f{
    aN fa,sz;aQ op;ll cnt;void clear(ll n){cnt=0;rep(i,1,n)sz[fa[i]=i]=1;}ll fd(ll u){return u^fa[u]?fd(fa[u]):u;}
    void link(ll u,ll v){//printf("link %lld %lld\n",u,v);
        if((u=fd(u))==(v=fd(v))){op[++cnt]=0;return;}if(sz[u]>sz[v])std::swap(u,v);++cnt,sz[fa[op[cnt]=u]=v]+=sz[u];
    }void del(){/*puts("del");*/ll u=op[cnt--],v=fa[u];if(u)sz[v]-=sz[fa[u]=u];}
}t;struct que{ll z,t,id;operator ll()const{return t;}}q[Q];
struct lk{ll u,v,id,d;void read(ll id_,ll d_){u=readll(),v=readll(),id=id_,d=d_;}}e[Q];
aQlog next,to;ll head[(K+Q)<<2],cnt=0;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
void update(ll u,ll l,ll r,ll ql,ll qr,ll c){//printf("u=%lld %lld %lld %lld %lld %lld\n",u,l,r,ql,qr,c);
    if(ql<=l&&r<=qr){add(u,c);return;}ll mid=(l+r)>>1;
    if(mid>=ql)update(u<<1,l,mid,ql,qr,c);if(mid+1<=qr)update(u<<1|1,mid+1,r,ql,qr,c);
}ll query(ll u,ll l,ll r,ll now,ll n){//printf("q=%lld %lld %lld\n",u,l,r);
    /*if(now>n)return now;*/rfor(ll i=head[u];i;i=next[i])t.link(e[to[i]].u,e[to[i]].v);ll mid=(l+r)>>1;
    if(l==r)while(now<=n&&q[now]==l)ans[q[now].id]=t.sz[t.fd(q[now].z)]/*,printf("query %lld %lld %lld\n",q[now].z,u,l)*/,now++;
    else now=query(u<<1|1,mid+1,r,query(u<<1,l,mid,now,n),n);rfor(ll i=head[u];i;i=next[i])t.del();return now;
}ll end[Q];bool p2;
int main(){//fprintf(stderr,"%.2lfMiB\n",(&p2-&p1)/1048576.0); 
    ll n=readll(),tq=readll(),k=readll(),now=1,cntq=0,cnty=0;t.clear(n);
    rep(i,1,tq)switch(readll()){
        case 3:end[now++]=i;break;case 2:++cntq,q[cntq]=(que){readll(),i,cntq};break;
        case 1:e[++cnty].read(i,now);//,update(1,1,k+tq,now,(now+k-1),cnty);
    }rep(i,1,k)end[now++]=tq;rep(i,1,cnty)update(1,1,tq,e[i].id,end[e[i].d+k-1],i);std::sort(q+1,q+cntq+1);
    query(1,1,tq,1,cntq);rep(i,1,cntq)printf("%lld\n",ans[i]);return 0;
}