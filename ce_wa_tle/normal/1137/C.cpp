#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef int ll;const ll N=114514,D=51,inf=0x3f3f3f3f;typedef ll aN[N],aND[N*D];typedef bool bND[N*D];
ll readll(){
	ll x=0,w=1;char c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}
int readchar(){char c=getchar();for(;c<'0'||c>'z';c=getchar());return c;}
bND in,q;
aND next,head,to,nst,f,low,dfn,col,st,&vis=dfn;aN u,v,ins;ll cnt=0,tnc=0,tot=0,tmp=0,top=0,n,m,d;
void add(ll u,ll v){if(u!=v)next[++cnt]=head[u],to[head[u]=cnt]=v;}
void dfs0(ll u){
    low[u]=dfn[u]=++tnc;in[u]=1;st[++top]=u;rfor(ll i=head[u],v;v=to[i],i;i=next[i])
    if(!dfn[v]||(dfn[v]&&in[v]))low[u]=std::min(low[u],v[!dfn[v]?dfs0(v),low:dfn]);
    if(low[u]==dfn[u]&&(st[top+1]=-1)){
    rfor(ll v=++tot;top&&(v=st[top],st[top+1]!=u);)
    col[nst[++tmp]=st[top--]]=tot,in[v]=0;
    rep(i,1,tmp)if(q[nst[i]])f[tot]+=!ins[nst[i]/d],ins[nst[i]/d]=1;}for(;tmp;ins[nst[tmp--]/d]=0);  
}
void dfs2(ll u){
    if(vis[u])return;ll max=0;rfor(ll i=head[vis[u]=1,u],v;v=to[i],i;i=next[i])dfs2(v),max<f[v]&&(max=f[v]);f[u]+=max;
} 
int main(){
    n=readll(),m=readll(),d=readll();rep(i,1,m)u[i]=readll()-1,v[i]=readll()-1;
    rep(i,1,m)ref(j,0,d)add(u[i]*d+j,v[i]*d+(j+1)%d);ref(i,0,n*d)q[i]=readchar()&15;
    dfs0(0);memset(head,cnt=0,sizeof head),memset(vis,0,sizeof vis);//ref(i,0,n*d)printf("c=%d %d %d\n",col[i],low[i],dfn[i]);
    rep(i,1,m)ref(j,0,d)add(col[u[i]*d+j],col[v[i]*d+(j+1)%d]);dfs2(col[0]),printf("%d\n",f[col[0]]);return 0;
}