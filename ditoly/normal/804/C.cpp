#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 300000
struct edge{int nx,t;}e[MN*2+5];
int h[MN+5],en,c[MN+5],u[MN+5];
vector<int> v[MN+5];
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
void dfs(int x,int fa)
{
	int i,j;
	for(i=0;i<v[x].size();++i)c[v[x][i]]?u[c[v[x][i]]]=x:0;
	for(i=j=0;i<v[x].size();++i)if(!c[v[x][i]])
	{
		for(++j;u[j]==x;++j);
		c[v[x][i]]=j;
	}
	for(i=h[x];i;i=e[i].nx)if(e[i].t!=fa)dfs(e[i].t,x);
}
int main()
{
	int n,m,k,i,j,l,ans=1;
	n=read();m=read();
	for(i=1;i<=n;++i)
	{
		ans=max(ans,k=read());
		while(k--)v[i].push_back(read());
	}
	for(i=1;i<n;++i)ins(read(),read());
	dfs(1,0);
	printf("%d\n",ans);
	for(i=1;i<=m;++i)printf("%d ",c[i]?c[i]:1);
}