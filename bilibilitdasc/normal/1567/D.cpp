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
int t,n;
ll s;
vector<ll> dig;
struct _compare{
	bool operator()(const pair<int,int> &a,const pair<int,int> &b)
	{
		if(a.first!=b.first) return a.first<b.first;
		if(a.second==0&&b.second!=0) return 1;
		if(b.second==0) return 0;
		return a.second>b.second;
	}
};
const ll pw[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
priority_queue<pair<int,int>,vector<pair<int,int> >,_compare> q;
void getdig(ll x,int lg)
{
	if(x>9)
	{
		getdig(x/10,lg+1);
		x%=10;
	}
	if(x)
	q.push(mp(int(x),lg));
	while(x--) dig.pb(pw[lg]);
}
void split()
{
	pair<int,int> x=q.top();q.pop();
	//cout<<x.first<<"e"<<x.second<<endl<<"{"<<endl;
	pair<int,int> y;
	if(x.first>1)
	{
		y.first=x.first-1;y.second=x.second;q.push(y);
		//cout<<y.first<<"e"<<y.second<<endl;
		y.first=1;q.push(y);
		//cout<<y.first<<"e"<<y.second<<endl;
	}
	else
	{
		y.first=9;y.second=x.second-1;q.push(y);
		//cout<<y.first<<"e"<<y.second<<endl;
		y.first=1;q.push(y);
		//cout<<y.first<<"e"<<y.second<<endl;
	}
	//cout<<"}"<<endl;
}
pair<int,int> p;
void Q()
{
	while(!q.empty()) q.pop();
	cin>>s>>n; 
	dig.clear();
	getdig(s,0);
	if(dig.size()>=n)
	{
		for(int i=1;i<n;++i)
		{
			cout<<dig[i]<<' ';
			s-=dig[i];
		}
		cout<<s<<endl;
		return;
	}
	//cout<<"QAQ"<<endl;
	while(q.size()<n)
	{
		split();
	}
	while(!q.empty())
	{
		p=q.top();q.pop();
		cout<<p.first*pw[p.second];
		if(q.empty()) cout<<endl;
		else cout<<' ';
	}
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