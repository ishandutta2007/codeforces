#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 200000
#define K 18
struct edge{int nx,t;}e[MN*4+5];
int h[MN+5],th[MN+5],en=1,d[MN+5],l[MN+5],cnt,z[MN+5],zn,v[MN+5],vn;
int fa[K][MN+5],c1[MN+5],c2[MN+5],ans;
inline void ins(int*h,int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
void tj(int x,int fa)
{
	d[x]=l[x]=++cnt;z[++zn]=x;
	for(int i=h[x];i;i=e[i].nx)if(i!=fa)
	{
		if(d[e[i].t])l[x]=min(l[x],d[e[i].t]);
		else
		{
			tj(e[i].t,i^1);l[x]=min(l[x],l[e[i].t]);
			if(l[e[i].t]>d[x])for(++vn;z[zn+1]!=e[i].t;--zn)v[z[zn]]=vn;
		}
	}
	if(!fa)for(++vn;zn;--zn)v[z[zn]]=vn;
}
void dfs(int x)
{
	l[x]=cnt;
	for(int i=th[x];i;i=e[i].nx)if(e[i].t!=fa[0][x])
	{
		fa[0][e[i].t]=x;
		d[e[i].t]=d[x]+1;
		dfs(e[i].t);
	}
}
int lca(int x,int y)
{
	int k=d[x]-d[y],i;
	if(k<0)k=-k,swap(x,y);
	for(i=0;k;k>>=1,++i)if(k&1)x=fa[i][x];
	if(x==y)return x;
	for(i=K;i--;)if(fa[i][x]!=fa[i][y])x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
void solve(int x)
{
	for(int i=th[x];i;i=e[i].nx)if(e[i].t!=fa[0][x])
	{
		solve(e[i].t);
		c1[x]+=c1[e[i].t];
		c2[x]+=c2[e[i].t];
	}
	if(c1[x]&&c2[x])ans=1;
}
int main()
{
	int n,m,q,i,j,x,y;
	n=read();m=read();q=read();
	for(i=1;i<=m;++i)ins(h,read(),read());
	for(i=1;i<=n;++i)if(!d[i])tj(i,0);
	for(i=1;i<=n;++i)for(j=h[i];j;j=e[j].nx)
		if(i<e[j].t&&v[i]!=v[e[j].t])ins(th,v[i],v[e[j].t]);
	memset(d,0,sizeof(d));
	for(i=1;i<=vn;++i)if(!d[i])d[i]=1,++cnt,dfs(i);
	for(i=1;i<K;++i)for(j=1;j<=vn;++j)fa[i][j]=fa[i-1][fa[i-1][j]];
	for(i=1;i<=q;++i)
	{
		if((x=v[read()])==(y=v[read()]))continue;
		if(l[x]!=l[y])return 0*puts("No");
		j=lca(x,y);
		++c1[x];--c1[j];
		++c2[y];--c2[j];
	}
	for(i=1;i<=vn;++i)if(!fa[0][i])solve(i);
	puts(ans?"No":"Yes");
}