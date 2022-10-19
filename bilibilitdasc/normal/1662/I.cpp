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
int n,m;
ll p[200005];
ll x[200005];
ll d[200005];
ll l[200005];
ll r[200005];
ll all[400005];
ll dif[400005];
ll ans;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	rep(i,n)
	{
		cin>>p[i];
	}
	x[0]=-INF;
	rep1(i,m)
	{
		cin>>x[i];
		x[i]*=3;
	}
	x[m+1]=INF;
	sort(x,x+m+2);
	rep(i,n)
	{
		d[i]=min((*lower_bound(x,x+m+2,i*300ll))-i*300ll,i*300ll-(*(upper_bound(x,x+m+2,i*300ll)-1)));
		l[i]=i*300ll-d[i]+1;
		r[i]=i*300ll+d[i]-1;
		all[i<<1]=l[i];all[i<<1|1]=r[i];
	}
	sort(all,all+(n<<1));
	rep(i,n)
	{
		l[i]=lower_bound(all,all+(n<<1),l[i])-all;
		r[i]=lower_bound(all,all+(n<<1),r[i])-all;
		dif[l[i]]+=p[i];dif[r[i]+1]-=p[i];
	}
	rep1(i,400000)
	{
		dif[i]+=dif[i-1];
		ans=max(ans,dif[i]);
	}
	cout<<ans<<endl;
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