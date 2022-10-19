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
int n,x,y;
char a[5005],b[5005];
vector<int> dif;
void printl(ll v)
{
	if(v<1000000000) printf("%d\n",int(v));
	else printf("%d%09d\n",int(v/1000000000),int(v%1000000000));
}
void Q()
{
	dif.clear();
	rep(i,n) if(a[i]!=b[i]) dif.pb(i);
	if(dif.size()&1u) printf("-1\n");
	else if(dif.size()!=2u) printl(dif.size()/2*1ll*y);
	else if(x<2*y&&dif[1]-dif[0]==1) printf("%d\n",x);
	else if(dif[1]-dif[0]!=1) printf("%d\n",y);
	else printf("%d\n",2*y);
}
void Q2()
{
	
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%s%s",&n,&x,&y,a,b);
		if(x>=y) Q();
		else Q2();
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