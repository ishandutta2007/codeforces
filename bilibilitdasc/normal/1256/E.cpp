#include <bits/stdc++.h>
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define repk(i,a,b) for(int i=(a),_##i##__end=(b);i<=_##i##__end;++i)
#define perk(i,a,b) for(int i=(a),_##i##__end=(b);i>=_##i##__end;++i)
#define rep0(i,a,b) for(int i=(a),_##i##__end=(b);i<_##i##__end;++i)
#define pb push_back
#define mp make_pair
#define debug(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
const long long INF=0x3f3f3f3f3f3f3f3fll;
int n;
long long a[200005];
long long p[200005];
long long dp[200005];
long long mndp[200005];
int clr[200005];
int prdp[200005];
int v;
long long res;
bool cmp(const int&i,const int&j)
{
	return a[i]<a[j];
}
vector<int> bp;//BreakPoint
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	rep1(i,n)
	{
		cin>>a[i];
		p[i]=i;
	}
	sort(p+1,p+1+n,cmp);
	dp[0]=0;dp[1]=dp[2]=INF;
	mndp[0]=mndp[1]=mndp[2]=-a[p[1]];
	prdp[0]=prdp[1]=prdp[2]=0;
	for(int i=3;i<=n;++i)
	{
		dp[i]=mndp[i-3]+a[p[i]];
		res=dp[i]-a[p[i+1]];
		if(mndp[i-1]>res)
		{
			prdp[i]=i;
			mndp[i]=res;
		}
		else
		{
			prdp[i]=prdp[i-1];
			mndp[i]=mndp[i-1];
		}
	}
	v=n;
	while(v!=0)
	{
		bp.pb(v);
		v=prdp[v-3];
	}
	cout<<dp[n]<<' '<<bp.size()<<endl;
	bp.pb(0);
	rep(i,bp.size())
	{
		if(i==bp.size()-1) break;
		for(int j=bp[i];j>bp[i+1];--j)
		{
			clr[p[j]]=i+1;
		}
	}
	rep1(i,n)
	{
		cout<<clr[i]<<(i==n?'\n':' ');
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

/* something to think about
1. greedy? dp? searching? dp with matrix/ segment tree? binary search?
2. If contains "not", why not  or few affect?
*/