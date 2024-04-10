#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#define LL long long
using namespace std;
const int inf=1000000007;
int dp[500010],color[500010];
int n;
LL N,ans;
int mypow(int x,int n)
{
	int res=1;
	while (n)
	{
		if(n&1)res=1ll*res*x%inf;
		x=1ll*x*x%inf;
		n>>=1;
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&color[i]);
		N+=color[i];
	}
	dp[0]=0;
	dp[1]=1ll*(N-1)*(N-1)%inf*mypow(N,inf-2)%inf;
	for(int i=1;i<110000;i++)
		dp[i+1]=((((dp[i]+dp[i])%inf-dp[i-1])%inf-1ll*(N-1)*mypow(N-i,inf-2)%inf)%inf+inf)%inf;
	for(int i=1;i<=n;i++)
		ans=(ans+dp[color[i]])%inf;
	cout<<ans<<endl;
	return 0;
}