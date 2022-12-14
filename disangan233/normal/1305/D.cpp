#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0;
	// in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	#define gc() getchar()
	in int read()
	{
		int x=0,y=1;while(nc=gc(),(nc<48||nc>57)&&nc!=-1)if(nc==45)y=-1;Bi=1;
		x=nc-48;while(nc=gc(),47<nc&&nc<58)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*y;
	}
	in db gf() {int a=read(),b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi):a);}
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
const int N=1e3+5;
int n,a[N*N],b[N*N],id[N*N],t[N],d[N][N],tot;
vector<int>e[N];in void add(int u,int v) {e[u].pb(v),e[v].pb(u);}
int fa[N],dep[N],siz[N],son[N],top[N];
void dfs1(int u)
{
	siz[u]=1;
	for(int v:e[u]) if(v^fa[u])
	{
		fa[v]=u,dep[v]=dep[u]+1,dfs1(v);siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int tp)
{
	top[u]=tp;if(son[u]) dfs2(son[u],tp);
	for(int v:e[u]) if(v^fa[u]&&v^son[u]) dfs2(v,v);
}
in int lca(int u,int v) {for(;top[u]^top[v];u=fa[top[u]])if(dep[top[u]]<dep[top[v]])swap(u,v);return dep[u]<dep[v]?u:v;}
in int ask(int a,int b)
{
	cout<<"? "<<a<<" "<<b<<endl;cout.flush();
	return read();
}
int find(int u,int f,int x,int y)
{
	if(u==x||u==y) return 1;
	for(int v:e[u]) if(v^f&&find(v,u,x,y)) return 1;
	return 0;
}
void upd(int u,int f) {t[u]=1;for(int v:e[u])if(v^f)upd(v,u);}
int main()
{
	n=read();
	for(int i=1;i<n;i++) add(read(),read());
	dfs1(1),dfs2(1,1);tot=0;int m=0;
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) d[i][j]=dep[i]+dep[j]-2*dep[lca(i,j)],a[++m]=i,b[m]=j,id[m]=m;
	sort(id+1,id+m+1,[](int x,int y){return d[a[x]][b[x]]>d[a[y]][b[y]];});
	for(int i=1;i<=m;i++)
	{
		int u=a[id[i]],v=b[id[i]];
		if(t[u]||t[v]) continue;
		int p=ask(u,v);for(int V:e[p]) if(find(V,p,u,v)) upd(V,p);
	}
	for(int i=1;i<=n;i++) if(!t[i]) cout<<"! "<<i,cout.flush();
	return 0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.
/*
10
1 2
1 3
2 4
2 5
3 6
6 7
5 8
4 9
6 10
*/