#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define log fjdsfan
typedef long long ll;const ll N=6e5+5,mod=998244353,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];aN jc,ny,e2,njc,A,B,ans,log;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll pow(ll a,ll b,ll p){ll res=1;while(b){if(b&1)res=res*a%p;a=a*a%p,b>>=1;}return res;}aN rev,wnk,t;
ll C(ll n,ll m){return jc[m]*njc[n]%mod*njc[m-n]%mod;}const ll g=3,g_1=pow(g,mod-2,mod);
ll NTT(ll n,ll*a,ll x){
    static ll lst=1,lsl=0;if(lst<n){rep(i,lst+1,n)log[i]=log[i>>1]+1;lst=n;}const ll w=x==1?g:g_1,l=log[n-1]+1,len=1<<l;
    if(len^lsl&&(lsl=len))ref(i,1,len)rev[i]=rev[i>>1]>>1|(i&1)<<l>>1;ref(i,0,len)if(i<rev[i])std::swap(a[i],a[rev[i]]);
    rfor(ll k=1;k<len;k<<=1){
        const ll wn=pow(w,(mod-1)/(k<<1),mod);wnk[0]=1;rep(j,1,k)wnk[j]=wnk[j-1]*wn%mod;ll x,y;
        rfor(ll i=0;i<len;i+=k<<1)ref(j,0,k)x=a[i|j],y=a[i|j|k]*wnk[j]%mod,a[i|j]=(x+y)%mod,a[i|j|k]=(x+mod-y)%mod;
    }const ll ny=pow(len,mod-2,mod);if(!~x)ref(i,0,len)a[i]=a[i]*ny%mod;return len;
}
int main(){
    ll n=readll(),k=readll();rep(i,1,n)t[readll()]++;e2[ny[1]=njc[0]=njc[1]=jc[0]=jc[1]=e2[0]=1]=2;
    rep(i,2,n)jc[i]=jc[i-1]*i%mod,njc[i]=njc[i-1]*(ny[i]=(mod-mod/i)*ny[mod%i]%mod)%mod,e2[i]=e2[i-1]*2%mod;
    rep(q,1,k){
        ll s1=0,s2=0,m=readll();rep(i,1,m-1)if(t[i])++(t[i]==1?s1:s2);s2*=2;
        rep(i,0,s1)A[i]=e2[i]*C(i,s1)%mod;rep(i,0,s2)B[i]=C(i,s2)%mod;
        const ll len=NTT(s1+s2+1,A,1);NTT(len,B,1);ref(i,0,len)A[i]=A[i]*B[i]%mod;NTT(len,A,-1);
        ref(i,0,len)if(i+m<=6e5)ans[i+m]=(ans[i+m]+A[i])%mod;ref(i,0,len)A[i]=B[i]=0;
    }ll q=readll();rep(i,1,q)printf("%lld\n",ans[readll()/2-1]);return 0;
}