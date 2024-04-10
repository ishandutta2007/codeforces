#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=5e5+9,M=1e6+7,mod=998244353;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct node{ll min,sum;}val[M<<2];ll tag[M<<2];
node operator+(const node&a,const node&b){return a.min!=b.min?a.min<b.min?a:b:(node){a.min,a.sum+b.sum};};
struct segment{
    void pushdown(ll u,ll l,ll r)const{
        if(tag[u]){val[u].min+=tag[u];if(l!=r)tag[u<<1]+=tag[u],tag[u<<1|1]+=tag[u];tag[u]=0;}
    }void update_sum(ll u,ll l,ll r,ll q,ll c)const{
        pushdown(u,l,r);if(l==r)return(void)(val[u].sum+=c);ll mid=(l+r)>>1;
        if(q<mid)update_sum(u<<1,l,mid,q,c),pushdown(u<<1|1,mid+1,r);
        else update_sum(u<<1|1,mid+1,r,q,c),pushdown(u<<1,l,mid);val[u]=val[u<<1]+val[u<<1|1];
    }void insert(ll u,ll c)const{/*printf("%s %lld\n",c==1?"ins":"del",u);*/update_sum(1,1,1e6+2,u,c);}
    void update_min(ll u,ll l,ll r,ll ql,ll qr,ll c)const{
        pushdown(u,l,r);if(ql<=l&&r<=qr){tag[u]+=c,pushdown(u,l,r);return;}ll mid=(l+r)>>1;
        if(mid>=ql)update_min(u<<1,l,mid,ql,qr,c);else pushdown(u<<1,l,mid);
        if(mid+1<=qr)update_min(u<<1|1,mid+1,r,ql,qr,c);else pushdown(u<<1|1,mid+1,r);val[u]=val[u<<1]+val[u<<1|1];
    }void update(ll l,ll r,ll c)const{/*printf("[%lld,%lld]+=%lld\n",l,r,c);*/update_min(1,1,1e6+2,l,r,c);}
}t;aN a;
void change(ll i,ll c){t.update(std::min(a[i+1],a[i])+1,std::max(a[i+1],a[i]),c);}
void hf(ll x,ll c){change(x-1,c),change(x,c),t.insert(a[x],c);}
int main(){
    ll n=readll(),m=readll(),x,y;rep(i,1,n)t.insert(a[i]=readll(),1);a[0]=1e6+2,a[n+1]=0;rep(i,0,n)change(i,1);
    /*printf("%lld\n",val[1].sum);*/rep(i,1,m)x=readll(),y=readll(),hf(x,-1),a[x]=y,hf(x,1),printf("%lld\n",val[1].sum);return 0;
}