#pragma GCC optimize(2,3,"Ofast","unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,ny;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;Bi=1;if(nc<0)return nc;
		x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*ny;
	}
	in db gf() {int a=read(),y=ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<=32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
	in void flush() {if(C>1<<22) ot();}
	template <typename T>
	in void write(T x,char t)
	{
		int y=0;if(x<0)y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y)z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;flush();
	}
	in void write(char *s) {int l=strlen(s);for(int i=0;i<l;i++)sr[++C]=*s++;sr[++C]='\n';flush();}
}
using namespace fast_io;
#define pb push_back
const int N=2e5+5;
int n,m,q,cnt=1,tim,id,nt,h[N],to[N<<1],nxt[N<<1],dfn[N],vis[N<<1],low[N],col[N],t[N],d[N],s1[N],s2[N],f[N][20];
vector<int>e[N];
in void Add(int u,int v) {nxt[++cnt]=h[u],to[cnt]=v,h[u]=cnt;}
in void add(int u,int v) {Add(u,v);Add(v,u);}
void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++tim;
	for(int i=h[u],v;v=to[i],i;i=nxt[i]) if(v^fa)
	{
		if(!dfn[v])
		{
			tarjan(v,u),low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]) vis[i]=vis[i^1]=1;
		}
		else low[u]=min(low[u],dfn[v]);
	}
}
void dfs1(int u) {col[u]=id;for(int i=h[u],v;v=to[i],i;i=nxt[i]) if(!col[v]&&!vis[i]) dfs1(v);}
void dfs2(int u)
{
	t[u]=nt;
	for(auto v:e[u]) if(v^f[u][0])
	{
		f[v][0]=u,d[v]=d[u]+1;
		for(int i=1;i<20;i++) f[v][i]=f[f[v][i-1]][i-1];dfs2(v);
	}
}
in int lca(int x,int y)
{
	if(d[x]<d[y]) swap(x,y);
	for(int i=19;~i;i--) if(d[f[x][i]]>=d[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=19;~i;i--) if(f[x][i]^f[y][i]&&f[x][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
in bool check(int u)
{
	for(auto v:e[u]) if(v^f[u][0])
	{
		if(!check(v)||(s1[v]&&s2[v])) return 0;
		s1[u]+=s1[v];s2[u]+=s2[v];
	}
	return 1;
}
int main()
{
	n=read(),m=read(),q=read();for(int i=1;i<=m;i++) add(read(),read());
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
	for(int i=1;i<=n;i++) if(!col[i]) id++,dfs1(i);
	for(int i=1;i<=n;i++) for(int j=h[i],k;k=to[j],j;j=nxt[j]) if(col[i]<col[k]) e[col[i]].pb(col[k]),e[col[k]].pb(col[i]);
	for(int i=1;i<=id;i++) if(!t[i]) nt++,d[i]=1,dfs2(i);
	for(int i=1;i<=q;i++)
	{
		int u=col[read()],v=col[read()];if(u==v) continue;
		if(t[u]^t[v]) return write("No"),ot(),0;
		int p=lca(u,v);s1[u]++;s2[v]++;s1[p]--;s2[p]--;
	}
	for(int i=1;i<=id;i++) if(d[i]==1&&!check(i)) return write("No"),ot(),0;
	write("Yes");
	return ot(),0;
}
//Author: disangan233