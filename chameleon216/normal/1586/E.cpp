#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=300100;
int N,M,Q,X[MX],Y[MX],cnt[MX];

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Link(int x,int y)
{
	E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;
}

int B[MX],D[MX],F[MX];
void dfs1(int x,int f,int d)
{
	B[x]=1,F[x]=f,D[x]=d;
	Fe(i,x,y)if(!B[y])dfs1(y,x,d+1);
}

int stkx[MX],stky[MX];
void Query(int x,int y)
{
	int tx=0,ty=0;
	while(x!=y)
	{
		if(D[x]>D[y])stkx[++tx]=x,x=F[x];
		else stky[++ty]=y,y=F[y];
	}
	stkx[++tx]=x;
	printf("%d\n",tx+ty);
	Fr(i,1,tx)printf("%d ",stkx[i]);
	Fl(i,ty,1)printf("%d ",stky[i]);
	putchar('\n');
}

int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,M)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Link(x,y),Link(y,x);
	}
	dfs1(1,0,1);
//	Fr(i,1,N)printf("%d ",F[i]);putchar('\n');
//	Fr(i,1,N)printf("%d ",D[i]);putchar('\n');
	scanf("%d",&Q);
	Fr(i,1,Q)
	{
		scanf("%d%d",&X[i],&Y[i]);
		cnt[X[i]]^=1,cnt[Y[i]]^=1;
	}
	int sum=0;
	Fr(i,1,N)sum+=cnt[i];
	if(sum)printf("NO\n%d\n",sum/2);
	else
	{
		printf("YES\n");
		Fr(i,1,Q)Query(X[i],Y[i]);
	}
	return 0;
}