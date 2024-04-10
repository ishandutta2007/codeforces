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

int Log10(int x){return x?Log10(x/10)+1:0;}

const int MX=200100,Inf=0x3f3f3f3f;
int N,M,nc,id[7],X[7],G[7][7],F[7];
struct Edge{int x,y;}ed[30];
int Find(int x){return x==F[x]?x:F[x]=Find(F[x]);}

// 1~N vertex
// N+1~N+M edge
// N+M+1~N+M+2 S/T

struct FlowEdge{int y,w,nx;}E[500];
int H[100],ec=1;
void Add(int x,int y,int w){E[++ec].y=y,E[ec].w=w,E[ec].nx=H[x],H[x]=ec;}
void Link(int x,int y,int w){Add(x,y,w),Add(y,x,0);}

int S,T;
int D[100],H_[100];
bool bfs()
{
	memset(D,0,(T+1)*sizeof(int));
	memcpy(H_,H,(T+1)*sizeof(int));
	queue<int> q;
	q.push(S),D[S]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		Fe(i,x,y)if(E[i].w&&!D[y])
		{
			D[y]=D[x]+1,q.push(y);
			if(y==T)return 1;
		}
	}
	return 0;
}
int dfs(int x,int a)
{
	if(x==T)return a;
	int b=0;
	for(int &i=H_[x];i;i=E[i].nx)
	{
		int y=E[i].y;
		if(E[i].w&&D[y]==D[x]+1)
		{
			int r=dfs(y,min(a,E[i].w));
			E[i].w-=r,E[i^1].w+=r,a-=r,b+=r;
			if(!a)break;
		}
	}
	return b;
}
int Dinic()
{
	int f=0;
	while(bfs())f+=dfs(S,Inf);
	return f;
}

void Try(int s)
{
	S=N+M+1,T=N+M+2;
	Fr(x,1,N)Link(S,x,X[x]-1),Link(x,T,G[x][x]);
	Fr(i,1,M)Link(ed[i].x,N+i,Inf),Link(ed[i].y,N+i,Inf);
	Fr(i,1,M)Link(N+i,T,G[ed[i].x][ed[i].y]-(s>>(i-1)&1));
	if(Dinic()==nc-N)
	{
		Fr(i,1,M)if(s>>(i-1)&1)printf("%d %d\n",id[ed[i].x],id[ed[i].y]);
		Fr(i,1,M)Fe(j,N+i,y)if(j&1)
		{
			Fr(k,1,E[j].w)
				printf("%d %d\n",id[y]+(--X[y]),id[ed[i].x^ed[i].y^y]);
		}
		Fr(x,1,N)Fr(i,1,G[x][x])
			printf("%d %d\n",id[x],id[x]+(--X[x]));
		exit(0);
	}
	memset(H,0,sizeof(H)),ec=1;
}

int main()
{
	scanf("%d",&nc),N=Log10(nc);
	id[1]=1;
	Fr(i,2,N)id[i]=id[i-1]*10,X[i-1]=id[i]-id[i-1];
	X[N]=nc-id[N]+1;
//	Fr(i,1,N)printf("%d %d\n",id[i],X[i]);
	char o[10];
	Fr(i,1,nc-1)
	{
		int x,y;
		scanf("%s",o),x=strlen(o);
		scanf("%s",o),y=strlen(o);
		if(x>y)swap(x,y);
		++G[x][y];
	}
	
	Fr(x,1,N)Fr(y,x+1,N)if(G[x][y])
		ed[++M].x=x,ed[M].y=y;
	Fr(s,0,(1<<M)-1)
	{
		if(__builtin_popcount(s)!=N-1)continue;
		Fr(x,1,N)F[x]=x;
		int b=0;
		Fr(i,1,M)if(s>>(i-1)&1)
		{
			int x=Find(ed[i].x),y=Find(ed[i].y);
			if(x==y){b=1;break;}
			F[x]=y;
		}
		if(b)continue;
		Try(s);
	}
	printf("-1\n");
	return 0;
}