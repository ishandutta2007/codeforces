#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;typedef long double ld;const ll N=422222;typedef ll aN[N];aN a;ll n,k;const ld eps=1e-7;
ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct pt{ll x,y;void read(){x=readll(),y=readll();}ll dis2()const{return x*x+y*y;}}p[N];ll to[21][N];
struct qj{ld l,r;operator ld()const{return l;}}q[N];const ld pi=acos(-1);
int check(ld r){
    ld ang,del;rep(i,1,n)ang=atan2(p[i].y,p[i].x),del=acos(r/sqrt(p[i].dis2())),q[i].l=ang-del,q[i].r=ang+del,
    q[i].l<0&&(q[i].l+=2*pi,q[i].r+=2*pi),q[i+n].l=q[i].l+2*pi,q[i+n].r=q[i].r+2*pi;ll n=::n<<1;std::sort(q+1,q+n+1);
//    printf("%.7Lf\n",r);rep(i,1,n)printf("%.7Lf,%.7Lf\n",q[i].l,q[i].r);puts("");
    ll now=n;per(i,n,1){while(q[now].l>q[i].r)now--;to[0][i]=now+1;}rep(i,1,20)rep(u,1,n)to[i][u]=to[i-1][to[i-1][u]];
    rep(u,1,n){ll now=u;per(i,20,0)if(k>>i&1)now=to[i][now];!now&&(now=n+1);if(now-u>=::n)return 1;}return 0; 
}int main(){
    n=readll(),k=readll();ld l=0,r=1e18;rep(i,1,n)p[i].read(),r=std::min(r,(ld)p[i].dis2());if(r<eps)return printf("%.10lf\n",0.0),0;
    r=sqrt(r);rep(i,1,40){ld mid=(l+r)/2;if(check(mid))l=mid;else r=mid;}printf("%.10lf",(double)l);return 0; 
}