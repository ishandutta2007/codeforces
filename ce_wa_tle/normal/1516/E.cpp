#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=333,mod=1e9+7;typedef ll aN[N],a2N[2*N];aN pre,f[N],npre,ny,ans;
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll pow(ll a,ll b,ll p){ll res=1;while(b){if(b&1)res=res*a%p;a=a*a%p,b>>=1;}return res;}
ll calc(ll n,ll k){
    ll low=std::max(2*k-n+1,1ll);pre[low-1]=1;rep(i,low,k)pre[i]=pre[i-1]*(n-2*k+i)%mod;npre[k]=pow(pre[k],mod-2,mod);
    per(i,k,low)npre[i-1]=npre[i]*(n-2*k+i)%mod,ny[i]=npre[i]*pre[i-1]%mod;ll C=1,res=0;
    rep(i,n-2*k+1+low-1,n+low-1)C=C*i%mod;rep(i,low-1,k)res=(res+f[k][i]*C)%mod,C=C*(n+i+1)%mod*ny[i+1]%mod;
    ll jc=1;rep(i,1,2*k)jc=jc*i%mod;/*printf("==%lld %lld\n",res,jc);*/return res*pow(jc,mod-2,mod)%mod;
}int main(){
    ll n=readll(),k=readll();f[0][0]=1;rep(i,1,k)rep(j,0,i)f[i][j]=((2*i-1-j)*f[i-1][j-1]+(j+1)*f[i-1][j])%mod;
    ans[0]=1;rep(i,1,k)printf("%lld ",ans[i]=((i==1?0:ans[i-2])+calc(n,i))%mod);return 0;
}