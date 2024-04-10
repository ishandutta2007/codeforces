#include <bits/stdc++.h>
//#define CinCout
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define pb push_back
#define mp make_pair
#define debugv(x) cout<<#x<<'='<<x<<",line "<<__LINE__-1<<endl
#define debug cout<<"at line "<<__LINE__-1<<" in function "<<__FUNCTION__<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
#ifdef CinCout
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#else
#define Yes puts("Yes")
#define No puts("No")
#define YES puts("YES")
#define NO puts("NO")
#endif
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int t,n,a;
int cnt[2];
int dp[105][105][2];
void Q()
{
	cnt[0]=cnt[1]=0;
	cin>>n;
	rep(i,n)
	{
		cin>>a;++cnt[a&1];
	}
	cout<<((dp[cnt[0]][cnt[1]][0])?"Alice":"Bob")<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	dp[0][0][0]=1;
	for(int i=1;i<=100;++i)
	{
		dp[i][0][0]=1;
		dp[0][i][min(i%4,3-i%4)]=1;
	}
	for(int i=1;i<=100;++i) for(int j=1;j<=100;++j)
	{
		dp[i][j][1-(j&1)]=(!dp[i][j-1][0])||(!dp[i-1][j][0]);
		dp[i][j][(j&1)]=(!dp[i][j-1][1])||(!dp[i-1][j][1]);
	}
	while(t--)
	Q();
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