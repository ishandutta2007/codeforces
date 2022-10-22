#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=216333,e7=1e7+7,inf=1e17,mod=998244353;typedef ll aN[N];
ll iabs(ll a){return a<0?-a:a;}
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
//[   )
//l   r
//abc
ll getans(ll a,ll b,ll c,ll l,ll r){
    static const ll w2=(mod+1)/2,w3=(mod+(mod%3==1?mod:0)+1)/3,w6=w3*w2%mod;
    ll x=r-l;return(
      (a)*((x-0)*(x-2)%mod*(x-3)%mod*w2%mod)+
    (a+b)%mod*((x-0)*(x-1)%mod*(x-3)%mod*(mod-w2)%mod)+
  (a+b+c)%mod*((x-0)*(x-1)%mod*(x-2)%mod*w6%mod))%mod;
}ll tag[514514],val[514514],rx[114514];
struct line{ll l,r,w,q;operator ll()const{return w;}}l[114514];
struct sgt{
    void pushup(ll u,ll l,ll r){val[u]=tag[u]?rx[r+1]-rx[l]:l==r?0:val[u<<1]+val[u<<1|1];}
    void build(ll u,ll l,ll r){
        ll mid=(l+r)>>1;if(l==r){val[u]=tag[u]=0;return;}
        build(u<<1,l,mid),build(u<<1|1,mid+1,r),val[u]=0;
    }void update(ll u,ll l,ll r,ll ql,ll qr,ll c){
        if(ql<=l&&r<=qr){tag[u]+=c,pushup(u,l,r);return;}ll mid=(l+r)>>1;
        if(ql<=mid)update(u<<1,l,mid,ql,qr,c);if(qr>mid)update(u<<1|1,mid+1,r,ql,qr,c);pushup(u,l,r);
    }
}t;ll n,tm,fj[114514],x[114514],y[114514];
ll solve(ll len){
    ll cnt=0,cx=0;rep(i,1,n)rx[++cx]=x[i]-len,rx[++cx]=x[i]+len+1;
    std::sort(rx+1,rx+cx+1);ll sum=0,lf,rt;t.build(1,1,cx-1);
    #define fake(x) std::lower_bound(rx,rx+cx+1,x)-rx
    rep(i,1,n)lf=fake(x[i]-len),rt=fake(x[i]+len+1)-1,
    l[++cnt]=(line){lf,rt,y[i]-len,1},l[++cnt]=(line){lf,rt,y[i]+len+1,-1};std::sort(l+1,l+cnt+1);
    rep(i,1,cnt)t.update(1,1,cx-1,l[i].l,l[i].r,l[i].q),sum=(sum+val[1]%mod*(l[i+1].w-l[i].w)%mod)%mod;return sum;
}
int main(){
    n=readll(),tm=readll();ll cnt=0;rep(i,1,n)x[i]=readll(),y[i]=readll();
    rep(i,1,n)rep(j,1,n)fj[++cnt]=std::max(iabs(x[i]-x[j]),iabs(y[i]-y[j]))/2;fj[++cnt]=tm;
    std::sort(fj+1,fj+cnt+1);ll sum=0,lst=0;//,sum1=0;
//    rep(i,0,tm-1)sum1=(sum1+solve(i))%mod;
//    rep(i,0,4)printf("solve(%lld)=%lld\n",i,solve(i));
    rep(i,0,cnt)if(fj[i+1]<=tm){
        ll l=fj[i],r=fj[i+1];lst=0;if(r-l<=3)rep(j,l,r-1)lst+=solve(j);
        else lst=getans(solve(l),solve(l+1),solve(l+2),l,r);sum=(sum+lst)%mod;//printf("%lld\n",sum);
    }printf("%lld\n",(solve(tm)*tm-sum+mod)%mod/*,(solve(tm)*tm-sum1+mod)%mod*/);return 0;
}
/*
2 70000
0 0
0 2

*/