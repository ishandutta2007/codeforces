#include <bits/stdc++.h>
//Submit on luogu
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
const int N=153;
const int M=53;
const int mod=51123987;
int n;
char s[N];
int dp[N][M][M][M];
int nxt[N][3];
int ans;
void add(int&a,int b)
{
	a+=b;if(a>=mod)a-=mod;
}
int main()
{
	scanf("%d%s",&n,s+1);s[0]='d';
	memset(nxt,-1,sizeof(nxt));
	for(int i=1;i<=n;++i)
	{
		nxt[i][s[i]-'a']=i;
	}
	for(int i=n-1;i>=0;--i)
	for(int j=0;j<3;++j)
	{
		if(nxt[i][j]==-1)
		nxt[i][j]=nxt[i+1][j];
	}
	dp[0][0][0][0]=1;
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=50;++j)
		{
			for(int k=0;k<=50;++k)
			{
				for(int l=0;l<=50;++l)
				{
					if(j+k+l==n&&max(j,max(k,l))-min(j,min(k,l))<=1)
					add(ans,dp[i][j][k][l]);
					char c=s[i];
					if(i!=0)
					{
						if(c=='a')
						add(dp[i][j+1][k][l],dp[i][j][k][l]);
						if(c=='b')
						add(dp[i][j][k+1][l],dp[i][j][k][l]);
						if(c=='c')
						add(dp[i][j][k][l+1],dp[i][j][k][l]);
					}
					for(char C='a';C<='c';++C)
					if(C!=c&&nxt[i][C-'a']!=-1)
					{
						int v=nxt[i][C-'a'];
						if(C=='a')
						add(dp[v][j+1][k][l],dp[i][j][k][l]);
						if(C=='b')
						add(dp[v][j][k+1][l],dp[i][j][k][l]);
						if(C=='c')
						add(dp[v][j][k][l+1],dp[i][j][k][l]);
					}
				}
			}
		}
	}
	printf("%d\n",ans);
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