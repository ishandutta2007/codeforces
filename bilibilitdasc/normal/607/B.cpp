#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define per1(i,n) for(int i=(n);i>=1;i--)
#define repk(i,a,b) for(int i=(a);i<=(b);i++)
#define perk(i,a,b) for(int i=(a);i>=(b);i--)
#define rep0(i,a,b) for(int i=(a);i<(b);i++)
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
//long long , 
//ios_base::sync_with_stdio(false);cin
int n,c[505];
int dp[505][505];
int main()
{
	cin>>n;
	rep(i,n) cin>>c[i];
	memset(dp,0x3f,sizeof(dp));
	rep(i,n) dp[i][i]=dp[i+1][i]=0;
	for(int dif=1;dif<=n;++dif)
	{
		for(int i=0,t=n-dif;i<=t;++i)
		{
			int j=i+dif;
			if(c[i]==c[j-1])
			{
				dp[i][j]=dp[i+1][j-1];
			 }
			for(int m=i;m<j-1;++m)
			{
				if(c[i]==c[m])
				dp[i][j]=min(dp[i][j],dp[i+1][m]+dp[m+1][j]+1);
			}
		}
	}
	cout<<dp[0][n]+1<<endl;
	return 0;
}