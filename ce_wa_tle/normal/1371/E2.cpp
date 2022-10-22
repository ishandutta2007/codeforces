#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=3116333,inf=1e9,mod=1e9+7;typedef ll aN[N];aN a,tag;ll cnt=0;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int main(){
    ll n=readll(),p=readll();rep(i,1,n)a[i]=readll()+1;std::sort(a+1,a+n+1);ll lx=a[1]-1,rx=a[p]-2,x,ans=0;
    rep(i,1,n)lx=std::max(a[i]-i,lx);if(lx>rx)return puts("0"),0;rep(i,p+1,n)(x=a[i]-i-1)<=rx&&
    (x+=(lx-x+p-1)/p*p)<=rx&&(tag[x-lx]=1);//,printf("%lld %lld %lld\n",lx,rx,x);
    rep(i,0,rx-lx)ans+=!(i>=p?tag[i]|=tag[i-p]:tag[i]);printf("%lld\n",ans);
    rep(i,0,rx-lx)!tag[i]&&printf("%lld ",i+lx);return 0;
}