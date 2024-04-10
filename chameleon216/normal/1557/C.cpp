#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long ll;
using namespace std;
const int MX=200100,Mod=1000000007;

ll Pow(ll a,ll b)
{
	ll r=1;
	a%=Mod;
	while(b)
	{
		if(b&1)r=r*a%Mod;
		a=a*a%Mod,b>>=1;
	}
	return r%Mod;
}

int N,K;
ll P[MX],dp[MX];

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d%d",&N,&K);
		ll p=Pow(2,N-1),q=p*2%Mod;
		dp[0]=1,P[0]=1;
		Fr(k,1,K)
		{
			dp[k]=0;
			if(~N&1)P[k]=P[k-1]*q%Mod,dp[k]+=P[k-1];
			dp[k]+=(p-(~N&1)+(N&1)+Mod)%Mod*dp[k-1]%Mod;
			dp[k]%=Mod;
		}
		printf("%lld\n",dp[K]);
	}
	return 0;
}