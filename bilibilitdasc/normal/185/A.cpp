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
struct mat{
	ll a[2][2];
};
mat operator*(const mat&a,const mat&b)
{
	mat c;
	c.a[0][0]=(a.a[0][0]*b.a[0][0]+a.a[0][1]*b.a[1][0])%mod2;
	c.a[0][1]=(a.a[0][0]*b.a[0][1]+a.a[0][1]*b.a[1][1])%mod2;
	c.a[1][0]=(a.a[1][0]*b.a[0][0]+a.a[1][1]*b.a[1][0])%mod2;
	c.a[1][1]=(a.a[1][0]*b.a[0][1]+a.a[1][1]*b.a[1][1])%mod2;
	return c; 
}
mat Q;
mat qkpw(mat A,ll p)
{
	mat ret;
	ret.a[0][0]=1;ret.a[0][1]=0;ret.a[1][0]=0;ret.a[1][1]=1;
	while(p)
	{
		if(p&1) ret=ret*A;
		A=A*A;
		p>>=1;
	}
	return ret;
}
ll V;
int main()
{
	Q.a[0][0]=3;Q.a[0][1]=1;Q.a[1][0]=1;Q.a[1][1]=3;
	cin>>V;
	cout<<qkpw(Q,V).a[0][0]<<endl;
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