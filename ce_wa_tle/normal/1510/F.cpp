#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)0
#define pow djsnfianj
#define X ^
typedef long long ll;typedef long double ld;const ll N=2e5+7,inf=1e18;typedef ll aN[N*2];
inline ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
const ld pi=3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986L,eps=1e-5;
ld qm(ld x){return x<0?x+2*pi:x;}ld sqr(ld u){return u*u;}
struct pt{ld x,y;ld dis2()const{return x*x+y*y;}void read(){x=readll(),y=readll();}}p[N],s[N];
typedef const pt&P;pt operator*(ld a,P b){return(pt){a*b.x,a*b.y};}ld area(ld d,ld l){return pi*l*sqrtl(l*l-d*d)/4.0L;}
pt operator-(P a,P b){return(pt){a.x-b.x,a.y-b.y};}pt operator+(P a,P b){return(pt){a.x+b.x,a.y+b.y};}
ld operator *(P a,P b){return a.x*b.x+a.y*b.y;}ld operator X(P a,P b){return a.x*b.y-a.y*b.x;}
pt xj(P a,P b,P c,ld l,ll s){pt x=c-b,y=b-a;return(sqr(l)-y.dis2())/2/(y*x+s*l*sqrtl(x.dis2()))*x+b;}
ld area(P a,P b,ld l,P c,P d){const pt h=b-a,m=1.0/2*(a+b);pt r=c-m,s=d-m;const ld f=h.dis2(),dl=(r X s)/2;
P z=(sqrtl(sqr(l)-f)/l-1)/f*h;r=r+r*h*z,s=s+s*h*z;return(qm(atan2l(s.y,s.x)-atan2l(r.y,r.x)))/2/pi*area(sqrtl(f),l)-dl;}
pt jd(P a,P b,P c,P d){const pt ab=b-a,cd=d-c;const ld D=ab X cd,b1=a X ab,b2=c X cd;
return fabsl(D)>eps?(pt){(ab.x*b2-b1*cd.x)/D,(ab.y*b2-b1*cd.y)/D}:(pt){-1145,0};}
int calc(ld a,ld b,ld c){const ld s=sqr(c)-a-b;return c>-eps&&s>-eps&&4*a*b<sqr(s)+eps;}
aN vis,u,v;ld len[N],slen[N],sm;ll n;ld dis(ll a,ll b){return slen[b]-slen[a];}ld lst(ll a,ll b){return sm-dis(a,b);}
ll check(ll l,ll r,ld sum){if(l==r)return 1;if(l==r-n)return 0;pt s=jd(p[l+1],p[l],p[r],p[r-1]);
return fabsl(s.x+1145)>eps&&(p[l+1]-p[l])*(s-p[l+1])>=-eps?calc((s-p[l]).dis2(),(s-p[r]).dis2(),sum-lst(l,r)):0;}
int main(){
    ll n=::n=readll(),m=readll(),top=0;rep(i,1,n)p[i].read(),p[i+n]=p[i],len[i]=len[i+n]=sqrtl((p[i]-p[i-1]).dis2());
    len[1]=len[n+1]=sqrtl((p[1]-p[n]).dis2());rep(i,1,2*n)slen[i]=slen[i-1]+len[i];sm=slen[n];ld ans=0;p[0]=p[n];
    rfor(ll l=1,r=1;l<=n;l++){
        while(r-l<n-2&&(l==r||check(l-1,r+1,m)))r++;while(r==l||(r+1!=l&&check(l,r+1,m)))r++,
        s[++top]=xj(p[l],p[r],p[r-1],m-lst(l,r),1),u[top]=l,vis[v[top]=r]=1;
        s[++top]=xj(p[r],p[l],p[l+1],m-lst(l,r),1),u[top]=l+1,vis[v[top]=r]=1;
    }rep(i,1,top)ans+=(s[i] X s[i%top+1])/2+area(p[u[i]],p[v[i]],m-lst(u[i],v[i]),s[i],s[i%top+1]);
    printf("%.15Lf\n",ans);return 0;
}//rep(i,1,top)printf("%lld %lld %.8Lf %.8Lf\n",u[i],v[i],s[i].x,s[i].y);
//    rep(i,0,2*n)printf("%lld %.8Lf\n",i,slen[i]);printf("dis=%.8Lf\n",lst(1,2));