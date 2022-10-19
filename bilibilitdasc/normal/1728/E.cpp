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
int a,b,x,y,ad[300005];
ll xn[300005];
ll ex1,ex2;
ll s;
int mx;
ll exgcd(ll a,ll b,ll&x,ll&y)
{
	if(b==0)
	{
		x=1;y=0;return a;
	}
	ll d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
ll floordiv(ll u,ll v)
{
	if(u>=0||u%v==0) return u/v;
	return -floordiv(-u,v)-1;
}
ll ceildiv(ll u,ll v)
{
	if(u%v==0) return u/v;
	return floordiv(u,v)+1;
}
void Q()
{
	scanf("%d%d",&x,&y);
	ll d=exgcd(x,y,ex1,ex2);
	if(n%d)
	{
		printf("-1\n");
		return;
	}
	ex1*=n/d;ex2*=n/d;
	ll X=y/d,Y=x/d;
	ll ret=-1;
	ll toadd=ceildiv(mx/x-ex1,X);
	ex1+=X*toadd;ex2-=Y*toadd;
	for(int i=-2;i<=2;++i)
	{
		ll nwex=ex1-i*X,nwxe=ex2+i*Y;
	//	if(nwex*x+nwxe*y!=n)
		//{
	//		printf("???\n");
	//	}
		if(nwex>=0&&nwxe>=0)
		{
		//	printf("!!%d %d\n",nwex,nwxe);
			ret=max(ret,xn[nwex*x]);
		}
	}
	if(ret<=2000000000)
	printf("%d\n",int(ret));
	else
	printf("%d%09d\n",int(ret/1000000000),int(ret%1000000000));
}
int main()
{
	scanf("%d",&n);
	rep(i,n)
	{
		scanf("%d%d",&a,&b);
		s+=b;
		ad[i]=a-b;
	}
	xn[0]=s;
	sort(ad,ad+n,greater<int>());
	rep(i,n)
	{
		xn[i+1]=xn[i]+ad[i];
		if(ad[i]>0) mx=i+1;
	}
	scanf("%d",&m);
	while(m--)
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