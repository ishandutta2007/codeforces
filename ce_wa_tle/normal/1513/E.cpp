#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i++)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;typedef long double ld;const ld eps=1e-6,inf=1e9;const ll N=1e5+5,mod=1e9+7;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}
int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN jc,njc,ny,a;
int main(){
    ll n=readll(),s=0,s1=0,s2=0,s3=0;rep(i,1,n)s+=a[i]=readll();if(s%n)return puts("0"),0;s/=n;
    rep(i,1,n)a[i]<s&&++s1,a[i]>s&&++s2,a[i]==s&&++s3;jc[0]=njc[0]=ny[1]=jc[1]=njc[1]=1;
    rep(i,2,n)jc[i]=jc[i-1]*i%mod,njc[i]=njc[i-1]*(ny[i]=(mod-mod/i)*ny[mod%i]%mod)%mod;
    std::sort(a+1,a+n+1);ll lst=0,mul=1;rep(i,1,n+1)if(i==n+1||!lst||a[i]!=a[lst])mul=mul*njc[i-lst]%mod,lst=i;
    printf("%lld\n",(s1<=1||s2<=1?jc[n]:jc[s1]*jc[s2]%mod*jc[n]%mod*2*njc[s1+s2]%mod)*mul%mod);
	return 0;
}