#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;

const int MX=600;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int N,C[MX][MX];
/*
ll S[MX][MX];
ll dp[MX][MX];


inline ll Calc(int u,int d,int l,int r)
{
	return S[d][r]-S[d][l-1]-S[u-1][r]+S[u-1][l-1];
}

ll DP()
{
//	Fr(i,1,2*N){Fr(j,1,2*N)printf("%lld ",S[i][j]);putchar('\n');}putchar('\n');
	Fr(i,1,2*N)Fr(j,1,2*N)
		S[i][j]+=S[i-1][j]+S[i][j-1]-S[i-1][j-1];
	printf("%lld\n",S[2*N][2*N]);
	Fr(i,0,2*N)Fr(j,0,2*N)dp[i][j]=Inf;
	Fr(i,N,2*N)Fr(j,N,2*N)
	{
		if(i==N&&j==N){dp[i][j]=0;continue;}
		dp[i][j]=min(dp[i-1][j]+Calc(i,i,j-N+1,j),dp[i][j-1]+Calc(i-N+1,i,j,j));
	}
	return dp[2*N][2*N];
}
*/

void Work()
{
	scanf("%d",&N);
	Fr(i,1,2*N)Fr(j,1,2*N)
		scanf("%d",&C[i][j]);
	ll ans=0;
	
	/*Fr(i,0,2*N-1)Fr(j,0,2*N-1)S[1+i][1+j]=C[i][j];
	ans=min(ans,DP());
	
	Fr(i,0,2*N-1)Fr(j,0,2*N-1)S[1+i][1+j]=C[(N-1-i+2*N)%(2*N)][j];
	ans=min(ans,DP());
	
	Fr(i,0,2*N-1)Fr(j,0,2*N-1)S[1+i][1+j]=C[i][(N-1-j+2*N)%(2*N)];
	ans=min(ans,DP());
	
	Fr(i,0,2*N-1)Fr(j,0,2*N-1)S[1+i][1+j]=C[(N-1-i+2*N)%(2*N)][(N-1-j+2*N)%(2*N)];
	ans=min(ans,DP());*/
	
	Fr(i,N+1,2*N)Fr(j,N+1,2*N)ans+=C[i][j];
	ans+=min(min(min(min(min(min(min(
		C[1][N+1],C[1][2*N]),C[N][N+1]),C[N][2*N]),
		C[N+1][1]),C[N+1][N]),C[2*N][1]),C[2*N][N]);
	
	printf("%lld\n",ans);
//	Fr(i,1,2*N)Fr(j,1,2*N)S[i][j]=0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)Work();
	return 0;
}