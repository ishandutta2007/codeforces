#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define pow(x...) djsnfianj(x)
#define log dhfesaffe
typedef long long ll;typedef long double ld;const ll N=2e6+7,M=1<<19,mod=1e9+7,mod2=mod*mod;typedef ll aN[N];
inline ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
inline int add(ll&a,ll b,ll p){;return(a+=b)>=p?a-=p,1:0;}aN next,to,head,sum,sz;ll cnt=0,f[100007][233],s[233][233];
void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
void dfs(ll u,ll fa,ll k){
    f[u][0]=2;rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(v^fa){dfs(v,u,k);per(i,std::min(k,sz[u]+=sz[v]),0)
        {f[u][i]=f[u][i]*f[v][0]%mod;per(j,std::min(sz[v],std::min(k,i+0)),1)add(f[u][i],f[u][i-j]*f[v][j],mod2);}
        per(i,std::min(k,sz[u]),0)f[u][i]%=mod,add(sum[i],mod-f[v][i],mod);
    }per(i,std::min(k,++sz[u]),0)add(sum[i],f[u][i],mod),i&&add(f[u][i],f[u][i-1],mod);add(f[u][1],mod-1,mod);
}int main(){
    ll n=readll(),k=readll(),u,v,ans=0;rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);dfs(1,0,k),s[1][1]=1;
    rep(i,2,k)rep(j,1,i)s[i][j]=(s[i-1][j]*j+s[i-1][j-1])%mod;//,printf("s[%lld][%lld]=%lld",i,j,s[i][j]);
    rfor(ll jc=1,i=0;i<=k;jc=jc*++i%mod)ans=(ans+sum[i]*jc%mod*s[k][i])%mod;printf("%lld\n",ans);return 0;
}