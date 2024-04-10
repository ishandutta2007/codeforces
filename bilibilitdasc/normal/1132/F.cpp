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
int n;string s;
int dp[505][505];
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;++i) dp[i][i]=1;
	for(int r=0;r<n;++r) for(int l=r-1;l>=0;--l)
	{
		dp[l][r]=1+dp[l+1][r];
		for(int i=r;i>l;--i)
		{
			if(s[i]==s[l])
			{
				dp[l][r]=min(dp[l][r],dp[i][r]+dp[l+1][i-1]);
			}
		}
	}
	cout<<dp[0][n-1]<<endl;
	return 0;
 }