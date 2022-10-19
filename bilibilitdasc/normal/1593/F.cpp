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
bool dp[45][45][45][45];// R B rR rB
pair<int,bool> ls[45][45][45][45];
pair<int,bool> num;
int t,n,a,b;
int x,y,ra,rb;
char s[45];
void Q()
{
	scanf("%d%d%d%s",&n,&a,&b,s);
	memset(dp,0,sizeof(dp));
	dp[0][0][0][0]=1;
	for(int i=0;i<n;++i) for(int j=0;j<n;++j) for(int k=0;k<a;++k) for(int l=0;l<b;++l)
	{
		if(i+j<n&&dp[i][j][k][l])
		{
			x=(k*10+s[i+j]-48)%a;
			y=(l*10+s[i+j]-48)%b;
			dp[i+1][j][x][l]=1;
			ls[i+1][j][x][l]=mp(k,0);
			dp[i][j+1][k][y]=1;
			ls[i][j+1][k][y]=mp(l,1);
		}
	}
	x=0;y=114514;
	for(int i=1;i<n;++i) if(dp[i][n-i][0][0]&&abs(n-i-i)<abs(x-y)) x=i,y=n-i;
	if(y==114514) return printf("-1\n"),void();
	ra=0,rb=0;
	while(x||y)
	{
		num=ls[x][y][ra][rb];
		if(num.second)
		{
			s[x+(--y)]='B';
			rb=num.first;
		}
		else
		{
			s[y+(--x)]='R';
			ra=num.first;
		}
	}
	printf("%s\n",s);
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