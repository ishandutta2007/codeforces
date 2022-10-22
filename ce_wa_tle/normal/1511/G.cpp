#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2e6+77,inf=1e18+7;typedef ll aN[N];const ll db=1;aN s,f[23];
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int main(){
    ll n=readll(),m=readll();rep(i,1,n)s[readll()]^=1;rep(i,1,m)s[i]^=s[i-1];
    rep(i,0,21)rep(j,1,m-(2<<i)+1)f[i+1][j]=f[i][j]^f[i][j+(1<<i)]^s[j+(2<<i)-1]<<i^s[j+(1<<i)-1]<<i;
    ll q=readll();rep(i,1,q){ll l=readll(),r=readll(),g=0;per(i,22,0)
    if((1<<i)+l<=r)g^=f[i][l],g^=s[r]<<i^s[(l+=1<<i)-1]<<i;putchar('A'+!g);}return 0;
}