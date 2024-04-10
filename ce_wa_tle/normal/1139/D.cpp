#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=4e5+7,inf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;typedef ll aN[N];aN ny,p,mu;
inline ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}inline int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int main(){
	ll n=readll(),top=0;ny[1]=mu[1]=1;rep(i,2,n){ny[i]=(mod-mod/i)*ny[mod%i]%mod;if(!p[i])mu[p[++top]=i]=mod-1;
	rfor(ll j=1;j<=top&&p[j]*i<=n;j++){p[i*p[j]]=1,mu[i*p[j]]=(mod-mu[i])%mod;if(i%p[j]==0){mu[i*p[j]]=0;break;}}}
	ll sum=1;rep(i,2,n)sum=(sum+mod-mu[i]*(n/i)%mod*ny[n-n/i]%mod)%mod;printf("%lld\n",sum);return 0;
}