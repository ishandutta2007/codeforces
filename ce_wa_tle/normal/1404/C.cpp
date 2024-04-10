#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=6e5+9,inf=1e9,mod=1e9+7;typedef ll aN[N];aN a,ans,f;ll tag[N<<2];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct que{ll l,r,id;}q[N];int operator<(que&a,que&b){return a.l>b.l;}struct ifm{ll min,mini;}val[N<<2];
ifm operator+(const ifm&a,const ifm&b){return(a.min==b.min?a.mini>b.mini:a.min<b.min)?a:b;}
struct bit{ll n;void set(ll n_){n=n_;}
    ll query(ll u){ll res=0;while(u)res+=f[u],u&=~-u;return res;}void update(ll u,ll c){while(u<=n)f[u]+=c,u+=u&-u;}
}b;
struct sgt{
    void pushdown(ll u,ll l,ll r){
        if(tag[u]){val[u].min+=tag[u];if(l!=r)tag[u<<1]+=tag[u],tag[u<<1|1]+=tag[u];tag[u]=0;}
    }void build(ll u,ll l,ll r){
        if(l==r){val[u]=(ifm){a[l],l};return;}ll mid=(l+r)>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r),val[u]=val[u<<1]+val[u<<1|1];
    }void update(ll u,ll l,ll r,ll ql,ll qr,ll c){
        pushdown(u,l,r);if(ql<=l&&r<=qr){tag[u]+=c,pushdown(u,l,r);return;}ll mid=(l+r)>>1;
        if(ql<=mid)update(u<<1,l,mid,ql,qr,c);else pushdown(u<<1,l,mid);
        if(qr>=mid+1)update(u<<1|1,mid+1,r,ql,qr,c);else pushdown(u<<1|1,mid+1,r);val[u]=val[u<<1]+val[u<<1|1];
    }ifm query(ll u,ll l,ll r,ll ql,ll qr){
        if(r<ql||qr<l)return(ifm){inf,inf};pushdown(u,l,r);if(ql<=l&&r<=qr)return val[u];
        ll mid=(l+r)>>1;return query(u<<1,l,mid,ql,qr)+query(u<<1|1,mid+1,r,ql,qr);
    }
}t;
int main(){
    ll n=readll(),m=readll(),now=1,s;ifm x;rep(i,1,n)a[i]=i-readll(),a[i]<0&&(a[i]=inf);t.build(1,1,n),b.set(n);
    rep(i,1,m)q[i].l=readll()+1,q[i].r=n-readll(),q[i].id=i;std::sort(q+1,q+m+1);
    per(i,n,1){
//        printf(":%lld ",i);rep(j,1,n)printf("%lld ",t.query(1,1,n,j,j).min);puts("");
        while((x=t.query(1,1,n,i,n)).min==0)b.update(s=x.mini,1),t.update(1,1,n,s,s,inf),t.update(1,1,n,s,n,-1);
        while(now<=m&&q[now].l==i)ans[q[now].id]=b.query(q[now].r),now++;
    }rep(i,1,m)printf("%lld\n",ans[i]);return 0;
}
/* 2  2  3  9  5  4  6  5  7  8  3 11 13*/
//i-=a[i]
/* x  0  0  x  0  2  1  3  2  2  8  1  0*/
//del i->add(i,n,-1)