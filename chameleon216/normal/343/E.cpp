#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <queue>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=1200,Inf=0x3f3f3f3f;
int N,M;
struct Edge{int y,w,nx;};

namespace F
{
	Edge E[MX*2];
	int H[MX],ec=1;
	void Add(int x,int y,int w){E[++ec].y=y,E[ec].w=w,E[ec].nx=H[x],H[x]=ec;}
	void Link(int x,int y,int w){Add(x,y,w),Add(y,x,w);}
	
	int D[MX],H_[MX];
	bool bfs(int s,int t)
	{
		memset(D,0,(N+1)*sizeof(int));
		memcpy(H_,H,(N+1)*sizeof(int));
		queue<int> q;
		D[s]=1,q.push(s);
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			Fe(i,x,y)if(E[i].w&&!D[y])
			{
				D[y]=D[x]+1,q.push(y);
				if(y==t)return 1;
			}
		}
		return 0;
	}
	int dfs(int x,int t,int in)
	{
		if(x==t)return in;
		int out=0;
		for(int &i=H_[x];i;i=E[i].nx)
		{
			int y=E[i].y;
			if(E[i].w&&D[y]==D[x]+1)
			{
				int r=dfs(y,t,min(in,E[i].w));
				in-=r,out+=r;
				E[i].w-=r,E[i^1].w+=r;
				if(!in)break;
			}
		}
		return out;
	}
	int Dinic(int s,int t)
	{
		for(int i=2;i<=ec;i+=2)
		{
			int w=E[i].w+E[i^1].w;
			E[i].w=E[i^1].w=w>>1;
		}
		int f=0;
		while(bfs(s,t))f+=dfs(s,t,Inf);
		return f;
	}
}

Edge E[MX*2];
int H[MX],ec=1;
void Link(int x,int y,int w){E[++ec].y=y,E[ec].w=w,E[ec].nx=H[x],H[x]=ec;}

int X[MX],Y[MX],sum;
void Divide(int l,int r)
{
	if(l==r)return;
	int f=F::Dinic(X[l],X[r]),p=l,q=r;
	sum+=f,Link(X[l],X[r],f),Link(X[r],X[l],f);
	Fr(i,l,r)
	{
		int x=X[i];
		if(F::D[x])Y[p++]=x;
		else       Y[q--]=x;
	}
	Fr(i,l,r)X[i]=Y[i];
	Divide(l,q),Divide(p,r);
}

int B[MX];
void dfs1(int x,int f,int& e)
{
	Fe(i,x,y)if(y!=f&&!B[i])
	{
		dfs1(y,x,e);
		if(!e||E[i].w<E[e].w)e=i;
	}
}
int res[MX],rc;
void Divide2(int x)
{
	int e=0;
	dfs1(x,0,e);
	if(!e){res[++rc]=x;return;}
	B[e]=B[e^1]=1;
	Divide2(E[e].y),Divide2(E[e^1].y);
}

int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,M)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		F::Link(x,y,w);
	}
	Fr(i,1,N)X[i]=i;
	Divide(1,N);
	Divide2(1);
	printf("%d\n",sum);
	Fr(i,1,rc)printf("%d ",res[i]);
	putchar('\n');
	return 0;
}