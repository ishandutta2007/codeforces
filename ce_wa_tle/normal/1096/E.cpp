#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2e5+7,mod=998244353;typedef ll aN[N];aN ny,jc,njc;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll C(ll n,ll m){return n<0||n>m?0:jc[m]*njc[n]%mod*njc[m-n]%mod;}
ll nC(ll n,ll m){return n<0||n>m?0:njc[m]*jc[n]%mod*jc[m-n]%mod;}
ll calc(ll n,ll m,ll r){if(!n)return!m;
    ll sum=0;rep(i,0,n){if(i*r>m)break;sum=(sum+(i&1?mod-1:1)*C(i,n)%mod*C(n-1,m-i*r+n-1))%mod;}return sum;
}int main(){
    ll p=readll(),s=readll(),r=readll(),sum=0;ny[1]=jc[0]=jc[1]=njc[0]=njc[1]=1;
    rep(i,2,6500)jc[i]=jc[i-1]*i%mod,njc[i]=njc[i-1]*(ny[i]=(mod-mod/i)*ny[mod%i]%mod)%mod;
    rep(i,r,s)rep(j,1,p){if(i*j>s)break;sum=(sum+ny[j]*C(j-1,p-1)%mod*calc(p-j,s-i*j,i))%mod;}
    printf("%lld\n",sum*nC(p-1,s-r+p-1)%mod);return 0;
}