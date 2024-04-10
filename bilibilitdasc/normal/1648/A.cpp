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
int n,m,c,l;
vector<ll> x[100005];
vector<ll> y[100005];
ll tot;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
//	n=m=3;
	rep(i,n)
	{
		rep(j,m)
		{
			cin>>c;
		//	c=1;
			x[c].pb(i);
			y[c].pb(j);
		}
	}
	rep1(i,100000)
	{
		sort(x[i].begin(),x[i].end());
		l=x[i].size();
		rep(j,l)
		{
			tot+=(j-(l-1-j))*x[i][j];
		}
	}
	rep1(i,100000)
	{
		sort(y[i].begin(),y[i].end());
		l=y[i].size();
		rep(j,l)
		{
			tot+=(j-(l-1-j))*y[i][j];
		}
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