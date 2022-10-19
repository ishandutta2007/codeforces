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
ll t,n,l,Lzero,r,Rzero,Lsum,Rsum;
ll a[100005];
ll fac[200005];
ll ivf[200005];
vector<int> Left;
vector<int> Right;
ll qkpw(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod1;a=a*a%mod1;b>>=1;
	}
	return ret;
}
void init()
{
	fac[0]=1;
	for(int i=1;i<=200003;++i) fac[i]=fac[i-1]*i%mod1;
	ivf[200003]=qkpw(fac[200003],mod1-2);
	for(int j=200002;j>=0;--j) ivf[j]=ivf[j+1]*(j+1)%mod1;
}
bool allzero;
void Q()
{
	cin>>n;allzero=0;
	rep1(i,n)
	{
		cin>>a[i];if(a[i])allzero=1;
	}
	if(!allzero)
	{
		int ret=1;
		for(int i=2;i<=n;++i) ret=(ret*2)%mod1;
		cout<<ret<<endl;
		return;
	}
	if(n==1)
	{
		cout<<1<<endl;
		return;
	}
	l=1;r=n+1;
	Lzero=(a[1]==0);Rzero=0;
	Lsum=a[1];Rsum=0;
	Left.clear();Right.clear();
	while(l+1<r)
	{
		if(a[l+1]==0)
		{
			++l;++Lzero;
		}
		else if(a[r-1]==0)
		{
			--r;++Rzero;
		}
		else if(Lsum<Rsum)
		{
			Lzero=0;Lsum+=a[++l];
		}
		else if(Lsum>Rsum)
		{
			Rzero=0;Rsum+=a[--r];
		}
		else
		{
			if(Lzero==l) --Lzero;
			Left.pb(Lzero+1);
			if(Rzero==n-r+1) --Rzero;
			Right.pb(Rzero+1);
			Lsum=Rsum=Lzero=Rzero=0;
			Lsum+=a[++l];
		}
	}
	ll ans=1;
	if(Lsum==Rsum)
	{
		ans=qkpw(2,Lzero+Rzero+1);
	//	cout<<"!"<<ans<<endl;
	}
	rep(i,Left.size())
	{
		ans=ans*fac[Left[i]+Right[i]]%mod1*ivf[Left[i]]%mod1*ivf[Right[i]]%mod1; 
	}
	cout<<ans<<endl;
}
int main()
{
	init();
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