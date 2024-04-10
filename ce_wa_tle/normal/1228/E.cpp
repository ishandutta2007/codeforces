#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define mem(x) memset(x,0,sizeof(x))
#define memn(x,n) memset(x,0,sizeof(ll)*((n)+1))
typedef long long ll;const ll N=2222221,mod=1e9+7,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];aN jc,njc,ny,ek,ef;
ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll pow(ll a,ll b,ll p){ll res=1;while(b){if(b&1)res=res*a%p;a=a*a%p,b>>=1;}return res;}
ll C(ll n,ll m){return jc[m]*njc[n]%mod*njc[m-n]%mod;}
int main(){
    ll n=readll(),k=readll(),sum=0;ny[1]=njc[0]=jc[0]=jc[1]=njc[1]=ek[0]=ef[0]=1;ek[1]=k%mod,ef[1]=(k-1)%mod;
    rep(i,2,n)ek[i]=ek[i-1]*ek[1]%mod,ef[i]=ef[i-1]*ef[1]%mod,
    jc[i]=jc[i-1]*i%mod,njc[i]=njc[i-1]*(ny[i]=(mod-mod/i)*ny[mod%i]%mod)%mod;
    rep(i,0,n)sum=(sum+(i&1?mod-C(i,n):C(i,n))*pow((ef[i]*ek[n-i]-ef[n]+mod)%mod,n,mod))%mod;
    printf("%lld\n",sum);return 0; 
}