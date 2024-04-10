#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=422222,inf=1e18,mod=998244353;typedef ll aN[N];aN a,v;
inline ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}inline int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll f[2][3333][3333],s[2],inv_[6666],*inv=inv_+3333;
ll pow(ll a,ll b,ll p){ll res=1;while(b){if(b&1)res=res*a%p;a=a*a%p,b>>=1;}return res;}
int main(){
    ll n=readll(),m=readll();rep(i,1,n)v[i]=readll();rep(i,1,n)s[v[i]]+=a[i]=readll();ll A=s[1],B=s[0];
    rep(i,-m,m)inv[i]=pow(A+B+i,mod-2,mod);rep(i,0,m)f[0][i][m-i]=f[1][i][m-i]=1;
    per(i,m,0)per(j,std::min(B,m-i-1),0)f[1][i][j]=((A+i+1)*f[1][i+1][j]+(B-j)*f[1][i][j+1])%mod*inv[i-j]%mod,
                                        f[0][i][j]=((B-j-1)*f[0][i][j+1]+(A+i)*f[0][i+1][j])%mod*inv[i-j]%mod;
    rep(i,1,n)printf("%lld\n",f[v[i]][0][0]*a[i]%mod);return 0;
}