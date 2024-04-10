#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
#define Fill(x,n) memset((x),(n),sizeof(x))
typedef long long ll;
using namespace std;
const int MX=110000;
const ll Inf=0x3f3f3f3f3f3f3f3fll;

int N;
ll A[MX],B[MX],C[MX];
ll dp[MX];

int mian()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%lld",C+i);
	Fr(i,1,N)scanf("%lld",A+i);
	Fr(i,1,N)scanf("%lld",B+i);	
	dp[1]=-Inf;
	Fr(i,2,N)
	{
		if(A[i]>B[i])swap(A[i],B[i]);
		if(A[i]!=B[i])
		{
			ll len=B[i]-A[i]+1;
			dp[i]=max(dp[i-1]-len+2+C[i],len+C[i]);
		}
		else dp[i]=C[i]+1;
	}
	ll ans=-Inf;
	Fr(i,2,N)ans=max(ans,dp[i]);
	printf("%lld\n",ans);
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
	return 0;
}