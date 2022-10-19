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
map<long long,long long> canup[24];
map<long long,long long> candown[24];
int n,m;
long long k;
long long a[24][24];
bool in(const int&x,const int&y)
{
	return 0<=x&&x<n&&0<=y&&y<m;
}
map<long long,long long>::iterator I;
void dfs(int x,int y,long long res,const int&d)
{
	res^=a[x][y];
	if(x+y==n-1)
	{
		if(d==1)
		{
			++canup[x][res];
			//cout<<x<<' '<<y<<':'<<res<<endl;	
		}
		else
		{
			++candown[x][res^a[x][y]];
			//cout<<x<<' '<<y<<':'<<(res^a[x][y])<<endl;
		}
	}
	else
	{
		if(in(x+d,y))
		{
			dfs(x+d,y,res,d);
		}
		if(in(x,y+d))
		{
			dfs(x,y+d,res,d);
		}
	}
}
long long need;
long long res;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>k;
	rep(i,n) rep(j,m) cin>>a[i][j];
	dfs(0,0,0,1);
	//cout<<"------"<<endl;
	dfs(n-1,m-1,0,-1);
	for(int i=0;i<n;++i)
	{
		for(I=canup[i].begin();I!=canup[i].end();++I)
		{
			need=(I->first)^k;
			if(candown[i].count(need))
			{
				res+=(I->second)*candown[i][need];
			}
		}
	}
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

/* something to think about
1. greedy? dp? searching? dp with matrix/ segment tree? binary search?
2. If contains "not", why not  or few affect?
*/