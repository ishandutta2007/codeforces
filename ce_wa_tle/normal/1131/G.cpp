#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=2.5e5+7,M=1e7+7,inf=1e18;
typedef ll aN[N],*aN_[N],aM[M];aN k,sa,sc;aN_ a,c;aM h,v,mn,f,s,l,r;ll*na=sa,*nc=sc;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int main(){
    const ll n=rd,m=rd;rep(i,1,n){k[i]=rd,a[i]=na;rep(j,1,k[i])*++na=rd;c[i]=nc;rep(j,1,k[i])*++nc=rd;}
    const ll q=rd;ll t=0;rep(i,1,q){ll id=rd,mul=rd;rep(j,1,k[id])h[++t]=a[id][j],v[t]=c[id][j]*mul;}
    t=0;rep(i,1,m){while(t&&h[i]-i>=h[s[t]]-s[t])t--;l[i]=!t||h[i]-i<=-s[t]?s[t]+1:l[s[t]],s[++t]=i;}s[0]=m+1;
    t=0;per(i,m,1){while(t&&h[i]+i>=h[s[t]]+s[t])t--;r[i]=!t||h[i]+i<=s[t]?s[t]-1:r[s[t]],s[++t]=i;}mn[t=0]=inf;
    rep(i,1,m){while(t&&r[s[t]]<i)t--;s[++t]=i,f[i]=std::min(mn[t]=std::min(mn[t-1],f[i-1]+v[i]),f[l[i]-1]+v[i]);}
    printf("%lld\n",f[m]);return 0;
}