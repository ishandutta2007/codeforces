#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=111,mod=998244353,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}char s[222222];
int main(){
    ll n=readll(),k=readll(),ls=0,fs=0;rep(i,1,n)s[i]=readchar();rfor(ll i=1,g=0;!g||fs||i!=1;i=i%n+1)if(s[i]==s[i%n+1])
    {if(ls){ll l=ls,r=i,f=k;for(;f--&&l!=r&&(l=l%n+1)!=r&&(r=(r-2+n)%n+1);)s[l]=s[ls],s[r]=s[i];while(l!=r&&s[l%n+1]==s[l])
    s[l=l%n+1]^='B'^'W';}if(i==fs)break;ls=i%n+1;fs=fs?:(i-1)%n+1;}else g=1;puts(s+1);return 0;
}
/*
8 1
WBWWBWBW
8 1
WWBWBWBW
*/