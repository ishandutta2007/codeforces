#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=216333,e7=1e7+7,inf=1e17,mod=998244353;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct ifm{
    ll q0,q1,q01,q10,h0,h1,h01,h10,m01,m10,size;
    void print()const{
        #define pr(x) printf("."#x"=%lld\n",x)
        pr(q0),pr(q1),pr(q01),pr(q10),pr(h0),pr(h1),pr(h01),pr(h10),pr(m01),pr(m10),pr(size);
    }
    ifm swap()const{return(ifm){q1,q0,q10,q01,h1,h0,h10,h01,m10,m01,size};}
}val[514514<<2],e0={.q0=1,.q1=0,.q01=1,.q10=1,.h0=1,.h1=0,.h01=1,.h10=1,.m01=1,.m10=1,.size=1},e1=e0.swap();
ifm operator+(const ifm&a,const ifm&b){
    return(ifm){
        .q0=a.q0==a.size?a.q0+b.q0:a.q0,//[(000)110][00100]/[(00000][000)11]
        .q1=a.q1==a.size?a.q1+b.q1:a.q1,//^
        .q01=a.q0==a.size?a.q0+b.q01:a.q01==a.size?a.q01+b.q1:a.q01,//[000][00011]/[00011][111100]/[000110][111100]
        .q10=a.q1==a.size?a.q1+b.q10:a.q10==a.size?a.q10+b.q0:a.q10,
        .h0=b.h0==b.size?b.h0+a.h0:b.h0,
        .h1=b.h1==b.size?b.h1+a.h1:b.h1,
        .h01=b.h1==b.size?b.h1+a.h01:b.h01==b.size?b.h01+a.h0:b.h01,
        .h10=b.h0==b.size?b.h0+a.h10:b.h10==b.size?b.h10+a.h1:b.h10,
        .m01=std::max(std::max(a.m01,a.h01+b.q1),std::max(b.m01,b.q01+a.h0)),
        .m10=std::max(std::max(a.m10,a.h10+b.q0),std::max(b.m10,b.q10+a.h1)),
        .size=a.size+b.size
    };
}ll tag[514514<<2],a[514514];
struct sgt{
    void pushdown(ll u,ll l,ll r){if(tag[u]){val[u]=val[u].swap();if(l!=r)tag[u<<1]^=1,tag[u<<1|1]^=1;tag[u]=0;}} 
    void build(ll u,ll l,ll r){
        ll mid=(l+r)>>1;if(l==r){val[u]=a[l]?e1:e0;return;}
        build(u<<1,l,mid),build(u<<1|1,mid+1,r),val[u]=val[u<<1]+val[u<<1|1];
    }void update(ll u,ll l,ll r,ll ql,ll qr){
        if(ql<=l&&r<=qr){tag[u]^=1,pushdown(u,l,r);return;}ll mid=(l+r)>>1;pushdown(u,l,r);
        ql<=mid?update(u<<1,l,mid,ql,qr):pushdown(u<<1,l,mid),
        qr>mid?update(u<<1|1,mid+1,r,ql,qr):pushdown(u<<1|1,mid+1,r),val[u]=val[u<<1]+val[u<<1|1];
    }ifm query(ll u,ll l,ll r,ll ql,ll qr){
        pushdown(u,l,r);if(ql<=l&&r<=qr)return val[u];ll mid=(l+r)>>1;
        return ql>mid?query(u<<1|1,mid+1,r,ql,qr):qr<=mid?query(u<<1,l,mid,ql,qr):
        query(u<<1,l,mid,ql,qr)+query(u<<1|1,mid+1,r,ql,qr);
    }
}t;
int main(){
    ll n=readll(),m=readll(),l,r;rep(i,1,n)a[i]=readchar('<','>')=='<';t.build(1,1,n);
//    (e0+e1+e1).print();(void)m,(void)l,(void)r;//011
    rep(i,1,m)l=readll(),r=readll(),t.update(1,1,n,l,r),printf("%lld\n",t.query(1,1,n,l,r).m01);return 0;
}