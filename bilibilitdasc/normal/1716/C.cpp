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
int t,n;
int a[200005],b[200005];
int lra[200005],rla[200005],lrb[200005],rlb[200005];
int cur,ans;
void Q()
{
	cin>>n;
	rep1(i,n)
	{
		cin>>a[i];
	}
	a[1]=-114514;
	rep1(i,n)
	{
		cin>>b[i];
	}
	cur=-114514;
	lra[n]=a[n]+1;lrb[n]=b[n]+1;rla[n]=a[n]+1;rlb[n]=b[n]+1;
	for(int i=n-1;i>=1;--i)
	{
		lra[i]=max(lra[i+1],a[i]+(n-i+1));
		lrb[i]=max(lrb[i+1],b[i]+(n-i+1));
		rla[i]=max(rla[i+1]+1,a[i]+1);
		rlb[i]=max(rlb[i+1]+1,b[i]+1);
	}
	ans=max(lra[1]+n,rlb[1]);
//	cout<<ans<<endl;
	for(int i=1;i<=n;++i)
	{
		if(i&1)
		{
			cur=max(cur+2,max(a[i]+2,b[i]+1));
			if(i!=n)
			ans=min(ans,max(cur+(n-i)*2,max(lrb[i+1]+(n-i),rla[i+1])));
			else
			ans=min(ans,cur);
		}
		else
		{
			cur=max(cur+2,max(b[i]+2,a[i]+1));
			if(i!=n)
			ans=min(ans,max(cur+(n-i)*2,max(lra[i+1]+(n-i),rlb[i+1])));
			else
			ans=min(ans,cur);
		}
	//	cout<<ans<<endl;
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