#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=216333,e7=1e7+7,inf=1e17,mod=1e9+7;typedef ll aN[N];
ll iabs(ll a){return a<0?-a:a;}
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int main(){
    //  7
    //1
    // 1
    //  1
    //a+2b+4c=m
    //sum_{c=0 to m/4}(m-4c)/2=sum_{c=0 to m/4}m/2+1-2c=(m/2+1)*(m/4+1)-(m/4)*(m/4+1)
    ll T=readll();while(T --> 0){ll n=readll();printf("%lld\n",((n/2+1-n/4)%mod*((n/4+1)%mod))%mod);}return 0;
}