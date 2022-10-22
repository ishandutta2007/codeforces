#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i++)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;typedef long double ld;const ld eps=1e-6,inf=1e9;const ll N=1e5+5,mod=1e9+7;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}
int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN a,f,v;
int main(){
    ll n=readll(),cnt=n,rt;rep(i,1,n){
        ll min=0,x=0,lst=i,p=2;rep(j,1,n)a[j]=readll();rep(j,1,i-1)if(!min||a[j]<x)x=a[min=j];
        std::sort(a+1,a+n+1),*std::unique(a+1,a+n+1)=0;while(v[min]!=x)min=f[min];
        v[i]=a[1];while(a[p]!=x)v[lst=f[lst]=++cnt]=a[p++];f[lst]=min,!min&&(rt=lst);
    }
    printf("%lld\n",cnt);rep(i,1,cnt)printf("%lld ",v[i]);printf("\n%lld\n",rt);
    rep(i,1,cnt)if(f[i])printf("%lld %lld\n",i,f[i]);
	return 0;
}