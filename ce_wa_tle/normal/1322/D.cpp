#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=1<<17,Q=2e5+7,K=N,V=42;typedef ll aN[N];
void qmax(ll&a,ll b){if(a<b)a=b;}
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll l[2444],s[2444],c[4444],f[4444][2222];
int main(){
    ll n=readll(),m=n+readll();per(i,n,1)l[i]=readll();per(i,n,1)s[i]=readll();rep(i,1,m)c[i]=readll();
    memset(f,-0x3f,sizeof f);rep(i,1,m)f[i][0]=0;
    rep(i,1,n){
        per(j,n,1)qmax(f[l[i]][j],f[l[i]][j-1]+c[l[i]]-s[i]);
        rep(j,l[i],m)rep(k,0,n>>(j-l[i]))qmax(f[j+1][k/2],f[j][k]+k/2*c[j+1]);
    }printf("%lld\n",f[m][0]);return 0;
}