#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=1e6+7,inf=0x3f3f3f3f3f3f3f3f,mod=998244353;typedef ll aN[N];ll p;
inline ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}inline int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct node{ll sum,*s,len;~node(){free(s);}
    void setlen(ll size){
        if(s)free(s),s=0;ll sz=sizeof(ll)*((len=size)+1);s=(ll*)malloc(sz),memset(s,0x3f,sz),s[0]=-inf;
    }ll find(ll x){return std::upper_bound(s,s+len+1,x)-s-1;}
}sgm[N<<2];aN a;
struct segment_tree{
    void pushup(ll u){
        const node&ls=sgm[u<<1],&rs=sgm[u<<1|1];node&now=sgm[u];now.sum=ls.sum+rs.sum;
        rfor(ll x=0,y=0;x<=ls.len&&y<=rs.len;)now.s[x+y]=std::min(now.s[x+y],std::max(ls.s[x],rs.s[y]+x*p-ls.sum)),
            y++,(y>rs.len||rs.s[y]+x*p-ls.sum>(x==ls.len?inf:ls.s[x+1]-1))&&(y--,x++);
    }void build(ll u,ll l,ll r){
        sgm[u].setlen(r-l+1);if(l==r){sgm[u].s[1]=p-(sgm[u].sum=a[l]);return;}ll mid=(l+r)>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r),pushup(u);
    }ll query(ll u,ll l,ll r,ll ql,ll qr,ll x){
    	if(ql<=l&&r<=qr)return x-p*sgm[u].find(x)+sgm[u].sum;ll mid=(l+r)>>1;
    	return ql>mid?query(u<<1|1,mid+1,r,ql,qr,x):qr<mid+1?
		query(u<<1,l,mid,ql,qr,x):query(u<<1|1,mid+1,r,ql,qr,query(u<<1,l,mid,ql,qr,x));
	} 
}t;
int main(){
    ll n=readll(),m=readll(),l,r;p=readll();rep(i,1,n)a[i]=readll();t.build(1,1,n);
    rep(i,1,m)l=readll(),r=readll(),printf("%lld\n",t.query(1,1,n,l,r,0));return 0;
}