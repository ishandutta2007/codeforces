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
ll t,n,k;
ll a[200005];
ll s[200005];
ll ans;
void Q()
{
	cin>>n>>k;
	rep1(i,n)
	{
		cin>>a[i];
		s[i]=a[i]+s[i-1];
	}
	if(k<=n)
	{
		ans=0;
		for(int i=k;i<=n;++i)
		ans=max(ans,s[i]-s[i-k]);
		cout<<ans+k*(k-1)/2<<endl;
		return ;
	}
	else if(n==1)
	{
		cout<<a[1]+k-1<<endl;
		return ;
	}
	ans=0;
	for(ll i=1;i<=n;++i)
	{
		ll res=0;
		ll L=k-i;
		if(L>=n-1)
		{
			L-=n-1; 
			res=s[n]+n*(n-1)/2+(n-i)*(i-1)+i*(i-1)+L/(n-1)*(n-1)*n+(L%(n-1)+1)*(L%(n-1));
		}
		else if(L>=i-1)
		{
			L-=i-1;
			res=s[L+i]+L*(L+1)/2+L*(i-1)+i*(i-1);
		}
		else
		{
			res=s[i]+i*(i-1)/2+L*(L+1);
		}
	//	cout<<i<<"L"<<res<<endl;
		ans=max(ans,res);
		ll R=k-(n-i+1);
		if(R>=n-1)
		{
			R-=n-1;
			res=s[n]+n*(n-1)/2+(n-i)*(i-1)+(n-i)*(n-i+1)+R/(n-1)*n+(R%(n-1)+1)*(R%(n-1));
		}
		else if(R>=n-i)
		{
			R-=n-i;
			res=s[n]-s[i-1-R]+R*(R+1)/2+R*(n-i)+(n-i)*(n-i+1);
		}
		else
		{
			res=s[n]+(n-i)*(n-i+1)/2+R*(R+1);
		}
		ans=max(ans,res);
//		cout<<i<<"R"<<res<<endl;
	}
	cout<<ans<<endl;
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


/*on luogu*/