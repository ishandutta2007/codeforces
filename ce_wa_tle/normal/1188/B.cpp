#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=422222;typedef ll aN[N];aN a;
inline ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}inline int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int main(){
    ll n=readll(),p=readll(),k=readll();rep(i,1,n)a[i]=readll(),a[i]=(a[i]*a[i]%p*a[i]%p-k+p)%p*a[i]%p;
    std::sort(a+1,a+n+1);ll s=0,sum=0;rep(i,2,n)sum+=a[i]==a[i-1]?++s:s=0;printf("%lld\n",sum);return 0; 
}