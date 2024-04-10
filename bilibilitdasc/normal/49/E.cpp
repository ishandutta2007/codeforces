#include <bits/stdc++.h>
//#define CinCout
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define repk(i,a,b) for(int i=(a),_##i##__end=(b);i<=_##i##__end;++i)
#define perk(i,a,b) for(int i=(a),_##i##__end=(b);i>=_##i##__end;++i)
#define rep0(i,a,b) for(int i=(a),_##i##__end=(b);i<_##i##__end;++i)
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
char s[55];
char t[55];
int l1,l2;
int n;
char tran[55];
vector<pair<int,int> > tr[55];
bool cs[55][55][29];
bool ct[55][55][29];
int dp[55][55];
int main()
{
	scanf("%s%s%d",s,t,&n);l1=strlen(s);l2=strlen(t);
	rep(i,n)
	{
		scanf("%s",tran);
		tr[tran[0]-'a'].pb(mp(tran[3]-'a',tran[4]-'a'));
	}
	for(int i=0;i<l1;++i)
	cs[i][i][s[i]-'a']=1;
	for(int i=0;i<l2;++i)
	ct[i][i][t[i]-'a']=1;
	for(int l=2;l<=l1;++l)
	for(int i=0,j=l-1;j<l1;++i,++j)
	for(int c=0;c<26;++c)
	{
		for(int k=i;k<j;++k)
		{
			rep(_,tr[c].size())
			{
				cs[i][j][c]|=cs[i][k][tr[c][_].first]&&cs[k+1][j][tr[c][_].second];
			}
		}
	}
	for(int l=2;l<=l2;++l)
	for(int i=0,j=l-1;j<l2;++i,++j)
	for(int c=0;c<26;++c)
	{
		for(int k=i;k<j;++k)
		{
			rep(_,tr[c].size())
			{
				ct[i][j][c]|=ct[i][k][tr[c][_].first]&&ct[k+1][j][tr[c][_].second];
			}
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=l1;++i)
	for(int j=1;j<=l2;++j)
	{
		for(int k=0;k<i;++k)
		for(int l=0;l<j;++l)
		if(dp[k][l]!=0x3f3f3f3f)
		for(int c=0;c<26;++c)
		{
			if(cs[k][i-1][c]&&ct[l][j-1][c])
			{
				dp[i][j]=min(dp[k][l]+1,dp[i][j]);
				break;
			}
		}
	}
	if(dp[l1][l2]==0x3f3f3f3f) dp[l1][l2]=-1;
	cout<<dp[l1][l2]<<endl;
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