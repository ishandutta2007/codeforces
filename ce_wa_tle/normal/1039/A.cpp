#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=2e6+9,mod=998244353;typedef ll aN[N];aN a,x,b;
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int main(){
    ll n=readll(),t=readll();rep(i,1,n)a[i]=readll();rep(i,1,n)if((x[i]=readll())<x[i-1]||x[i]<i)return puts("No"),0;
    ll p=1;rep(i,1,n){if(x[i]!=i){if(p<=i)p=i;while(p!=x[i])++p,b[p-1]=a[p]+t;}b[i]=std::max(a[i]+t,b[i]);}
    rep(i,1,n)b[i]=std::max(b[i-1]+1,b[i]);rep(i,1,n)if(x[i]!=n&&a[x[i]+1]+t<=b[x[i]])return puts("No"),0;puts("Yes");
    rep(i,1,n)printf("%lld ",b[i]);return 0;
}
/*
4 5
1 2 3 5
1 3 3 4
*/