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
int t,n,m;
int dp[5000006];
int c[5000006];
int a[1000006];
int ct[5000006];
int lb,mx,ans;
void Q()
{
	scanf("%d%d",&n,&m);
	rep1(i,m)
	{
		c[i]=ct[i]=0;
		dp[i]=m+1;
	}
	rep(i,n)
	{
		scanf("%d",a+i);++ct[a[i]];
	}
	c[m+1]=n;
	mx=m+1;ans=0x3f3f3f3f; 
	for(lb=m;lb>=1;--lb)
	{
		c[dp[lb]]-=ct[lb];c[lb]+=ct[lb];
		dp[lb]=lb;
		for(int k=lb;k<=m/lb;++k)
		{
			if(dp[k]<dp[k*lb])
			{
				c[dp[k*lb]]-=ct[k*lb];c[dp[k]]+=ct[k*lb];
				dp[k*lb]=dp[k];
			}
		}
		while(!c[mx]) --mx;
		if(mx!=m+1) ans=min(ans,mx-lb);
	//	cout<<lb<<","<<mx<<endl;
	}
	printf("%d\n",ans);
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

//testq