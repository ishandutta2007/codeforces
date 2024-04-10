#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=5e5+9,M=1e6+7,mod=998244353;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll a[512][512],b[512][512],x[111],y[111];
int main(){
    const ll n=readll(),z=1<<n;ll sum=0;ref(i,0,z)ref(j,0,z)a[i][j]=readll();
    ll m=readll();ref(i,0,m)x[i]=readll(),y[i]=readll();
    ref(now,0,n){
        ref(i,0,z)ref(j,0,z)b[i][j]=0;ref(i,0,z)ref(j,0,z)ref(s,0,m)b[(i+x[s])&(z-1)][(j+y[s])&(z-1)]^=a[i][j];
        ref(i,0,z)ref(j,0,z)a[i][j]=b[i][j];rep(s,0,m)x[s]=x[s]<<1&(z-1),y[s]=y[s]<<1&(z-1);
    }ref(i,0,z)ref(j,0,z)sum+=!!a[i][j];printf("%lld\n",sum);return 0;
}