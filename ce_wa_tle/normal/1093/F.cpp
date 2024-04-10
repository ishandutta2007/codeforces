#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2e5+7,mod=998244353;typedef ll aN[N];aN s,f1,f2,a;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll d(ll u){return u<0?0:s[u];}
ll getans(ll i,ll k,ll l,ll c){if(k>i)return 0;k=(i-k+1)/l;return(d(i-1)-(a[i-k*l]!=-1&&a[i-k*l]!=c?d(i-1-k*l):d(i-1-(k+1)*l))-d(i-l)+d(i-(k+1)*l)+mod*3)%mod;}
int main(){
    ll n=readll(),k=readll(),l=readll(),k1=1,k2=1,c=0;s[0]=1;rep(i,1,n){ll x=a[i]=readll();if(~x)c!=x&&(k2=k1,c=x),k1=i+1;
    s[i]=(d(i-l)+(f1[i]=getans(i,k1,l,c+1))*(k-1)+(f2[i]=getans(i,k2,l,c)))%mod;}printf("%lld\n",(f1[n]*(k-1)+f2[n])%mod);return 0;
}
/*
3 3 2
1 -1 -1
*/