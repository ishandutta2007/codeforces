#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2222222,mod=998244353,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];aN a,c,ans;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}aN s;
aN next,to,head,dfn,col,st,low,sz;ll cnt,ts,tu,tc;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
void dfs(ll u){
    dfn[st[++ts]=u]=low[u]=++tu;rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(!dfn[v])
    dfs(v),low[u]=std::min(low[u],low[v]);else if(!col[v])low[u]=std::min(low[u],dfn[v]);
    if(low[u]==dfn[u]){s[++tc]=0;do++s[col[st[ts--]]=tc];while(st[ts+1]!=u);}
}int calc(int cases){
    ll n=readll(),m=readll(),u,v,sz=sizeof(ll)*(n+1);memset(head,cnt=0,sz);rep(i,1,m)u=readll(),v=readll(),add(u,v);
    memset(col,ts=tu=tc=0,sz),memset(dfn,0,sz);rep(i,1,n)if(!dfn[i])dfs(i);if(tc==1)return puts("No");printf("Yes\n%lld %lld\n",s[1],n-s[1]);
    rep(i,1,n)if(col[i]==1)printf("%lld ",i);puts("");rep(i,1,n)if(col[i]!=1)printf("%lld ",i);puts("");return cases;
}int main(){ll T=readll(),cnt=0;while(T --> 0)calc(++cnt);return 0;}