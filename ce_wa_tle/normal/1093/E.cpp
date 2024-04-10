#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2e5+7,mod=998244353;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct node{ll f,l,r,w,c,id;operator ll()const{return w;}}p[N*6],q[N*6];aN ans,a,b;ll top=0;
void add(ll a,ll b,ll c,ll d,ll e,ll f){p[++top]=(node){a,b,c,d,e,f};}
void add(ll a,ll b,ll c,ll d){p[++top]=(node){a,b,b,c,d,0};}
int check(const node&a,const node&b){return a.f==2&&b.f==1&&a.w<=b.w&&b.l<=a.l&&b.r>=a.l;}
#define rd readll()
struct bit{
    aN f;ll n;void set(ll n_){n=n_;}void update(ll u,ll c){while(u<=n)f[u]+=c,u+=u&-u;}
    ll query(ll u)const{ll res=0;while(u)res+=f[u],u&=~-u;return res;}
    void clear(ll u){while(u<=n)if(f[u])f[u]=0,u+=u&-u;else return;}void clear(){memset(f,0,sizeof(ll)*(n+1));} 
}t;
void cdq(ll l,ll r){
    ll mid=(l+r)>>1;if(l==r)return;if(r-l+1<=100){
        rep(i,l,r)if(p[i].f==2)rep(j,i,r)if(check(p[i],p[j]))ans[p[j].id]+=p[j].c*p[i].c;std::sort(p+l,p+r+1);return;
    }cdq(l,mid),cdq(mid+1,r);ll i=l,j=mid+1,k=l,cnt=0;
    while(i<=mid||j<=r){node c;if(i<=mid&&(j>r||p[i].w<=p[j].w))c=q[k++]=p[i++],c.f==2&&(t.update(c.l,c.c),++cnt);
    else c=q[k++]=p[j++],c.f==1&&(ans[c.id]+=c.c*(t.query(c.r)-t.query(c.l-1)),0);}
    if((cnt<<4)>t.n)t.clear();else rep(i,l,mid)if(p[i].f==2)t.clear(p[i].l);memcpy(p+l,q+l,sizeof(node)*(r-l+1));
}int main(){
    ll n=rd,m=rd,t=0;rep(i,1,n)a[rd]=i;rep(i,1,n)add(2,i,b[i]=a[rd],1);::t.set(n);
    rep(i,1,m)if(rd==1){ll la=rd,ra=rd,lb=rd,rb=rd;add(1,lb,rb,ra,1,++t),add(1,lb,rb,la-1,-1,t);}
    else{ll x=rd,y=rd;add(2,x,b[x],-1),add(2,x,b[y],1),add(2,y,b[x],1),add(2,y,b[y],-1),std::swap(b[x],b[y]);}
    cdq(1,top);rep(i,1,t)printf("%lld\n",ans[i]);return 0;
}