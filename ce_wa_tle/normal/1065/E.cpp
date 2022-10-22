#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2e5+7,mod=998244353,n2=(mod+1)/2;typedef ll aN[N];
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll pow(ll a,ll b,ll p){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%p,b>>=1;}return res;}
int main(){
    ll n=readll(),m=readll(),c=readll(),ans=1,lst=0,x;rep(i,1,m)x=readll(),
    ans=ans*(pow(c,(x-lst)*2,mod)+pow(c,x-lst,mod))%mod*n2%mod,lst=x;printf("%lld\n",ans*pow(c,n-2*x,mod)%mod);return 0;
}