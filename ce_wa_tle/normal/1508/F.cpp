#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=3e5;typedef ll aN[N];aN left[2],right[2],a,w;ll cnt;
ll readll(){
    ll x=0,w=1;char c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
void check(ll l,ll r){ll p=a[l]<a[r],*lf=left[p],*rt=right[p];
if(!lf[r]||(a[lf[r]]<a[l])==p)cnt-=(rt[lf[r]]==r)+(lf[rt[l]]==l),cnt++,lf[rt[l]=r]=l;}
int main(){
    ll n=readll(),m=readll();rep(i,1,n)a[w[i]=i]=readll();
    rep(i,1,m)rfor(ll l=readll(),r=readll(),i=std::lower_bound(w+l+1,w+r+1,(ll)r)-w-1;
    w[i]<r||--i>=l||(printf("%lld\n",cnt),0);check(i,++w[i]));return 0;
}