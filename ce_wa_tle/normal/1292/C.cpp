#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=3e3+7;typedef ll aN[N],aN2[N*N],a2N[N][N];
void qmax(ll&a,ll b){if(a<b)a=b;}
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}a2N s,p,f,l;aN2 to,next;aN head;
void dfs(ll root,ll u,ll fa){
    fa&&(l[root][u]=l[root][fa]+1);p[root][u]=fa,s[root][u]=1;
    rfor(ll i=head[u];i;i=next[i])if(to[i]^fa)dfs(root,to[i],u),s[root][u]+=s[root][to[i]];
}ll cnt=0;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
#define id(u,v)((u-1)*n+(v))
#define u(id)((id-1)/n+1)
#define v(id)((id-1)%n+1)
int main(){
    ll n=readll(),u,v,ans=0;rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);
    rep(i,1,n)dfs(i,i,0);memset(head,cnt=0,sizeof(ll)*(n+1));rep(u,1,n)rep(v,1,n)add(l[u][v],id(u,v));
    rep(len,1,n)rfor(ll i=head[len],u,v;u=u(to[i]),v=v(to[i]),i;i=next[i])
    qmax(ans,f[u][v]=std::max(f[u][p[u][v]],f[p[v][u]][v])+s[u][v]*s[v][u]);printf("%lld\n",ans);return 0;
}