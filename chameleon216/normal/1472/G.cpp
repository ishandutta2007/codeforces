#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;
const int MX=200000;

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Add(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int N,M,B[MX],D[MX];
void bfs()
{
	memset(B,0,(N+1)*sizeof(int));
	memset(D,0,(N+1)*sizeof(int));
	queue<int> q;
	q.push(1),B[1]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		Fe(i,x,y)if(!B[y])
			q.push(y),D[y]=D[x]+1,B[y]=1;
	}
}

bool Comp(int x,int y){return D[x]<D[y];}
int I[MX],dp[MX];

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d%d",&N,&M);
		Fr(i,1,M)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			Add(x,y);
		}
		bfs();
		Fr(i,1,N)I[i]=i;
		sort(I+1,I+N+1,Comp);
		Fl(i,N,1)
		{
			int x=I[i];
			dp[x]=D[x];
			Fe(j,x,y)
			{
				if(D[x]<D[y])dp[x]=min(dp[x],dp[y]);
				else dp[x]=min(dp[x],D[y]);
			}
		}
		Fr(x,1,N)printf("%d ",dp[x]);
		putchar('\n');
		
		memset(H,0,(N+1)*sizeof(int)),ec=0;
	}
	return 0;
}