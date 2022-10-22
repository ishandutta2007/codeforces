#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=1116333,inf=1e9,mod=1e9+7;typedef ll aN[N];aN f[2];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int main(){
    ll n=readll(),r1=readll(),r2=readll(),r3=readll(),d=readll(),x,nowr2,gf;f[0][1]=f[0][0]=-d;
    rep(i,1,n){
        x=readll(),nowr2=std::min(r2,r1*(x+1)),gf=std::min(x*r1+r3,r2+r3+2*d);
        f[1][i]=std::min(f[0][i-1]+d+nowr2,f[1][i-1]+d+nowr2+d+r1+d),
        f[0][i]=std::min(f[0][i-1]+d+gf,f[1][i-1]+d+std::min(nowr2+d+r1*2,gf+d+r1)+d);
        //printf("%lld %lld\n",f[i][0],f[i][1]);
    }printf("%lld\n",std::min(f[0][n],f[1][n-1]+d+gf+d+r1));return 0;
}