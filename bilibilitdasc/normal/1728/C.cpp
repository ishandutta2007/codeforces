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
int t,n,a,b;
multiset<pair<int,bool> > s;
multiset<pair<int,bool> >::iterator it;
int cnt;
int powers[9]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
void Q()
{
	scanf("%d",&n);cnt=0;
	rep(i,n)
	{
		scanf("%d",&a);s.insert(mp(a,false));
	}
	rep(i,n)
	{
		scanf("%d",&b);it=s.find(mp(b,0));
		if(it!=s.end()) s.erase(it);
		else s.insert(mp(b,true));
	}
	while(!s.empty())
	{
		it=prev(s.end());
		int v=it->first;bool fl=it->second;s.erase(it);
		v=upper_bound(powers,powers+9,v)-powers;
		it=s.find(mp(v,!fl));
		if(it!=s.end()) s.erase(it);
		else s.insert(mp(v,fl));
		++cnt;
	}
	printf("%d\n",cnt);
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