#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
char BB[1<<25],*S=BB;
inline int read()
{
	int x;char c;
	while((c=*S++)<'0'||c>'9');
	for(x=c-'0';(c=*S++)>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
#define K 700
struct edge{int nx,t;}e[MN*2+5];
struct query{int x,y,id;}Q[MN+5];
int a[MN+5],b[MN+5],cnt,h[MN+5],en,fa[MN+5],d[MN+5],f[MN+5],dep[MN+5];
int rt,nw,u[MN+5],A[MN+5],B[MN+5];
long long ans,C[MN+5];
bool cmp(const query&a,const query&b){return f[a.x]<f[b.x];}
map<int,int> mp;
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
void dfs(int x)
{
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=fa[x])
	{
		fa[e[i].t]=x;dep[e[i].t]=dep[x]+1;dfs(e[i].t);
		d[x]=max(d[x],d[e[i].t]+1);
	}
	if(d[x]==K||x==rt)f[x]=x,d[x]=-1;
}
void build(int x)
{
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=fa[x])
	{
		if(!f[e[i].t])f[e[i].t]=f[x];
		build(e[i].t);
	}
}
void DFS(int x,int fa)
{
	d[x]=++cnt;
	for(int i=h[x];i;i=e[i].nx)
		if(e[i].t!=fa)DFS(e[i].t,x);
}
bool CMP(const query&a,const query&b){return d[a.y]<d[b.y];}
void cal(int x)
{
	if(u[x]^=1)ans+=a[x]?A[b[x]]:B[b[x]],a[x]?++B[b[x]]:++A[b[x]];
	else ans-=a[x]?A[b[x]]:B[b[x]],a[x]?--B[b[x]]:--A[b[x]];
}
void solve(int x,int fr)
{
	d[x]=MN+5;cal(x);
	for(;rt==f[Q[nw].x]&&Q[nw].y==x;++nw)
	{
		for(int i=Q[nw].x,u=1;i!=rt;i=fa[i])
			if(d[i]==MN+5&&u)cal(rt),u=0;else cal(i);
		C[Q[nw].id]=ans;
		for(int i=Q[nw].x,u=1;i!=rt;i=fa[i])
			if(d[i]==MN+5&&u)cal(rt),u=0;else cal(i);
	}
	for(int i=h[x];i;i=e[i].nx)
		if(e[i].t!=fr)solve(e[i].t,x);
	d[x]=0;cal(x);
}
int main()
{
	BB[fread(BB,1,1<<25,stdin)]=0;
	int n=read(),i,j,q;
	for(i=1;i<=n;++i)a[i]=read();
	for(i=1;i<=n;++i)b[i]=mp[b[i]=read()]?mp[b[i]]:mp[b[i]]=++cnt;
	for(i=1;i<n;++i)ins(read(),read());
	rt=2333333%n+1;dfs(rt);build(rt);
	for(q=read(),i=1;i<=q;++i)
	{
		Q[i].x=read();Q[i].y=read();Q[i].id=i;
		if(dep[Q[i].x]-dep[f[Q[i].x]]>dep[Q[i].y]-dep[f[Q[i].y]])swap(Q[i].x,Q[i].y);
	}
	sort(Q+1,Q+q+1,cmp);
	for(nw=1;nw<=q;)
	{
		DFS(f[Q[nw].x],cnt=0);
		for(i=nw;f[Q[i].x]==f[Q[nw].x];++i);
		sort(Q+nw,Q+i,CMP);
		solve(rt=f[Q[nw].x],ans=0);
	}
	for(i=1;i<=q;++i)printf("%I64d\n",C[i]);
}