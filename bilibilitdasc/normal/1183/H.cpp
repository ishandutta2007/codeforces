#include <bits/stdc++.h>
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define repk(i,a,b) for(int i=(a),_##i##__end=(b);i<=_##i##__end;++i)
#define perk(i,a,b) for(int i=(a),_##i##__end=(b);i>=_##i##__end;++i)
#define rep0(i,a,b) for(int i=(a),_##i##__end=(b);i<_##i##__end;++i)
#define pb push_back
#define mp make_pair
#define debug(x) cout<<#x<<'='<<x<<endl
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
long long k;
long long sum;
long long tot;
string s;
long long dp[114][114];
bool Count[514];
int main()
{
	cin>>n>>k>>s;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=i;++j)
	{
		if(j==1)
		{
			if(!Count[s[i-1]])
			{
				Count[s[i-1]]=1;
				dp[i][j]=1;
			}
		}
		else if(j==i)
		dp[i][j]=1;
		else
		for(int k=i-1;k>=j-1;--k)
		{
			dp[i][j]+=dp[k][j-1];
			if(s[i-1]==s[k-1]) break;
			
		}
	}
	//for(int i=1;i<=n;++i)
	//for(int j=1;j<=i;++j)
	//printf("dp[%d][%d]=%lld\n",i,j,dp[i][j]);
	for(int len=n;len>=1;--len)
	{
		sum=0;
		for(int i=n;i>=len;--i)
		{
			sum+=dp[i][len];
			//if(s[len-1]==s[i-1]) break;
		}
		//cout<<len<<":"<<sum<<endl;
		if(sum>=k)
		{
			cout<<tot+k*(n-len)<<endl;
			return 0;
		}
		else
		{
			tot+=sum*(n-len);
			k-=sum;
		}
	}
	if(k==1)
	{
		tot+=n;
		cout<<tot<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
	return 0;
}
/* things to check
1.  int overflow or long long memory need
2.  recursion/array/binary search/dp/loop bounds
3.  precision
4.  special cases(n=1,bounds)
5.  delete debug statements
6.  initialize(especially multi-tests)
7.  = or == , n or m ,++ or -- , i or j , > or >= , < or <=
8.  keep it simple and stupid
9.  do not delete, use // instead
10. operator priority
11. is there anything extra to output?
12. ...
*/

/* something to think about
1. greedy? dp? searching? dp with matrix/ segment tree? binary search?
2. If contains "not", why not  or few affect?
*/