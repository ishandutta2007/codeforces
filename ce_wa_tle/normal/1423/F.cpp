#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=1e6+7,Q=1e6+7,V=42;const ld eps=1e-7;
ld sqr(ld x){return x*x;}
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}ld readld(){
	ll x=0,w=1;ld s=0,d=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());
    if(c=='.')for(c=getchar();c>='0'&&c<='9';s+=(d*=0.1)*(c^48),c=getchar());return(x+s)*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int main(){
    ll n=readll(),k=readll(),s=0,z=0,x,y;rep(i,1,k)x=readll(),y=readll(),s+=y,z=(z+x*y)%n;
    printf("%d\n",s<n?1:s>n?-1:z==(n&1?0:n/2)?1:-1);return 0;
}