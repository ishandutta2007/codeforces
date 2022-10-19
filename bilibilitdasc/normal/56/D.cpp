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
char s[1005],t[1005];
int dp[1005][1005];
int tp[1005][1005];
int ls,lt;
void path(int x,int y)
{
	//printf("(%d,%d)!\n",x,y);
	if(x==0&&y==0)return;
	if(tp[x][y]==3)
	{
		path(x-1,y-1);return;
	}
	if(tp[x][y]==2)
	{
		printf("REPLACE %d %c\n",x,t[y]);path(x-1,y-1);return;
	}
	if(tp[x][y]==1)
	{
		printf("INSERT %d %c\n",x+1,t[y]);path(x,y-1);return;
	}
	printf("DELETE %d\n",x);path(x-1,y);return;
}
int main()
{
	scanf("%s%s",s+1,t+1);
	ls=strlen(s+1);lt=strlen(t+1);
	for(int i=0;i<=ls;++i)
	{
		dp[i][0]=i;tp[0][i]=0;
	}
	for(int i=0;i<=lt;++i)
	{
		dp[0][i]=i;tp[0][i]=1;
	}
	for(int i=1;i<=ls;++i) for(int j=1;j<=lt;++j)
	{
		if(s[i]==t[j])
		{
			dp[i][j]=dp[i-1][j-1];
			tp[i][j]=3;
		}
		else if(dp[i-1][j-1]<min(dp[i][j-1],dp[i-1][j]))
		{
			dp[i][j]=dp[i-1][j-1]+1;
			tp[i][j]=2;
		}
		else if(dp[i][j-1]>dp[i-1][j])
		{
			dp[i][j]=dp[i-1][j]+1;
			tp[i][j]=0;
		}
		else
		{
			dp[i][j]=dp[i][j-1]+1;
			tp[i][j]=1;
		}
	}
	printf("%d\n",dp[ls][lt]);
	path(ls,lt);
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