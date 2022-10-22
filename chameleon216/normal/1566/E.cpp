#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
typedef long long ll;
using namespace std;

const int MX=200100;
int N;

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Add(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int dp[MX];
void dfs1(int x,int f)
{
	int c=0,d=0;
	Fe(i,x,y)if(y!=f)
	{
		dfs1(y,x);
		if(dp[y]==1)++c;
		else if(dp[y]==2)++d;
	}
	if(!c&&!d)dp[x]=1;
	else if(f&&!d)dp[x]=0;
	else dp[x]=2;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d",&N);
		Fo(i,1,N)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			Add(x,y),Add(y,x);
		}
		dfs1(1,0);
	//	Fr(i,1,N)printf("%d ",dp[i]);putchar('\n');
		int sum=0;
		Fr(x,1,N)
		{
			if(dp[x]==0)--sum;
			else if(dp[x]==1)++sum;
		}
		printf("%d\n",sum);
		
		memset(H,0,(N+1)*sizeof(int));
		memset(dp,0,(N+1)*sizeof(int));
		ec=0;
	}
	return 0;
}