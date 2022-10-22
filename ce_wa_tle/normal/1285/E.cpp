#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=4e5+7,k=65535,mod=1e9+7;typedef ll aN[N];
void qmax(ll&a,ll b){if(a<b)a=b;}
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN c,l,r,d;
int solve(){
    ll n=readll(),cnt=0,ans=0;rep(i,1,n)c[++cnt]=l[i]=readll()*2,c[++cnt]=r[i]=readll()*2+1;
    std::sort(c+1,c+cnt+1),cnt=std::unique(c+1,c+cnt+1)-c-1;rep(i,0,cnt)d[i]=0;
    rep(i,1,n)l[i]=std::lower_bound(c+1,c+cnt+1,l[i])-c,r[i]=std::lower_bound(c+1,c+cnt+1,r[i])-c-1,
    d[l[i]]++,d[r[i]+1]--;rep(i,1,cnt)d[i]+=d[i-1];ll s=0;rep(i,1,cnt)s+=d[i]&&!d[i+1],d[i]=(d[i]==1)+d[i-1];
    rep(i,1,n)ans=std::max(ans,s+d[r[i]]-d[l[i]-1]-(d[r[i]]-d[r[i]-1]==1)-(d[l[i]]-d[l[i]-1]==1));
    printf("%lld\n",ans);return 0; 
}int main(){ll T=readll();while(T --> 0)solve();return 0;}