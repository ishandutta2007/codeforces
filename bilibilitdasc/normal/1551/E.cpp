#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define repk(i,a,b) for(int i=(a);i<=(b);++i)
#define perk(i,a,b) for(int i=(a);i>=(b);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int t,n,k;
int a[2005];
int dp[2005][2005];
void Q()
{
	scanf("%d%d",&n,&k);
	rep(i,n)
	scanf("%d",a+i);
	for(int i=0;i<=n;++i) for(int j=0;j<=n;++j) dp[i][j]=-0x7f7f7f7f;
	dp[0][0]=0;
	for(int i=0;i<n;++i) for(int j=0;j<n;++j)
	{
		dp[i+1][j]=max(dp[i+1][j],dp[i][j]+(a[i]==i+1-j));
		dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
	}
	//for(int i=0;i<=n;++i) for(int j=0;j<=n;++j) printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
	for(int i=0;i<=n;++i)
	{
		if(dp[n][i]>=k)
		{
			printf("%d\n",i);
			return ;
		}
	}
	printf("-1\n");
}
int main()
{
	scanf("%d",&t);
	while(t--)
	Q();
	return 0;
}
/* things to check
1. int overflow or long long memory need
2. recursion/array/binary search/dp bounds
3. precision
4. forever loop
5. special cases(n=1,bounds)
*/