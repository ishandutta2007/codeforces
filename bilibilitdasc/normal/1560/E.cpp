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
int cnt[26];
int lastoccur[26];
string charset;
string t;
string s;
string inits;
string imagt;
int lt;
int ls;
int tot;
bool cmp(const char&c,const char&d)
{
	return lastoccur[c-'a']<lastoccur[d-'a'];
}
bool flag;
void Q()
{
	cin>>t;
	lt=t.size();
	tot=0;
	charset="";
	memset(cnt,0,sizeof(cnt));
	memset(lastoccur,0,sizeof(lastoccur));
	for(int i=0;i<lt;++i)
	{
		if(!(cnt[t[i]-'a']++)) charset+=t[i],++tot;
		lastoccur[t[i]-'a']=i;
	}
	flag=0;ls=0;
	sort(charset.begin(),charset.end(),cmp);
	rep(i,tot)
	{
		if(cnt[charset[i]-'a']%(i+1))
		{
			flag=1;
			break;
		}
		ls+=cnt[charset[i]-'a']/(i+1);
	}
	if(flag)
	{
		cout<<-1<<endl;
		return;
	}
	s=t.substr(0,ls);
	imagt="";
	inits=s;
	rep(i,tot)
	{
		imagt+=s;
		while(((int)(s.find(charset[i])))!=-1)
		{
			s.erase(s.find(charset[i]),1);
		}
	}
	if(imagt==t)
	{
		cout<<inits<<' '<<charset<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
}
int T;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
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