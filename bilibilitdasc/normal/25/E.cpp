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
int p[200005];
int res=0x3f3f3f3f;
void build_array(string s)
{
	int l=s.size();
	memset(p,0,sizeof(p));
	for(int i=1;i<l;++i)
	{
		p[i]=p[i-1];
		while(p[i]&&s[i]!=s[p[i]]) p[i]=p[p[i]-1];
		if(s[i]==s[p[i]]) ++p[i];
	}
}
string min_string_with(string s1,string s2)
{
	build_array(s2);
	int i1=0,i2=0;
	int l1=s1.size(),l2=s2.size();
	while(i1<l1)
	{
		if(s1[i1]==s2[i2])
		{
			++i1,++i2;
			if(i2==l2)
			{
				return s1;
			}
		}
		else
		{
			if(i2==0)
			{
				++i1;
			}
			else
			{
				i2=p[i2-1];
			}
		}
	}
	return s1+s2.substr(i2);
}
string s1,s2,s3; 
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>s1>>s2>>s3;
	res=min(res,(int)min_string_with(min_string_with(s1,s2),s3).size());
	res=min(res,(int)min_string_with(min_string_with(s1,s3),s2).size());
	res=min(res,(int)min_string_with(min_string_with(s2,s1),s3).size());
	res=min(res,(int)min_string_with(min_string_with(s2,s3),s1).size());
	res=min(res,(int)min_string_with(min_string_with(s3,s1),s2).size());
	res=min(res,(int)min_string_with(min_string_with(s3,s2),s1).size());
	
	res=min(res,(int)min_string_with(s3,min_string_with(s1,s2)).size());
	res=min(res,(int)min_string_with(s2,min_string_with(s1,s3)).size());
	res=min(res,(int)min_string_with(s3,min_string_with(s2,s1)).size());
	res=min(res,(int)min_string_with(s1,min_string_with(s2,s3)).size());
	res=min(res,(int)min_string_with(s2,min_string_with(s3,s1)).size());
	res=min(res,(int)min_string_with(s1,min_string_with(s3,s2)).size());
	
	cout<<res<<endl;
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