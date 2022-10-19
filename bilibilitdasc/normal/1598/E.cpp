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
int n,m,q;
int x,y;
ll ans;
bool closed[1234][1234];
void add(const int&b,const ll&x)
{
	if(b) ans+=x;else ans-=x;
}
bool isin(const int&x,const int&y)
{
	return x>=1&&x<=n&&y>=1&&y<=m&&!closed[x][y];
}
ll fl(int x,int y,int dx,int dy)//find longest
{
	int cnt=1;
	x+=dx;y+=dy;
	while(isin(x,y))
	{
		++cnt;swap(dx,dy);x+=dx;y+=dy;//1 1 ->
	}
	return cnt;
}
ll change(const int&x,const int&y)
{
	closed[x][y]=!closed[x][y];
	add(!closed[x][y],fl(x,y,-1,0)*fl(x,y,0,1)+fl(x,y,1,0)*fl(x,y,0,-1)-1);
	return ans;
}
void cf()//calc first
{
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j/2<n&&i+(j+1)/2<=m;++j)
		{
			ans+=j;
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j/2<m&&i+(j+1)/2<=n;++j)
		{
			ans+=j;
		}
	}
	ans+=1ll*n*m;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>q;
	cf();
	//cout<<ans<<endl;
	while(q--)
	{
		cin>>x>>y;
		change(x,y);
		cout<<ans<<endl;
	}
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