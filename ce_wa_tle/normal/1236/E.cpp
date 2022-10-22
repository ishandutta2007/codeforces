#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define mem(x) memset(x,0,sizeof(x))
#define memn(x,n) memset(x,0,sizeof(ll)*((n)+1))
typedef long long ll;const ll N=2222221,mod=998244353,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];aN lf,rt,a;
ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int main(){
    ll n=readll(),m=readll(),x;if(n==1)return puts("0"),0;rep(i,1,m)a[i]=readll();ll sum=n;
    rep(i,0,n+m)lf[i]=std::max(1ll,i-m);per(i,m,1)x=i+a[i]-1,lf[x]=lf[x+1];rep(i,1,n)sum-=lf[i-1];
    rep(i,0,n+m)rt[i]=std::min(i+1,n);per(i,m,1)x=m-i+a[i],rt[x]=rt[x-1];rep(i,m,n+m-1)sum+=rt[i+1];
    printf("%lld\n",sum);return 0; 
}