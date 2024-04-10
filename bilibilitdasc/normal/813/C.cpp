#include <bits/stdc++.h>
/*code*/
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
int n,X;
vector<int> path;
int a,b;
vector<int> c[200005];
int p[200005],d[200005];
bool dfs(int x,int P,int D)
{
	p[x]=P;d[x]=D;
	bool fl=(x==X);
	rep(i,c[x].size())
	{
		int y=c[x][i];
		if(y!=P&&dfs(y,x,D+1)) fl=1;
	}
	if(fl) path.pb(x);
	return fl;
}
int dfs2(int x)
{
	int ans=d[x];
	rep(i,c[x].size())
	{
		int y=c[x][i];
		if(y!=p[x]) ans=max(ans,dfs2(y));
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>X;
	rep1(i,n-1)
	{
		cin>>a>>b;
		c[a].pb(b);c[b].pb(a);
	}
	//cout<<"FC"<<endl;
	dfs(1,0,0);
	//cout<<"CF"<<endl;
	int v=path[path.size()/2-1];
	//cout<<"WW"<<endl;
	int u=dfs2(v);
	cout<<u*2<<endl;
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