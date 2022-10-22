#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
typedef long long ll;
using namespace std;
const int MX=120000;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int N;
ll P[MX][2];
ll Abs(ll x){return x>=0?x:-x;}
ll Dis(int x,int kx,int y,int ky)
	{ return Abs(P[x][kx]-P[y][ky]); }

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Add(int x,int y)
	{ E[++ec].y=y,E[ec].nx=H[x],H[x]=ec; }

ll dp[MX][2];
#define y E[i].y
void dfs(int x,int f)
{
	Fe(i,x)if(y!=f)
	{
		dfs(y,x);
		Fr(k,0,1)dp[x][k]+=max(dp[y][0]+Dis(x,k,y,0),dp[y][1]+Dis(x,k,y,1));
	}
}
#undef y


int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d",&N);
		Fr(i,1,N)Fr(k,0,1)scanf("%lld",&P[i][k]);
		Fo(i,1,N)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			Add(x,y),Add(y,x);
		}
		dfs(1,0);
		printf("%lld\n",max(dp[1][0],dp[1][1]));
		
		Fr(i,1,N)H[i]=0;
		Fr(i,1,N)dp[i][0]=dp[i][1]=0,P[i][0]=P[i][1]=0;
		ec=0;
		N=0;
	}
	return 0;
}