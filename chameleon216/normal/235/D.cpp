#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <utility>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
using namespace std;
typedef long long ll;
const int MX=3500;
int N;

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Add(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}


int B[MX],dfn[MX],low[MX],dc;
int Cr[MX],Ic[MX],cc,stk[MX],tp;
#define y E[i].y
void Tarjan(int x,int f)
{
	B[x]=1,dfn[x]=low[x]=++dc,stk[++tp]=x;
	Fe(i,x)
	{
		if(B[y]==0)Tarjan(y,x),low[x]=min(low[x],low[y]);
		else if(y!=f)low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x])
	{
		if(stk[tp]!=x)
		{
			int z=0;
			while(z!=x)z=stk[tp--],Cr[++cc]=z,Ic[z]=1;
		}
		else tp--;
	}
}


int C[MX],Ds[MX][MX];
void dfs1(int x,int f,int c)
{
	C[x]=c;
	Fe(i,x)if(y!=f&&!Ic[y])dfs1(y,x,c);
}
void dfs2(int x,int f,int rt,int d)
{
	Ds[rt][x]=d;
	Fe(i,x)if(y!=f&&C[x]==C[y])
		dfs2(y,x,rt,d+1);
}
#undef y


double Calc(int x,int y)
{
	if(C[x]==C[y])return 1.0/Ds[x][y];
	int rx=Cr[C[x]],ry=Cr[C[y]];
	int a=Ds[x][rx]+Ds[y][ry]+(C[x]-C[y]+cc)%cc-1;
	int b=Ds[x][rx]+Ds[y][ry]+(C[y]-C[x]+cc)%cc-1;
	int c=Ds[x][rx]+Ds[y][ry]+cc-2;
	return 1.0/a+1.0/b-1.0/c;
}


int main()
{
	scanf("%d",&N);
	Fr(i,1,N)
	{
		int x,y;
		scanf("%d%d",&x,&y),++x,++y;
		Add(x,y),Add(y,x);
	}
	Tarjan(1,0);
//	Fr(i,1,cc)printf("%d ",Cr[i]);putchar('\n');
	Fr(i,1,cc)dfs1(Cr[i],0,i);
	Fr(i,1,N)dfs2(i,0,i,1);
//	Fr(i,1,N)printf("%d ",C[i]);putchar('\n');
//	Fr(i,1,N){Fr(j,1,N)printf("%d ",Ds[i][j]);putchar('\n');}
	double ans=0;
	Fr(i,1,N)Fr(j,1,N)ans+=Calc(i,j);
	printf("%.10f\n",ans);
	return 0;
}