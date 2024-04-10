#include <cstdio>
#define MN 10005
struct edge{int nex,to,wt;}e[MN<<1];
int hr[MN],dep[MN],pin,ans,n;

inline int read()
{
	int n=0,f=1;char c=getchar();
	while (c<'0' || c>'9') {if(c=='-')f=-1; c=getchar();}
	while (c>='0' && c<='9') {n=n*10+c-'0'; c=getchar();}
	return n*f;
}
inline void ins(int x,int y,int z) {e[++pin]=(edge){hr[x],y,z}; hr[x]=pin;}

void dfs(int x,int fat)
{
	register int i;
	if (dep[x]>ans) ans=dep[x];
	for (i=hr[x];i;i=e[i].nex)
	{
		if (e[i].to==fat) continue;
		dep[e[i].to]=dep[x]+e[i].wt;
		dfs(e[i].to,x);
	}
}

int main()
{
	register int i,x,y,z;
	n=read();
	for (i=1;i<n;++i)
	{
		x=read(); y=read(); z=read();
		ins(x,y,z); ins(y,x,z);
	}
	dfs(0,-1);
	printf("%d",ans);
}