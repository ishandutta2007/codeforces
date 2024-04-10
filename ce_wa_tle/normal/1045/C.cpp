#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define log jdsif
#define rd readll()
bool p1;typedef long long ll;const ll N=1e6+7,inf=998244353;typedef int aN[N];ll sqr(ll u){return u*u;}
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct bs{
    aN next,to,head;ll cnt;bs():cnt(0){}void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
}b1,b2;ll top=0,col=0,ts=0;aN dfn,low,s,in,st[23],log,deep;ll min2(ll u,ll v){return deep[u]<deep[v]?u:v;}
void dfs0(ll u,ll fa){//printf("%lld %lld\n",u,fa);
    dfn[u]=low[u]=++top,in[s[++ts]=u]=1,(void)fa;rfor(ll i=b1.head[u],v;v=b1.to[i],i;i=b1.next[i])
    if(in[v])low[u]=std::min(low[u],dfn[v]);else if(!dfn[v]){if(dfs0(v,u),low[v]!=dfn[u])low[u]=std::min(low[u],low[v]);
    else for(b2.add(u,++col),b2.add(col,u);s[ts+1]!=v;)b2.add(s[ts],col),in[s[ts]]=0,b2.add(col,s[ts--]);}
}void dfs2(ll u,ll fa){deep[st[0][dfn[u]=++top]=u]=deep[fa]+1;//printf("dfs=%lld %lld %lld\n",u,fa,deep[u]);
    rfor(ll i=b2.head[u],v;v=b2.to[i],i;i=b2.next[i])if(v^fa)dfs2(v,u),st[0][++top]=u;
}ll lca(ll u,ll v){if((u=dfn[u])>(v=dfn[v]))std::swap(u,v);ll lg=log[v-u+1];return min2(st[lg][u],st[lg][v-(1<<lg)+1]);}
ll dis(ll u,ll v){return deep[u]+deep[v]-2*deep[lca(u,v)];}bool p2;
int main(){fprintf(stderr,"%.2lfMiB\n",(&p2-&p1)/1048576.0);
    ll n=col=rd,m=rd,q=rd,u,v;rep(i,1,m)u=rd,v=rd,b1.add(u,v),b1.add(v,u);dfs0(1,0),top=0,dfs2(1,0);n=top;
    rep(i,2,n)log[i]=log[i>>1]+1;rep(i,1,log[n])rep(j,1,n-(1<<i)+1)st[i][j]=min2(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    rep(i,1,q)u=rd,v=rd,printf("%lld\n",dis(u,v)/2);return 0;
}
/*
2
1 2
0 0 -8 1
0 0 9 1
*/