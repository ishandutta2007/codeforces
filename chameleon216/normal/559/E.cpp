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

template<typename T1,typename T2>
inline void max_eq(T1& a,T2 b){if(a<b)a=b;}
template<typename T1,typename T2>
inline void min_eq(T1& a,T2 b){if(b<a)a=b;}

const int MX=105;
int N;
struct Node{int x,n;}P[MX];
inline bool operator<(const Node& a,const Node& b){return a.x<b.x;}
int dp[MX][MX][2];

int main()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d%d",&P[i].x,&P[i].n);
	sort(P+1,P+N+1);
	P[0].x=-0x3f3f3f3f;
	Fr(i,1,N)Fr(j,0,i-1)Fr(a,0,1)
	{
		int p=P[j].x+a*P[j].n;
		max_eq(dp[i][j][a],dp[i-1][j][a]);
		if(P[i].x>p)max_eq(dp[i][i][0],dp[i-1][j][a]+min(P[i].n,P[i].x-p));
		if(P[i].x+P[i].n>p)max_eq(dp[i][i][1],dp[i-1][j][a]+min(P[i].n,P[i].x+P[i].n-p));
		if(P[i].x>p)
		{
			Fr(k,i+1,N)if(P[k].x<P[i].x+P[i].n)
				max_eq(dp[k][i][1],dp[i-1][j][a]+P[i].x+P[i].n-max(P[k].x-P[k].n,p));
		}
	}
	int ans=0;
	Fr(j,1,N)Fr(a,0,1)ans=max(ans,dp[N][j][a]);
	printf("%d\n",ans);
	return 0;
}