#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=2e6+9,mod=1e9+7;typedef ll aN[N];
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll iabs(ll u){return u>0?u:-u;}aN t,d;
int main(){
    ll n=readll(),x,b=0;rep(i,1,n)t[x=readll()]++,b=std::max(b,x);x=0;while(t[x]>=x*4)x++;if(b>n)return puts("-1"),0;
    rfor(ll r=1;r<=n;r++)if(n%r==0){
        ll c=n/r,y=r+c-b-x;memset(d,0,sizeof(ll)*(b+1));rep(i,1,r)rep(j,1,c)d[iabs(i-x)+iabs(j-y)]++;
        ll p=1;rep(i,0,b)if(t[i]!=d[i]){p=0;break;}if(p)return printf("%lld %lld\n%lld %lld\n",r,c,x,y),0;
    }return puts("-1"),0;
}