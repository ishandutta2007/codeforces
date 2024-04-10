#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=100100,Inf=0x3f3f3f3f;
int N,M,Q;
char U[MX],D[MX],L[MX],R[MX];
int dp[MX][2],ans=Inf;

int main()
{
	scanf("%d%d%d%s%s%s%s",&N,&M,&Q,L+1,R+1,U+1,D+1);
	Fr(i,1,N)L[i]=L[i]=='B',R[i]=R[i]=='B';
	Fr(i,1,M)U[i]=U[i]=='B',D[i]=D[i]=='B';
	
	Fr(i,1,M)++dp[0][U[i]^1];
	Fr(i,1,N)Fr(j,0,1)
		dp[i][j]=min(dp[i-1][j],dp[i-1][j^1]+M)+(L[i]^j)+(R[i]^j);
	Fr(i,1,M)++dp[N][D[i]^1];
	ans=min(ans,min(dp[N][0],dp[N][1]));
	
	dp[0][0]=dp[0][1]=0;
	Fr(i,1,N)++dp[0][L[i]^1];
	Fr(i,1,M)Fr(j,0,1)
		dp[i][j]=min(dp[i-1][j],dp[i-1][j^1]+N)+(U[i]^j)+(D[i]^j);
	Fr(i,1,N)++dp[M][R[i]^1];
	ans=min(ans,min(dp[M][0],dp[M][1]));
	
	printf("%d\n",ans);
	return 0;
}