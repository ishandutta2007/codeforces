#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
typedef long long ll;
using namespace std;

template<typename T,typename U>
void max_eq(T& a,const U& b){if(a<b)a=b;}
template<typename T,typename U>
void min_eq(T& a,const U& b){if(b<a)a=b;}

const int MX=200100,Inf=0x3f3f3f3f;
int N;
struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Add(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int dp[MX],ep[MX];
void dfs(int x,int f,int d)
{
	int c=0;
	Fe(i,x,y)if(y!=f)++c,dfs(y,x,d+1);
	if(!c)ep[x]=d;
	else
	{
		int son=0;
		ep[x]=Inf,dp[x]=1;
		Fe(i,x,y)if(y!=f&&ep[y]<ep[x])
			ep[x]=ep[y],son=y;
		Fe(i,x,y)if(y!=f)
		{
			max_eq(dp[x],dp[y]);
			if(y!=son)max_eq(dp[x],ep[y]-d+1);
		}
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
	
		scanf("%d",&N);
		Fr(i,2,N)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			Add(x,y),Add(y,x);
		}
		dfs(1,0,1);
		
		int son=0,ans=0;
		Fe(i,1,y)if(ep[son]<ep[y])son=y;
		Fe(i,1,y)
		{
			max_eq(ans,dp[y]);
			max_eq(ans,y==son?ep[y]-1:ep[y]);
		}
		
		printf("%d\n",ans);
		
		memset(H,0,(N+1)*sizeof(int)),ec=0;
		memset(dp,0,(N+1)*sizeof(int));
		memset(ep,0,(N+1)*sizeof(int));
	}
	return 0;
}