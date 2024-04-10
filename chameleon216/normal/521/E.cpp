#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#define rg register
#define Fo(i,a,b) for(int i=(a);i< (b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
using namespace std;
typedef long long ll;
const int MX=4e5+100;
int N,M;

struct Graph{int y,nx;char t;/*  */}E[MX];
int H[MX],ec;
void add(int x,int y)
{
	E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;
}

struct Edge{int x,y;}Ed[MX]; // 
int cnt;

int P[MX],pc;
char B[MX];
#define yi E[i].y
void dfs1(int x,int f)
{
	P[++pc]=x,B[x]=1;
	Fe(i,x)if(yi!=f)
	{
		if(B[yi]==1)Ed[++cnt].x=x,Ed[cnt].y=yi;
		else if(B[yi]==0)E[i].t=1,dfs1(yi,x);
	}
	B[x]=2;
}

int D[MX],F[MX],sz[MX],son[MX],U[MX];
void dfs2(int x,int f,int d)
{
	D[x]=d,F[x]=f,sz[x]=1,son[x]=-1;
	int mx=0;
	Fe(i,x)if(E[i].t)
	{
		dfs2(yi,x,d+1),sz[x]+=sz[yi];
		if(sz[yi]>mx)mx=sz[yi],son[x]=yi;
	}
}

void dfs3(int x,int u)
{
	U[x]=u;
	if(son[x]!=-1)dfs3(son[x],u);
	Fe(i,x)if(E[i].t&&yi!=son[x])dfs3(yi,yi);
}

int Lca(int x,int y)
{
	while(U[x]!=U[y])
	{
		if(D[U[x]]>D[U[y]])x=F[U[x]];
		else y=F[U[y]];
	}
	if(D[x]<D[y])return x;
	else return y;
}

int C[MX];
void dfs4(int x)
{
	Fe(i,x)if(E[i].t)
		dfs4(yi),C[x]+=C[yi];
}

int stk[MX];

void solve(int x)
{
	cnt=0,pc=0;
	dfs1(x,0);
	dfs2(x,0,1);
	dfs3(x,x);
	Fr(i,1,cnt)
	{
		int x=Ed[i].x,y=Ed[i].y;
		C[x]++,C[y]--;
	}
	dfs4(x);
//	Fr(i,1,N)printf("%d ",C[i]);printf("\n");
	int mx=-1,a=-1,b=-1,c=-1,d=-1,e=-1,f=-1;
	Fr(j,1,pc)
	{
		int i=P[j];
		if(C[i]>=2&&D[i]>mx)mx=D[i],a=i;
	}
	if(a==-1)return;
	printf("YES\n");
	
	Fr(i,1,cnt)
	{
		int x=Ed[i].x,y=Ed[i].y;
		if(Lca(x,a)==a&&D[y]<D[a])
		{
			if(b==-1){b=x,d=y;continue;}
			if(c==-1){c=x,e=y;continue;}
		}
		if(b!=-1&&c!=-1)break;
	}
	f=D[d]>D[e]?d:e;
//	printf("%d %d %d %d %d %d\n",a,b,c,d,e,f);
	
	//a --> f
	int stktop=0,now=a;
	stk[++stktop]=now;
	while(now!=f)now=F[now],stk[++stktop]=now;
	printf("%d ",stktop);
	Fr(i,1,stktop)printf("%d ",stk[i]);
	printf("\n");
	
	//a --> b --> d --> f
	stktop=0,now=f;
	stk[++stktop]=now;
	while(now!=a)
	{
		if(now==d)now=b;
		else now=F[now];
		stk[++stktop]=now;
	}
	printf("%d ",stktop);
	Fl(i,stktop,1)printf("%d ",stk[i]);
	printf("\n");
	
	//a --> c --> e --> f
	stktop=0,now=f;
	stk[++stktop]=now;
	while(now!=a)
	{
		if(now==e)now=c;
		else now=F[now];
		stk[++stktop]=now;
	}
	printf("%d ",stktop);
	Fl(i,stktop,1)printf("%d ",stk[i]);
	printf("\n");
	
	exit(0);
}


int main()
{
	scanf("%d%d",&N,&M);
	int x,y;
	Fr(i,1,M)scanf("%d%d",&x,&y),add(x,y),add(y,x);
	Fr(i,1,N)if(!B[i])solve(i);
	printf("NO\n");
	return 0;
}