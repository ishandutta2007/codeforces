#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2e6+77,inf=1e18+7;typedef ll aN[N];aN a,b,c,f;
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int cmp(ll x,ll y){return a[x]<a[y];}
int main(){
	ll n=readll();rep(i,1,n)a[i]=readll();rep(i,1,n)b[i]=readll();
	rep(i,1,n)c[i]=i,(f[i]=a[i]>b[i])&&(std::swap(a[i],b[i]),0);std::sort(c+1,c+n+1,cmp);
	ll max[2]={},ans=0,sum=0,i;rep(j,1,n)i=c[j],max[f[i]]=std::max(max[f[i]],b[i]),
	ans=std::max(ans,std::min(max[f[i]^1],b[i])-a[i]),sum+=b[i]-a[i];
	printf("%lld\n",sum-2*ans);return 0;
}