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
struct dir{
	int x,y;
	int mnx,mny,mxx,mxy;
	void update(char c)
	{
		if(c=='U') mnx=min(mnx,--x);
		else if(c=='D') mxx=max(mxx,++x);
		else if(c=='L') mny=min(mny,--y);
		else mxy=max(mxy,++y);
	}
	dir()
	{
		x=y=mnx=mny=mxx=mxy=0;
	}
	dir gen()const
	{
		dir c=dir();
		c.x=-mnx+1;c.y=-mny+1;
		return c;
	}
	bool valid(int n,int m)
	{
		return (mxx-mnx+1<=n&&mxy-mny+1<=m);
	}
	void print()const
	{
		printf("%d %d\n",x,y);
	}
};
dir d;
dir vald;
int t,n,m,l,ind;
char s[1000006];
void Q()
{
	scanf("%d%d%s",&n,&m,s);ind=0;l=strlen(s);
	d=dir();
	while(d.valid(n,m)&&ind<=l)
	{
		vald=d;
		d.update(s[ind++]);
	}
	vald.gen().print();
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