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
const int MX=2e5+100;
int N;
ll A[MX],dp[MX];
int mian()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%lld",A+i);
	Fl(i,N,1)
	{
		if(i+A[i]>N)dp[i]=A[i];
		else dp[i]=A[i]+dp[i+A[i]];
	}
	ll mx=dp[1];
	Fr(i,2,N)mx=max(mx,dp[i]);
	printf("%lld\n",mx);
	Fr(i,1,N)dp[i]=0;
	return 0;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
	return 0;
}