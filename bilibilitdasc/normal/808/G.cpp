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
int dp[4005];
int nw[4005];
char s[100005],t[100005];
int nxt[4005][29];
int kmp[4005];
int n,m;
int V;
int main()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);m=strlen(t+1);
	if(n<m) puts("0");
	else
	{
		nxt[1][t[1]&31]=1;
		for(int i=2;i<=m;++i)
		{
			kmp[i]=nxt[i-1][t[i]&31];
			for(char c='a';c<='z';++c)
			{
				if(t[kmp[i]+1]==c)
				{
					nxt[i][c&31]=kmp[i]+1;
				}
				else
				{
					nxt[i][c&31]=nxt[kmp[i]][c&31];
				}
			}
		}
		memset(dp,0xc0,sizeof(dp));
		dp[0]=0;
		for(int i=1;i<=n;++i)
		{
			memset(nw,0xc0,sizeof(nw));
			if(s[i]=='?')
			{
				for(int j=0;j<=m;++j)
				{
					for(int k=1;k<=26;++k)
					{
						if((t[j+1]&31)!=k)
						nw[nxt[j][k]]=max(nw[nxt[j][k]],dp[j]);
						else
						nw[j+1]=max(nw[j+1],dp[j]);
					}
				}
			}
			else
			{
				for(int j=0;j<=m;++j)
				{
					if(t[j+1]!=s[i])
					nw[nxt[j][s[i]&31]]=max(nw[nxt[j][s[i]&31]],dp[j]);
					else
					nw[j+1]=max(nw[j+1],dp[j]);
				}
			}
			memcpy(dp,nw,sizeof(dp));
			++dp[m];
		//	rep1(i,m) cout<<dp[i]<<',';
		//	cout<<endl;
		}
		for(int j=0;j<=m;++j) V=max(V,dp[j]);
		cout<<V<<endl;
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