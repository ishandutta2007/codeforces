#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=105;
int N,M,L[MX][MX],R[MX][MX],dp[MX][MX];

int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,N)
	{
		int n,l,r;
		scanf("%d",&n);
		Fr(j,1,n)
		{
			scanf("%d%d",&l,&r);
			Fr(k,l,r)L[i][k]=l,R[i][k]=r;
		}
	}
	Fl(l,M,1)Fr(r,l,M)Fr(m,l,r)
	{
		int s=0;
		Fr(i,1,N)s+=(l<=L[i][m]&&R[i][m]<=r);
		dp[l][r]=max(dp[l][r],dp[l][m-1]+s*s+dp[m+1][r]);
	}
	printf("%d\n",dp[1][M]);
	return 0;
}