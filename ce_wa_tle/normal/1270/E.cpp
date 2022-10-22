#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=4e5+9,mod=998244353;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN x,y;
int main(){
    ll n=readll();rep(i,1,n)x[i]=readll()+mod,y[i]=readll()+mod;
    while(1){
        ll p[4]={};rep(i,1,n)p[(x[i]&1)<<1|(y[i]&1)]++;
        if((p[0]+p[3]&&p[1]+p[2])||(p[0]&&p[3])||(p[1]&&p[2])){
            printf("%lld\n",p[0]+p[3]&&p[1]+p[2]?p[1]+p[2]:p[3]+p[2]);
            rep(i,1,n)if(p[0]+p[3]&&p[1]+p[2]?(x[i]^y[i])&1:x[i]&1)printf("%lld ",i);return 0;
        }rep(i,1,n)x[i]/=2,y[i]/=2;
    }
    return 0;
}