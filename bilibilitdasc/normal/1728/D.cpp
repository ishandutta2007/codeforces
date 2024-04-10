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
int t,n;
char s[2005];
int dp[2005][2005];
// 1 for Alice
inline int calc(int S,char A,char B)
{
	return S?S:((A<B)?1:((A>B)?(-1):0));
}
void Q()
{
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<n;++i)
	{
		dp[i][i+1]=(s[i]!=s[i+1]);
	}
	for(int l=4;l<=n;++++l)
	for(int i=1,j=l;j<=n;++i,++j)
	{
		dp[i][j]=max(min(calc(dp[i][j-2],s[j],s[j-1]),calc(dp[i+1][j-1],s[j],s[i]))
		,min(calc(dp[i+2][j],s[i],s[i+1]),calc(dp[i+1][j-1],s[i],s[j])));
	}
	if(dp[1][n]>0) puts("Alice");
	else if(dp[1][n]<0) puts("Bob");
	else puts("Draw");
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