#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define f(x...)asdf(x)
typedef long long ll;const ll N=2e4+9;typedef ll aN[N];aN f,c;inline int eq(ll&a,ll b){return a!=b?a=b,1:0;}
ll readll(){
    ll x=0,w=1;char c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct pt{ll x,y,i,v;void read(ll id){x=readll(),y=readll(),v=readll(),i=id;}}p[N];typedef const pt&pp;
pt operator-(pp a,pp b){return(pt){a.x-b.x,a.y-b.y};};ll operator*(pp a,pp b){return a.x*b.y-a.y*b.x;}
ll f(ll u){return u^f[u]?f[u]=f(f[u]):u;}struct cmp_t{pp c;cmp_t(pp s):c(s){}
int operator()(pt a,pt b)const{a=a-c,b=b-c;ll sa=(a.y?:a.x)<0,sb=(b.y?:b.x)<0;return sa==sb?a*b>0:sa<sb;}};
ll cnt;aN u,v;inline void change(pt&x,pt&y){++cnt,std::swap(x.v,y.v),u[cnt]=x.i,v[cnt]=y.i;}
int main(){
    ll n=0,t=readll();rep(i,1,t)p[++n].read(f[i]=i),p[n].v==i&&--n;rep(i,1,n)f[f(p[i].i)]=f(p[i].v);
    if(!n)return puts("0"),0;rep(i,2,n)if(p[1].x<p[i].x)std::swap(p[1],p[i]);std::sort(p+2,p+n+1,cmp_t(p[1]));
    rep(i,3,n)if(eq(f[f(p[i].i)],f(p[i-1].i)))change(p[i],p[i-1]);rep(i,2,n)c[p[i].i]=i;//printf("%lld\n",cnt);
    rep(i,2,n)change(p[c[p[1].v]],p[1]);printf("%lld\n",cnt);rep(i,1,cnt)printf("%lld %lld\n",u[i],v[i]);return 0;
}
/*
5
-1 -2 1
3 0 2
1 3 4
4 -3 5
5 2 3
*/