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
int t;
ll n,m,k;
ll a[100005],s1;
ll b[100005],s2;
int cg1,cg2,c21,c22;
bool check(int cg,int c2,ll s,ll target)
{
	if(s<target) return false;
	if(c2==cg&&(target&1)) return false;
	return true;
}
void Q()
{
	cin>>n>>m>>k;cg1=cg2=c21=c22=0;s1=s2=0;
	rep(i,k)
	{
		cin>>a[i];
		b[i]=a[i]/n;
		a[i]/=m;
		if(a[i]>=2)
		{
			++cg1;s1+=a[i];
		}
		if(a[i]==2) ++c21;
		if(b[i]>=2)
		{
			++cg2;s2+=b[i];
		}
		if(b[i]==2) ++c22;
	}
	if(check(cg1,c21,s1,n)||check(cg2,c22,s2,m))
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
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