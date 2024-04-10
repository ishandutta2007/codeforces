#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=414514,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;char c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}
int readchar(){char c=getchar();for(;c<'A'||c>'z';c=getchar());return c;}
struct pt{ll x,y;void read(){x=readll(),y=readll();}operator ll()const{return x;}}p[114514],*p1=p,*p2,t;
ll solve(pt*p,ll n){
    static ll hmx[1145141],hmn[1145141];std::sort(p+1,p+n+1);ll sum=0,qmx=hmx[n+1]=-inf,qmn=hmn[n+1]=inf;
    per(i,n,1)hmx[i]=std::max(p[i].y,hmx[i+1]),hmn[i]=std::min(p[i].y,hmn[i+1]);rep(i,1,n)sum+=(p[i+1].x-p[i].x)
    *std::max(0ll,std::min(qmx=std::max(p[i].y,qmx),hmx[i+1])-std::max(qmn=std::min(p[i].y,qmn),hmn[i+1]));return sum;
}
int main(){
    ll n=readll(),m=0;p2=p+n;rep(i,1,n)t.read(),((t.x^t.y)&1?p1[++m]:*p2--)=(pt){(t.x+t.y)>>1,(t.x-t.y)>>1};
    printf("%lld\n",solve(p1,m)+solve(p2,n-m));return 0;
}
//struct qj{ll l,r;void len()const{return std::max(0ll,r-l+1);}}hz[114514];
//qj operator&(const qj&a,const qj&b){return(qj){std::max(a.l,b.l),std::min(a.r,b.r)};}