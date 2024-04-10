#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=2e6+9,mod=998244353;typedef ll aN[N];
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN next,to,head,d,f,g;ll cnt=0;void add(ll u,ll v){d[u]++,next[++cnt]=head[u],to[head[u]=cnt]=v;}ll n,k;
void dfs(ll u,ll fa){//printf("%lld %lld\n",u,fa);
    ll*s=(ll*)malloc(sizeof(ll)*(d[u]+2)),n=s[0]=0;rfor(ll i=head[u],v;v=to[i],i;i=next[i])
    if(v^fa)dfs(v,u),s[++n]=g[v]+1,f[u]+=f[v];std::sort(s+1,s+n+1);
    rep(i,1,n)if(i==n||s[i]+s[i+1]>k){g[u]=s[i],f[u]-=i-1;break;}free(s);if(n==0)f[u]=1,g[u]=0;
//    printf("%lld %lld %lld\n",u,f[u],g[u]); 
}int main(){
    n=readll(),k=readll();ll u,v,c=1;rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);
    rep(i,1,n)if(d[i]!=1){dfs(c=i,0);break;}printf("%lld\n",f[c]);return 0;
}