#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=422222,mod=998244853,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];aN a;
ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int main(){
    ll n=readll(),k=readll();a[0]=a[n+1]=-1;rep(i,1,n)a[i]=readchar('0','1');ll l=1,r=n;while(a[l]==a[l+1])l++;
    while(a[r]==a[r-1])r--;if((a[l]==a[r]&&r-l-1<=k)||n-l<=k||r-1<=k)return puts("tokitsukaze"),0;
    if(l>=n-k-1&&r<=k+1+1&&k*2>=n)return puts("quailty"),0;puts("once again");return 0; 
}