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

const int MX=1005,W=1000000;
int N,K,A[MX],dp[W+10];

int main()
{
	scanf("%d%d",&N,&K);
	Fr(i,1,N)scanf("%d",&A[i]);
	sort(A+1,A+N+1);
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	Fr(i,2,N)
	{
		int v=A[i]-A[1];
		Fr(j,v,W)dp[j]=min(dp[j],dp[j-v]+1);
	}
	Fr(j,0,W)if(dp[j]<=K)printf("%d ",j+A[1]*K);
	putchar('\n');
	return 0;
}