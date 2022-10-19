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
int n;
int a[1005];
int b[1005];
bool id[1005];
vector<int> di;
vector<int> nu;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	rep1(i,n) cin>>a[i];
	rep1(i,n) cin>>b[i];
	rep1(i,n)
	{
		if(a[i]==b[i]) id[a[i]]=1;
		else di.pb(i);
	}
	rep1(i,n) if(!id[i]) nu.pb(i);
	if(di.size()==1)
	{
		rep1(i,n)
		{
			if(a[i]==b[i]) cout<<(a[i]+b[i])/2;
			else cout<<nu[0];
			if(i==n) cout<<endl;
			else cout<<' ';
		}
	}
	else
	{
		if(a[di[0]]+b[di[1]]==nu[0]+nu[1]&&a[di[0]]*b[di[1]]==nu[0]*nu[1])
		{
			a[di[1]]=b[di[1]];
		}
		else
		{
			a[di[0]]=b[di[0]];
		}
		rep1(i,n)
		{
			cout<<a[i];
			if(i==n) cout<<endl;
			else cout<<' ';
		}
	}
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

/* so
luogu
y? dp? searching? dp with matrix/ segment tree? binary search?
2. If contains "not", why not  or few affect?
*/