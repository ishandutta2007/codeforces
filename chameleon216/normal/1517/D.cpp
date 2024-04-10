#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
using namespace std;
typedef long long ll;
const int MX=300000;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
struct Edge{int y,nx;ll w;}E[MX<<4];
int H[MX],ec;
void Add(int x,int y,ll w)
	{ E[++ec].y=y,E[ec].w=w,E[ec].nx=H[x],H[x]=ec; }
void Bee(int x,int y,ll w)
	{ Add(x,y,w),Add(y,x,w); }

int N,M,K;
int Pos(int x,int y){return (x-1)*M+y;}

ll dp[MX][22];

int main()
{
	scanf("%d%d%d",&N,&M,&K);
	if(K&1)
	{
		Fr(i,1,N){Fr(j,1,M)printf("-1 ");putchar('\n');}
		return 0;
	}
	K/=2;
	int w;
	Fr(i,1,N)Fo(j,1,M)
		scanf("%d",&w),Bee(Pos(i,j),Pos(i,j+1),w);
	Fo(i,1,N)Fr(j,1,M)
		scanf("%d",&w),Bee(Pos(i,j),Pos(i+1,j),w);
	Fr(k,1,K)Fr(x,1,N*M)
	{
		dp[x][k]=Inf;
		Fe(i,x)
		{
			int y=E[i].y;
			ll w=E[i].w;
			dp[x][k]=min(dp[x][k],dp[y][k-1]+w);
		}
	}
	Fr(i,1,N)
	{
		Fr(j,1,M)printf("%lld ",dp[Pos(i,j)][K]*2);
		putchar('\n');
	}
	return 0;
}