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
int n;
int a[505];
int dp1[505][505];
int dp2[505];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	for(int i=0;i<n;++i) dp1[i][i]=a[i];
	for(int s=1;s<n;++s) for(int i=0,j=s;j<n;++i,++j)
	{
		for(int k=i;k<j;++k)
		{
			if(dp1[i][k]==dp1[k+1][j]&&dp1[i][k])
			{
				dp1[i][j]=dp1[i][k]+1;
			}
		}
	}
	memset(dp2,0x3f,sizeof(dp2));
	dp2[0]=0;
	dp2[1]=1;
	for(int i=2;i<=n;++i)
	{
		for(int j=0;j<i;++j)
		{
			if(dp1[j][i-1])
			{
				dp2[i]=min(dp2[i],dp2[j]+1); 
			}
		}
	}
	//rep(i,n+1)
	printf("%d\n",dp2[n]);
	return 0;
}
/* things to check
1. int overflow or long long memory need
2. recursion/array/binary search/dp bounds
3. precision
4. forever loop
5. special cases(n=1,bounds)
*/