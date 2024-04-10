#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2.5e5+7;typedef ll aN[N],s2[444][444];s2 f[2];aN a;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct node{ll s,t,c,r;void read(){s=readll(),t=readll(),c=readll(),r=readll();}operator ll()const{return r;}}p[N];
int main(){
    ll n=readll(),m=readll(),ans=0;rep(i,1,n)a[i]=readll();rep(i,1,m)p[i].read();std::sort(p+1,p+m+1);
    memset(f,0x3f,sizeof f);ll t=1;rep(i,1,n)f[0][i][i]=0;rep(k,1,n+1){s2&lst=f[~k&1],&now=f[k&1];
    rep(i,1,n){ll p=i;if(k)rep(j,i,n){while(lst[i][p]<a[j]-a[p])p++;now[i][j]=std::min(lst[i][p],a[j]-a[p-1]);}}
    while(t<=m&&k==p[t].r+1)ans=std::max(ans,now[p[t].s][p[t].t]*p[t].c),t++;}printf("%lld\n",ans);return 0;
}