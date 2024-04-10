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
ll dp[20][2][2520][48];
int t;
ll l,r;
int qwq[20],qaq[20];
int Lcm[48][10];
const int lcms[48]={1,2,3,4,5,6,7,8,9,10,12,14,15,18,20,21,24,28,30,35,36,40,42,45,56,60,63,70,72,84,90,105,120,126,140,168,180,210,252,280,315,360,420,504,630,840,1260,2520};
int lcmof(int x,int y)
{
	int z=x;while(z%y)z+=x;return z;
}
void doit(int Len,int Mod,int LCM,int Max)
{
	int v=Mod%252*10;
	for(int i=0;i<=9;++i)
	{
		dp[Len+1][0][v+i][Lcm[LCM][i]]+=dp[Len][0][Mod][LCM];
	}
	for(int i=0;i<Max;++i)
	{
		dp[Len+1][0][v+i][Lcm[LCM][i]]+=dp[Len][1][Mod][LCM];
	}
	dp[Len+1][1][v+Max][Lcm[LCM][Max]]+=dp[Len][1][Mod][LCM];
}
ll solve(int *qvq)
{
	memset(dp,0,sizeof(dp));
	dp[0][1][0][0]=1;
	for(int i=0;i<=18;++i)
	for(int j=0;j<2520;++j)
	for(int k=0;k<48;++k)
	doit(i,j,k,qvq[i]);
	ll tot=0;
	for(int j=0;j<48;++j) for(int k=0;k<2520;k+=lcms[j])
	tot+=dp[19][0][k][j]+dp[19][1][k][j];
	return tot;
}
void Q()
{
	cin>>l>>r;--l;
	for(int i=18;i>=0;--i)
	{
		qwq[i]=r%10;r/=10;
	}
	ll x=solve(qwq);
//	cout<<x<<endl;
	if(l==0)
	{
		cout<<x-1<<endl;return;
	}
	for(int i=18;i>=0;--i)
	{
		qaq[i]=l%10;l/=10;
	}
	cout<<x-solve(qaq)<<endl;
}
int main()
{
	for(int i=0;i<48;++i)
	{
		for(int j=0;j<=9;++j)
		{
			if(j==0)
			{
				Lcm[i][j]=i;
			}
			else
			{
				Lcm[i][j]=lower_bound(lcms,lcms+48,lcmof(lcms[i],j))-lcms;
			}
//			cout<<lcms[i]<<','<<j<<','<<lcms[Lcm[i][j]]<<endl;
		}
	}
	cin>>t;
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