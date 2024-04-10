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
int in,n,st,ind;
long long res;
int a[100005];
int _;
int _big(int lg,long long &k)
{
	//cout<<lg<<' '<<k<<endl;
	if(lg>=60) return 1;
	int cnt=0;
	while(k>0)
	{
		k-=(1ll<<(lg--));++cnt;
		//cout<<k<<' '<<lg<<endl;
	}
	if(k<0)
	{
		k+=(1ll<<(++lg));
	}
	else
	{
		++cnt;
	}
	return cnt;
}
void Q()
{
	cin>>n>>res;
	a[n-1]=0;
	in=n;
	if(n<=61&&((1ll<<(n-1))<res))
	{
		cout<<-1<<endl;
		return;
	}
	--res;
	st=1;
	ind=0;
	while(n>=2)
	{
		_=_big(n-2,res);
		per(i,_)
		{
			a[ind++]=i+st;
		}
		st+=_;
		n-=_;
	}
	if(!a[in-1]) a[in-1]=in;
	rep1(i,in)
	{
		cout<<a[i-1];
		if(i==in) cout<<endl;
		else cout<<' ';
	}
}
int t;
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