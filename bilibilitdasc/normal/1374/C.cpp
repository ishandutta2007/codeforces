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
int T,n,l,r;
char s[55];
char t[55];
int c3;
int open[55],c1;
int clos[55],c2;
int ans;
bool check(int x,int y)
{
	for(int i=0;i<x;++i)
	t[i]='(';
	for(int i=n-y;i<n;++i)
	t[i]=')';
	c3=x;
	for(int i=0;i<n;++i)
	{
		if(s[i]=='('&&i<=open[x])
		t[c3++]='(';
		if(s[i]==')'&&i>=clos[y])
		t[c3++]=')';
	}
	int cnt=0;
	rep(i,n)
	{
		if(t[i]=='(') ++cnt;
		if(t[i]==')') --cnt;
		if(cnt<0) return 0;
	}
	return 1;
}
void Q()
{
	scanf("%d%s",&n,s);
	l=0;r=n/2;c1=c2=0;
	rep(i,n)
	{
		if(s[i]==')')
		clos[c2++]=i;
	}
	clos[c2]=n;
	per(i,n)
	{
		if(s[i]=='(')
		open[c1++]=i;
	}
	open[c1]=-1;
//	rep(i,n/2) cout<<clos[i]<<' ';
//	cout<<endl;
//	rep(i,n/2) cout<<open[i]<<' ';
//	cout<<endl;	
	//cout<<check(n/2,n/2)<<endl;
//	cout<<check(0,1)<<endl;
	while(r>=0&&check(l,r))
	--r;
	++r;
	ans=r;
	while((++l)<=n/2)
	{
		while(r>=0&&check(l,r))
		--r;
		++r;
		ans=min(ans,l+r);
	}
	printf("%d\n",ans);
}
int main()
{
	scanf("%d",&T);
	while(T--)
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