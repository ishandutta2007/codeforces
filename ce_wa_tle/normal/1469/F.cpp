#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=2916333,e7=1e7+7,inf=1e17;typedef ll aN[N];char s1[N],s2[N],s3[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
const ll m=2e5;ll t[m+4],cf[m+4];
int main(){
    ll n=readll(),k=readll();rep(i,1,n)t[readll()]++;cf[0]=1,cf[1]=-1;ll now=0;per(i,m,3)rfor(ll j=1;j<=t[i];j++)
    for(cf[now]--,cf[now+1]++,cf[now+2]+=2,cf[now+2+i/2]--,cf[now+2+~-i/2]--;now<=m&&!cf[now];now++)
    if(cf[now+1]*2+cf[now+2]>=k)return printf("%lld\n",now+2),0;//    rep(i,1,100)printf("%lld ",cf[i]);puts("");
    rfor(ll tot=0;now<=m;now++)if((tot+=cf[now]+=cf[now-1])>=k)return printf("%lld\n",now),0;puts("-1");return 0;
}
/*
10 100000
184056 6564 18232 46874 116555 187227 138825 180211 171932 153322
*/