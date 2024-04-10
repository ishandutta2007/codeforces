#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 1000
#define INF (int)1e9
using namespace std;
int n,m,ct,a[N+5],dc,dv[N+5];
namespace D
{
	#define PS (N+2)
	#define ES (N*N)
	#define s (n+1)
	#define t (n+2)
	#define add(x,y,f) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].F=f)
	int ee=1,lnk[PS+5],cur[PS+5];struct edge {int to,nxt,F;}e[2*ES+5];
	void Add(int x,int y,int f) {add(x,y,f),add(y,x,0);}
	int q[PS+5],D[PS+5];bool BFS()
	{
		int i,k,H,T;for(i=1;i<=t;++i) D[i]=-1;D[q[H=T=1]=s]=0;
		while(H<=T) for(i=lnk[k=q[H++]];i;i=e[i].nxt) !~D[e[i].to]&&e[i].F&&(D[q[++T]=e[i].to]=D[k]+1);
		return ~D[t];
	}
	int DFS(int x=s,int f=INF)
	{
		if(x==t||!f) return f;int o,g=0;for(int& i=cur[x];i;i=e[i].nxt)
		{
			if(D[e[i].to]!=D[x]+1||!(o=DFS(e[i].to,min(f,e[i].F)))) continue;
			if(g+=o,e[i].F-=o,e[i^1].F+=o,!(f-=o)) break;
		}return g;
	}
	int Dinic()
	{
		int f=0;while(BFS()) {for(int i=1;i<=t;++i) cur[i]=lnk[i];f+=DFS();}return f;
	}
	int tg[N+5],sx[N+5],sy[N+5];void Print()
	{
		int i,j,tt=0;for(i=1;i<=n;++i) if(3*a[i]>m)
		{
			for(j=lnk[i];j;j=e[j].nxt) if(!e[j].F) break;
			sx[++tt]=2*a[i]+a[e[j].to],sy[tt]=a[i]+a[e[j].to],tg[i]=tg[e[j].to]=1;
		}
		for(i=1;i<=n;++i) !tg[i]&&(sx[++tt]=3*a[i],sy[tt]=2*a[i]);
		for(printf("%d\n",tt),i=1;i<=tt;++i) printf("%d %d\n",sx[i],sy[i]);
	}
}
int main()
{
	int i,j,c=0;for(scanf("%d%d",&n,&m),i=1;i<=n;++i) scanf("%d",a+i);
	for(i=1;i<=n;++i) if(3LL*a[i]>m) D::Add(s,i,1),++c;else D::Add(i,t,1);
	for(i=1;i<=n;++i) if(3LL*a[i]>m) for(j=1;j<=n;++j) if(2LL*a[i]+a[j]<=m&&!(a[i]%a[j])) D::Add(i,j,1);
	if(D::Dinic()<c) return puts("-1"),0;return D::Print(),0;
}