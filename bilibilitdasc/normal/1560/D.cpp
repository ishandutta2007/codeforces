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
string pot[61]={"1","2","4","8","16","32","64","128","256","512","1024","2048","4096","8192","16384","32768","65536","131072","262144","524288","1048576","2097152","4194304","8388608","16777216","33554432","67108864","134217728","268435456","536870912","1073741824","2147483648","4294967296","8589934592","17179869184","34359738368","68719476736","137438953472","274877906944","549755813888","1099511627776","2199023255552","4398046511104","8796093022208","17592186044416","35184372088832","70368744177664","140737488355328","281474976710656","562949953421312","1125899906842624","2251799813685248","4503599627370496","9007199254740992","18014398509481984","36028797018963968","72057594037927936","144115188075855872","288230376151711744","576460752303423488","1152921504606846976"};//Power Of Two
int matches(char c,string s,int l)
{
	int n=s.size();
	while(l<n) if(s[l++]==c) return --l;
	return n;
}
int ans(string s,string t)
{
	int n=s.size(),m=t.size();
	int i=0,j=0;
	rep(i,n)
	{
		j=matches(s[i],t,j);
		if(j>=m) return i;
		++j;
	}
	return n;
}
string s;
int l,answer,t;
void Q()
{
	cin>>s;
	l=s.size();answer=0x3f3f3f3f;
	rep(i,61)
	answer=min(answer,(int)(pot[i].size()+l-(ans(pot[i],s)<<1)));
	cout<<answer<<endl;
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