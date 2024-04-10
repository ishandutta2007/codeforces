#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define mem(x) memset(x,0,sizeof(x))
#define memn(x,n) memset(x,0,sizeof(ll)*((n)+1))
typedef long long ll;const ll N=222222,mod=1e9+7,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N],a9[9];
ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct node{a9 min;ll ans;node(ll x=inf){ll lx=x;ref(i,0,9)min[i]=x%10?lx:inf,x/=10;ans=inf;}ll get()const{return ans==inf?-1:ans;}};
void add(node&a,const node&b,const node&c){
    a.ans=std::min(b.ans,c.ans);ref(i,0,9)a.min[i]=std::min(b.min[i],c.min[i]),a.ans=std::min(a.ans,b.min[i]+c.min[i]);
}aN a;struct segment_tree{
    node val[N<<2];
    void build(ll u,ll l,ll r){
        if(l==r){val[u]=a[l];return;}ll mid=(l+r)>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);add(val[u],val[u<<1],val[u<<1|1]);
    }void update(ll u,ll l,ll r,ll q,ll c){
        if(l==r){val[u]=c;return;}ll mid=(l+r)>>1;if(q<=mid)update(u<<1,l,mid,q,c);
        else update(u<<1|1,mid+1,r,q,c);add(val[u],val[u<<1],val[u<<1|1]);
    }node query(ll u,ll l,ll r,ll ql,ll qr)const{
        if(ql<=l&&r<=qr)return val[u];ll mid=(l+r)>>1;node res={};if(ql<=mid)if(qr<mid+1)res=query(u<<1,l,mid,ql,qr);
        else add(res,query(u<<1,l,mid,ql,qr),query(u<<1|1,mid+1,r,ql,qr));else res=query(u<<1|1,mid+1,r,ql,qr);return res;
    }
}t;
int main(){
    ll n=readll(),m=readll(),f,x,y;rep(i,1,n)a[i]=readll();t.build(1,1,n);rep(i,1,m)f=readll(),x=readll(),y=readll(),
    f==1?t.update(1,1,n,x,y),0:printf("%lld\n",t.query(1,1,n,x,y).get());return 0; 
}