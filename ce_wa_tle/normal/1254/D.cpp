#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=5e5+9,mod=998244353;typedef ll aN[N];ll cnt=0,tot=0;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN next,to,head,dfn,size,son,top,tag,fa;
ll pow(ll a,ll b,ll p){ll res=1;while(b){if(b&1)res=res*a%p;a=a*a%p,b>>=1;}return res;}
void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
void dfs(ll u,ll fa){
    dfn[u]=++tot,size[u]=1,son[u]=0;rfor(ll i=head[u],v;v=to[i],i;i=next[i])
    if(v^fa)dfs(v,u),size[u]+=size[v],(size[v]>size[son[u]])&&(son[u]=v);
}void dfs(ll u,ll fa,ll t){
    ::fa[u]=fa,top[u]=t?top[fa]:u;if(son[u])dfs(son[u],u,1);
    rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(v^fa&&v^son[u])dfs(v,u,0);
}struct bit{
    aN f;ll tag,n;void set(ll n_){memset(f,tag=0,sizeof(ll)*((n=n_)+1));}
    void update(ll u,ll c){for(;u<=n;f[u]+=c,u+=u&-u);}void update(ll l,ll r,ll c){update(l,c),update(r+1,-c);}
    ll query(ll u){ll res=0;while(u)res+=f[u],u&=~-u;return tag+res;}
}t;
void update_tree(ll u,ll c,ll n){
    tag[u]=(tag[u]+c)%mod;if(son[u])t.update(dfn[son[u]],dfn[son[u]]+size[son[u]]-1,(n-size[son[u]])*c%mod);
//    rep(i,1,n)printf("%lld ",t.query(i)%mod);puts("");printf("son=%lld\n",son[u]);
    if(u!=1)t.tag=(t.tag+size[u]*c)%mod,t.update(dfn[u],dfn[u]+size[u]-1,(mod-size[u])*c%mod);
//    rep(i,1,n)printf("%lld ",t.query(i)%mod);puts("");
}ll query_tree(ll u,ll n){ll res=(tag[u]*n+t.query(dfn[u]))%mod;u=top[u];//printf("res=%lld %lld\n",res,t.query(dfn[4])%mod);
while(u)res=(res+tag[fa[u]]*(n-size[u]))%mod,/*printf("==%lld\n",top[3]),*/u=top[fa[u]];return res;}
int main(){
    ll n=readll(),m=readll(),u,v,ni=pow(n,mod-2,mod);rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);
    dfs(1,0),dfs(1,0,0);/*rep(i,1,n)printf("%lld %lld %lld\n",dfn[i],size[i],top[i]);*/t.set(n);
    rep(i,1,m)if(readll()==1)u=readll(),update_tree(u,readll(),n);
    else printf("%lld\n",query_tree(readll(),n)*ni%mod);return 0;
}