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
int dp[1005][1005];
pair<int,int> pre1[1005][1005];
pair<int,int> pre2[1005][1005];
int a[1005];
int n;
void getans(int i,int j)
{
	if(pre1[i][j].fi==0&&pre1[i][j].se==0) return ;
	getans(pre2[i][j].fi,pre2[i][j].se);
	printf("%d %d\n",pre1[i][j].fi+1,pre1[i][j].se+1);
}
int ii,res=0x3f3f3f3f;
int main()
{
	scanf("%d",&n);
	rep(i,n) scanf("%d",a+i);
	memset(dp,0x3f,sizeof(dp));
	dp[0][1]=0;
	for(int i=0;i<=n;++i) for(int j=i+1;j<=n;++j)
	{
		if(dp[j+1][j+2]>dp[i][j]+max(a[i],a[j]))
		{
			dp[j+1][j+2]=dp[i][j]+max(a[i],a[j]);
			pre1[j+1][j+2]=mp(i,j);
			pre2[j+1][j+2]=mp(i,j);
		 } 
		if(dp[j][j+2]>dp[i][j]+max(a[i],a[j+1]))
		{
			dp[j][j+2]=dp[i][j]+max(a[i],a[j+1]);
			pre1[j][j+2]=mp(i,j+1);
			pre2[j][j+2]=mp(i,j);
		}
		if(dp[i][j+2]>dp[i][j]+max(a[j],a[j+1]))
		{
			dp[i][j+2]=dp[i][j]+max(a[j],a[j+1]);
			pre1[i][j+2]=mp(j,j+1);
			pre2[i][j+2]=mp(i,j);
		}
	}
	if(n&1)
	{
		rep(i,n)
		if(dp[i][n]+a[i]<res)
		{
			res=dp[i][n]+a[i];
			ii=i;
		}
		printf("%d\n",res);
		getans(ii,n);
		printf("%d\n",ii+1);
		return 0;
	}
	else
	{
		printf("%d\n",dp[n][n+1]);
		getans(n,n+1);
	}
	return 0;
}
/* things to check
1. int overflow or long long memory need
2. recursion/array/binary search/dp bounds
3. precision
4. forever loop
5. special cases(n=1,bounds)
*/