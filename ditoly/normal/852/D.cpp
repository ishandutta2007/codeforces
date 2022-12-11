#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MN 1005
#define MM 500005
#define GS 1731313
#define INF 0x3FFFFFFF
using namespace std;
struct edge{int nex,to,flw;}e[MM];
int dep[MN],qe[MN],hr[MN],d[MN],a[MN],mp[MN][MN];
int hd,tl,S,T,pin,n,m,p,q,L,R,ans;

inline int read()
{
	int n=0,f=1; char c=getchar();
	while (c<'0' || c>'9') {if(c=='-')f=-1; c=getchar();}
	while (c>='0' && c<='9') {n=n*10+c-'0'; c=getchar();}
	return n*f;
}

inline void ins(int x,int y,int z)
{
	e[++pin]=(edge){hr[x],y,z}; hr[x]=pin;
	e[++pin]=(edge){hr[y],x,0}; hr[y]=pin;
}

bool bfs()
{
//	puts("sb");
	register int i,x;
	memset(dep,0,sizeof(dep));
	for (dep[qe[hd=tl=1]=S]=1;hd<=tl;++hd)
		for (x=qe[hd],i=d[x]=hr[x];i;i=e[i].nex)
			if (!dep[e[i].to]&&e[i].flw) qe[++tl]=e[i].to,dep[e[i].to]=dep[x]+1;
	return dep[T];
}

int dfs(int x,int fw)
{
	if (x==T) return fw;
	register int lt,sum=0;
	for (int &i=d[x];i;i=e[i].nex)
	{
		if (dep[x]+1!=dep[e[i].to]||!e[i].flw) continue;
		lt=dfs(e[i].to,min(e[i].flw,fw));
		sum+=lt; fw-=lt;
		e[i^1].flw+=lt; e[i].flw-=lt;
		if (!fw) return sum;
	}
	dep[x]=0; return sum;
}

int main()
{
	register int i,j,k,x,y,z;
	n=read(); m=read(); p=read(); q=read();
	for (i=1;i<=p;++i) a[i]=read();
	for (i=1;i<=n;++i)
		for (j=1;j<=n;++j) mp[i][j]=INF;
	for (i=1;i<=m;++i)
	{
		x=read(); y=read(); z=read();
		mp[x][y]=mp[y][x]=min(mp[x][y],z);
	}
	for (i=1;i<=n;++i) mp[i][i]=0;
	for (k=1;k<=n;++k)
		for (i=1;i<=n;++i) if (k!=i)
			for (j=1;j<=n;++j) if (i!=j&&k!=j)
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
//	for (i=1;i<=n;++i,puts(""))
//		for (j=1;j<=n;++j)
//			printf("%d ",mp[i][j]);
	L=0; R=GS; S=0; T=n+p+1;
	while (L<R)
	{
		int mid=L+R>>1;
		memset(hr,0,sizeof(hr)); pin=1;
		for (i=1;i<=p;++i) ins(S,i,1);
		for (i=1;i<=n;++i) ins(p+i,T,1);
		for (i=1;i<=p;++i)
			for (j=1;j<=n;++j)
				if (mp[a[i]][j]<=mid) ins(i,p+j,INF);
		ans=0;
		while (bfs()) ans+=dfs(S,INF);
//		printf("ans=%d\n",ans);		
		if (ans<q) L=mid+1; else R=mid;
	}
	if (L==GS) printf("-1"); else printf("%d",L);
}