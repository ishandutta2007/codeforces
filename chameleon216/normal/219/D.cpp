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
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
using namespace std;
typedef long long ll;
const int MX=300000,Inf=0x3f3f3f3f;
int N;

struct Edge{int y,w,nx;}E[MX<<1];
int H[MX],ec=1;
void Add(int x,int y,int w)
{
	E[++ec].y=y,E[ec].w=w,E[ec].nx=H[x],H[x]=ec;
}

#define y E[i].y
int dfs1(int x,int f)
{
	int ans=0;
	Fe(i,x)if(y!=f)
		ans+=E[i].w+dfs1(y,x);
	return ans;
}
int dp[MX];
void dfs2(int x,int f,int a)
{
	dp[x]=a;
	Fe(i,x)if(y!=f)
		dfs2(y,x,a-E[i].w+E[i^1].w);
}
#undef y


int main()
{
	scanf("%d",&N);
	Fo(i,1,N)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Add(x,y,0),Add(y,x,1);
	}
	int sum=dfs1(1,0);
	dfs2(1,0,sum);
	int mn=Inf;
	Fr(x,1,N)mn=min(mn,dp[x]);
	printf("%d\n",mn);
	Fr(x,1,N)if(dp[x]==mn)printf("%d ",x);
	putchar('\n');
	return 0;
}