#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define rg register
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=2100,Mod=1000000007;
int N,K;
ll dp[MX][MX];

int main()
{
	scanf("%d%d",&N,&K);
	Fr(i,1,N)dp[i][1]=1;
	Fr(k,2,K)
	{
		Fr(i,1,N)
		{
			for(int j=i;j<=N;j+=i)
				dp[j][k]+=dp[i][k-1];
		}
		Fr(i,1,N)dp[i][k]%=Mod;
	}
	ll sum=0;
	Fr(i,1,N)sum+=dp[i][K];
	printf("%lld\n",sum%Mod);
	/*Fr(k,1,K)
	{
		Fr(i,1,N)printf("%lld ",dp[i][k]);
		putchar('\n');
	}*/
	return 0;
}