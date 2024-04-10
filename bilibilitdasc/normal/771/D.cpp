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
int l;
char s[75];
int dp[75][75][75][2];
vector<int> v,k,x;
void init()
{
	scanf("%d%s",&l,s);
	rep(i,l)
	{
		if(s[i]=='V') v.pb(i);
		else if(s[i]=='K') k.pb(i);
		else x.pb(i);
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0][0]=0;
}
int calc_left(int pos,int V,int K,int X)
{
	int cnt=0;
	for(int i=V;i<v.size();++i) if(v[i]<pos) ++cnt;
	for(int i=K;i<k.size();++i) if(k[i]<pos) ++cnt;
	for(int i=X;i<x.size();++i) if(x[i]<pos) ++cnt;
	return cnt;
}
//dp[i][j][k][0/1]+left(i+j+k,i,j,k) -> dp[i+1][j][k][1]
//dp[i][j][k][0]+left(i+j+k,i,j,k) -> dp[i][j+1][k][0]
//dp[i][j][k][0/1]+left(i+j+k,i,j,k) -> dp[i][j][k+1][0]
void Min(int&a,const int&b)
{
	a=min(a,b);
}
void Update_dp(int x1,int y,int z,int tp)
{
	#define lef(i) calc_left(i,x1,y,z)
	int nw=dp[x1][y][z][tp];
	if(x1<v.size()) Min(dp[x1+1][y][z][1],nw+lef(v[x1]));
	if(y<k.size()&&!tp) Min(dp[x1][y+1][z][0],nw+lef(k[y]));
	if(z<x.size()) Min(dp[x1][y][z+1][0],nw+lef(x[z]));	
}
int main()
{
	init();
	for(int i=0,I=v.size();i<=I;++i)
	for(int j=0,J=k.size();j<=J;++j)
	for(int l=0,L=x.size();l<=L;++l)
	for(int rp=0;rp<2;rp++)
	Update_dp(i,j,l,rp);
	cout<<min(dp[v.size()][k.size()][x.size()][0],dp[v.size()][k.size()][x.size()][1])<<endl;
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