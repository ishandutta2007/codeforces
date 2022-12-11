#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 500000
struct edge{int nx,t,w;}e[MN*2+5];
int h[MN+5],en,f[MN+5],fa[MN+5],dep[MN+5],ans[MN+5],u[MN+5];
struct Edge{int x,y,w;}E[MN+5];
bool cmp(const Edge&a,const Edge&b){return a.w<b.w;}
int gf(int k){return f[k]?f[k]=gf(f[k]):k;}
inline void ins(int x,int y,int w)
{
	f[gf(x)]=gf(y);
	e[++en]=(edge){h[x],y,w};h[x]=en;
	e[++en]=(edge){h[y],x,w};h[y]=en;
}
void dfs(int x)
{
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=fa[x])
		fa[e[i].t]=x,dep[e[i].t]=dep[x]+1,u[e[i].t]=e[i].w,dfs(e[i].t);
}
int main()
{
	int n,k,m,i;long long s=0;
	n=read();k=read();m=read();
	for(i=1;i<=k;++i)ins(read(),read(),1);
	for(i=1;i<=m;++i)E[i].x=read(),E[i].y=read(),E[i].w=read();
	for(i=1;i<=m;++i)if(gf(E[i].x)!=gf(E[i].y))ins(E[i].x,E[i].y,0);
	dfs(1);memset(f,0,sizeof(f));
	for(i=1;i<=m;++i)
	{
		E[i].x=gf(E[i].x);E[i].y=gf(E[i].y);
		while(E[i].x!=E[i].y)
		{
			if(dep[E[i].x]<dep[E[i].y])swap(E[i].x,E[i].y);
			ans[E[i].x]=E[i].w;f[E[i].x]=fa[E[i].x];E[i].x=gf(E[i].x);
		}
	}
	for(i=2;i<=n;++i)if(u[i])if(ans[i])s+=ans[i];else return 0*puts("-1");
	cout<<s;
}