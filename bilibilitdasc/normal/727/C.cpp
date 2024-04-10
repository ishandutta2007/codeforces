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
int n,ver;
int a[5005],s1,s2,s3,ss;
void answer()
{
	cout<<"!";
	for(int i=1;i<=n;++i)
	cout<<" "<<a[i];
	cout<<endl;
}
int query(int a,int b)
{
	cout<<"? "<<a<<" "<<b<<endl;
	cin>>ver;
	return ver;
}
int main()
{
	cin>>n;
	s1=query(1,2);
	s2=query(1,3);
	s3=query(2,3);
	ss=s1+s2+s3;
	ss>>=1;
	a[1]=ss-s3;
	a[2]=ss-s2;
	a[3]=ss-s1;
	for(int i=4;i<=n;++i)
	{
		a[i]=query(1,i)-a[1];
	}
	answer();
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