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
#define ok 0
#define usf 1/*unsafe*/
#define add 2
#define mul 3
int pls[4][4]={
	add,usf,add,add,
	usf,usf,usf,usf,
	add,usf,add,add,
	add,usf,add,add
};
int mns[4][4]={
	add,usf,usf,add,
	usf,usf,usf,usf,
	add,usf,usf,add,
	add,usf,usf,add
};
int tms[4][4]={
	mul,usf,usf,mul,
	usf,usf,usf,usf,
	usf,usf,usf,usf,
	mul,usf,usf,mul
};
int dv[4][4]={
	mul,usf,usf,usf,
	usf,usf,usf,usf,
	usf,usf,usf,usf,
	mul,usf,usf,usf
};
int par[4]={ok,usf,ok,ok};
map<string,int> macro;
int calc(const string&s)
{
	//cout<<"We are going to calculate"<<quoted(s)<<endl;
	int n=s.size();
	int tot=0,qwq;
	vector<int> a=vector<int>();
	vector<int> b=vector<int>();
	vector<int> c=vector<int>();
	vector<int> d=vector<int>();
	vector<int> l=vector<int>();
	vector<int> r=vector<int>();
	for(int i=0;i<n;++i)
	{
		if(s[i]=='(')
		{
			++tot;l.pb(i);
		}
		else if(s[i]==')')
		{
			--tot;r.pb(i);
		}
		else if(s[i]=='+'&&tot==0)
		{
			a.pb(i);
		}
		else if(s[i]=='-'&&tot==0)
		{
			b.pb(i);
		}
		else if(s[i]=='*'&&tot==0)
		{
			c.pb(i);
		}
		else if(s[i]=='/'&&tot==0)
		{
			d.pb(i);
		}
	}
	if(!a.empty())
	{
		qwq=a.back();
		if(b.empty()||b.back()<qwq)
		{
			return pls[calc(s.substr(0,qwq))][calc(s.substr(qwq+1))];
		}
	}
	if(!b.empty())
	{
		qwq=b.back();
		return mns[calc(s.substr(0,qwq))][calc(s.substr(qwq+1))];
	}
	if(!c.empty())
	{
		qwq=c.back();
		if(d.empty()||d.back()<qwq)
		{
			return tms[calc(s.substr(0,qwq))][calc(s.substr(qwq+1))];
		}
	}
	if(!d.empty())
	{
		qwq=d.back();
		return dv[calc(s.substr(0,qwq))][calc(s.substr(qwq+1))];
	}
	if(!l.empty())
	{
		return par[calc(s.substr(l.front()+1,r.back()-l.front()-1))];
	}
	string lst=s;
	while(lst[0]==' ') lst=lst.substr(1);
	while(lst.back()==' ') lst=lst.substr(0,lst.size()-1);
	if(macro.count(lst)) return macro[lst];
	return ok;
}
int n;
string s;
string name,expr;
void once()
{
	getline(cin,s);name=expr="";
	int ind=s.find("define");
	ind+=6;
	while(s[ind]==' ') ++ind;
	while(s[ind]!=' ') name+=s[ind++];
	while(s[ind]==' ') ++ind;
	expr=s.substr(ind);
	macro[name]=calc(expr);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;getline(cin,s);
	rep(i,n) once();
	getline(cin,expr);
	cout<<(par[calc(expr)]?"Suspicious":"OK")<<endl;
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