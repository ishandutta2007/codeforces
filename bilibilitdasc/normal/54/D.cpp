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
int n,k,l;
char p[105];
char P[105];
char t[105];
bool dp[105][105];
char trans[105][105];
int Trans[105][105];
char nw[105];
char ed;
char answer[105];
int main()
{
	scanf("%d%d%s",&n,&k,p+1);l=strlen(p+1);
	scanf("%s",t+l);
	ed='a'+k-1;
	dp[0][0]=1;
	strcpy(P+1,p+1);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<=l;++j)
		{
			strcpy(nw+1,p+1);nw[j+2]=0;
			if(dp[i][j])
			for(char c='a';c<=ed;++c)
			{
				nw[j+1]=c;
				int ans=0;
				for(int k=1;k<=j+1;++k)
				{
					P[j+3-k]=0;//cout<<'('<<P+1<<'|'<<nw+l-k+1<<')'<<endl;
				//	cout<<'('<<P+1<<' '<<nw+k<<')'<<endl;
					if(strcmp(P+1,nw+k)==0)
					{
						P[j+3-k]=p[j+3-k];
						ans=j+2-k;
					//	cout<<i<<' '<<j<<' '<<ed<<" "<<ans<<endl;
						break;
					}
					P[j+3-k]=p[j+3-k];
				}
				if((ans==l)==(t[i+1]=='1'))
				{
					dp[i+1][ans]=1;
			//		cout<<i<<' '<<j<<' '<<c<<' '<<i+1<<"!"<<ans<<endl;
					trans[i+1][ans]=c;
					Trans[i+1][ans]=j;
				}
			}
		}
	}
	int cur=-1;
	for(int i=0;i<=l;++i) if(dp[n][i]) cur=i;
	if(cur==-1)
	{
		puts("No solution");return 0;
	}
	for(int i=n;i>=1;--i)
	{
		answer[i]=trans[i][cur];
		cur=Trans[i][cur];
	}
	printf("%s\n",answer+1);
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