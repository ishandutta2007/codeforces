#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=2e6+9,mod=1e9+7;typedef ll aN[N];
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN next,to,head,son,l,max;ll*f[N];ll*na(ll sz){static ll s[N*4],n=0;n+=++sz;return s+n-sz;}
ll cnt=0;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
ll cmp(ll u,ll a,ll b){return f[u][a]==f[u][b]?a<b:f[u][a]>f[u][b];}void qmax(ll u,ll&a,ll b){if(cmp(u,b,a))a=b;}
void dfs0(ll u,ll fa){
    rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(v^fa)dfs0(v,u),l[v]+1>l[u]&&(l[u]=l[son[u]=v]+1); 
}void dfs2(ll u,ll fa){
    f[u][0]=1;if(son[u])f[son[u]]=f[u]+1,dfs2(son[u],u),qmax(u,max[u],max[son[u]]+1);
    rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(v^fa&&v^son[u])
    {f[v]=na(l[v]),dfs2(v,u);rep(i,0,l[v])f[u][i+1]+=f[v][i],qmax(u,max[u],i+1);}
}int main(){
    ll n=readll(),u,v;rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);dfs0(1,0),f[1]=na(l[1]),dfs2(1,0);
    rep(i,1,n)printf("%lld\n",max[i]);return 0;
}