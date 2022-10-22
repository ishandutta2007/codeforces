#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=2e5+8;typedef ll aN[N];aN next,to,head,g,col,w,dfn,s,low,in,deep;ll cnt,tc,tu,ts;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}void add(ll u,ll v,ll c){next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;}
void dfs(ll u,ll fa){
	dfn[s[++ts]=u]=low[u]=++tu,in[u]=1;rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(!dfn[v])deep[v]=deep[u]+w[i],
	dfs(v,u),low[u]=std::min(low[u],low[v]);else if(in[v])low[u]=std::min(low[u],dfn[v]);
	if(low[u]==dfn[u])for(in[s[ts]]=0,col[s[ts--]]=++tc;in[u];in[s[ts]]=0,col[s[ts--]]=tc);
}int main(){
	ll n=rd,m=rd,u,v,c;rep(i,1,m)u=rd,v=rd,c=rd,add(u,v,c);rep(i,1,n)if(!dfn[i])dfs(i,0);
	rep(u,1,n)rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(col[u]==col[v])g[col[u]]=gcd(g[col[u]],deep[u]+w[i]-deep[v]);
	ll sg,q=rd;rep(i,1,q)u=rd,v=rd,c=rd,puts(!(sg=gcd(g[col[u]],c))||gcd(v,c)%sg?"NO":"YES");return 0;
}