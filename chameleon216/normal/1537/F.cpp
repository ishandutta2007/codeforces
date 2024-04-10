#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=200100;
int N,M,W[MX];

struct Graph{int y,nx;}E[MX<<1];
int H[MX],ec;
void Link(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int B[MX],C[MX],res;
ll sum;
void dfs(int x,int c)
{
	B[x]=1,C[x]=c,sum+=c?W[x]:-W[x];
	Fe(i,x,y)
	{
		if(!B[y])dfs(y,c^1);
		else if(c==C[y])res=1;
	}
}

int mian()
{
	scanf("%d%d",&N,&M);
	int w;
	Fr(x,1,N)scanf("%d",&w),W[x]+=w;
	Fr(x,1,N)scanf("%d",&w),W[x]-=w;
	Fr(i,1,M)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Link(x,y),Link(y,x);
	}
	dfs(1,0);
	printf((sum&1)==0&&(res||!sum)?"YES\n":"NO\n");
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		mian();
		memset(H,0,(N+1)*sizeof(*H));
		memset(W,0,(N+1)*sizeof(*W));
		memset(B,0,(N+1)*sizeof(*B));
		memset(C,0,(N+1)*sizeof(*C));
		res=ec=sum=0;
	}
}