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
char s[200005];
int l;
ll n;
ll dp[200005][8],S;
ll dp2[200005][8],S2;
void add(ll&x,ll y)
{
	x+=y;if(x>=mod1)x-=mod1;
}
int main()
{
	scanf("%s",s);
	l=strlen(s);
	rep(i,l)
	{
		n=(n<<1|(s[i]&1));
		if(n>=mod1) n-=mod1;
	}
	++n;if(n==mod1)n=0;
	dp[0][7]=1;
	dp2[0][7]=1;
	for(int i=0;i<l;++i)
	{
		for(int j=0;j<8;++j)
		{
			for(int k=0;k<8;++k)
			{
				if(k!=5&&k!=2)
				{
					if(s[i]=='0')
					{
						if((j&k)==0)
						{
							add(dp[i+1][j],dp[i][j]);
						}
					}
					else
					{
						add(dp[i+1][j&k],dp[i][j]);
					}
					if(k!=6&&k!=1)
					{
						if(s[i]=='0')
						{
							if((j&k)==0)
							{
								add(dp2[i+1][j],dp2[i][j]);
							}
						}
						else
						{
							add(dp2[i+1][j&k],dp2[i][j]);
						}
					}
				}
			}
		}
	}
	rep(i,8)
	{
		add(S,dp[l][i]);
		add(S2,dp2[l][i]);
	}
//	cout<<S<<' '<<S2<<endl;
	S=S2-S;if(S<0)S+=mod1;
	S*=3;S%=mod1;
	S-=n;if(S<0)S+=mod1;
	n*=(n*n)%mod1;n%=mod1;
	S+=n;if(S>=mod1)S-=mod1;
	printf("%d\n",int(S));
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