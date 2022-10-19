#include <bits/stdc++.h>
//#define CinCout
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define pb push_back
#define mp make_pair
#define debugv(x) cout<<#x<<'='<<x<<",line "<<__LINE__-1<<endl
#define debug cout<<"at line "<<__LINE__-1<<" in function "<<__FUNCTION__<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
#ifdef CinCout
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#else
#define Yes puts("Yes")
#define No puts("No")
#define YES puts("YES")
#define NO puts("NO")
#endif
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int n,m;
char s[505][505];
char p[505][505];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool in(int x,int y)
{
	return 0<=x&&0<=y&&x<n&&y<m;
}
void dfs(int x,int y)
{
	p[x][y]='V';
	rep(i,4)
	{
		int X=x+dx[i],Y=y+dy[i];
		if(in(X,Y)&&p[X][Y]=='.')
		dfs(X,Y);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
//	n=500;m=500;
	rep(i,n)
	{
		scanf("%s",s[i]);
//		rep(j,m) s[i][j]=(rand()&1)?'S':'W'; 
		rep(j,m)
		{
			if(s[i][j]=='.') s[i][j]='D';
			p[i][j]=((s[i][j]=='S'||s[i][j]=='W')?'.':s[i][j]);
		}
	}
//	rep(i,n) puts(p[i]);
	rep(i,n) rep(j,m)
	{
		if(s[i][j]=='W'&&p[i][j]=='.')
		dfs(i,j);
	}
//	rep(i,n) puts(p[i]);
	rep(i,n) rep(j,m)
	{
		if(s[i][j]=='S'&&p[i][j]=='V')
		{
			puts("No");return 0;
		}
	}
	puts("Yes");
	rep(i,n) puts(s[i]);
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