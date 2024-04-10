#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=333,mod=998244353;typedef ll aN[N],a2N[2*N];ll n;
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
a2N next,to,head,st,g_;ll cnt=1,f_[N][2*N],*f[N],*g=g_+N;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
ll pow(ll a,ll b,ll p){ll res=1;while(b){if(b&1)res=res*a%p;a=a*a%p,b>>=1;}return res;}
void qadd(ll&a,ll b){if((a+=b)>=mod)a-=mod;}ll max(ll a,ll b){return a>b?a:b;}ll min(ll a,ll b){return a<b?a:b;}
void dfs(ll u,ll fa,ll d){
    rep(i,-n,n)f[u][i]=0;f[u][d]=f[u][-1]=1;
    rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(to[i]^fa){
        dfs(v,u,d);ll top=0;rep(j,-n,n)if(f[v][j])st[++top]=j;rep(j,-n,n)g[j]=f[u][j],f[u][j]=0;
        ll k=0;rep(j,-n,n)if(g[j])rep(s,1,top)k=st[s],qadd(f[u][k+j>=0?max(k-1,j):min(k-1,j)],g[j]*f[v][k]%mod);
    }//rep(i,-n,n)printf("f[%lld][%lld]=%lld\n",u,i,f[u][i]);
}int main(){
    ll n=::n=readll(),u,v,ans=0;rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);rep(i,1,n)f[i]=f_[i]+N;
    rep(i,1,n-1){dfs(1,0,i);rep(j,-n,-1)qadd(ans,f[1][j]);}printf("%lld\n",ans*pow(2,mod-1-n,mod)%mod);return 0;
}