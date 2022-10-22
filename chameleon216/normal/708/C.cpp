#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,x) for(int i=H[x],y=E[i].y;i;i=E[i].nx,y=E[i].y)
using namespace std;
typedef long long ll;
const int MX=900000,Inf=0x3f3f3f3f;
int N;

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Add(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int F[MX],sz[MX],Dp[MX],Ep[MX];
void dfs1(int x,int f)
{
	F[x]=f,sz[x]=1;
	Fe(i,x)if(y!=f)
		dfs1(y,x),sz[x]+=sz[y],Dp[x]=max(Dp[x],Dp[y]);
	if(sz[x]<=N/2)Dp[x]=sz[x];
}

void dfs2(int x,int f)
{
	int mx1=-Inf,son=0,mx2=-Inf;
	Fe(i,x)
	{
		int a=(y!=f?Dp[y]:Ep[x]);
		if(a>mx1)mx2=mx1,mx1=a,son=y;
		else if(a>mx2)mx2=a;
	}
	Fe(i,x)if(y!=f)
	{
		if(N-sz[y]<=N/2)Ep[y]=N-sz[y];
		else Ep[y]=(y==son?mx2:mx1);
		dfs2(y,x);
	}
}


int main()
{
	scanf("%d",&N);
	Fo(i,1,N)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Add(x,y),Add(y,x);
	}
	dfs1(1,0);
	dfs2(1,0);
//	Fr(i,1,N)printf("#%d: d=%d e=%d\n",i,Dp[i],Ep[i]);
	Fr(x,1,N)
	{
		int b=1;
		Fe(i,x)
		{
			int siz=(y!=F[x])
				?sz[y]-Dp[y]
				:N-sz[x]-Ep[x];
			if(siz>N/2){b=0;break;}
		}
		printf("%d ",b);
	}
	return 0;
}