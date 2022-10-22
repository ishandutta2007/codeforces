#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=422222,inf=1e18;typedef ll aN[N];
inline ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}inline int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll calc(ll a,ll b,ll c,ll n){
//printf("%lld\n"); 
    ll res,t;return n>=0?res=n*(n+1)/2*(a/c)+(n+1)*(b/c),a%=c,b%=c,t=(a*n+b)/c,res+t*n-calc(c,c-b-1,a,t-1):0;
}ll exgcd(ll a,ll b,ll&x,ll&y){ll res;return b?res=exgcd(b,a%b,y,x),y-=a/b*x,res:(x=1,y=0,a);}
int check(ll a,ll b,ll p,ll q,ll x){
    ll l=(q-x+1)/2,r=(q+x)/2;return calc(p,q-l,q,b)-calc(p,q-l,q,a-1)-calc(p,q-r-1,q,b)+calc(p,q-r-1,q,a-1);
}void calc(int cases){
    ll a=readll(),b=readll(),p=readll(),q=readll();//sin(min|2(px%q)-q|) |2(px%q)-q|<=k <=> (q-k+1)/2<=px%q<=(q+k)/2
    ll l=0,r=q;while(l<=r){ll mid=(l+r)>>1;if(check(a,b,p,q,mid))r=mid-1;else l=mid+1;}//exit(0);
    ll x,y,g=exgcd(p,q,x,y),res=inf,ans1=(q+l)/2,ans2=(q-l+1)/2,rx;q/=g,x%=q,x+=q,x%=q;
    if(ans1%g==0)rx=x*(ans1/g)%q,res=std::min(res,(a-rx+q-1)/q*q+rx);(void)cases;
    if(ans2%g==0)rx=x*(ans2/g)%q,res=std::min(res,(a-rx+q-1)/q*q+rx);printf("%lld\n",res);
}int main(){ll T=readll(),cnt=0;while(T --> 0)calc(++cnt);return 0;}
/*
1
175 963 82051 96137
*/