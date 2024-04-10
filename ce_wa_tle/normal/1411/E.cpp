#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i++)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=6e5+9,inf=1e9,mod=1e9+7;typedef ll aN[N];ll t[123],n,T,x;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
#define rc readchar()
int main(){
    n=readll(),T=-readll();rep(i,1,n-2)t[x=rc-96]++,T+=1<<~-x;T-=(1<<(rc-97)),T+=(1<<(rc-97));if(T<0)return puts("NO");
    rfor(ll w=0;T;t[w+1]+=t[w]/2,w++)if((T>>w&1)&&(!t[w]||(--t[w],T&=~-T,0)))return puts("NO"),0;puts("YES");return 0;
}