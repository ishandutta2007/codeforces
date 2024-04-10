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
int t,n,mx;
int a[200005];
map<int,int> cnt;
int res;
int cntmx,cntmxmin,las,tot;
void Q()
{
	mx=0;
	scanf("%d",&n);
	cnt.clear();
	rep(i,n)
	{
		scanf("%d",&a[i]);
		++cnt[a[i]];
		mx=max(mx,a[i]);
	}
	if(cnt.size()==1||cnt[mx]>=2)
	{
		res=1;
		rep1(i,n) res=1ll*res*i%mod1;
		printf("%d\n",res);
		return;
	}
	cntmxmin=cnt[mx-1];
	las=n-1-cntmxmin;
	res=1;
	rep1(i,cntmxmin) res=1ll*res*i%mod1;
	tot=1;
	rep1(i,n) tot=1ll*tot*i%mod1;
	rep1(i,las) res=1ll*res*(n--)%mod1;
	tot-=res;
	if(tot<0) tot+=mod1;
	printf("%d\n",tot); 
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