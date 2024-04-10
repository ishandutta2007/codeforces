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
const int N=200005;
int t,n;
int a[N];
char s[N];
int b[N],lb;
int r[N],lr;
void Q()
{
	scanf("%d",&n);rep(i,n) scanf("%d",&a[i]);scanf("%s",s);lb=lr=0;
	rep(i,n)
	{
		if(s[i]=='B') b[++lb]=a[i];
		else r[++lr]=a[i];
	}
	sort(b+1,b+lb+1);sort(r+1,r+lr+1);
	for(int i=1;i<=lb;++i) if(b[i]<i) return printf("NO\n"),void();
	for(int i=lb+1;i<=n;++i) if(r[i-lb]>i) return printf("NO\n"),void();
	printf("YES\n");
}
int main()
{
	scanf("%d",&t);while(t--)Q();
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