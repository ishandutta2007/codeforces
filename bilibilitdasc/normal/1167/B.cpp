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
int a[7]={1,4,8,15,16,23,42};
int p[5];
int ver;
void answer()
{
	cout<<"!";
	for(int i=1;i<=6;++i)
	cout<<" "<<a[i];
	cout<<endl;
	exit(0);
}
int query(int a,int b)
{
	cout<<"? "<<a<<" "<<b<<endl;
	cin>>ver;
	return ver;
}
bool check()
{
	for(int i=1;i<=4;++i)
	{
		if(a[i]*a[i+1]!=p[i]) return 0;
	}
	return 1;
}
int main()
{
	for(int i=1;i<=4;++i)
	{
		p[i]=query(i,i+1);
	}
	do
	{
		if(check()) answer();
	}
	while(nextp(a+1,a+7));
	return 0;
}
/* things to check
1.  int overflow or long long memory need
2.  recursion/array/binary search/dp bounds
3.  precision
4.  forever loop
5.  special cases(n=1,bounds)
6.  delete debug statements
7.  initialize(especially multi-tests)
8.  = or == , n or m ,++ or -- , i or j , > or >= , < or <=
9.  keep it simple and stupid
10. do not delete, use // instead
11. operator priority
12. ...
*/