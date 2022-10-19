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
int n,m,ans;
int dis[25][50005];
int lb[25];
ll fac[25];
ll ivf[25];
void init()
{
	fac[0]=1;
	for(int i=1;i<=20;i++) fac[i]=fac[i-1]*i%mod1;
	ivf[20]=400962745;
	for(int i=19;i>=0;--i) ivf[i]=ivf[i+1]*(i+1)%mod1;
}
int solve_for(int x)
{
	for(int i=1;i<=n;++i)
	{
		lb[i]=n+2-dis[i][x];
	}
	sort(lb+1,lb+n+1);
	ll prob=1;
	for(int i=1;i<=n;++i)
	{
		prob*=upper_bound(lb+i,lb+n+1,i)-lb-i;prob%=mod1;
	}
	return prob;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	rep1(i,n) rep1(j,m) cin>>dis[i][j];
	rep1(i,m)
	{
		ans+=solve_for(i);if(ans>=mod1)ans-=mod1;
	}
	init();
	cout<<(mod1+m-ans*ivf[n]%mod1)%mod1<<endl;
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