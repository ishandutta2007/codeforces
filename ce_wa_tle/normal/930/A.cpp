#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=414514,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;char c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}
int readchar(){char c=getchar();for(;c<'A'||c>'z';c=getchar());return c;}
ll s[1145141],t[1145141];
int main(){
    ll n=readll(),q=0;s[0]=1;rep(i,2,n)s[t[i]=t[readll()]+1]^=1;rep(i,0,n)q+=s[i];printf("%lld\n",q);
	return 0;
}