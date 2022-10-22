#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=222,mod=998244353,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];aN fl,a,c;ll n;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
std::bitset<1250001>f[51][27];int cmp(ll x,ll y){return fl[x]!=fl[y]?fl[x]>fl[y]:a[x]==a[y]?0:fl[x]^(a[x]>a[y]);}
ll find(ll now,ll s,ll lst){rep(i,3,lst-1)if(a[i]<=now)rep(j,2,i-1)if(f[j][s-1][now-a[i]])return i;return 0;}
int main(){
    n=readll();ll lst=2*n+1;rep(i,1,2*n)a[c[i]=i]=readll();std::sort(a+1,a+2*n+1);f[2][0][0]=1;
    rep(i,3,2*n){ref(j,0,n)f[i][j]=f[i-1][j];ref(j,1,n)f[i][j]|=f[i-1][j-1]<<a[i];}
    ll s=0;rep(i,3,2*n)s+=a[i];s/=2;ll now=0;per(i,s,1)if(f[2*n][n-1][i]){now=i;break;}fl[1]=1;//printf("%lld\n",now);
    per(s,n-1,1){ll fd=lst=find(now,s,lst);fl[fd]=1,now-=a[fd];}std::sort(c+1,c+2*n+1,cmp);
    rep(i,1,n)printf("%lld ",a[c[i]]);puts("");rep(i,n+1,2*n)printf("%lld ",a[c[i]]);puts("");return 0; 
}