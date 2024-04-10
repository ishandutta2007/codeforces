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

const int MX=2010,Mod=1000000007;
int N,D,A[MX];

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Link(int x,int y)
{
	E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;
}

int id[MX];
bool cmp(int i,int j){return A[i]<A[j];}

int B[MX],dp[MX];
void dfs1(int x,int f,int w)
{
	dp[x]=1;
	Fe(i,x,y)if(y!=f&&!B[y]&&A[y]-w<=D)
	{
		dfs1(y,x,w);
		dp[x]=1ll*dp[x]*(dp[y]+1)%Mod;
	}
}

int main()
{
	scanf("%d%d",&D,&N);
	Fr(i,1,N)scanf("%d",&A[i]);
	Fr(i,2,N)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Link(x,y),Link(y,x);
	}
	Fr(i,1,N)id[i]=i;
	sort(id+1,id+N+1,cmp);
	int ans=0;
	Fr(i,1,N)
	{
		int x=id[i];
		dfs1(x,0,A[x]);
		ans=(ans+dp[x])%Mod;
		B[x]=1;
	}
	printf("%d\n",ans);
	return 0;
}