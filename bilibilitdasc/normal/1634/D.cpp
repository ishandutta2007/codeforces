#include <bits/stdc++.h>
//#define CinCout
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define repk(i,a,b) for(int i=(a),_##i##__end=(b);i<=_##i##__end;++i)
#define perk(i,a,b) for(int i=(a),_##i##__end=(b);i>=_##i##__end;++i)
#define rep0(i,a,b) for(int i=(a),_##i##__end=(b);i<_##i##__end;++i)
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
int n;
int query(int a,int b,int c)
{
	printf("? %d %d %d\n",a,b,c);fflush(stdout);
	int x;scanf("%d",&x);
	if(x==-1) exit(0);
	return x;
}
void answer(int x,int y=1)
{
	printf("! %d %d\n",x,y);fflush(stdout);
}
queue<int> q;
void Extract()
{
	int a=q.front();q.pop();
	int b=q.front();q.pop();
	int c=q.front();q.pop();
	int d=q.front();q.pop();
	int exd=query(a,b,c);
	int exc=query(a,b,d);
	int exb=query(a,c,d);
	int exa=query(b,c,d);
	int mx=max(max(exa,exb),max(exc,exd));
	int cnt=0;
	if(exa==mx) ++cnt;
	if(exb==mx) ++cnt;
	if(exc==mx) ++cnt;
	if(exd==mx) ++cnt;
	if(cnt==4)
	{
		return;
	}
	if(cnt==3)
	{
		if(exd!=mx) q.push(d);
		else if(exc!=mx) q.push(c);
		else if(exb!=mx) q.push(b);
		else q.push(a);
	}
	if(cnt==2)
	{
		if(exd!=mx) q.push(d);
		if(exc!=mx) q.push(c);
		if(exb!=mx) q.push(b);
		if(exa!=mx) q.push(a);
	}
}
void Q()
{
	scanf("%d",&n);
	rep1(i,n) q.push(i);
	while(q.size()>=4) Extract();
	if(q.size()==3)
	{
		int a=q.front();q.pop();
		int b=q.front();q.pop();
		int c=q.front();q.pop();
		q.push(a);q.push(b);q.push(c);
		for(int i=1;i<=4;++i)
		if(i!=a&&i!=b&&i!=c)
		{
			q.push(i);break;
		}
		Extract();
	}
	if(q.size()==2)
	{
		int a=q.front();q.pop();
		int b=q.front();q.pop();
		answer(a,b);
	}
	else if(q.size()==1)
	{
		int a=q.front();q.pop();
		answer(a);
	}
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