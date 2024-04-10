#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2e5+7,mod=998244353;typedef ll aN[N];aN ny,jc,njc;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct point{ll sex[5];void read(ll x){ref(i,0,x)sex[i]=readll();rep(i,x,5)sex[i]=0;}}p[N];
struct node{ll val[32];node(){memset(val,0,sizeof val);}node(const point&b):node(){
    ll sm=0;ref(i,0,5)sm-=val[1<<i]=b.sex[i];ref(i,0,32)val[i]=val[i&-i]+val[i&~-i];ref(i,0,32)val[i]=val[i]*2+sm;
}ll getans()const{ll ans=0;ref(i,0,16)ans=std::max(ans,val[i]+val[i^31]);return ans;}
void print()const{ref(i,0,32)printf("%lld ",val[i]);puts("");}
}val[N<<2];void add(node&res,const node&a,const node&b){ref(i,0,32)res.val[i]=std::max(a.val[i],b.val[i]);}
struct segment_tree{ll n;void set(ll n_){n=n_;}
    void build(ll u,ll l,ll r){
        ll mid=(l+r)>>1;if(l==r){val[u]=(node)p[l];return;}
        build(u<<1,l,mid),build(u<<1|1,mid+1,r),add(val[u],val[u<<1],val[u<<1|1]);
    }void build(){build(1,1,n);}void update(ll u,ll l,ll r,ll q){
        ll mid=(l+r)>>1;if(l==r){val[u]=(node)p[l];return;}
        q<=mid?update(u<<1,l,mid,q):update(u<<1|1,mid+1,r,q),add(val[u],val[u<<1],val[u<<1|1]);
    }void update(ll q){update(1,1,n,q);}
    node query(ll u,ll l,ll r,ll ql,ll qr)const{
        ll mid=(l+r)>>1;if(ql<=l&&r<=qr)return val[u];
        if(mid<ql)return query(u<<1|1,mid+1,r,ql,qr);if(qr<mid+1)return query(u<<1,l,mid,ql,qr);
        node res;add(res,query(u<<1|1,mid+1,r,ql,qr),query(u<<1,l,mid,ql,qr));return res;
    }node query(ll l,ll r)const{return query(1,1,n,l,r);}
}t;
int main(){
    ll n=readll(),k=readll();rep(i,1,n)p[i].read(k)/*,node(p[i]).print()*/;t.set(n),t.build();
    ll m=readll();rep(i,1,m)if(readll()==1){ll x=readll();p[x].read(k),t.update(x);}
    else{ll l=readll(),r=readll();/*t.query(l,r).print();*/printf("%lld\n",t.query(l,r).getans());}
    return 0;
}