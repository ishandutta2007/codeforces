#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define pow djsnfianj
typedef long long ll;typedef long double ld;const ll N=1e6+7,inf=1e18;typedef ll aN[N];
ld pow[N];char s[N];aN ms;const ld fz=1.0/RAND_MAX;
inline ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ld ranld(){ld s=fz,res=0;rep(i,1,5)res+=rand()*s,s*=fz;return res;}
int main(){//rep(i,1,1000)printf("%.57Lf\n",(ld)ranld());
    ll n=readll(),m=readll(),min=0,x;ld p[3];pow[0]=1;rep(i,1,m)pow[i]=pow[i-1]*0.75;rep(t,1,m){
    scanf("%s",s+1),p[0]=p[1]=0;rep(i,1,n)p[s[i]&15]+=pow[ms[i]-min];printf("%d\n",ranld()*(p[0]+p[1])<=p[1]);
    fflush(stdout),x=readchar(),min=inf;rep(i,1,n)min=std::min(min,ms[i]+=x^s[i]);}return 0;
}