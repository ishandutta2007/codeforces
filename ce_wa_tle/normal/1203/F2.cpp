#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=422222,mod=998244853,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];aN f;
ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct node{ll a,b;}s[N];
int operator<(const node&a,const node&b){return(a.b>=0)==(b.b>=0)?a.b>=0?a.a<b.a:a.a+a.b>b.a+b.b:a.b>b.b;} 
int main(){
    ll n=readll(),m=readll(),max=0,sum=0;rep(i,1,n)s[i].a=readll(),s[i].b=readll();std::sort(s+1,s+n+1);
    rep(i,1,n)if(s[i].b>=0){if(s[i].a<=m)sum++,m+=s[i].b;}else
    rep(j,std::max(0ll,s[i].a+s[i].b),m+s[i].b)f[j]=std::max(f[j],f[j-s[i].b]+1);
    rep(i,0,m)max=std::max(max,f[i]);printf("%lld\n",max+sum);return 0; 
}