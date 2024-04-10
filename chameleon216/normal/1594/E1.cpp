#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
const int Mod=1000000007;

int N;
ll dp[70];


int main()
{
	scanf("%d",&N);
	dp[1]=1;
	Fr(i,2,N)dp[i]=dp[i-1]*dp[i-1]%Mod*16%Mod;
	printf("%lld\n",dp[N]*6%Mod);
	return 0;
}