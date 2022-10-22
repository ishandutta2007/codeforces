#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2222222,mod=998244353,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}aN s;
int main(){
    ll n=readll(),k=readll()-n*(n+1)/2;if(k<0)return puts("-1"),0;ll a=k>(n/2)*(n-n/2)?n/2:(n-sqrt(n*n-4*k))/2
    ,b=k>(n/2)*(n-n/2)?0:k-a*(n-a);printf("%lld\n",n*(n+1)/2+a*(n-a)+b);rep(i,1,n)printf("%lld ",s[i]=i);
    puts("");rep(i,1,a)std::swap(s[i],s[n-i+1]);std::swap(s[a+1],s[a+b+1]);rep(i,1,n)printf("%lld ",s[i]);return 0;
}