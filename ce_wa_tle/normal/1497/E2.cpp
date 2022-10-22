#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=216333,e7=1e7+7,inf=1e17;typedef ll aN[N];aN a,pre[22],f[22];ll p[e7],md[e7],(&t)[e7]=p;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
void init(){
    const static ll n=1e7;ll top=0;p[0]=1e9+7;md[1]=1;rfor(ll i=2,j;i<=n;i++)
    for(j=1,p[i]||(md[p[++top]=i]=i);j<=top&&p[j]*i<=n&&i%p[j-1];j++)
    p[i*p[j]]=1,md[i*p[j]]=i%p[j]?md[i]*p[j]:md[i/p[j]];memset(t,0,sizeof t);
}
void calc(ll cases){
    ll n=readll(),k=readll(),now=0;rep(i,1,n)a[i]=md[readll()];(void)cases;rep(i,0,k)memset(f[i]+1,0x3f,sizeof(ll)*n);
    rep(j,0,k)rfor(ll i=1,p=1;i<=n+1;pre[j][i]=p,i++)for(now+=!!t[a[i]]++;i<=n?now>j:p<=i;now-=!!--t[a[p++]]);
//    rep(i,1,n)printf("%lld ",a[i]);puts("");rep(j,0,k){rep(i,1,n)printf("%lld ",pre[j][i]);puts("");}//exit(0);
    rep(j,0,k)rep(i,1,n)rep(l,0,j)f[j][i]=std::min(f[j][i],f[j-l][pre[l][i]-1]+1);printf("%lld\n",f[k][n]);
}
int main(){ll T=readll(),cnt=0;init();while(T --> 0)calc(++cnt);return 0;}