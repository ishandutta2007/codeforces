#include <bits/stdc++.h>
/*code*/
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
unsigned long long x,y,l,r;
unsigned long long mx=1234567891234567891ull;
vector<unsigned long long> X,Y;
set<unsigned long long> interval;
unsigned long long answer;
int main()
{
	cin>>x>>y>>l>>r;
	interval.insert(l-1);
	interval.insert(r+1);
	X.pb(1);Y.pb(1);
	while(X.back()<=mx/x) X.pb(X.back()*x);
	while(Y.back()<=mx/y) Y.pb(Y.back()*y);
	rep(i,X.size()) rep(j,Y.size())
	{
		unsigned long long value=X[i]+Y[j];
		if(l<=value&&value<=r)
		{
			interval.insert(value);//cout<<value<<endl;
		}
	}
	for(set<unsigned long long>::iterator itr=next(interval.begin());
	itr!=interval.end();++itr)
	{
		answer=max(answer,(*itr)-(*prev(itr))-1);
	}
	cout<<answer<<endl;
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