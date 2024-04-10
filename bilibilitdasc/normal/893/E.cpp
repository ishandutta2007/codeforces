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
int q,x,y;
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
vector<int> c;
void pf(int a)
{
	if(!(a&1))
	{
		int cr=0;
		while(!(a&1))
		{
			a>>=1;++cr;
		}
		c.pb(cr);
	}
	if(!(a%3))
	{
		int cr=0;
		while(!(a%3))
		{
			a/=3;++cr;
		}
		c.pb(cr);
	}
	for(int i=5;i<=a/i;i+=6)
	{
		if(!(a%i))
		{
			int cr=0;
			while(!(a%i))
			{
				a/=i;++cr;
			}
			c.pb(cr);
		}
		if(!(a%(i+2)))
		{
			int cr=0;
			while(!(a%(i+2)))
			{
				a/=i+2;++cr;
			}
			c.pb(cr);
		}
	}
	if(a>1) c.pb(1);
}
ll ans;
void Q()
{
	cin>>x>>y;
	c.clear();ans=1;
	pf(x);
	rep(i,c.size())
	{
		int v=c[i];
		rep1(j,v)
		{
			ans=ans*(y+v-j)%mod2*qkpw(j,mod2-2)%mod2;
		}
	}
	ans=ans*qkpw(2,y-1)%mod2;
	cout<<ans<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>q;
	while(q--)
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