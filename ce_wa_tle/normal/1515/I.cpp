#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define log hgbhjkvghf
typedef long long ll;const ll N=2e5+5,inf=0x3f3f3f3f3f3f3f3f,mod=1e9+7,S=1e5;typedef ll aN[N],a2N[2*N];aN log,ys;
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}ll cnt=0;
struct pt{ll a,w,v,id;void read(ll i){a=readll(),w=readll(),v=readll(),id=i;}operator ll()const{return w-v*mod;}}p[N];
struct node{ll w1[22],v1[22],w2[22];void set(const pt&b){
    rep(i,0,20)w1[i]=v1[i]=0,w2[i]=inf,(b.w>>i||(w1[i]=b.w*b.a,v1[i]=b.v*b.a,0))&&(b.w>>(i+1)||!b.a||(w2[i]=b.w));
}void print()const{rep(i,1,7)printf("%lld %lld %lld\n",w1[i],v1[i],w2[i]);}}val[N<<2];
void merge(node&w,const node&u,const node&v){
//    puts("------------------------------------------------"),u.print(),puts(""),v.print(),puts("");
    rep(i,0,20)w.w1[i]=u.w1[i]+v.w1[i],w.v1[i]=u.v1[i]+v.v1[i],w.w2[i]=std::min(u.w2[i],u.w1[i]+v.w2[i]);//w.print();
}struct sgt{
    void pushup(ll u){merge(val[u],val[u<<1],val[u<<1|1]);}
    void build(ll u,ll l,ll r){
        if(l==r){val[u].set(p[l]);return;}ll mid=(l+r)>>1;build(u<<1,l,mid),build(u<<1|1,mid+1,r),pushup(u);
    }void update(ll u,ll l,ll r,ll q,ll c){
        if(l==r){p[l].a+=c,val[u].set(p[l]);return;}ll mid=(l+r)>>1;
        if(q<=mid)update(u<<1,l,mid,q,c);else update(u<<1|1,mid+1,r,q,c);pushup(u); 
    }ll query(ll u,ll l,ll r,ll&c){
        ll w=log[std::min((ll)1e5,c)],g=w+1,t,mid=(l+r)>>1;const node&s=val[u];
        if(l==r){t=std::min(c/p[l].w,p[l].a),c-=t*p[l].w;return t*p[l].v;}if(s.w1[g]<=c){c-=s.w1[g];return s.v1[g];}
        if(s.w1[w]<=c&&s.w2[w]>c){c-=s.w1[w];return s.v1[w];}ll d=query(u<<1,l,mid,c);return d+query(u<<1|1,mid+1,r,c);
    }
}t;
int main(){//IO(no/1515I);
    ll n=readll(),q=readll(),x;rep(i,1,n)p[i].read(i);std::sort(p+1,p+n+1);t.build(1,1,n);rep(i,2,S)log[i]=log[i>>1]+1;
    ll f;rep(i,1,n)ys[p[i].id]=i;rep(i,1,q)switch(f=readll(),x=readll(),f){case 1:t.update(1,1,n,ys[readll()],x);break;
    case 2:t.update(1,1,n,ys[readll()],-x);break;case 3:printf("%lld\n",t.query(1,1,n,x));}return 0;
}