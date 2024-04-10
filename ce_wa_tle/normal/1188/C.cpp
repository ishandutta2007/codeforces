#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=422222,mod=998244353;typedef ll aN[N];aN a;ll f[1111][1111],p[1111][1111];
inline ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}inline int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int main(){
    ll n=readll(),k=readll(),sum=0;rep(i,1,n)a[i]=readll();std::sort(a+1,a+n+1);ll up=a[n]/(k-1);f[0][0]=p[0][0]=1;
    rep(ans,1,up){ll now=0;rep(i,1,n){while(a[now+1]+ans<=a[i])now++;rep(j,0,k)j&&(f[i][j]=p[now][j-1]),
    p[i][j]=(p[i-1][j]+f[i][j])%mod;}sum=(sum+p[n][k])%mod;}printf("%lld\n",sum);return 0; 
}