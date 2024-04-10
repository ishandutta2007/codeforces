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
set<int> _x;
set<int> _y;
map<int,int> cntx;
map<int,int> cnty;
map<pair<int,int>,int> sx;
map<pair<int,int>,int> sy;
map<int,int>::iterator i;
map<pair<int,int>,int>::iterator j;
int t,n,m,k;
int rx,ry;
int px,py;
long long ans;
ll f(const int&x)
{
	return (1ll*(x-1)*x)>>1;
}
void Q()
{
	_x.clear();_y.clear();cntx.clear();cnty.clear();sx.clear();sy.clear();
	cin>>n>>m>>k;
	rep(i,n)
	{
		cin>>rx;_x.insert(rx);
	}
	rep(i,m)
	{
		cin>>ry;_y.insert(ry);
	}
	rep(i,k)
	{
		cin>>px>>py;
		if(!_x.count(px))
		{
			++cntx[*(_x.lower_bound(px))];
			++sx[mp(*(_x.lower_bound(px)),py)];
		}
		if(!_y.count(py))
		{
			++cnty[*(_y.lower_bound(py))];
			++sy[mp(*(_y.lower_bound(py)),px)];
		}
	}
	ans=0;
	//cout<<ans<<endl;
	for(i=cntx.begin();i!=cntx.end();++i)
	{
		ans+=f(i->second);
	}
	for(i=cnty.begin();i!=cnty.end();++i)
	{
		ans+=f(i->second);
	}
	for(j=sx.begin();j!=sx.end();++j)
	{
		ans-=f(j->second);
	}
	for(j=sy.begin();j!=sy.end();++j)
	{
		ans-=f(j->second);
	}
	cout<<ans<<endl;
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