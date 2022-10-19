#include <bits/stdc++.h>
//#define CinCou submit on luogu
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
int t,n;
char b[2][200005];
int dp[200005][4];
int f(int a,int b)
{
	return (a=='*')<<1|(b=='*');
}
void Q()
{
	scanf("%d%s%s",&n,b[0],b[1]);
//	printf("%d\n",n);
//	printf("%s\n%s\n",b[0],b[1]);
	for(int i=0;i<n;++i)
	{
		dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=0x3f3f3f3f;
	}
	int V=f(b[0][0],b[1][0]);
	dp[0][V]=0;
	dp[0][1]=min(dp[0][1],dp[0][3]+1);
	dp[0][2]=min(dp[0][2],dp[0][3]+1);
	dp[0][1]=min(dp[0][1],dp[0][2]+1);
	dp[0][2]=min(dp[0][2],dp[0][1]+1);
	for(int i=1;i<n;++i)
	{
		int v=f(b[0][i],b[1][i]);
		for(int j=0;j<4;++j)
		{
			dp[i][j|v]=min(dp[i][j|v],dp[i-1][j]+(j>>1)+(j&1));
	//		printf("dp[%d][%d]:=%d\n",i,j|v,dp[i][j|v]);
		}
		dp[i][1]=min(dp[i][1],dp[i][3]+1);
		dp[i][2]=min(dp[i][2],dp[i][3]+1);
		dp[i][1]=min(dp[i][1],dp[i][2]+1);
		dp[i][2]=min(dp[i][2],dp[i][1]+1); 
	}
//	rep(i,n) rep(j,4) printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
	for(int i=n-1;i>=0;--i)
	{
	//	printf(":%d%c%c\n",i,b[0][i],b[1][i]);
		if((b[0][i]=='*')||(b[1][i]=='*'))
		{
		//	printf("%d\n",i);
			printf("%d\n",min(dp[i][1],dp[i][2]));
			return;
		}
	}
}
int main()
{
	scanf("%d",&t);
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