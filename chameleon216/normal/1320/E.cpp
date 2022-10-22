#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <algorithm>
#include <queue>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=200100,Inf=0x3f3f3f3f;
int N,M;

struct Edge{int y,w,nx;}E[MX*2];
int H[MX],ec;
void Link(int x,int y,int w){E[++ec].y=y,E[ec].w=w,E[ec].nx=H[x],H[x]=ec;}

int D[MX],F[MX],sz[MX],son[MX],U[MX],dfn[MX],dc;
void dfs1(int x,int f,int d)
{
	D[x]=d,F[x]=f,sz[x]=1;
	Fe(i,x,y)if(y!=f)
	{
		dfs1(y,x,d+1),sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
void dfs2(int x,int u)
{
	U[x]=u,dfn[x]=++dc;
	if(son[x])dfs2(son[x],u);
	Fe(i,x,y)if(y!=F[x]&&y!=son[x])dfs2(y,y);
}
int LCA(int x,int y)
{
	while(U[x]!=U[y])
	{
		if(D[U[x]]>D[U[y]])x=F[U[x]];
		else y=F[U[y]];
	}
	return D[x]<D[y]?x:y;
}

int qk,qm,V[MX],S[MX],W[MX];
int fa[MX],X[MX*2],xc;
inline bool cmp(int x,int y){return dfn[x]<dfn[y];}
void Build()
{
	sort(X+1,X+xc+1,cmp);
	xc=unique(X+1,X+xc+1)-X-1;
	int n=xc;
	Fr(i,2,n)
	{
		int x=X[i-1],y=X[i],z=LCA(x,y);
		while(D[fa[x]]>=D[z])x=fa[x];
		if(x!=z)X[++xc]=z,fa[z]=fa[x],fa[x]=z;
		fa[y]=z;
	}
	Fr(i,1,xc)
	{
		int x=X[i],w=D[x]-D[fa[x]];
		if(fa[x])Link(fa[x],x,w),Link(x,fa[x],w);
	}
}

struct Node
{
	int x,c,d;
	Node(){}
	Node(int x_,int c_,int d_){x=x_,c=c_,d=d_;}
}dis[MX];
char B[MX];
inline bool operator<(const Node& b,const Node& a)
{
	int at=(a.d+S[a.c]-1)/S[a.c];
	int bt=(b.d+S[b.c]-1)/S[b.c];
	return at!=bt?at<bt:a.c<b.c;
}

priority_queue<Node> Q;
void Solve()
{
	scanf("%d%d",&qk,&qm);
	Fr(i,1,qk)scanf("%d%d",&V[i],&S[i]),X[++xc]=V[i];
	Fr(i,1,qm)scanf("%d",&W[i]),X[++xc]=W[i];
	Build();
	S[0]=1;
	Fr(i,1,xc)dis[X[i]].d=Inf;
	Fr(i,1,qk)
	{
		dis[V[i]].x=V[i],dis[V[i]].c=i,dis[V[i]].d=0;
		Q.push(Node(dis[V[i]]));
	}
	while(!Q.empty())
	{
		int x=Q.top().x;
		Q.pop();
		if(B[x])continue;
		B[x]=1;
		Fe(i,x,y)
		{
			Node o=dis[x];
			o.x=y,o.d+=E[i].w;
			if(dis[y]<o)dis[y]=o,Q.push(o);
		}
	}
	Fr(i,1,qm)printf("%d ",dis[W[i]].c);
	putchar('\n');
	
	Fr(i,1,xc)
	{
		int x=X[i];
		fa[x]=B[x]=H[x]=0;
	}
	xc=ec=0;
}

int main()
{
	scanf("%d",&N);
	Fr(i,2,N)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Link(x,y,0),Link(y,x,0);
	}
	dfs1(1,0,1);
	dfs2(1,1);
	memset(H,0,sizeof(H)),ec=0;
	
	scanf("%d",&M);
	Fr(i,1,M)Solve();
	return 0;
}