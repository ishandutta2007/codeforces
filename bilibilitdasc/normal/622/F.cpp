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
ll qkpw(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod2;
		a=a*a%mod2;
		b>>=1;
	}
	return res;
}
ll inv(ll a)
{
	return qkpw(a,mod2-2);
}
ll n,k,sum,tot;
ll ans[1000006];
ll fac[1000006];
ll num_prod;
/* deg = k+1 , use = k+2 */
void init()
{
	cin>>n>>k;
	rep1(i,k+2)
	ans[i]=(sum+=qkpw(i,k))%=mod2;
	if(n<=k+2)
	{
		cout<<ans[n]<<endl;
		exit(0);
	}
	num_prod=1;
	rep1(i,k+2)
	{
		(num_prod*=(n-i))%=mod2;
	}
	fac[0]=1;
	rep1(i,k+2)
	{
		fac[i]=fac[i-1]*i%mod2;
	}
}
int main()
{
	init();
	rep1(i,k+2)
	{
		ll num=num_prod*inv(n-i)%mod2;
		ll dem=fac[i-1]*fac[k+2-i]%mod2;
		if(k+i&1) dem=mod2-dem;
		ll val=ans[i]*(num*inv(dem)%mod2)%mod2;
		tot+=val;
		if(tot>=mod2) tot-=mod2;
	}
	cout<<tot<<endl;
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