#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=400100;
int N,M;

struct Edge{int y,w,nx;}E[MX*2];
int H[MX],ec=1;
void Link(int x,int y,int w)
{
	E[++ec].y=y,E[ec].w=w,E[ec].nx=H[x],H[x]=ec;
}

struct DisjointSet
{
	int f[MX],w[MX];
	void Init(){Fr(i,1,N)f[i]=i,w[i]=0;}
	void Compress(int x)
	{
		if(x==f[x])return;
		Compress(f[x]);
		w[x]^=w[f[x]],f[x]=f[f[x]];
	}
	bool Union(int x,int y,int v)
	{
		Compress(x),Compress(y);
		int a=f[x],b=f[y];
		if(a==b)return (w[x]^w[y])!=v;
		w[a]=w[x]^w[y]^v,f[a]=b;
		return 0;
	}
	int Get(int x,int y)
	{
		Compress(x),Compress(y);
		if(f[x]!=f[y])return -1;
		return w[x]^w[y];
	}
}T;

int Work()
{
	scanf("%d%d",&N,&M);
	T.Init();
	int ret=1;
	Fr(i,2,N)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		if(!ret)continue;
		Link(x,y,w),Link(y,x,w);
		if(w>=0)
		{
			int a=__builtin_popcount(w)&1;
//			printf("%d\n",a);
			if(T.Union(x,y,a))ret=0;
		}
	}
	Fr(i,1,M)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		if(!ret)continue;
		if(T.Union(x,y,w))ret=0;
	}
	return ret;
}

void dfs1(int x,int f)
{
	Fe(i,x,y)if(y!=f)
	{
		if(E[i].w==-1)
		{
			int a=(T.Get(x,y)==1);
			E[i].w=E[i^1].w=a;
			T.Union(x,y,a);
		}
		dfs1(y,x);
	}
}

int main()
{
//	freopen("test.in","r",stdin);
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		int r=Work();
		if(r)
		{
			printf("YES\n");
			dfs1(1,0);
			for(int i=2;i<=ec;i+=2)
				printf("%d %d %d\n",E[i^1].y,E[i].y,E[i].w);
		}
		else printf("NO\n");
		
		memset(H,0,(N+2)*sizeof(int));
		ec=1;
	}
}