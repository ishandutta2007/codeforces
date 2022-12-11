#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 200000
#define K 20
struct edge{int nx,t;}e[MN*2+5];
int h[MN+5],en,d[MN+5],fa[K][MN+5];
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
void dfs(int x)
{
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=fa[0][x])
		d[e[i].t]=d[x]+1,fa[0][e[i].t]=x,dfs(e[i].t);
}
int lca(int x,int y)
{
	int dx=d[x]-d[y],i;
	if(dx<0)swap(x,y),dx=-dx;
	for(i=0;dx;++i,dx>>=1)if(dx&1)x=fa[i][x];
	if(x==y)return x;
	for(i=K;i--;)if(fa[i][x]!=fa[i][y])x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
int main()
{
	int n,x,i,j,ans=0;
	n=read();x=read();
	for(i=1;i<n;++i)ins(read(),read());
	dfs(1);
	for(i=1;i<K;++i)for(j=1;j<=n;++j)fa[i][j]=fa[i-1][fa[i-1][j]];
	for(i=1;i<=n;++i)if(d[x]<2*d[lca(x,i)])ans=max(ans,2*d[i]);
	printf("%d",ans);
}