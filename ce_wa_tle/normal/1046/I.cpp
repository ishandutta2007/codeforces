#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=6e5+7,inf=998244353;typedef ll aN[N];ll sqr(ll u){return u*u;}
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct pt{ll x,y;void read(){x=readll(),y=readll();}ll dis2()const{return x*x+y*y;}}p[N],a,b;
#define X ^
pt operator -(const pt&a,const pt&b){return(pt){a.x-b.x,a.y-b.y};}
ll operator *(const pt&a,const pt&b){return a.x*b.x+a.y*b.y;}
ll operator X(const pt&a,const pt&b){return a.x*b.y-a.y*b.x;}
int main(){
    ll n=readll(),d1=sqr(readll()),d2=sqr(readll()),ans=0,f=1,s,d;rep(i,1,n)a.read(),b.read(),p[i]=a-b;p[0]=p[1];
    rep(i,1,n)s=p[i]*p[i-1],d=std::min(p[i-1].dis2(),p[i].dis2()),
    f&&(s>=d?d<=d1:sqr(p[i] X p[i-1])<=d1*(p[i]-p[i-1]).dis2())&&(ans++,f=0),f|=p[i].dis2()>d2;printf("%lld\n",ans);return 0;
}
/*
2
1 2
0 0 -8 1
0 0 9 1
*/