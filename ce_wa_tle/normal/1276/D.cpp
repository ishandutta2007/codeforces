#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=4e5+9,mod=998244353;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN a,b,c,next,head,to;ll cnt=0;ll f[N][4]; 
void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
void dfs(ll u,ll fa){
    ll k=0,m=0;rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(v^fa)dfs(v,u);
    rfor(ll i=head[u],v;v=to[i],i;i=next[i])
    if(v^fa)++m,a[m]=(f[v][1]+f[v][2])%mod,b[m]=(f[v][0]+f[v][3])%mod,c[m]=(b[m]+f[v][1])%mod;else k=m;
//    rep(i,1,m)printf("%lld\n",c[i]);
    a[m+1]=c[0]=1;per(i,m,1)a[i]=a[i]*a[i+1]%mod;rep(i,1,m)c[i]=c[i]*c[i-1]%mod;
    rep(i,1,m)f[u][i>k?1:3]=(f[u][i>k?1:3]+b[i]*c[i-1]%mod*a[i+1])%mod;
    f[u][0]=a[1],f[u][2]=c[k]*a[k+1]%mod;
//    printf("%lld %lld %lld %lld %lld\n",u,f[u][0],f[u][1],f[u][2],f[u][3]); 
}
int main(){
    ll n=readll(),u,v;rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);
    dfs(1,0),printf("%lld\n",(f[1][0]+f[1][1]+f[1][3])%mod);return 0;
}