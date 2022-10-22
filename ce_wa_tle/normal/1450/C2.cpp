#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i++)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=4e5+5,inf=1e9;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='.',int r='X'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll a[333][333],s[3][3],t[128];char st[]="XO.";void calc(ll cases){
    ll n=readll();memset(s,0,sizeof s);rep(i,1,n)rep(j,1,n)s[a[i][j]=t[readchar()]][(i+j)%3]++;
    ll x=0,g=inf;ref(i,0,3)if(s[0][i]+s[1][(i+1)%3]<g)g=s[0][i]+s[1][(i+1)%3],x=i;(void)cases;
    rep(i,1,n){rep(j,1,n)putchar(st[a[i][j]^(a[i][j]!=2&&(i+j-a[i][j])%3==x)]);puts("");}
}int main(){ll T=readll(),cnt=0;t['.']=2,t['X']=0,t['O']=1;while(T --> 0)calc(++cnt);return 0;}